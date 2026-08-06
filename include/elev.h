#pragma once

#include <iostream>
#include <string>
using namespace std;

class Elev
{
    private:
        unsigned int cod_matricol;
        string nume;
        string clasa; 

    public:

        Elev(unsigned int cod = 0, const string& nume = "", const string& clasa = "");

        ~Elev();


        unsigned int getCodMatricol() const;
        const string& getNume() const;  
        const string& getClasa() const;


        void setCodMatricol(unsigned int cod);
        void setNume(const string& nume);
        void setClasa(const string& clasa);
        

        void afiseaza() const;
};

