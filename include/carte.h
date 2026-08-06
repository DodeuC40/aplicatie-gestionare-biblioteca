#pragma once

#include "elev.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Carte
{
    private:
        unsigned int ID;
        string titlu;
        string autor;
        int an_aparitie;
        bool disponibila;
        vector<Elev> elevi;

    public:
      
        Carte(unsigned int id = 0, string t = "", string a = "", int an = 0, bool disp = true);

       
        ~Carte();

        
        unsigned int getID() const;
        string getTitlu() const;
        string getAutor() const;
        int getAnAparitie() const;
        bool isDisponibila() const;
        const vector<Elev>& getElevi() const;

      
        void setTitlu(const string& t);
        void setAutor(const string& a);
        void setAnAparitie(int an);
        void setDisponibila(bool disp);


        bool imprumutaCarte(const Elev& e);
        void returneazaCarte();
        void adaugainIstoric(const Elev& e);

        void afiseazaDetalii() const;
        void afiseazaIstoricElevi() const;

        
    
};