#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define NUMERO_PARTIDOS 5
#define NUMERO_VOTOS 4
#define MAXIMA_LONGITUD_CADENA 10000
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0

int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_PARTIDOS][NUMERO_VOTOS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz [NUMERO_PARTIDOS][NUMERO_VOTOS+1], char partidos [NUMERO_PARTIDOS][MAXIMA_LONGITUD_CADENA],string nombrePartido);

char nom1, nom2,nom3,nom4,nom5;

//cout << "Ingrese el nombre del primer partido: " << endl;
//cin >> nom1;
//cout << "Ingrese el nombre del segundo partido: " << endl;
//cin >> nom2;
//cout << "Ingrese el nombre del tercer partido: " << endl;
//cin >> nom3;
//cout << "Ingrese el nombre del cuarto partido: " << endl;
//cin >> nom4;
//cout << "Ingrese el nombre del quinto partido: " << endl;
//cin >> nom5;


void llamarciclo();

int main()
{
    srand(getpid());
    llamarciclo();
    return 0;
}

void llamarciclo ()
{
    float matriz_voto_1[NUMERO_PARTIDOS][NUMERO_VOTOS + 1];
    float matriz_voto_2[NUMERO_PARTIDOS][NUMERO_VOTOS + 1];
    float matriz_voto_3[NUMERO_PARTIDOS][NUMERO_VOTOS + 1];

    char partido [NUMERO_PARTIDOS][MAXIMA_LONGITUD_CADENA] = {"ParVerde","ParVos","ParMadera","ParLuz","ParFeliz"};

}
    int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz (float matriz[NUMERO_PARTIDOS][NUMERO_VOTOS + 1]);
{
    int y,x;
    for (y=0; y<NUMERO_PARTIDOS; y++)
    {
        float suma = 0;
        int voto = 0;
        for (x = 0; x < NUMERO_VOTOS; x++)
        {
            if (x == 0 || x == 3)  //primer parcial
            {
                voto = busquedaAleatorios(MIN_CALIFICACION, 50);
            } else if (x == 1)  //segundo parcial
            {
                voto = busquedaAleatorios(MIN_CALIFICACION, 50);
            } else if (x == 2)  //examen final
            {
                voto = busquedaAleatorios(MIN_CALIFICACION, 50);
            }
            suma += (float)voto;
            matriz[y][x] = voto;
            voto=0;
        }
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea();
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}

float imprimirMatriz(float matriz [NUMERO_PARTIDOS][NUMERO_VOTOS+1], char partidos [NUMERO_PARTIDOS][MAXIMA_LONGITUD_CADENA],string nombrePartido);
{
    int y,x

    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    char PartidoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char PartidoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(PartidoPromedioMayor, partidos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(PartidoPromedioMenor, partidos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombrePartido << endl;
    cout << "(Ronda1) (Ronda2) (Ronda3) (Ronda4)"  << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Partido";
    for (x = 0; x < NUMERO_VOTOS; x++)
    {
        cout << setw(9) << "Voto" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_PARTIDOS; y++)
    {
        cout << "!" << setw(8) << partidos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_VOTOS; x++)
        {
            int vot = matriz[y][x];
            cout << setw(9) << vot << "!";
        }
        float promedio = matriz[y][NUMERO_VOTOS];
        totalGeneral += matriz[y][NUMERO_VOTOS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(PartidoPromedioMayor, partidos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(PartidoPromedioMenor, partidos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    cout << "Voto mayor: " << setw(10) << PartidoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "Voto menor: " << setw(10) << PartidoPromedioMenor <<  setw(10) << promedioMenor << endl;
}
