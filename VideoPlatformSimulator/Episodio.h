

#ifndef Episodio_h
#define Episodio_h

#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

class Episodio : public Video {
private:
    string serie;
    int numeroEp;
    int numTemporada;

public:
    Episodio();
    Episodio(char _tipo, int _idVideo, string _serie, string _genero, int _duracion, int _calificacion, int _numeroEp, int _numTemporada);
    string muestra();

    void setSerie(string _serie);
    void setNumeroEp(int _numeroEp);
    void setNumTemporada(int _numTemporada);

    string getSerie();
    int getNumeroEp();
    int getNumTemporada();
};

#endif
