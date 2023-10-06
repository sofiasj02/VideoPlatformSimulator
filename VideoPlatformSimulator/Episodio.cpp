

#include "Episodio.h"

Episodio::Episodio() {
    serie = "N/A";
    numeroEp = 1;
    numTemporada = 1;
}

Episodio::Episodio(char _tipo, int _idVideo, string _serie, string _genero, int _duracion, int _calificacion, int _numeroEp, int _numTemporada)
    : Video(_tipo, _idVideo, "", _genero, _duracion, _calificacion) {
    serie = _serie;
    numeroEp = _numeroEp;
    numTemporada = _numTemporada;
}

string Episodio::muestra() {
    return "El tipo de video es: " + string(1, tipo) +
        "\nEl Id es: " + to_string(idVideo) +
        "\nLa serie es: " + serie +
        "\nEl género es: " + genero +
        "\nLa duración es: " + to_string(duracion) +
        "\nLa calificación es: " + to_string(calificacion) +
        "\nEl número de episodios es: " + to_string(numeroEp) +
        "\nEl número de temporadas es: " + to_string(numTemporada);
}
