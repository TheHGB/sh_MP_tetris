#include "GestioResultats.h"


void inicialitzarTaulaMillorJugadors(TipusJugador TMillorsJugadors[])
{
	//INICIALITZA L'ARRAY A UN VALOR CONEGUT
	int i;
	for (i = 0; i < MAX_MILLORS_JUGADORS; i++)
	{
		strcpy(TMillorsJugadors[i].nom, "--------------");
		TMillorsJugadors[i].puntuacio = 0;
	}

	//CARREGA EL RANKING D'UN FITXER

	ifstream fitxer;
	const char nomFitxer[] = "TOP.txt";
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int punts,i=0;
		char nom[MAX_NOM];
		fitxer >> nom >> punts;
		while (!fitxer.eof() && i < MAX_MILLORS_JUGADORS)
		{
			strcpy(TMillorsJugadors[i].nom, nom);
			TMillorsJugadors[i].puntuacio = punts;
			fitxer >> nom >> punts;
			i++;
		}
		fitxer.close();
	}

}

int esMillorPuntuacio(TipusJugador TMillorsJugadors[], int punts)
{
	int i = 0;
	int trobat = 0;

	do
	{
		if (TMillorsJugadors[i].puntuacio < punts)
		{
			trobat = 1;
		}
		i++;

	} while ((i < MAX_MILLORS_JUGADORS) && (!trobat));
	if (trobat)
	{
		return (i - 1);
	}
	else
	{
		return -1;
	}
}

void desplacarArray(TipusJugador TMillorsJugadors[], int posicio)
{
	int i;

	for (i = MAX_MILLORS_JUGADORS - 1; i > posicio; i--)
	{
		strcpy(TMillorsJugadors[i].nom, TMillorsJugadors[i - 1].nom);
		TMillorsJugadors[i].puntuacio = TMillorsJugadors[i - 1].puntuacio;
	}
}

void emplenarPosicioArray(TipusJugador &TMillorsJugadors, int punts)
{
	printf("Entra el teu nom\n");
	scanf("%s", &(TMillorsJugadors.nom));
	(TMillorsJugadors).puntuacio = punts;

}

void escriuRanking(TipusJugador TMillorsJugadors[])
{
	int i;
	for (i = 0; i < MAX_MILLORS_JUGADORS; i++)
	{
		printf("%d.- %s %d\n", i + 1, TMillorsJugadors[i].nom, TMillorsJugadors[i].puntuacio);
	}
}

void guardarRanking(TipusJugador TMillorsJugadors[])
{

	const char nomFitxer[] = "TOP.txt";
	ofstream fitxer2;
	fitxer2.open(nomFitxer);
	if (fitxer2.is_open())
	{
		int punts, i;
		char nom[MAX_NOM];

		for (int i = 0; i < MAX_MILLORS_JUGADORS; i++)
		{
			fitxer2 << TMillorsJugadors[i].nom << " " << TMillorsJugadors[i].puntuacio << "\n";
		}
		fitxer2.close();
	}
}
