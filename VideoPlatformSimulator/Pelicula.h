

#ifndef Pelicula_h
#define Pelicula_h
#include <iostream>
#include <stdio.h>
#include <string>
#include "Video.h"
using namespace std;

class Pelicula: public Video{
  private: 

  public: 

    Pelicula();
    Pelicula(char _tipo, int _idVideo, string _titulo, string _genero, int _duracion, int _calificacion);
    string muestra();
    
};


#endif