

#include "Usuario.h"
using namespace std;

Usuario::Usuario(string _cuenta, string _nombre, string _misVideos, string _contadorVideos) {
    cuenta = _cuenta;
    nombre = _nombre;
    misVideos = std::stoi(_misVideos);
    contadorVideos = std::stoi(_contadorVideos);
}

void Usuario::setCuenta(const string& _cuenta) {
  cuenta = _cuenta;
}

void Usuario::setNombre(const string& _nombre) {
  nombre = _nombre;
}


void Usuario::setmisVideos(int _misVideos) {
  misVideos = _misVideos;
}

void Usuario::setcontadorVideos(int _contadorVideos) {
  contadorVideos = _contadorVideos;
}

int Usuario::getmisVideos() {
  return misVideos;
}

int Usuario::getcontadorVideos() {
  return contadorVideos;
}

string Usuario::muestra() {
  return "\nLa cuenta es: " + cuenta +
    "\n\nEl nombre: " + nombre +
    "\n\nTus videos son: " + to_string(misVideos) +
    "\n\nEl contador de videos es: " + to_string(contadorVideos);
}
