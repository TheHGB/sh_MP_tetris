#include "FigTetris.h"
#include<iostream>
using namespace std;


FigTetris::FigTetris()
{
    setlinea(0);
    // Constructor. No s'ha de modificar
}

FigTetris::~FigTetris()
{
    for (int i = 0; i < MAX_MASK; i++)
    {
        for (int j = 0; j < MAX_MASK; j++)
        {
            delete[] m_figures[i][j];
        }
        delete[] m_figures[i];
    }
    delete[] m_figures;

    m_figures = NULL;


}

void FigTetris::setPosX(int posX)//DONE
{
    // TODO
    // Heu de modificar el valor de l'atribut m_posX (posició x de la figura) amb el valor posX que es passa com a paràmetre

    m_posX=posX;

}

void FigTetris::setPosY(int posY)//DONE
{
    // TODO
    // Heu de modificar el valor de l'atribut m_posY (posició y de la figura) amb el valor posY que es passa com a paràmetre

    m_posY=posY;

}

void FigTetris::draw()//DONE
{
    // TODO
    // Heu e dibuixar el gràfic de la figura del tetris a la posicio m_posX, m_posY
    m_figura[m_gir].Draw(m_posX,m_posY);
}

void FigTetris::create(int indexFig)//DONE
{
    //inicialització i creació de la mascara per mitjà d'un array d'apuntadors de 3 dimensions
   m_figures = new int**[MAX_MASK];
   for (int i = 0; i < MAX_MASK; i++)
   {
       m_figures[i] = new int*[MAX_MASK];
       {
           for (int j = 0; j < MAX_MASK; j++)
           {
               m_figures[i][j] = new int[MAX_MASK];
           }
       }
   }
   for(int i = 0 ; i < MAX_MASK; i++)
   {
       for(int j = 0; j < MAX_MASK; j++)
       {
           for(int z = 0; z < MAX_MASK; z++)
           {
               m_figures[i][j][z] = COLOR_NEGRE;
           }
       }
   }

   m_gir = 0;
   m_indexFig = indexFig;
   switch (indexFig)
   {
       case I:

           m_color = COLOR_BLAUCEL;

               m_figura[0].Create("data/Graficstetris/palblaucel2.png");
               m_figura[2].Create("data/Graficstetris/palblaucel2.png");
               for(int i = 0; i < MAX_MASK; i++)
               {
                   m_figures[0][i][0] = m_color;
                   m_figures[0][i][2] = m_color;

               }

               m_figura[1].Create("data/Graficstetris/palblaucel1.png");
               m_figura[3].Create("data/Graficstetris/palblaucel1.png");
                for(int i = 0; i < MAX_MASK; i++)
                {
                   m_figures[i][0][1] = m_color;
                   m_figures[i][0][3] = m_color;

                }
              break;

            case O:
                m_figura[0].Create("data/Graficstetris/q4groc1.png");
                m_figura[1].Create("data/Graficstetris/q4groc1.png");
                m_figura[2].Create("data/Graficstetris/q4groc1.png");
                m_figura[3].Create("data/Graficstetris/q4groc1.png");
                m_color=COLOR_GROC;
                for (int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        m_figures[i][j][0] = m_color;
                        m_figures[i][j][1] = m_color;
                        m_figures[i][j][2] = m_color;
                        m_figures[i][j][3] = m_color;
                    }
                }
                break;
                case T:
                    m_color=COLOR_MAGENTA;

                    m_figura[0].Create("data/Graficstetris/tmagenta1.png");
                    for(int i = 0; i < 3; i++)
                    {
                        m_figures[i][0][0] = m_color;
                    }
                    m_figures[1][1][0] = m_color;

                    m_figura[1].Create("data/Graficstetris/tmagenta2.png");
                    for (int i = 0; i < 3; i++)
                    {
                        m_figures[1][i][1] = m_color;
                    }
                    m_figures[0][1][1] = m_color;

                    m_figura[2].Create("data/Graficstetris/tmagenta3.png");
                    for(int i = 0; i < 3; i++)
                    {
                        m_figures[i][1][2] = m_color;
                    }
                    m_figures[1][0][2] = m_color;

                    m_figura[3].Create("data/Graficstetris/tmagenta4.png");
                    for(int i = 0; i < 3; i++)
                    {
                        m_figures[0][i][3] = m_color;
                    }
                    m_figures[1][1][3] = m_color;
                    break;

                    case L:
                         m_color = COLOR_TARONJA;

                        m_figura[0].Create("data/Graficstetris/ltaronja1.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[i][1][0] = m_color;

                        }
                        m_figures[0][0][0]=m_color;

                        m_figura[1].Create("data/Graficstetris/ltaronja2.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[1][i][1] = m_color;
                        }
                        m_figures[0][2][1] = m_color;

                        m_figura[2].Create("data/Graficstetris/ltaronja3.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[i][0][2] = m_color;
                        }
                        m_figures[2][1][2] = m_color;

                        m_figura[3].Create("data/Graficstetris/ltaronja4.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[0][i][3] = m_color;
                        }
                        m_figures[1][0][3] = m_color;
                        break;
                    case P:
                        m_color = COLOR_BLAUFOSC;

                        m_figura[0].Create("data/Graficstetris/pblaufosc1.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[i][0][0] = m_color;
                        }
                        m_figures[0][1][0]=m_color;

                        m_figura[1].Create("data/Graficstetris/pblaufosc2.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[0][i][1] = m_color;
                        }
                        m_figures[1][2][1] = m_color;

                        m_figura[2].Create("data/Graficstetris/pblaufosc3.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[i][1][2] = m_color;
                        }
                        m_figures[2][0][2] = m_color;

                        m_figura[3].Create("data/Graficstetris/pblaufosc4.png");
                        for(int i = 0; i < 3; i++)
                        {
                            m_figures[1][i][3] = m_color;
                        }
                        m_figures[0][0][3] = m_color;
                        break;

                    case S:
                        m_color = COLOR_VERD;

                        m_figura[0].Create("data/Graficstetris/sverd1.png");
                        m_figura[2].Create("data/Graficstetris/sverd1.png");
                        m_figures[1][0][0] = m_color;
                        m_figures[1][1][0] = m_color;
                        m_figures[0][1][0] = m_color;
                        m_figures[0][2][0] = m_color;

                        m_figures[1][0][2] = m_color;
                        m_figures[1][1][2] = m_color;
                        m_figures[0][1][2] = m_color;
                        m_figures[0][2][2] = m_color;

                        m_figura[1].Create("data/Graficstetris/sverd2.png");
                        m_figura[3].Create("data/Graficstetris/sverd2.png");
                        m_figures[0][0][1] = m_color;
                        m_figures[1][0][1] = m_color;
                        m_figures[1][1][1] = m_color;
                        m_figures[2][1][1] = m_color;

                        m_figures[0][0][3] = m_color;
                        m_figures[1][0][3] = m_color;
                        m_figures[1][1][3] = m_color;
                        m_figures[2][1][3] = m_color;
                        break;

                    case Z:
                        m_color=COLOR_ROIG;

                        m_figura[0].Create("data/Graficstetris/zroig1.png");
                        m_figura[2].Create("data/Graficstetris/zroig1.png");

                        m_figures[0][0][0] = m_color;
                        m_figures[0][1][0] = m_color;
                        m_figures[1][1][0] = m_color;
                        m_figures[1][2][0] = m_color;

                        m_figures[0][0][2] = m_color;
                        m_figures[0][1][2] = m_color;
                        m_figures[1][1][2] = m_color;
                        m_figures[1][2][2] = m_color;

                        m_figura[1].Create("data/Graficstetris/zroig2.png");
                        m_figura[3].Create("data/Graficstetris/zroig2.png");

                        m_figures[0][1][1] = m_color;
                        m_figures[1][0][1] = m_color;
                        m_figures[1][1][1] = m_color;
                        m_figures[2][0][1] = m_color;

                        m_figures[0][1][3] = m_color;
                        m_figures[1][0][3] = m_color;
                        m_figures[1][1][3] = m_color;
                        m_figures[2][0][3] = m_color;

                        break;






           }


}

int FigTetris::amplada()//DONE
{

      // TODO
    // Retorna l'amplada de la figura
    int ample = 0;
    switch (m_indexFig)
    {
        case I:
            switch (m_gir)
            {
            case 0:
            case 2:
                ample = 4;
                break;
            case 1:
            case 3:
                ample = 1;
                break;
                }
            break;

        case O:
            ample = 2;
            break;

        case T:
        case L:
        case P:
            switch (m_gir)
            {
            case 0:
            case 2:
                ample = 2;
                break;
            case 1:
            case 3:
                ample = 3;
                break;
            }
            break;
        case S:
        case Z:
            switch (m_gir)
            {
            case 0:
            case 2:
                ample = 3;
                break;
            case 1:
            case 3:
                ample = 2;
                break;
            }
            break;

    }
    return ample;
}

int FigTetris::alcada()//DONE
{
    // TODO
    // Retorna l'amplada de la figura
    int alt = 0;
    switch (m_indexFig)
    {
        case I:
            switch (m_gir)
            {
            case 0:
            case 2:
                alt = 1;
                break;
            case 1:
            case 3:
                alt = 4;
                break;
                }
            break;

        case O:
            alt = 2;
            break;

        case T:
        case L:
        case P:
            switch (m_gir)
            {
            case 0:
            case 2:
                alt = 3;
                break;
            case 1:
            case 3:
                alt = 2;
                break;
            }
            break;
        case S:
        case Z:
            switch (m_gir)
            {
            case 0:
            case 2:
                alt = 2;
                break;
            case 1:
            case 3:
                alt = 3;
                break;
            }
            break;

    }
    return alt;
}

bool FigTetris::moureFig(int dirX, int dirY, Fons& fons)//DONE
{
    // TODO:
    // Heu d'analitzar si es pot fer el moviment indicat a dirX i dirY en funció de l'estat del fons i de la posició actual de la figura.
    // Si el moviment és possible, haure de modificar com correspongui el valor dels atributs m_posX i m_posY per actualitzar la posició
    // de la figura d'acord al moviment indicat. La funció ha de retornar true si la figura ha arribat a l'última línia del tauler

    // Els valors de dirX i dirX que indiquen el moviment poden ser de moment:
    // -1, 0: moviment a l'esquerra. Aqui sempre retornem fals.
    // 1, 0: moviment a la dreta. Aqui sempre retornem fals.
    // 0, 1: moviment a baix. Aqui a més hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la última línia del tauler del fons amb els quadres del color de la figura actual.
    // 0, 2: moviment a baix de dues posicions. Aqui a més hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la última línia del tauler del fons amb els quadres del color de la figura actual.
    setlinea(0);
    bool meta=false;
    switch (dirX)
    {
    case -1:
        if(!fons.shaSolapao(m_posX/MIDA_Q,m_posY/MIDA_Q, m_figures, dirX, dirY,amplada(),alcada(),m_gir))
        {
            m_posX = m_posX + (dirX * MIDA_Q);
        }

        break;

    case 1:
        if (!fons.shaSolapao(m_posX/MIDA_Q,m_posY/MIDA_Q, m_figures, dirX, dirY,amplada(),alcada(),m_gir))
        {
            m_posX = m_posX + (dirX * MIDA_Q);
        }
        break;
    case 0:
         switch (dirY)
        {
        case 1:
            //fons.returnTauler(m_posX/MIDA_Q, m_posY/MIDA_Q+alcada());
            //if (m_posY < FI_Y-(alcada()*MIDA_Q))
            //if (fons.returnTauler(m_posX/MIDA_Q, m_posY/MIDA_Q+alcada())==COLOR_NEGRE)
            if (!fons.shaSolapao(m_posX/MIDA_Q,m_posY/MIDA_Q,m_figures ,dirX,dirY,amplada(),alcada(),m_gir))
            {
                m_posY = m_posY + (dirY * MIDA_Q);
            }
            else
            {
                //cout << fons.uWin(alcada(),m_posX/MIDA_Q,m_posY/MIDA_Q);
                figuraEncaixada(fons);
                meta=true;
                int auxiliarUWin = fons.uWin(alcada(),m_posX/MIDA_Q,m_posY/MIDA_Q);

                if(auxiliarUWin!=0)
                {

                    setlinea(auxiliarUWin);

                }
            }
            break;
        case 2:

          if((!fons.shaSolapao(m_posX/MIDA_Q,m_posY/MIDA_Q+2, m_figures,0,0,amplada(),alcada(),m_gir)))
              {
               if (!fons.shaSolapao(m_posX/MIDA_Q,m_posY/MIDA_Q, m_figures,dirX,dirY,amplada(),alcada(),m_gir))
                {
                    m_posY = m_posY + (dirY * MIDA_Q);
                }
                else
                {
                   figuraEncaixada(fons);
                   meta=true;
                   int auxiliarUWin = fons.uWin(alcada(),m_posX/MIDA_Q,m_posY/MIDA_Q);

                    if(auxiliarUWin!=0)
                    {

                        setlinea(auxiliarUWin);

                    }
                }

            }
        break;
        }
    }

    return meta;
}



void FigTetris::figuraEncaixada(Fons& fons)//DONE
{
	// TODO:
	// Aquest mètode s'ha de cridar quan la figura arriba a baix de tot.
	// Modifica els quadres corresponents a l'amplada de la figura actual a les posicions de la última línia del tauler el fons amb els colors de la figura actual

    for(int i = 0; i < 4; i++)
    {
        for(int j=0; j < 4; j++)
        {
            if(m_figures[i][j][m_gir]!=COLOR_NEGRE)
            {

                fons.setTauler(i+(m_posY/MIDA_Q),j+(m_posX/MIDA_Q),m_color);
            }



        }

    }
}

int FigTetris::getlinea()
{
    return m_linea;
}

void FigTetris::setlinea(int linea)
{
    m_linea=linea;
}

void FigTetris::nextGir(Fons& fons)
{


    if (m_gir < 3)
    {
        m_gir++;
    }
    else
    {
        m_gir=0;
    }
    if (fons.shaSolapao(m_posX/MIDA_Q,m_posY/MIDA_Q, m_figures,0,0,amplada(),alcada(),m_gir))
    {
        if (!m_gir)
        {
            m_gir=3;
        }
        else
        {
            m_gir--;
        }
    }
}

int FigTetris::getGir()
{
    return m_gir;
}
