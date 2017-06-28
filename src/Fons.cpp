#include "Fons.h"
#include "FigTetris.h"
#include<iostream>
#include<conio.h>
using namespace std;

Fons::Fons()
{

    // Constructor. No s'ha de modificar.
    // Crea els gràfics que s'utilitzaran per dibuixar els quadrats de colors al tauler a mesura que les figures vagin arribant a baix de tot
    m_quadrats[COLOR_GROC].Create("data/Graficstetris/q1groc.png");
    m_quadrats[COLOR_TARONJA].Create("data/Graficstetris/q1taronja.png");
    m_quadrats[COLOR_ROIG].Create("data/Graficstetris/q1roig.png");
    m_quadrats[COLOR_MAGENTA].Create("data/Graficstetris/q1magenta.png");
    m_quadrats[COLOR_VERD].Create("data/Graficstetris/q1verd.png");
    m_quadrats[COLOR_BLAUCEL].Create("data/Graficstetris/q1blaucel.png");
    m_quadrats[COLOR_BLAUFOSC].Create("data/Graficstetris/q1blaufosc.png");
    m_quadrats[COLOR_NEGRE].Create("data/Graficstetris/q1blaufosc.png");
    m_quadrats[COLOR_GRIS].Create("data/Graficstetris/q1blaufosc.png");
}

Fons::~Fons()
{
    // Destructor. No s'ha de modificar
}

void Fons::inicialitzar(const char *rutaFons)
   { // TODO
    // Heu de crear l'Sprite amb el dibuix del fons del tauler
    // També heu d'inicialitzar totes les posicions de la matriu m_tauler  a color negre, excepte la primera i ultima columna
    // i la última fila que s'han d'inicialitzar a gris. D'aquesta manera marquem que tot el tauler està buit. Per fer-ho podeu utilitzar
    // els mètodes posarNegre() i posarGris()
    m_fons.Create(rutaFons);
    posarNegre();
    posarGris();

    // TODO
    // Heu de crear l'Sprite amb el dibuix del fons del tauler
    // També heu d'inicialitzar totes les posicions de la matriu m_tauler  a color negre, excepte la primera i ultima columna
    // i la última fila que s'han d'inicialitzar a gris. D'aquesta manera marquem que tot el tauler està buit. Per fer-ho podeu utilitzar
    // els mètodes posarNegre() i posarGris()

}
void Fons::posarNegre()
{

    int i, j;
    for (i = 0; i < MAX_FILA-1; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = COLOR_NEGRE;
        }

    }
    // TODO
    // Heu d'inicialitzar totes les posicions interiors (que no són límits) de la matriu m_tauler a negre

}

void Fons::posarGris()
{
    int i, j;
    for (i = 0; i < MAX_FILA; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            if(j == 0)
                m_tauler[i][j] = COLOR_GRIS;

            if(j == (MAX_COL-1))
                m_tauler[i][j] = COLOR_GRIS;

            if(i == MAX_FILA-1)
                m_tauler[i][j] = COLOR_GRIS;
        }
    }
    // TODO
    // Heu d'inicialitzar primera i ultima columnes de la matriu m_tauler a gris
    // Heu d'inicialitzar la última fila de la matriu m_tauler a gris

}

void Fons::pintaFons()
{
    m_fons.Draw(0, 0);
    int i, j;
    for (i = 0; i < MAX_FILA-1; i++)
    {
        for (j = 1; j < MAX_COL-1; j++)
        {
            if(m_tauler[i][j] != COLOR_NEGRE){
                m_quadrats[m_tauler[i][j]].Draw((j*MIDA_Q), INICI_Y+(i*MIDA_Q));
            }
        }
    }
    // TODO:
    // Heu de pintar tots els quadres del fons del tauler que que no són negres
    //i que per tant corresponen a figures que ja s'han col·locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'úlitima línia del tauler
    // Recoreu que els quares grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.
}

void Fons::setTauler(int fila, int columna, int color)
{

    m_tauler[fila][columna] = color;
    // TODO
    // Heu de modificar el valor de color de la posició fila,
    // columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a paràmetre.
}


bool Fons::guanyar()
{
    bool plena = false;
	int i = 1;
	while(i < MAX_COL-1 && plena){
        if(m_tauler[MAX_FILA-2][i] == COLOR_NEGRE)
            plena = false;

        i++;
	}

	return plena;
    //em de fer un if qe retorni true i ale, ja tindrem tant si esta be com si no, si no ho  esta ale, ja tornara fals
	// TODO
	// Heu de retornar cert si la última línia del tauler que no està gris està tota pintada de colors
	// i fals si hi ha algun quadre a negre.
}

int Fons::returnTauler(int X, int Y)
{


    return m_tauler[Y][X];
}

bool Fons::shaSolapao(int X, int Y, int*** mask, int dirX,int dirY,int amplada,int alcada, int gir)
{


    bool solapat = false;

    for (int i = 0; i < amplada; i++)
    {
        for(int j = 0; j < alcada; j++)
        {

             if((m_tauler[Y+j+1][X+i+dirX]!=COLOR_NEGRE)&&(mask[j][i][gir]!=COLOR_NEGRE))
                {
                    solapat = true;
                }
           }

    }




    return solapat;

}

bool Fons::uLoose()
{
    bool loosah = false;
    for(int i = 1; i < MAX_COL-1; i++)
    {
        if(m_tauler[INICI_Y][i]!=COLOR_NEGRE)
            loosah = true;
    }
return loosah;
}

int Fons::uWin(int alcada, int X, int Y)

{
    int liniesDesplacades = 0;
    int yPrimeraLinia = 0;
    int linies = 0;
    int suma[alcada];
    bool linia[alcada];
    for (int i = 0; i < alcada; i++)
    {
        suma[i] = 0;
        linia[i] = 0;
    }

    for(int j = 0; j < alcada; j++)
    {
        for(int z = 1; z < 12; z++)
        {
            if(m_tauler[Y+alcada-1-j][z] == COLOR_NEGRE)
            {
                suma[j]++;
            }
        }
        if(suma[j]==0)
        {
            linies++;
            linia[j] = 1;
            if (!yPrimeraLinia)
            {
                yPrimeraLinia = Y+alcada-1-j;
            }
        }
        if(linia[j])
        {
            liniesDesplacades++;
            for(int l = 1; l < 12; l++)
                {
                    m_tauler[Y+(alcada-1-j)][l]=COLOR_NEGRE;
                }
        }
    }
    for(int w = liniesDesplacades; w > 0; w--)
    {
        for(int y = yPrimeraLinia; y > 0; y--)
        {
            for(int x = 1; x < 12; x++)
            {
                if(m_tauler[y][x]!=COLOR_NEGRE)
                {
                    m_tauler[y+1][x]=m_tauler[y][x];
                    m_tauler[y][x]=COLOR_NEGRE;
                }
            }
    }
    }

    return linies;
}





