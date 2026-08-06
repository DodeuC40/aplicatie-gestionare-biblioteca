#include "elev.h"
#include <iostream>
using namespace std;

Elev::Elev(unsigned int cod, const string& nume, const string& clasa){
    
    this->cod_matricol = cod;
    this->nume = nume;
    this->clasa = clasa;

    cout << "[CONSTRUCTOR] A fost adaugat elevul cu numele " << this->nume << ", clasa " << this->clasa
         << " (cod matricol: "<<this->cod_matricol<<")"<<endl;
}

Elev::~Elev(){}

unsigned int Elev::getCodMatricol() const{
    return this->cod_matricol;
}

const string& Elev::getNume() const{
    return this->nume;
}

const string& Elev::getClasa() const{
    return this->clasa;
}

void Elev::setCodMatricol(unsigned int cod){
    this->cod_matricol = cod;
}

void Elev::setNume(const string& nume){
    this->nume = nume;
}

void Elev::setClasa(const string& clasa){
    this->clasa = clasa;
}

void Elev::afiseaza() const{
    cout << this->nume << ", clasa "<<this->clasa<<", cod matricol "<<this->cod_matricol<<endl;
}