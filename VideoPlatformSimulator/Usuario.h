

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;
#include <stdexcept>


class Usuario {
private:
  string cuenta;
  string nombre;
  int misVideos;
  int contadorVideos;

public:
  Usuario(string _cuenta, string _nombre, string _misVideos, string _contadorVideos);
  void setCuenta(const string& _cuenta);
  void setNombre(const string& _nombre);
  void setmisVideos(int _misVideos);
  void setcontadorVideos(int _contadorVideos);
  int getmisVideos();
  int getcontadorVideos();
  string muestra();
};

#endif

