#include <iostream>

#include "funciones.h"

using namespace std;



// GENERARA EL LANZAMIENTO ALEATORIAMENTE
void cargarAleatorio(int v[], int tam)
{
    int i;
    for( i=0; i<tam; i++ )
    {
        v[i]=(rand()%tam)+1;
    }
}
// CARGA EL LANZAMIENTO MANUALMENTE
void cargarManual(int v[], int tam)
{
    int i;
    int numero;
    for(i=0; i<tam; i++)
    {
        bool ciclo = true;
        while(ciclo)
        {
            cout<<"Ingrese un numero: ";
            cin>>numero;
            if(numero>=1 && numero<=6)
            {
                v[i] = numero;
                ciclo = false;
            }
            else
            {
                cout<<"Numero incorrecto, vuelva a ingresarlo."<<endl;
            }
        }
    }
}
// MUESTRA LA TIRADA CON UNOS TAB
void mostrarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
    cout << endl;
}
// METODO PARA ORDENAR EL VECTOR
// SE USA PARA ENCONTRAR LA ESCALERA

void ordenarVector(int v[], int tam )
{
    int i,j, posmin, aux;
    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
        {
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

// VERIFICAR SI ES UNA ESCALERA
bool esEscalera(int v[], int tam)
{

    int escalera[] = {1, 2, 3, 4, 5, 6};


    ordenarVector(v, tam);


    for (int i = 0; i < tam; i++)
    {
        if (v[i] != escalera[i])
        {
            return false;
        }
    }
    return true;
}


// FUNCION PARA SABER SI SON TODOS LOS VALORES IGUALES
// TAMBIEN DEVUELVE EL NUMERO REPETIDO

bool sonTodosIguales(int v[], int tam, int &numeroRepetido)
{
    for (int i = 1; i < tam; i++)
    {
        if (v[i] != v[0])
        {
            return false;
        }
    }
    numeroRepetido = v[0];
    return true;
}
// VERIFICA SI SON TODOS IGUALES Y SI EL NUMERO REPETIDO ES 6
bool sextetoDeSeis(int v[], int tam, int &numeroRepetido)
{
    if (sonTodosIguales(v, tam, numeroRepetido) && numeroRepetido == 6)
    {
        return true;
    }
    return false;
}
// SUMA EL PUNTAJE DE LA TIRADA
int sumarVector(int v[], int tam )
{
    int i, suma=0;
    for(i=0; i<tam; i++)
    {
        suma+=v[i];
    }
    return suma;
}
// FUNCION GENERAL DE COMPROBACION
// RETORNA NUMEROS QUE USO EN LA F DE ABAJO

int comprobarTirada(int v[], int tam, int &numeroRepetido)
{

    if (esEscalera(v, tam))
    {
        return 1;
    }

    if (sextetoDeSeis(v, tam, numeroRepetido))
    {
        return 0;
    }

    if (sonTodosIguales(v, tam, numeroRepetido))
    {
        return numeroRepetido * 10;
    }
    return sumarVector(v, tam);

}
// PROCESA EL RESULTADO ANTERIOR
// TERMINA SI HAY ESCALERA
// DA 0 DE PUNTAJE SI HAY SEXTETO
// CASO CONTRARIO COMPARA Y GUARDA MAXIMO

bool procesarResultadoTirada(int resultado, int &maxPuntajeRonda, bool &partidaTerminada,bool &sextetoSi, int &numeroRepetido)
{
    if (resultado == 1)    // Escalera
    {
        cout << "­ESCALERA! ­Ganaste la partida!" << endl;
        partidaTerminada = true;
        return false;  // Terminamos la ronda
    }
    else if (resultado == 0)    // Sexteto de 6
    {
        cout << "­SEXTETO 6! Perdes todos los puntos." << endl;
        sextetoSi = true;
        maxPuntajeRonda = 0;
        return false;  // Terminamos la ronda
    }
    else if (resultado == numeroRepetido * 10)
    {
        cout << "SEXTETO " << numeroRepetido << endl;
        cout << "Puntaje total despues de multiplicar: " << numeroRepetido * 10 << endl;
        return true;  // Continuamos la ronda
    }
    else
    {
        cout << "SUMA DE DADOS" << endl;
        return true;  // Continuamos la ronda
    }
}
// CALCULO DE MAXIMO

int calcularMaximo(int valorActual, int nuevoValor)
{
    if (nuevoValor > valorActual)
    {
        return nuevoValor;
    }
    else
    {
        return valorActual;
    }
}
void mostrarEntreTurnos(int ronda, string nombreJugador, int puntaje) {
    system("cls");
    cout << "--------------------------\n";
    cout << "\t" << "RONDA N# " << ronda << endl;
    cout << "NOMBRE DEL JUGADOR: " << nombreJugador << endl;
    cout << "PUNTAJE ACTUAL: " << puntaje << " PUNTOS" << endl;
    cout << "--------------------------\n";
    system("pause>null");
}



void actualizarMaximo(string jugador, int puntos, int rondas, string &mejorJugador, int &maxPuntaje, int &rondasMax, bool &hayGanador) {
    if (!hayGanador || puntos > maxPuntaje || (puntos == maxPuntaje && rondas < rondasMax)) {
        maxPuntaje = puntos;
        mejorJugador = jugador;
        rondasMax = rondas;
        hayGanador = true;
    }
}

void mostrarPuntuacionMaxima(string mejorJugador, int maxPuntaje, int rondasMax, bool hayGanador) {
    if (!hayGanador) {
        cout << "No hay puntajes registrados." << endl;
    } else {
        cout << "MEJOR JUGADOR: " << mejorJugador
             << " con " << maxPuntaje << " puntos en "
             << rondasMax << " rondas." << endl;
    }
}


