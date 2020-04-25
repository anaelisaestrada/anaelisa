/*
    Programación Orientada a Objetos
    PROYECTO 2
    Ana Elisa Estrada Lugo
    A01251091
    24/04/2020
*/
//Funcion.h
#include <iostream>
#include <iomanip>
#include <string>
#include "Hora.h"
using namespace std;

class Funcion{
  public:
  Funcion();
  Funcion(string clave, int nPeli, int s,Hora h);
  void setCveFuncion(string clave);
  string getCveFuncion();
  void setNumPeli(int nPeli);
  int getNumPeli();
  void setSala(int s);
  int getSala();
  void setHora(Hora h);
  Hora getHora();
  void muestraFuncion();
  Hora hora;
  
  
  private:
  string cveFuncion;
  int numPeli,sala;

};
Funcion::Funcion()
{
  cveFuncion = "S/C";
  numPeli = 0;
  sala = 0;
  Hora h (0,0);
  hora = h;
}
Funcion::Funcion(string clave, int nPeli, int s,Hora h)
{
  cveFuncion = clave;
  numPeli = nPeli;
  sala = s;
  hora = h;
}
void Funcion::setCveFuncion(string clave)
{
  cveFuncion = clave;
}
void Funcion::setNumPeli(int nPeli)
{
  numPeli = nPeli;
}
void Funcion::setSala(int s)
{
  sala = s;
}
void Funcion::setHora(Hora h)
{
  hora = h;
}
string Funcion::getCveFuncion()
{
  return cveFuncion;
}
int Funcion::getNumPeli()
{
  return numPeli;
}
int Funcion::getSala()
{
  return sala;
}
Hora Funcion::getHora()
{
  return hora;
}
void Funcion::muestraFuncion()
{
  cout<<cveFuncion<<"\t"<<numPeli<<"\t"<<sala<<"\t"<<Funcion::hora.getHh()<<":"<<Funcion::hora.getMm();
  cout<<endl;
}