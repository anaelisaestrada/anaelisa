/*
    Programación Orientada a Objetos
    PROYECTO 2
    Ana Elisa Estrada Lugo
    A01251091
    24/04/2020
*/
//Hora.h
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Hora{
  public:
  Hora();
  Hora(int hr, int min);
  void setHh(int hr);
  int getHh();
  void setMm(int min);
  int getMm();
  void muestraHora();

  private:
  int hh,mm;
};
Hora::Hora()
{
  hh = 0;
  mm = 0;
}
Hora::Hora(int hr, int min)
{
  hh = hr;
  mm = min;
}
void Hora::setHh(int hr)
{
  hh = hr;
}
void Hora::setMm(int min)
{
  mm = min;
}
int Hora::getHh()
{
  return hh;
}
int Hora::getMm()
{
  return mm;
}
void Hora::muestraHora()
{
  cout<<hh<<" : "<<mm<<endl;
}