#pragma once


#include "elev.h"
#include "carte.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Biblioteca
{
    private: 
        vector<Elev> listaElevi;
        vector<Carte> listaCarti;

    public: 

        Biblioteca();

        ~Biblioteca();


        bool adaugaElev(const Elev& e);
        void afiseazaTotiElevii() const;
        Elev* cautaElevDupaCod(unsigned int cod);

        bool adaugaCarte(const Carte& c);
        void afiseazaToateCartile() const;
        Carte* cautaCarteDupaID(unsigned int id);

        bool imprumutaCarte(unsigned int idCarte, unsigned int codElev);
        bool returneazaCarte(unsigned int idCarte);
        void afiseazaIstoricCarte(unsigned int idCarte) const;

        void incarcaDatele();
        void salveazaDatele() const;

        bool stergeElev(unsigned int cod);
        bool stergeCarte(unsigned int id);
        void golesteBazaDeDate();



};