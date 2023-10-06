

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Usuario.h"

using namespace std;
void agregarVideo(std::vector<Video*>& videosDisponibles, Usuario& usuarioActual) {
    std::ofstream archivo("archivo.txt", std::ios::app); // Abrir el archivo en modo de escritura (append)

    char tipo;
    int idVideo, duracion, calificacion;
    std::string titulo, genero;

    std::cout << "Ingresa el tipo de video (P para película, E para episodio): ";
    std::cin >> tipo;
    std::cout << "Ingresa el ID del video: ";
    std::cin >> idVideo;
    std::cout << "Ingresa el título del video: ";
    std::cin.ignore(); // Ignorar el salto de línea después de ingresar el ID
    std::getline(std::cin, titulo);
    std::cout << "Ingresa el género del video: ";
    std::getline(std::cin, genero);
    std::cout << "Ingresa la duración del video en minutos: ";
    std::cin >> duracion;
    std::cout << "Ingresa la calificación del video (entero del 1 al 5): ";
    std::cin >> calificacion;

    // Buscar si ya existe un video con el mismo ID
    bool encontrado = false;
for (auto it = videosDisponibles.begin(); it != videosDisponibles.end(); ++it) {
    if ((*it)->getIdVideo() == idVideo) {
        encontrado = true;
        delete *it; // Eliminar el video anterior del vector
        videosDisponibles.erase(it); // Eliminar el video anterior del vector

        break; // Salir del bucle al encontrar el video con el mismo ID
    }
}

if (tipo == 'P') {
    archivo << "P," << idVideo << "," << titulo << "," << genero << "," << duracion << "," << calificacion << std::endl;
    Pelicula* pelicula = new Pelicula('P', idVideo, titulo, genero, duracion, calificacion);
    videosDisponibles.push_back(pelicula);
} else if (tipo == 'E') {
    int numeroEp, numTemporada;
    std::cout << "Ingresa el número de episodio: ";
    std::cin >> numeroEp;
    std::cout << "Ingresa el número de temporada: ";
    std::cin >> numTemporada;

    archivo << "E," << idVideo << "," << titulo << "," << genero << "," << duracion << "," << calificacion
            << "," << numeroEp << "," << numTemporada << std::endl;
    Episodio* episodio = new Episodio('E', idVideo, titulo, genero, duracion, calificacion, numeroEp, numTemporada);
    videosDisponibles.push_back(episodio);
}

archivo.close(); // Cerrar el archivo

if (encontrado) {
    std::cout << "El video con ID " << idVideo << " ha sido actualizado." << std::endl;
} else {
    usuarioActual.setmisVideos(usuarioActual.getmisVideos() + 1);
}
}

int main() {
    Usuario usuarioActual("cuenta", "nombre", "0", "0");
    vector<Video*> videosDisponibles;

    ifstream archivo("archivo.txt");
    string linea;

    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string tipo;
        getline(iss, tipo, ',');

        if (tipo == "P") {
            int idVideo, duracion, calificacion;
            string idVideoStr, titulo, genero, duracionStr, calificacionStr;
            getline(iss, idVideoStr, ',');
            getline(iss, titulo, ',');
            getline(iss, genero, ',');
            getline(iss, duracionStr, ',');
            getline(iss, calificacionStr);

            try {
                idVideo = stoi(idVideoStr);
                duracion = stoi(duracionStr);
                calificacion = stoi(calificacionStr);
            } catch (const std::invalid_argument& e) {
                cerr << "Error al convertir a entero en línea: " << linea << endl;
                continue;
            }

            Pelicula* pelicula = new Pelicula('P', idVideo, titulo, genero, duracion, calificacion);
            videosDisponibles.push_back(pelicula);
        } else if (tipo == "E") {
            int idVideo, duracion, calificacion, numeroEp, numTemporada;
            string idVideoStr, titulo, genero, duracionStr, calificacionStr, numeroEpStr, numTemporadaStr;
            getline(iss, idVideoStr, ',');
            getline(iss, titulo, ',');
            getline(iss, genero, ',');
            getline(iss, duracionStr, ',');
            getline(iss, calificacionStr, ',');
            getline(iss, numeroEpStr, ',');
            getline(iss, numTemporadaStr);

            try {
                idVideo = stoi(idVideoStr);
                duracion = stoi(duracionStr);
                calificacion = stoi(calificacionStr);
                numeroEp = stoi(numeroEpStr);
                numTemporada = stoi(numTemporadaStr);
            } catch (const std::invalid_argument& e) {
                cerr << "Error al convertir a entero en línea: " << linea << endl;
                continue;
            } catch (const std::out_of_range& e) {
                cerr << "Valor fuera de rango en línea: " << linea << endl;
                continue;
            }

            Episodio* episodio = new Episodio('E', idVideo, titulo, genero, duracion, calificacion, numeroEp, numTemporada);
            videosDisponibles.push_back(episodio);
        }
    }

    archivo.close();

    int opcion;
    while (true) {
        std::cout << "Menu de opciones\n\n\n";
        std::cout << "1. Consultar la lista de videos disponibles" << std::endl;
        std::cout << "2. Consultar la lista de Videos con cierta calificación" << std::endl;
        std::cout << "3. Consultar la lista de Videos por género" << std::endl;
        std::cout << "4. Ver datos del usuario" << std::endl;
        std::cout << "5. Modificar el perfil del usuario" << std::endl;
        std::cout << "6. Agregar un video" << std::endl; // Nueva opción para agregar un video
        std::cout << "7. Terminar" << std::endl;

        std::cout << "Ingresa una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea después de ingresar la opción

        switch (opcion) {
            case 1: {
                cout << "Lista de videos disponibles:" << endl;
                for (const auto& video : videosDisponibles) {
                    cout << video->muestra() << endl;
                }
                break;
            }
            case 2: {
                int calificacion;
                cout << "Ingresa la calificación deseada: ";
                cin >> calificacion;
                cin.ignore(); // Ignorar el salto de línea después de ingresar la calificación

                cout << "Lista de videos con calificación " << calificacion << ":" << endl;
                for (const auto& video : videosDisponibles) {
                    if (video->getCalificacion() == calificacion) {
                        cout << video->muestra() << endl;
                    }
                }
                break;
            }
            case 3: {
                string genero;
                cout << endl;
                cout << "Ingresa el género deseado (Drama, Acción, Ciencia Ficción,Fantasía,Terror,Comedia): ";

                getline(cin, genero);

                cout << "Lista de videos del género " << genero << ":" << endl;
                for (const auto& video : videosDisponibles) {
                    if (video->getGenero() == genero) {
                        cout << video->muestra() << endl;
                    }
                }
                break;
            }
            case 4: {
                cout << "Datos del usuario:" << endl;
                cout << usuarioActual.muestra() << endl;
                cout << "Lista de videos agregados por el usuario:" << endl;
for (const auto& video : videosDisponibles) {
    if (video->getIdVideo() == usuarioActual.getmisVideos()) {
        cout << video->muestra() << endl;
    }
}
                break;
            }
            case 5: {
                string nuevaCuenta, nuevoNombre;
                cout << "Ingresa la nueva cuenta: ";
                getline(cin, nuevaCuenta);
                cout << "Ingresa el nuevo nombre: ";
                getline(cin, nuevoNombre);

                usuarioActual.setCuenta(nuevaCuenta);
                usuarioActual.setNombre(nuevoNombre);
                cout << "Perfil del usuario actualizado." << endl;
                break;
            }
            case 6: {
                // Agregar un video
                agregarVideo(videosDisponibles, usuarioActual);
                break;
            }
            case 7:
                // Liberar la memoria de los videos
                for (const auto& video : videosDisponibles) {
                    delete video;
                }
                videosDisponibles.clear();

                return 0;

            default:
                cout << "Opción inválida. Inténtalo nuevamente." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}





