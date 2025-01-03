#include <iostream>

#include "funciones.h"


using namespace std;


void jugar(string &nombre, int &puntajeTotal, int &ronda, bool modoSimulado){

    int numeroRepetido, resultado, dados[6];
    puntajeTotal=0;
    ronda = 0;
    int lanzamiento;
    bool partidaTerminada = false;
    bool sextetoSi;
    modoSimulado;
    string apellido;

    cout<<"BIENVENIDOS/AS AL JUEGO!!!"<<endl;
    cout << "INGRESA TU NOMBRE: ";
    cin >> nombre;
    cout << "INGRESA TU APELLIDO: ";
    cin >> apellido;
    system("cls");


    do{

        sextetoSi = false;
        lanzamiento = 1;
        ronda++;
        cout <<endl<<endl;
        cout <<"TURNO DE " << nombre << "| " << "RONDA Nø "<< ronda << "| " << "PUNTAJE TOTAL: " <<puntajeTotal<< " PUNTOS" <<endl;
        cout <<"----------------------------------------------------"<< endl;

        int maxPuntajeRonda = 0;
        cout<< "Presiona una tecla para lanzar los dados..."<< endl;
        cout<<endl;


        for (int i=0; i<4; i++){

            //system("pause");

            if (modoSimulado){
                cargarManual(dados, 6);
            } else{
                cargarAleatorio(dados, 6);
            }
            resultado = comprobarTirada(dados,6, numeroRepetido);
            maxPuntajeRonda = calcularMaximo(maxPuntajeRonda, resultado);
            cout << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " puntos." << endl;
            cout << "LANZAMIENTO #" << lanzamiento << endl;
            cout <<"----------------------------------------------------"<< endl;
            mostrarVector(dados,6);
            cout << endl;
            lanzamiento++;
            if (!procesarResultadoTirada(resultado, puntajeTotal, partidaTerminada, sextetoSi, numeroRepetido)) {
                system("pause");
                break;
            }
            system("pause");
            system("cls");
            cout <<endl<<endl;
            cout <<"TURNO DE " << nombre << "| " << "RONDA Nø "<< ronda << "| " << "PUNTAJE TOTAL: " <<puntajeTotal<< " PUNTOS" <<endl;
            cout <<"----------------------------------------------------"<< endl;

        }
        if (sextetoSi) {

            cout << endl;

            //system("pause");
            //mostrarEntreTurnos (ronda, nombre, puntajeTotal);

        } else if(!partidaTerminada) {

            puntajeTotal += maxPuntajeRonda;

            cout << endl;

            //system("pause");
            //mostrarEntreTurnos (ronda, nombre, puntajeTotal);
        }

        if (!partidaTerminada && puntajeTotal<100){
            system("pause");
            mostrarEntreTurnos (ronda, nombre, puntajeTotal);
        }

        system("pause<null");
        system("cls");


        if (partidaTerminada){
            system("pause");
            system("cls");
            cout << "Felicitaciones!!! " << nombre << " " << apellido << " has conseguido una Escalera. Ganaste la partida en " << ronda  << " rondas!" << endl;
        }
        if (puntajeTotal >= 100) {
            system("pause");
            system("cls");
            cout << endl;
            cout << "Felicitaciones!!!" << nombre<< " " << apellido <<", has obtenido " <<puntajeTotal<< " en " << ronda <<" rondas!" <<endl;
        }

    } while (puntajeTotal < 100 && !partidaTerminada);

}


