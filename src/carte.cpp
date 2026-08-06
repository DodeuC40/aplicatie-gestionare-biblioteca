#include "carte.h"
#include <iostream>
using namespace std;


Carte::Carte(unsigned int id, string titlu, string autor, int an_aparitie, bool disponibila){
    this->ID = id;
    this->titlu = titlu;
    this->autor = autor;
    this->an_aparitie = an_aparitie;
    this->disponibila = disponibila;

    cout << "[CONSTRUCTOR] A fost creata cartea: \"" << this->titlu << "\" (ID: " << this->ID << ")" << endl;
}

Carte::~Carte(){}

unsigned int Carte::getID() const{
    return this->ID;
}

 string Carte::getTitlu() const{
    return this->titlu;
 }

        string Carte::getAutor() const
{
    return this->autor;
}

int Carte::getAnAparitie() const
{
    return this->an_aparitie;
}

bool Carte::isDisponibila() const
{
    return this->disponibila;
}

const vector<Elev>& Carte::getElevi() const
{
    return this->elevi;
}

void Carte::setTitlu(const string& t)
{
    this->titlu = t;
}

void Carte::setAutor(const string& a)
{
    this->autor = a;
}

void Carte::setAnAparitie(int an)
{
    this->an_aparitie = an;
}

void Carte::setDisponibila(bool disp)
{
    this->disponibila = disp;
}

bool Carte::imprumutaCarte(const Elev& e)
{
    if (!this->disponibila)
    {
        cout << "[EROARE] Cartea \"" << this->titlu << "\" este deja imprumutata!\n";
        return false;
    }

    adaugainIstoric(e);
    
    this->disponibila = false;

    cout << "[ACTIUNE REUSITA] Cartea \"" << this->titlu << "\" a fost imprumutata de elevul " << e.getNume() << "\n";
    return true;
}

void Carte::returneazaCarte()
{
    if (this->disponibila)
    {
        cout << "[EROARE] Cartea \"" << this->titlu << "\" este deja in biblioteca!\n";
        return;
    }

    this->disponibila = true;
    cout << "[ACTIUNE REUSITA] Cartea \"" << this->titlu << "\" a fost returnata si este din nou disponibila.\n";
}

void Carte::afiseazaDetalii() const
{
    cout << endl<< "---------------------------------------------" << endl;
    cout << "ID Carte: " << this->ID << endl;
    cout << "Titlu: " << this->titlu << endl;
    cout << "Autor: " << this->autor << endl;
    cout << "An aparitie: " << this->an_aparitie << endl;
    if(this->disponibila){
        cout << "Status: " << "Disponibila" << endl;
    }
    else{
         cout << "Status: " << "Imprumutata de " << this->getElevi().back().getNume() 
            << " (Cod matricol: " << this->getElevi().back().getCodMatricol() << ")" << endl;
    }
    cout << "Numar total imprumuturi: " << this->elevi.size() << endl;
    cout << "---------------------------------------------" << endl;
}

void Carte::afiseazaIstoricElevi() const
{
    cout << endl << " Istoric imprumuturi pentru cartea \"" << this->titlu << "\""<< endl;

    if (this->elevi.empty())
    {
        cout << "Niciun elev nu a imprumutat aceasta carte pana acum." << endl;
        return;
    }

    int contor = 1;

    for (const auto& elev : this->elevi)
    {
        cout << contor++ << ". ";
        elev.afiseaza(); 
    }
}

void Carte::adaugainIstoric(const Elev& elev){
    this->elevi.push_back(elev);
}