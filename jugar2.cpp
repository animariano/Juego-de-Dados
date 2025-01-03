#include <iostream>
#include "jugar2.h"
#include "funciones.h"

using namespace std;

void jugar2(string &nombre, int &puntajeTotal, int &ronda, bool modoSimulado)
{
    string nombre1, nombre2, apellido1, apellido2;
    int numeroRepetido, resultado, dados[6];
    int puntajeTotal_1 = 0, puntajeTotal_2 = 0;
    bool partidaTerminada = false, partidaTerminada1 = false, partidaTerminada2 = false;
    bool turno = true, cartel_turno =true;
    bool ganadorEscalera1 = false, ganadorEscalera2 = false;
    int ronda1 = 0, ronda2 = 0, lanzamiento1, lanzamiento2;
    int maxPuntajeRonda1 = 0, maxPuntajeRonda2 = 0;
    bool sextetoSi;
    modoSimulado;

    // variables para fijar rondas - opcional 2
    int rondasManual = 0;
    int fijarRondas=0;


    // variables desempate - opcional 1
    bool empateDetectado= false;
    bool supero100_1 = false, supero100_2 = false;
    int lanzamientosTotales1=0, lanzamientosTotales2=0;
    int puntajeTotalDesempate1 = 0, puntajeTotalDesempate2 = 0;
    int puntajeDesempate1, puntajeDesempate2;


    cout << "BIENVENIDOS/AS AL JUEGO!!!" << endl;
    cout << "NOMBRE DE JUGADOR 1: ";
    cin >> nombre1;
    cout << "APELLIDO DE JUGADOR 1: ";
    cin >> apellido1;
    system("cls");
    cout << "BIENVENIDOS/AS AL JUEGO!!!" << endl;
    cout << "NOMBRE DE JUGADOR 2: ";
    cin >> nombre2;
    cout << "APELLIDO DE JUGADOR 2: ";
    cin >> apellido2;
    system("cls");

    cout << "Quiere fijar una cantidad de rondas a jugar? 1: SI, 2: NO"<< endl;
    cin >>fijarRondas;

    if(fijarRondas==1)
    {
        cout << "Elija la cantidad de rondas a jugar"<< endl;
        cin >> rondasManual;
        system("cls");
    }

    while (puntajeTotal_1 < 100 && puntajeTotal_2 < 100 && !partidaTerminada1 && !partidaTerminada2 && !partidaTerminada )
    {
        if(fijarRondas==1)
        {

            if (ronda1 == rondasManual && ronda2 == rondasManual)
            {
                partidaTerminada = true;
                cout << endl;
                if (puntajeTotal_1 > puntajeTotal_2)
                {

                    cout <<"El ganador es " << nombre1 << " " << apellido1 << ", ha obtenido " <<puntajeTotal_1<< " en " << ronda1 <<" rondas." <<endl;

                }
                else
                {
                    cout <<"El ganador es " << nombre2<< " " << apellido2 << ", has obtenido " <<puntajeTotal_2<< " en " << ronda2 <<" rondas." <<endl;

                }

                system("pause");
                break;
            }
        }
        if(turno)
        {
            sextetoSi = false;
            lanzamiento1 = 1;
            ronda1++;
            cout <<endl<<endl;
            cout <<"TURNO DE " << nombre1 << "| " << "RONDA Nø "<< ronda1 << "| " << "PUNTAJE TOTAL: " <<puntajeTotal_1<< " PUNTOS" <<endl;
            cout <<"----------------------------------------------------"<< endl;

            int maxPuntajeRonda1 = 0;
            cout<< "Presiona una tecla para lanzar los dados..."<< endl;
            cout<<endl;

            for (int i=0; i<3; i++)
            {
                if (!supero100_1)
                {
                    lanzamientosTotales1++;
                }
                puntajeDesempate1 = puntajeTotal_1;
                std::cin.get();
                if (modoSimulado)
                {
                    cargarManual(dados, 6);
                }
                else
                {
                    cargarAleatorio(dados, 6);
                }
                resultado = comprobarTirada(dados,6, numeroRepetido);
                maxPuntajeRonda1 = calcularMaximo(maxPuntajeRonda1, resultado);

                puntajeDesempate1 += resultado;

                if (puntajeDesempate1 >= 100 && !supero100_1)
                {
                    supero100_1 = true;
                    puntajeTotalDesempate1 = puntajeDesempate1;
                }
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda1 << " puntos." << endl;
                cout << "LANZAMIENTO #" << lanzamiento1 << endl;
                cout <<"----------------------------------------------------"<< endl;
                mostrarVector(dados,6);
                cout << endl;

                if (!procesarResultadoTirada(resultado, puntajeTotal_1, partidaTerminada1, sextetoSi, numeroRepetido))
                {
                    system("pause");
                    break;
                }
                lanzamiento1++;
                system("pause");
                system("cls");
                cout <<endl<<endl;
                cout <<"TURNO DE " << nombre1 << "| " << "RONDA Nø "<< ronda1 << "| " << "PUNTAJE TOTAL: " <<puntajeTotal_1<< " PUNTOS" <<endl;
                cout <<"----------------------------------------------------"<< endl;

            }
            if (sextetoSi)
            {
                cout << endl;
                system("pause");
                mostrarEntreTurnosDosJugadores(ronda1, nombre1, nombre2, puntajeTotal_1, puntajeTotal_2, cartel_turno);
            }
            else if(!partidaTerminada1)
            {
                puntajeTotal_1 += maxPuntajeRonda1;
                cout << endl;
                system("pause");
                mostrarEntreTurnosDosJugadores(ronda1, nombre1, nombre2, puntajeTotal_1, puntajeTotal_2, cartel_turno);
            }


            system("pause");
            system("cls");

            if (partidaTerminada1){
                mostrarEntreTurnosDosJugadores(ronda1, nombre1, nombre2, puntajeTotal_1, puntajeTotal_2, cartel_turno);
                system("pause");
                system("cls");
            }

            turno= false;
            cartel_turno=false;


        }
        if(!turno)
        {

            sextetoSi = false;
            lanzamiento2 = 1;
            ronda2++;
            cout <<endl<<endl;
            cout <<"TURNO DE " << nombre2 << "| " << "RONDA Nø "<< ronda2 << "| " << "PUNTAJE TOTAL: " <<puntajeTotal_2<< " PUNTOS" <<endl;
            cout <<"----------------------------------------------------"<< endl;

            int maxPuntajeRonda2 = 0;
            cout<< "Presiona una tecla para lanzar los dados..."<< endl;
            cout<<endl;

            for (int i=0; i<3; i++)
            {
                if (!supero100_2)
                {
                    lanzamientosTotales2++;
                }
                puntajeDesempate2 = puntajeTotal_2;
                std::cin.get();
                if (modoSimulado)
                {
                    cargarManual(dados, 6);
                }
                else
                {
                    cargarAleatorio(dados, 6);
                }
                resultado = comprobarTirada(dados,6, numeroRepetido);
                maxPuntajeRonda2 = calcularMaximo(maxPuntajeRonda2, resultado);

                puntajeDesempate2 += resultado;
                if (puntajeDesempate2 >= 100 && !supero100_2)
                {
                    supero100_2 = true;
                    puntajeTotalDesempate2 = puntajeDesempate2;
                }
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda2 << " puntos." << endl;
                cout << "LANZAMIENTO #" << lanzamiento2 << endl;
                cout <<"----------------------------------------------------"<< endl;
                mostrarVector(dados,6);
                cout << endl;
                if (!procesarResultadoTirada(resultado, puntajeTotal_2, partidaTerminada2, sextetoSi, numeroRepetido))
                {
                    system("pause");
                    break;
                }
                lanzamiento2++;
                system("pause");
                system("cls");
                cout <<endl<<endl;
                cout <<"TURNO DE " << nombre2 << "| " << "RONDA Nø "<< ronda2 << "| " << "PUNTAJE TOTAL: " <<puntajeTotal_2<< " PUNTOS" <<endl;
                cout <<"----------------------------------------------------"<< endl;
            }


            if (sextetoSi)
            {
                cout << endl;
                system("pause");

            }
            else if(!partidaTerminada2)
            {
                puntajeTotal_2 += maxPuntajeRonda2;
                cout << endl;
                system("pause");
            }
            if (puntajeTotal_1<100 && puntajeTotal_2<100)
            {
                mostrarEntreTurnosDosJugadores(ronda1, nombre1, nombre2, puntajeTotal_1, puntajeTotal_2, cartel_turno);
            }

            system("pause");
            system("cls");

            turno=true;
            cartel_turno=true;
        }




        if (supero100_1 && supero100_2 && ronda1 == ronda2)
        {
            cout << "Empate detectado" << endl;
            empateDetectado = true;

            if (lanzamientosTotales1 < lanzamientosTotales2)
            {
                cout << "Gana " << nombre1 << " por alcanzar los 100 puntos en menos lanzamientos" << endl;

            }
            else if (lanzamientosTotales2 < lanzamientosTotales1)
            {
                cout << "Gana " << nombre2 << " por alcanzar los 100 puntos en menos lanzamientos" << endl;
            }
            else
            {
                if (puntajeTotalDesempate1 > puntajeTotalDesempate2)
                {
                    cout << "Gana " << nombre1 << " con un puntaje mayor en la tirada decisiva" << endl;
                }
                else if (puntajeTotalDesempate2 > puntajeTotalDesempate1)
                {
                    cout << "Gana " << nombre2 << " con un puntaje mayor en la tirada decisiva" << endl;
                }
                else
                {
                    cout << "Empate. Ambos jugadores tienen el mismo puntaje em la misma cantidad de lanzamientos." << endl;
                }
            }

        }

        if(((puntajeTotal_1>= 100 || puntajeTotal_2 >= 100) && puntajeTotal_1>puntajeTotal_2) || ganadorEscalera1)
        {
            nombre = nombre1;
            puntajeTotal = puntajeTotal_1;
            ronda = ronda1;
        }
        else if (((puntajeTotal_1 >= 100 || puntajeTotal_2 >= 100 || puntajeTotal_1<puntajeTotal_2)) || ganadorEscalera2)
        {
            nombre = nombre2;
            puntajeTotal = puntajeTotal_2;
            ronda = ronda2;
        }

    }

    if (!empateDetectado)
        {
            if (puntajeTotal_1 >= 100)
            {
                system("pause");
                system("cls");
                cout << endl;
                cout << "Felicitaciones!!! " << nombre1 << " " << apellido1 << ", has obtenido " <<puntajeTotal_1<< " en " << ronda1 <<" rondas!" <<endl;
            }

            if (puntajeTotal_2 >= 100)
            {
                system("pause");
                system("cls");
                cout << endl;
                cout << "Felicitaciones!!! " << nombre2<< " " << apellido2 << ", has obtenido " <<puntajeTotal_2<< " en " << ronda2 <<" rondas!" <<endl;
            }
        }
        if (partidaTerminada1){
            system("pause");
            system("cls");
            cout << "Felicitaciones!!! " << nombre1<< " " << apellido1 <<" Has conseguido una Escalera. Ganaste la partida en " << ronda1  << " rondas!" << endl;
        }
        if (partidaTerminada2 ){
            system("pause");
            system("cls");
            cout << "Felicitaciones!!! " << nombre2<< " " << apellido2 <<" Has conseguido una Escalera. Ganaste la partida en " << ronda2  << " rondas!" << endl;
        }


}


void mostrarEntreTurnosDosJugadores(int ronda, string nombreJugador, string nombreJugador2, int puntaje, int puntaje2, bool turno)
{
    system("cls");
    cout << "--------------------------\n";
    cout << "\t" << "RONDA N# " << ronda << endl;
    if(turno==true)
    {
        cout << "PROXIMO TURNO: " << nombreJugador2 << endl;
    }
    else
    {
        cout << "PROXIMO TURNO: " << nombreJugador << endl;
    }

    cout << "PUNTAJE "<< nombreJugador <<": "<< puntaje << " PUNTOS" << endl;
    cout << "PUNTAJE "<< nombreJugador2 <<": "<< puntaje2 << " PUNTOS" << endl;
    cout << "--------------------------\n";
    system("pause>null");
}



