#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "elev.h"
#include "carte.h"
#include "biblioteca.h"

using namespace std;

unsigned int citesteNumar(const string& mesaj)
{
    long long valoare;
    while (true)
    {
        cout << mesaj;
        if (cin >> valoare)
        {
           if(valoare > 0){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valoare;
           }
           else{
            cout << "[EROARE] Codul/ID-ul trebuie sa fie un numar strict pozitiv!\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }
        }
        else
        {
            cout << "[EROARE] Introducere invalida! Te rugam sa introduci un numar intreg pozitiv.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

void afiseazaMeniu()
{
    cout << "\n========================================\n";
    cout << "   SISTEM DE GESTIUNE BIBLIOTECA   \n";
    cout << "========================================\n";
    cout << "1. Adauga un elev\n";
    cout << "2. Adauga o carte\n";
    cout << "3. Imprumuta o carte\n";
    cout << "4. Returneaza o carte\n";
    cout << "5. Afiseaza istoricul unei carti\n";
    cout << "6. Afiseaza elevii inregistrati\n";
    cout << "7. Afiseaza cartile inregistrate\n";
    cout << "8. Sterge un elev\n";
    cout << "9. Sterge o carte\n";
    cout << "10. Goleste intreaga baza de date\n";
    cout << "0. Iesire\n";
    cout << "----------------------------------------\n";
    cout << "Alege o optiune: ";
}

int main()
{
    Biblioteca b;

    string optiune = "";

    do
    {
        afiseazaMeniu();
        getline(cin, optiune);

        if (optiune == "1")
        {
            cout << "\n--- Adaugare Elev ---\n";
            unsigned int cod;
            string nume, clasa;

            cod = citesteNumar("Cod matricol: ");

            if (b.cautaElevDupaCod(cod) != nullptr)
            {
                cout << "[EROARE] Exista deja inregistrat un elev cu acest cod matricol!\n";
            }
            else
            {
                cout << "Nume: ";
                getline(cin, nume);

                cout << "Clasa: ";
                getline(cin, clasa);

                b.adaugaElev(Elev(cod, nume, clasa));
                cout << "[SUCCES] Elevul a fost inregistrat!\n";
            }
        }





        else if (optiune == "2")
        {
            cout << "\n--- Adaugare Carte ---\n";
            unsigned int id;
            string titlu, autor;
            int an;


            id = citesteNumar("ID Carte: ");


            if (b.cautaCarteDupaID(id) != nullptr)
            {
                cout << "[EROARE] Exista deja o carte cu acest ID!\n";
            }
            else
            {
                cout << "Titlu: ";
                getline(cin, titlu);

                cout << "Autor: ";
                getline(cin, autor);

                cout << "An aparitie: ";
                cin >> an;
                cin.ignore(10000, '\n');

                b.adaugaCarte(Carte(id, titlu, autor, an));
                cout << "[SUCCES] Cartea a fost adaugata!\n";
            }
        }





        else if (optiune == "3")
        {
            cout << "\n--- Imprumut Carte ---\n";
            unsigned int idCarte, codElev;
            
            idCarte = citesteNumar("Introdu ID-ul cartii: ");
            
            codElev = citesteNumar("Introdu codul matricol al elevului: ");

            cin.ignore(10000, '\n');

            b.imprumutaCarte(idCarte, codElev);
        }





        else if (optiune == "4")
        {
            cout << "\n--- Returnare Carte ---\n";
            unsigned int idCarte;

            idCarte = citesteNumar("Introdu ID-ul cartii de returnat: ");

            b.returneazaCarte(idCarte);
        }






        else if (optiune == "5")
        {
            cout << "\n--- Istoric Carte ---\n";
            unsigned int idCarte;

            idCarte = citesteNumar("Introdu ID-ul cartii: ");

            b.afiseazaIstoricCarte(idCarte);
        }





        else if (optiune == "6")
        {
            cout << "\n--- Lista Elevi Inregistrati ---\n";
            b.afiseazaTotiElevii();
        }





        else if (optiune == "7")
        {
            cout << "\n--- Lista Carti din Biblioteca ---\n";
            b.afiseazaToateCartile();
        }


        else if (optiune == "8")
        {
            cout << "\n--- Stergere Elev ---\n";
            unsigned int cod;

            cod = citesteNumar("Introdu codul matricol al elevului de sters: ");

            b.stergeElev(cod);
        }


        else if (optiune == "9")
        {
            cout << "\n--- Stergere Carte ---\n";
            unsigned int id;

            id = citesteNumar("Introdu ID-ul cartii de sters: ");

            b.stergeCarte(id);
        }


        else if (optiune == "10")
        {
            cout << "\n--- Golire Baza de Date ---\n";
            cout << "Sigur doresti sa stergi toti elevii si toate cartile? [Y/N]: ";
            char optiune;
            cin >> optiune;
            cin.ignore(10000, '\n');

            if (toupper(optiune) == 'Y')
            {
                b.golesteBazaDeDate();
            }
            else
            {
                cout << "[INFO] Operatiune anulata.\n";
            }
        }




        else if (optiune == "0")
        {
            cout << "\nAplicatia se inchide.\n";
        }




        else
        {
            cout << "\nOptiune invalida! Incearca din nou.\n";
        }

        

        if (optiune != "0")
        {
            cout << "\n\nPentru a va intoarce la meniul de optiuni apasati ENTER...";
            cin.get();
            system("cls");
        }

    } while (optiune != "0");

    return 0;
}