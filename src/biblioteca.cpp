#include "biblioteca.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


Biblioteca::Biblioteca(){
    incarcaDatele();
}

Biblioteca::~Biblioteca(){
    salveazaDatele();
}

bool Biblioteca::adaugaElev(const Elev& e){
    if(this->cautaElevDupaCod(e.getCodMatricol()) != nullptr)
    {
        return false;
    }
    listaElevi.push_back(e);
    return true;
}

Elev* Biblioteca::cautaElevDupaCod(unsigned int cod){
    for(auto& e : listaElevi)
            {
                if(e.getCodMatricol() == cod){
                    return &e;
                }
            }

    return nullptr;
}

void Biblioteca::afiseazaTotiElevii() const{
    if(listaElevi.empty())
            {
                cout << " Nu exista niciun elev inregistrat!\n";
            }
            else{

                int contor = 1;

                for(const auto&e : listaElevi)
                {
               
                    cout << contor++ << ". ";
                    e.afiseaza();
                }
            }
}

bool Biblioteca::adaugaCarte(const Carte& c)
{
    if (this->cautaCarteDupaID(c.getID()) != nullptr)
    {
        return false; 
    }
    listaCarti.push_back(c);
    return true;
}

Carte* Biblioteca::cautaCarteDupaID(unsigned int id)
{
    for (auto& c : listaCarti)
    {
        if (c.getID() == id)
        {
            return &c;
        }
    }
    return nullptr; 
}

void Biblioteca::afiseazaToateCartile() const
{
    if(listaCarti.empty())
            {
                cout << " Nu exista nicio carte inregistrata!\n";
            }
            else{

                int contor = 1;

                for(const auto&c : listaCarti)
                {
               
                    cout << contor++ << ". ";
                    c.afiseazaDetalii();
                }
            }
}

bool Biblioteca::imprumutaCarte(unsigned int idCarte, unsigned int codElev)
{
    Carte* carte = cautaCarteDupaID(idCarte);
    Elev* elev = cautaElevDupaCod(codElev);

    if (carte == nullptr || elev == nullptr)
    {
        cout << "[EROARE] Cartea sau elevul nu au fost gasiti!\n";
        return false;
    }

    carte->imprumutaCarte(*elev);
    return true;
}

bool Biblioteca::returneazaCarte(unsigned int idCarte)
{
    Carte* carte = cautaCarteDupaID(idCarte);

    if (carte == nullptr)
    {
        cout << "[EROARE] Cartea nu a fost gasita!\n";
        return false;
    }

    carte->returneazaCarte();
    return true;
}

void Biblioteca::afiseazaIstoricCarte(unsigned int idCarte) const
{
    
    for (const auto& c : listaCarti)
    {
        if (c.getID() == idCarte)
        {
            c.afiseazaIstoricElevi();
            return;
        }
    }
    cout << "[EROARE] Cartea nu a fost gasita!\n";
}

void Biblioteca::incarcaDatele()
{
    ifstream fElevi("elevi.txt");

    if(fElevi.is_open()){
        
        unsigned int cod;
        string nume, clasa;

        while (fElevi >> cod)
        {
            fElevi.ignore(10000, '\n'); 
            getline(fElevi, nume);
            getline(fElevi, clasa);

            listaElevi.push_back(Elev(cod, nume, clasa));
        }
        fElevi.close();
    }

    ifstream fCarti("carti.txt");
    if (fCarti.is_open())
    {
        unsigned int id;
        string titlu, autor;
        int an;
        bool disponibila;
        size_t nrElevi;
        

        while (fCarti >> id)
        {
            fCarti.ignore(10000, '\n'); 
            getline(fCarti, titlu);
            getline(fCarti, autor);
            fCarti >> an;
            fCarti >> disponibila; 
            fCarti >> nrElevi; 
            fCarti.ignore(10000, '\n');

            Carte carte(id, titlu, autor, an);

            if (disponibila) carte.setDisponibila(true); 
            else carte.setDisponibila(false); 

            for (size_t i = 0; i < nrElevi; ++i)
            {
                unsigned int codE;
                string numeE, clasaE;

                fCarti >> codE;
                fCarti.ignore(10000, '\n');
                getline(fCarti, numeE);
                getline(fCarti, clasaE);

                carte.adaugainIstoric(Elev(codE, numeE, clasaE));
            }

            listaCarti.push_back(carte);
        }
        fCarti.close();
    }
    
}

void Biblioteca::salveazaDatele() const
{
    
    ofstream fElevi("elevi.txt");


    if (fElevi.is_open())
    {
        for (const auto& e : listaElevi)
        {
            fElevi << e.getCodMatricol() << "\n";
            fElevi << e.getNume() << "\n";
            fElevi << e.getClasa() << "\n";
        }
        fElevi.close();
    }

    
    ofstream fCarti("carti.txt");

    if (fCarti.is_open())
    {
        for (const auto& c : listaCarti)
        {
            fCarti << c.getID() << "\n";
            fCarti << c.getTitlu() << "\n";
            fCarti << c.getAutor() << "\n";
            fCarti << c.getAnAparitie() << "\n";
            fCarti << c.isDisponibila() << "\n";

            fCarti << c.getElevi().size() << "\n";

            for (const auto& elev : c.getElevi())
            {
                fCarti << elev.getCodMatricol() << "\n";
                fCarti << elev.getNume() << "\n";
                fCarti << elev.getClasa() << "\n";
            }
        }
        fCarti.close();
    }
}

bool Biblioteca::stergeElev(unsigned int cod){
    Elev* e = cautaElevDupaCod(cod);

    if(e == nullptr){
        cout << "[EROARE] Nu exista niciun elev cu acest cod matricol! \n" ;
        return false;
    }

    for(const auto& carte : listaCarti){
        if(!carte.isDisponibila() && !carte.getElevi().empty()){
            if(carte.getElevi().back().getCodMatricol() == cod){
                cout << "[EROARE] Elevul " << e->getNume() << " nu poate fi sters din baza de date deoarece are cartea " << carte.getTitlu() 
                    << " (ID: " << carte.getID() <<  ") nereturnata! \n";

                return false;
            }
        }
    }

    cout << "\n Confirmati stergerea din baza de date a elevului ";
    e->afiseaza();
    cout << "\n [Y/N] :  "; 

    char optiune;
    cin >> optiune;
    cin.ignore(10000, '\n');

    if(toupper(optiune) == 'Y'){
        listaElevi.erase(
        std::remove_if(listaElevi.begin(), listaElevi.end(),
            [cod](const Elev& elev) { return elev.getCodMatricol() == cod; }),
        listaElevi.end()
    );

        cout << "[SUCCES] Elevul cu codul " << cod << " a fost sters din baza de date!\n";
        return true;
    }

    else if(toupper(optiune) == 'N'){
        cout << "[INFO] Operatiune anulata.\n";
        return true;
    }  
    
    else {
        cout << "Optiune invalida! Se paraseste functia ...\n";
        return false;
    }
}

bool Biblioteca::stergeCarte(unsigned int id){
    Carte* c = cautaCarteDupaID(id);

    if (c == nullptr)
    {
        cout << "[EROARE] Nu exista nicio carte cu acest ID\n";
        return false;
    }


    if (!c->isDisponibila())
    {
        cout << "[EROARE] Cartea '" << c->getTitlu()
                  << "' este in prezent imprumutata de elevul " << c->getElevi().back().getNume()
                   <<" (Cod Matricol: " << c->getElevi().back().getCodMatricol() << ") si nu poate fi stearsa!\n";
        return false;
    }


    cout << "\n Confirmati stergerea din baza de date a cartii ";
    c->afiseazaDetalii();
    cout << "\n [Y/N] :  "; 

    char optiune;
    cin >> optiune;
    cin.ignore(10000, '\n');

    if(toupper(optiune) == 'Y'){
        listaCarti.erase(
        std::remove_if(listaCarti.begin(), listaCarti.end(),
            [id](const Carte& carte) { return carte.getID() == id; }),
        listaCarti.end()
    );

        cout << "[SUCCES] Cartea cu ID-ul " << id << " a fost stearsa din baza de date!\n";
        return true;
    }

    else if(toupper(optiune) == 'N'){
        cout << "[INFO] Operatiune anulata.\n";
        return true;
    }  
    
    else {
        cout << "Optiune invalida! Se paraseste functia ...\n";
        return false;
    }
}

void Biblioteca::golesteBazaDeDate()
{
    listaElevi.clear();
    listaCarti.clear();
    cout << "[SUCCES] Baza de date a fost golita complet!\n";
}
