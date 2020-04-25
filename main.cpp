/*
    Programación Orientada a Objetos
    PROYECTO 2
    Ana Elisa Estrada Lugo
    A01251091
    24/04/2020
*/
#include <iostream>
#include <fstream>
#include <sstream> 
#include "Pelicula.h"
#include "Funcion.h"
#include<string>
using namespace std;

int cambioInt(string a){
  stringstream entero(a);
    int nPeli = 0;
    entero >> nPeli;
    return nPeli;
}//funcion que convierte string en entero


int main() {
  //Declaración de arreglos de cada clase
  Actor arrAct[20];
  Funcion arrFun[20];
  Pelicula arrPeli[20];


  int y=0,numCaracteres=0,numId,restCarac;
  string nom,lineaPeli,lineaActor,ids;
  Pelicula lista;
  
  //Abrir archivos
  ifstream infoAct;
  infoAct.open("actores.txt");
  ifstream infoPeli;
  infoPeli.open("peliculas.txt");
  
  //Leer linea por linea de arch actores
  while(getline(infoAct,lineaActor)){
    numCaracteres = lineaActor.length();//Obtiene el num de caracteres del renglon
    ids = lineaActor.substr(0,2);//Toma 2 caracteres apartir del caracter 0 del renglon 
    numId = cambioInt(ids);//Cambio de string a int
    
    arrAct[y].setId(numId);//Almacena Id en arreglo actor
    //cout<<arrAct[y].getId()<<"\t"; //Verificacion Id

    restCarac = numCaracteres - 3; 
    nom = lineaActor.substr(3,restCarac);//Toma el resto de caracteres del renglon apartir de posición 3
    
    arrAct[y].setNombre(nom);//Almacena nombre en arreglo actor
    //cout<<arrAct[y].getNombre()<<endl; //Verificacion nombre

    y++;//Indice que representa el renglon del arreglo
  }



  int lugar=0,j=0,k=0,nPeli,aPeli,dPeli,longGene,numRenglon=0,noActor,l=0;
  int numEspacios[20][numCaracteres],idActor[10];
  string gene,nombrePelicula,numPelicula,anioPelicula,duraPelicula,cantA,noId[5];

  //Leer archivo peliculas
  while(getline(infoPeli,lineaPeli)){
    numCaracteres = lineaPeli.length();
    //Obtiene la posición de todos los espacios en el renglón y lo guarda en arr numEspacios[][]
    for(int z=0;z<numCaracteres;z++){
      if(lineaPeli[z] == ' '){
        numEspacios[numRenglon][j]=z;
        //cout<<ii<<"\t"<<j<<"\t";
        //cout<<numEspacios[ii][j]<<"\t";//Verificación de matriz de espacios
        j++;//Cambia a la sig columna
        }
    }
    numPelicula = lineaPeli.substr(0,3);
    nPeli = cambioInt(numPelicula);
    arrPeli[k].setNumPeli(nPeli);
    //cout<<arrPeli[k].getNumPeli()<<"\t"; Verificación número pelicula

    anioPelicula = lineaPeli.substr(4,4);
    aPeli = cambioInt(anioPelicula);
    arrPeli[k].setAnio(aPeli);
    //cout<<arrPeli[k].getAnio()<<"\t"; //Verificación año

    duraPelicula = lineaPeli.substr(9,3);
    dPeli = cambioInt(duraPelicula);
    arrPeli[k].setDuracion(dPeli);
    //cout<<arrPeli[k].getDuracion()<<"\t"; //Verificación duración pelicula

    longGene = ((numEspacios[numRenglon][3]-numEspacios[numRenglon][2])-1);//Obtiene el num de caracteres del genero de pelicula
    gene = lineaPeli.substr((numEspacios[numRenglon][2]+1),longGene);
    arrPeli[k].setGenero(gene);
    //cout<<arrPeli[k].getGenero()<<"\t"; //Verificación género

    cantA = lineaPeli.substr((numEspacios[numRenglon][3]+1),1);
    noActor = cambioInt(cantA);
    arrPeli[k].setCantActores(noActor);
   // cout<<arrPeli[k].getCantActores()<<"\t"; //Verificación cantidad de actores

    for(int w=0;w<noActor;w++){
      noId[w] = lineaPeli.substr((numEspacios[numRenglon][4+w]+1),2);//Toma los dos caracteres desde la posicion de espacio (4 + w)+1
      idActor[w] = cambioInt(noId[w]);
      lista.setListaActores(w);
      arrPeli[k].listaActores[w].setId(idActor[w]);
      //cout<<arrPeli[k].listaActores[w].getId()<<"\t"; //Verificación lista de actores
    }

    l = noActor+4;//Determinas la posición del espacio donde inicia el nombre de la pelicula
    restCarac = numCaracteres - numEspacios[numRenglon][l];
    nombrePelicula = lineaPeli.substr((numEspacios[numRenglon][l]+1),restCarac);
    arrPeli[k].setTitulo(nombrePelicula);
    //cout<<arrPeli[k].getTitulo()<<"\t"; //Verificación título
    
    k++;//Salta a la sig localidad del arrPeli
    numRenglon++;//Salta al sig renglon de la matriz numEspacios
    j=0;//inicializa el num de la columna de la matriz numEspacios[][]
  }

  string clavePeli;
  int salaPeli,horaPeli,minPeli;
  cout<<endl;
  cout<<"Captura de datos de las funciones(clave, sala y horarios) "<<endl;
  cout<<endl;

  for(int i=0;i<numRenglon;i++){
  cout<<"Dame los datos de la pelicula: "<<arrPeli[i].getTitulo()<<"\t"<<"Duración: "<<arrPeli[i].getDuracion()<<" min"<<endl;
  
  cout<<"Clave(Se sugiere iniciales de pelicula): "<<"\t";
  cin>>clavePeli;
  arrFun[i].setCveFuncion(clavePeli);
  cout<<endl;

  do{
  cout<<"Sala(1->5): "<<"\t";
  cin>>salaPeli;
  arrFun[i].setSala(salaPeli);
  cout<<endl;
  }while(salaPeli>5||salaPeli<1);

  do{
  cout<<"Hora(0->23): "<<"\t";
  cin>>horaPeli;
  arrFun[i].hora.setHh(horaPeli);
  }while(horaPeli>23||horaPeli<0);
  
  do{
  cout<<"Minutos(0->59): "<<"\t";
  cin>>minPeli;
  arrFun[i].hora.setMm(minPeli);
  cout<<endl;
  }while(minPeli>59||minPeli<0);
  //cout<<arrFun[i].hora.getHh()<<" : "<<arrFun[i].hora.getMm();
  cout<<endl;

  }
  char opcion;
  int cant,ID,val,validar;
  string actName;
  do{
    cout<<endl;
    cout<<"MENÚ"<<endl;
    cout<<"a. Mostrar datos de actores"<<endl;
    cout<<"b. Mostrar datos de películas"<<endl;
    cout<<"c. Consulta de funciones disponibles"<<endl;
    cout<<"d. Consulta de funciones por hora"<<endl;cout<<"e. Consulta por clave de función"<<endl;cout<<"f. Consulta de películas en las que participar un actor"<<endl;
    cout<<"g. Terminar"<<endl;
    
    cout<<endl; 
    cout<<"Teclea la letra de la opción deseada"<<"\t";
    cin>>opcion;
    opcion=tolower(opcion);

    switch(opcion){
      case 'a':
      cout<<endl;
      cout<<"ID  "<<"NOMBRE ACTOR"<<endl;
      for(int y=0;y<20;y++){
      cout<<arrAct[y].getId()<<"\t";
      cout<<arrAct[y].getNombre()<<endl;
      }
      break;

      case 'b':
      cout<<endl;
      cout<<"AÑO   "<<"DURACIÓN "<<"GÉNERO "<<"    TÍTULO"<<endl;                              
      for(int y=0;y<numRenglon;y++){
        cout<<arrPeli[y].getAnio()<<"\t";
        cout<<arrPeli[y].getDuracion()<<"\t"<<"\t";
        cout<<arrPeli[y].getGenero()<<"\t"<<"\t";
        cout<<arrPeli[y].getTitulo()<<endl;
        cant = arrPeli[y].getCantActores();
        cout<<"ACTORES:"<<"\t";
        //Ciclo for para leer los nombre de los actores mediante el arrActor y guardarlos en listaActores de arrPeli 
        for(int j=0;j<cant;j++){
          ID = arrPeli[y].listaActores[j].getId(); 
          for(int k=0;k<20;k++){
            if(ID == arrAct[k].getId()){
              actName = arrAct[k].getNombre();
              arrPeli[y].listaActores[j].setNombre(actName);
              cout<<arrPeli[y].listaActores[j].getNombre()<<"\t";

            }
          }
        }
        cout<<endl;
        cout<<endl;
      }
      break;

      case 'c':
      cout<<endl;
      cout<<"CLAVE"<<"\t"<<"SALA"<<"\t"<<"HORARIO"<<"\t"<<"PELICULA"<<endl;
      for(int y=0;y<numRenglon;y++){
        cout<<arrFun[y].getCveFuncion()<<"\t"<<"\t";
        cout<<arrFun[y].getSala()<<"\t"<<"\t";
        cout<<arrFun[y].hora.getHh()<<":"<<arrFun[y].hora.getMm()<<"\t"<<"\t";
        cout<<arrPeli[y].getTitulo()<<endl;
        }
      break;

      case 'd':
      cout<<endl;
      cout<<"Teclea hora para funciones disponibles:"<<endl;
      cout<<endl;
      do{
        cout<<"Hora(0->23): "<<"\t";
        cin>>horaPeli;
        }while(horaPeli>23||horaPeli<0);

        do{
          cout<<"Minutos(0->59): "<<"\t";
          cin>>minPeli;
          }while(minPeli>59||minPeli<0);
        cout<<endl;
        cout<<"Funciones de peliculas a las "<<horaPeli<<" : "<<minPeli<<endl;
        cout<<endl;
        cout<<"SALA"<<"\t"<<"PELICULA"<<endl;
        for(int y=0;y<numRenglon;y++){
        if(horaPeli == arrFun[y].hora.getHh()){
          if(minPeli == arrFun[y].hora.getMm()){
            cout<<arrFun[y].getSala()<<"\t";
            cout<<arrPeli[y].getTitulo()<<endl;
          }
        }
      }
      break;

      case 'e':
      cout<<endl;
      do{
      cout<<"Dame la clave de la pelicula: "<<"\t";
      cin>>clavePeli;
      cout<<endl;
      cout<<"SALA"<<"\t"<<"HORA"<<"\t"<<"DURACIÓN"<<"\t"<<"GÉNERO"<<"\t"<<"PELICULA"<<endl;
      for(int y=0;y<numRenglon;y++){
      if(clavePeli == arrFun[y].getCveFuncion()){
        cout<<arrFun[y].getSala()<<"\t"<<"\t";
        cout<<arrFun[y].hora.getHh()<<":"<<arrFun[y].hora.getMm()<<"\t"<<"\t";
        cout<<arrPeli[y].getDuracion()<<"\t"<<"\t"<<"\t";
        cout<<arrPeli[y].getGenero()<<"\t";
        cout<<arrPeli[y].getTitulo()<<endl;
        cant = arrPeli[y].getCantActores();
        cout<<"ACTORES:"<<endl;
       for(int j=0;j<cant;j++){
          ID = arrPeli[y].listaActores[j].getId(); 
          for(int k=0;k<20;k++){
            if(ID == arrAct[k].getId()){
              actName = arrAct[k].getNombre();
              arrPeli[y].listaActores[j].setNombre(actName);
              cout<<arrPeli[y].listaActores[j].getNombre()<<endl;
            }
          }
        }
        val = 1;
      }
      }
      }while(val == 0);
      val=0;
      break;

      case 'f':
      cout<<endl;
      int numAct;
      do{
      cout<<"Dame el Id del actor: "<<"\t";
      cin>>ID;
      cout<<endl;
      cout<<"AÑO"<<"\t"<<"\t"<<"PELICULA"<<endl;
      for(int y=0;y<numRenglon;y++){
        cant = arrPeli[y].getCantActores();
        for(int j=0;j<cant;j++){
          numAct = arrPeli[y].listaActores[j].getId();
          if(ID == numAct){
            cout<<arrPeli[y].getAnio()<<"\t";
            cout<<arrPeli[y].getTitulo()<<endl;
            validar = 1;
            }
          }
        }
      }while(validar == 0);
      validar = 0;
      break;

      case 'g':
      cout<<endl;
      cout<<"PROGRAMA TERMINADO"<<endl;
      break;
      

      default:
      cout<<endl;
      cout<<"NO EXISTE LA OPCIÓN SELECCIONADA"<<endl;
    }
   }while(opcion != 'g');

   infoAct.close();
   infoPeli.close();

return 0;
}