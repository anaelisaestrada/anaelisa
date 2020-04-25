/*
    Programación Orientada a Objetos
    PROYECTO 2
    Ana Elisa Estrada Lugo
    A01251091
    24/04/2020
*/
//Pelicula.h
#include <iostream>
#include <iomanip>
#include <string>
#include "Actor.h"
using namespace std;

class Pelicula{
  public:
  Pelicula();
  void setNumPeli(int num);
  int getNumPeli();
  void setAnio(int a);
  int getAnio();
  void setDuracion(int d);
  int getDuracion();
  void setTitulo(string t);
  string getTitulo();
  void setGenero(string g);
  string getGenero();
  void setListaActores(int sub);
  bool agregarActor(Actor act);
  void setCantActores(int actors);
  int getCantActores();
  Actor listaActores[10];

  private:
  int numPeli,anio,duracion,cantActores,subindice;
  string titulo,genero;

};
Pelicula::Pelicula()
{
  numPeli = 0;
  anio = 0;
  duracion = 0;
  cantActores = 0;
  titulo = "S/N";
  genero = "S/N";
  subindice = 0;
}
void Pelicula::setNumPeli(int num)
{
  numPeli = num;
}
void Pelicula::setAnio(int a)
{
  anio = a;
}
void Pelicula::setDuracion(int d)
{
  duracion = d;
}
void Pelicula::setTitulo(string t)
{
  titulo = t;
}
void Pelicula::setListaActores(int sub)
{
  subindice = sub;
}
void Pelicula::setGenero(string g)
{
  genero = g;
}
void Pelicula::setCantActores(int actors)
{
  cantActores = actors;
}
int Pelicula::getNumPeli()
{
  return numPeli;
}
int Pelicula::getAnio()
{
  return anio;
}
int Pelicula::getDuracion()
{
  return duracion;
}
string Pelicula::getTitulo()
{
  return titulo;
}
string Pelicula::getGenero()
{
  return genero;
}
bool Pelicula::agregarActor(Actor act)
{
  for(int x=0;x<10;x++){ 
    if(listaActores[x].getId() < 10){ //si el Id <10 se ingresa el num actor, por eso el limite es 10 ya que se maneja dos digitos para Id(10-99)
      listaActores[x]= act;
      cantActores++;
      return true;
      }
    }
  return false;
}
int Pelicula::getCantActores()
{
  return cantActores;
}

