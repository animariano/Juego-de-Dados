#include <iostream>
#include <ctime>
#include "funciones.h"
#include "jugar.h"
#include "jugar2.h"

using namespace std;

int main()
{
    int opcion;
    srand(time(0));
    string jugador;
    int puntos;
    int rondas;
    int rondasMax=0;
    int maxPuntaje = 0;
    string mejorJugador;
    bool hayGanador = false;
    bool modoSimulado = false;

    do{
        system ("cls");
        cout << "CIEN o ESCALERA" << endl;
        cout << "------------------------------" << endl;
        cout << "1- Jugar 1 jugador" << endl;
        cout << "2- Jugar 2 jugadores" << endl;
        cout << "3- Mostrar puntuacion mas alta" << endl;
        cout << "------------------------------" << endl;
        cout << "0- Salir" << endl;
        cout<<endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        system("cls");
        switch(opcion)
        {
        case 1:
            jugar(jugador, puntos, rondas, modoSimulado);
            actualizarMaximo(jugador, puntos, rondas, mejorJugador, maxPuntaje, rondasMax, hayGanador);
            break;
        case 2:
            jugar2(jugador, puntos, rondas, modoSimulado);
            actualizarMaximo(jugador, puntos, rondas, mejorJugador, maxPuntaje, rondasMax, hayGanador);
            break;
        case 3:
            mostrarPuntuacionMaxima(mejorJugador, maxPuntaje, rondasMax, hayGanador);
            break;
        case 0:
            cout << "Fin del programa. Gracias por jugar" << endl;
            break;
        default:
            cout << "El numero ingresado no realiza ninguna operacion. Por favor, vuelva a ingresar un numero."<< endl;
        }
        system("pause");

    }while(opcion != 0);
    return 0;
}


