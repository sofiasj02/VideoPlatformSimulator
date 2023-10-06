
#ifndef Video_h
#define Video_h

#include <iostream>
#include <string>

using namespace std;

class Video {
protected:
    char tipo;
    int idVideo;
    string titulo;
    string genero;
    int duracion;
    int calificacion;

public:
    Video();
    Video(char _tipo, int _idVideo, string _titulo, string _genero, int _duracion, int _calificacion);

    void setTipo(char _tipo);
    void setIdVideo(int _idVideo);
    void setTitulo(string _titulo);
    void setGenero(string _genero);
    void setDuracion(int _duracion);
    void setCalificacion(int _calificacion);

    char getTipo();
    int getIdVideo();
    string getTitulo();
    string getGenero();
    int getDuracion();
    int getCalificacion();

    virtual string muestra();
};

#endif
