
#include "Joc.h"
#include "../lib/libreria.h"
#include <cstdlib>
#include<iostream>

#include "Resultats.h"


int llegirEvent()
{
    int tecla;

    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        tecla = TECLA_ESQUERRA;
    else
        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
            tecla = TECLA_DRETA;
        else
            if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
                tecla = TECLA_ABAIX;
            else
                if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
                    tecla = TECLA_ESC;
                    else
                        if ((Keyboard_GetKeyTrg(KEYBOARD_UP))||(Keyboard_GetKeyTrg(KEYBOARD_SPACE)))
                            tecla = TECLA_ESPAI;
    return tecla;
}

int aleatori(int min, int max)
{
	int aleatori = rand() % (max - min + 1) + min;
	return aleatori;
}

void tractarEvent(int tecla, FigTetris& fig, Fons& fons)//DONE
{
	// TODO
	// Adaptar el mateix tractament de cada possible event (tecla) que vau fer a la sessi� 1, modificant el codi per
	// utilitzar els m�todes de les classes FigTetris i Fons
	switch (tecla)
	{
        case TECLA_ESQUERRA:
            fig.moureFig(-1,0,fons);
            break;
        case TECLA_DRETA:
            fig.moureFig(1,0,fons);
            break;
        case TECLA_ABAIX:
            fig.moureFig(0,2,fons);
            break;
        case TECLA_ESPAI:
            fig.nextGir(fons);
            break;

	}


}

void crearFigTetris(FigTetris* figTetrisActual)
{
    // TODO
    // Heu de crear totes les figures del tetris utilitzant el m�tode create de la classe FigTetris i guardar cadascuna de les figures
    // en una de les posicions de l'array de figures que es passa com a par�metre
    for (int i = 0; i < MAX_FIG; i++)
        {
                figTetrisActual[i].create(i);
        }
}

int joc(int nivell)
{
    // TODO
    // Definicions i Inicialitzacions necess�ries per utilitzar la llibreria gr�fica
    // Ha de ser el mateix codi que teniu a la versi� de la primera sessi�
    Game joc;
    joc.Init();

    // TODO
    // Definicions dels objectes del fons i resultats
    Fons fons;
    Resultats resultats;




	// Declaracions de variables. No s'han de modificar
    int tecla = 0; // Valor de la tecla pressionada en cada iteraci� del joc
    bool metaAconseguida; // Indica si la figura ha arribat a la �ltima l�nia del taules
    bool finalTemps; // Indica si se'ns ha acabat el temps per completar la �ltima l�nia del tauler
	int velocitatJoc = 300; // Indica velocitat del joc, quantes m�s linies es fan m�s r�pida �s
	int contVPeca; // Comptador per controlar la velocitat
	int vides = 3; // N� de vides
	int punts = 0; // Punts
	int diffT = 0; // Control del temps del joc
	time_t now;

    //Inizialitzar llavor per a la funci� rand()
	srand((unsigned)time(NULL));
	// Inicialtizar variable per control del temps
    now = time(NULL);

    // TODO
    // Inicialitzar els gr�fics del fons i resultat cridant als m�todes Inicialitzar de les classes fons i resultat
    // per al fons "data/GraficsTetris/fons.png");
    // per el resultat "data/GraficsTetris/Resultats.png"
    fons.inicialitzar("data/GraficsTetris/fons.png");
    resultats.inicialitzar("data/GraficsTetris/Resultats.png") ;


   	// TODO
   	// Mostrem la finestra del joc com a la sesio 1
    joc.Video_ShowWindow();
    // TODO
    // Declaraci� d'un array per guardar totes les figures del tetris.
    // Inicialitza els gr�fics de totes les figures de l'array amb la funci� CrearFigTetris
    FigTetris figura[MAX_FIG];
    for (int i = 0;i < MAX_FIG; i++)
    {

            figura[i].create(i);


    }

	do
    {
        // Definici� i inicialitzaci� aleatoria de la figura del tetris
        int indexFig  = aleatori(INI_FIG, FI_FIG);
        int indexFigAnt = 0;
        int gir = aleatori(0,3);

        // TODO
        // Inicialitzacio de la posicio de la figura que s'ha generat aleat�riament utilitzant els m�todes setPosX i setPosY de la figura que
        // ocupa la posici� indexFig dins de l'array de figures
        // La posici� x vindria donada per ( (INICI_X) + ( ( rand() % ( ( (FI_X - INICI_X - (amplada en quadres figura actual * MIDA_Q)) / MIDA_Q ) + 1 ) ) * MIDA_Q ));
        // La posici� y per (INICI_Y);
        figura[indexFig].setPosX((INICI_X) + ( ( rand() % ( ( (FI_X - INICI_X - (figura[indexFig].amplada() * MIDA_Q)) / MIDA_Q ) + 1 ) ) * MIDA_Q ));
        figura[indexFig].setPosY(INICI_Y);

        // Inicialitzar variables que controlen si s'ha omplert la �ltima l�nia i la velocitat del joc
        metaAconseguida = false;
        finalTemps = false;
        contVPeca = velocitatJoc / nivell;
        now = time(NULL);


        // TODO
        // Dibuixar el fons, els resultats, la figura actual (cridant els m�todes corresponents de cada objecte) i refrescar pantalla (com a la primera sessi�)
        fons.pintaFons();
        resultats.pintaResultats(nivell,punts,vides);
        figura[indexFig].draw();
        joc.VideoUpdate();


        do
        {
           // TODO
           // Permetre que es processin els events com a la sesio 1, llegir event i tractar event, igual que es fa a la primera sessi�
            joc.ProcessEvents();

            tecla = llegirEvent();
            tractarEvent(tecla, figura[indexFig], fons);


            // Moviment de la figura segons la velocitat del joc
            contVPeca--;
            if(contVPeca == 0)
            {
                // TODO
                // Moure la figura una posicions cap avall i verificar si hem arribat a la �ltima l�nia del tauler actualitzant
                // metaAconseguida a true si �s aix� i les posicions corresponent de la �ltima l�nia del tauler ams els colors de la figura
                // Aix� s'ha de fer cridant al m�tode moureFig de la classe FigTetris.
              if(fons.guanyar())
              {
                  metaAconseguida=true;
              }
              else
              {
                    if(figura[indexFig].moureFig(0,1,fons))
                    {
                        fons.pintaFons();
                        indexFigAnt = indexFig;
                        indexFig  = aleatori(INI_FIG, FI_FIG);
                        figura[indexFig].setPosX((INICI_X) + ( ( rand() % ( ( (FI_X - INICI_X - (figura[indexFig].amplada() * MIDA_Q)) / MIDA_Q ) + 1 ) ) * MIDA_Q ));
                        figura[indexFig].setPosY(INICI_Y);

                    }
              }

                contVPeca = velocitatJoc / nivell; // reinicialitzaci� comptador de velocitat
            }

            // TODO
            // Dibuixar el fons, els resultats, la figura actual (cridant els m�todes corresponents de cada objecte)
            fons.pintaFons();
            resultats.pintaResultats(nivell,punts,vides);
            figura[indexFig].draw();



			// TODO
			// Actualitza la pantalla com a sesio 1.

            joc.VideoUpdate();

            // Mira el temps que ha trigat
            diffT = difftime(time(NULL),  now);
            // Mira si triga molt i si ho fa perd una vida
            if(fons.uLoose())
            {


                // TODO
                // Reinicialitzar el fons a negre (m�tode posarNegre de la classe Fons)
                fons.posarNegre();
                fons.posarGris();

                // Decrementem n� de vides
                vides--;

            }
            if(figura[indexFigAnt].getlinea()!=0) //suma els punts depenent del nivell i el nivell depentent dels punts
            {

                punts+=20*(figura[indexFigAnt].getlinea())*nivell;
                figura[indexFigAnt].setlinea(0);
                if (punts >= 200*nivell)
                {
                    nivell++;
                }
            }


            // TODO Mira si ha fet una linia
           if(fons.guanyar())
            {
                metaAconseguida = true;

                // TODO
                // Reinicialitzar el fons a negre (m�tode posarNegre de la classe Fons)
                fons.posarNegre();

                // Incrementem puntuaci� i nivell
                punts += 1*nivell;
                nivell++;
                // Reinicialitzem control del temps
                now = time(NULL);

            }


        }while((tecla != TECLA_ESC) && (!metaAconseguida) && (!finalTemps) && (vides>0));

	}while((nivell<4) && (vides>0) && (tecla != TECLA_ESC));


	return punts;
}
