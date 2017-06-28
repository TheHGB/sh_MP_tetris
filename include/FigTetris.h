#ifndef FIGTETRIS_H
#define FIGTETRIS_H

#include "Fons.h"

//========================================================================
// Codis peces
const int  O = 0;
const int  L = 1;
const int  Z = 2;
const int  T = 3;
const int  S = 4;
const int  I = 5;
const int  P = 6;

const int INI_FIG = O;
const int FI_FIG = P;

const int MAX_FIG = 7;

const int MAX_MASK = 4;

class FigTetris
{
    public:
        FigTetris();
        virtual ~FigTetris();
        void draw();
        void create(int);
        int alcada();
        int amplada();
        bool moureFig(int, int, Fons&);
        void setPosX(int);
        void setPosY(int);
        void figuraEncaixada(Fons&);
        int getlinea();
        void setlinea(int);
        void nextGir(Fons&);
        int getGir();


    protected:
    private:
        Sprite m_figura[4];
        int m_amplada;
        int m_alcada;
        int m_posX;
        int m_posY;
        int m_indexFig;
        int m_color;
        int*** m_figures;
        int m_linea;
        int m_gir;
};

#endif // FIGTETRIS_H
