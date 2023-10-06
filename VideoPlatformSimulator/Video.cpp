

#include "Video.h"

Video::Video() {
    tipo = 'N';
    idVideo = 0;
    titulo = "";
    genero = "";
    duracion = 0;
    calificacion = 0;
}

Video::Video(char _tipo, int _idVideo, string _titulo, string _genero, int _duracion, int _calificacion) {
    tipo = _tipo;
    idVideo = _idVideo;
    titulo = _titulo;
    genero = _genero;
    duracion = _duracion;
    calificacion = _calificacion;
}

string Video::muestra() {
    return "El tipo de video es: " + string(1, tipo) +
        "\nEl Id es: " + to_string(idVideo) +
        "\nEl título es: " + titulo +
        "\nEl género es: " + genero +
        "\nLa duración es: " + to_string(duracion) +
        "\nLa calificación es: " + to_string(calificacion);
}

int Video::getCalificacion() {
    return calificacion;
}

string Video::getGenero() {
    return genero;
}

int Video::getIdVideo() {
    return idVideo;
}
