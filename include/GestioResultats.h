#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define MAX_MILLORS_JUGADORS 5
#define MAX_NOM 15

typedef struct
{
	char nom[MAX_NOM];
	int puntuacio;

} TipusJugador;


void inicialitzarTaulaMillorJugadors(TipusJugador TMillorsJugadors[]);
int esMillorPuntuacio(TipusJugador TMillorsJugadors[], int punts);
void desplacarArray(TipusJugador TMillorsJugadors[], int posicio);
void emplenarPosicioArray(TipusJugador &TMillorsJugadors, int punts);
void escriuRanking(TipusJugador TMillorsJugadors[]);
void guardarRanking(TipusJugador TMillorsJugadors[]);
