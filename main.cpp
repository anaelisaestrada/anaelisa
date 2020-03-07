/*
    Programación Orientada a Objetos
    PROYECTO 1
    Ana Elisa Estrada Lugo
    A01251091
    06/03/2020
 */
#include <iostream>
#include <fstream>
#include <string>
#include<math.h>
#include<cmath>

using namespace std;

int main() {
  string nombreArchEntrada,nombreArchSalida,texto,linea,num,num2;
  int largoNum,largoNum2,operacion,numFinal=0,numFinal2=0;
  double resultado=0;
  char letra,operador,signo;
    ifstream archEntrada;
    ofstream archSalida;
    cout<<"¿Nombre del archivo de entrada existente?"<<endl;
    cin>>nombreArchEntrada;
    archEntrada.open(nombreArchEntrada.c_str());
    cout<<"¿Nombre que desea del archivo de salida a crear?"<<endl;
    cin>>nombreArchSalida;
    archSalida.open(nombreArchSalida.c_str());

    for(int i=0;i<14;i++){
      archEntrada>>letra;
      linea+= letra;
    }
    while(archEntrada>>num>>signo>>num2){
      largoNum = num.length();
      for (int x=0; x<largoNum;x++){
        operacion = linea.find(num[x]);
        numFinal+= operacion * pow(10,-x-1);
      }
      largoNum2 = num2.length();
      for (int x=0; x<largoNum2;x++){
        operacion = linea.find(num2[x]);
        numFinal2+= operacion * pow(10,-x-1);
      }

      switch (signo){
      case 10:
      resultado = numFinal+numFinal2;
      cout<<numFinal<<"+"<<numFinal2<<"="<<resultado;
      break;
      case 11:
      resultado = numFinal-numFinal2;
      cout<<numFinal<<"-"<<numFinal2<<"="<<resultado;
      break;
      case 12:
      resultado = numFinal*numFinal2;
      cout<<numFinal<<"*"<<numFinal2<<"="<<resultado;
      break;
      case 13:
      resultado = numFinal/numFinal2;
      cout<<numFinal<<"/"<<numFinal2<<"="<<resultado;
      break;
      default:
      cout<<"ERROR"<<endl;
      }
    }
    //archSalida>>numFinal>>signo>>numFinal2;
    
    archEntrada.close();
    archSalida.close();

    return 0;
}
