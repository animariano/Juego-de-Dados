#pragma once

#include <string>


void cargarAleatorio(int v[], int tam);
void mostrarVector(int v[], int tam);
void ordenarVector(int v[], int tam );
bool esEscalera(int tirada[], int tamano);
void cargarManual(int v[], int tam);
int comprobarTirada(int v[], int tam, int &numeroRepetido);
void mostrarResultadoTirada(int resultado, int numeroRepetido);
bool sonTodosIguales(int v[], int tam, int &numeroRepetido);
bool sextetoDeSeis(int v[], int tam, int &numeroRepetido);
int sumarVector(int v[], int tam );
bool procesarResultadoTirada(int resultado, int &maxPuntajeRonda, bool &partidaTerminada, bool &sextetoSi, int &numeroRepetido);
int calcularMaximo(int valorActual, int nuevoValor);


void mostrarEntreTurnos(int ronda, std::string nombreJugador, int puntaje);
//void cargarPuntajes(std::string jugador, int puntos, std::string nombres[], int tablaPuntajes[]);
//void mostrarPuntajes(std::string jugadores[], int tabla[]);

//void actualizarMaximo(std::string jugador, int puntos, std::string &mejorJugador, int &maxPuntaje);
//void mostrarPuntuacionMaxima(std::string mejorJugador, int maxPuntaje);


void actualizarMaximo(std::string jugador, int puntos, int rondas, std::string& mejorJugador, int& maxPuntaje, int& rondasMax, bool &hayGanador);
void mostrarPuntuacionMaxima(std::string mejorJugador, int maxPuntaje, int rondasMax, bool hayGanador);

