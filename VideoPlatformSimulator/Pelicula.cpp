
//pelicula.cpp
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula(){
}


Pelicula::Pelicula(char _tipo, int _idVideo, string _titulo, string _genero, int _duracion, int _calificacion):Video(_tipo, _idVideo, _titulo, _genero, _duracion, _calificacion )
{
  
}

string Pelicula::muestra() {
    return "El tipo de video es: " + string(1, tipo) + "\nEl Id es: " + to_string(idVideo) + "\nEl título es: " + titulo + "\nEl género es: " + genero + "\nLa duración es: " + to_string(duracion) + "\nLa calificación es: " + to_string(calificacion);
}
