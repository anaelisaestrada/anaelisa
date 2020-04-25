/*
    Programación Orientada a Objetos
    PROYECTO 2
    Ana Elisa Estrada Lugo
    A01251091
    24/04/2020
*/
//Actor.h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Actor{

  public:
  Actor();
  Actor(int i,string n);
  void setId(int i);
  int getId();
  void setNombre(string n);
  string getNombre();
  void muestraActor();

  private:
  int id;
  string nombre;

};
Actor::Actor()
{
  id = 0;
  nombre = "S/N";
}
Actor::Actor(int i,string n)
{
  id = i;
  nombre = n;
}
void Actor::setId(int i)
{
  id = i;
}
void Actor::setNombre(string n)
{
  nombre = n;
}
int Actor::getId()
{
  return id;
}
string Actor::getNombre()
{
  return nombre;
}
void Actor::muestraActor()
{
  cout<<id<<"\t"<<nombre<<endl;
}