#include "Resultats.h"

Resultats::Resultats()
{
    // Constructor. Crea tots els gr�fics per mostrar el d�gits. No s'ha de modificar
    m_digits[0].Create("data/numeros/numero0000.png");
    m_digits[1].Create("data/numeros/numero0001.png");
    m_digits[2].Create("data/numeros/numero0002.png");
    m_digits[3].Create("data/numeros/numero0003.png");
    m_digits[4].Create("data/numeros/numero0004.png");
    m_digits[5].Create("data/numeros/numero0005.png");
    m_digits[6].Create("data/numeros/numero0006.png");
    m_digits[7].Create("data/numeros/numero0007.png");
    m_digits[8].Create("data/numeros/numero0008.png");
    m_digits[9].Create("data/numeros/numero0009.png");
}

Resultats::~Resultats()
{
    // Destructor
}

void Resultats::inicialitzar(const char* rutaResultats)//DONE
{
   // TODO
   // Crea el gr�fic que s'utilitza per mostrar els resultats a partir de la ruta que es passa com a par�metre
    m_resultats.Create(rutaResultats);
}

void Resultats::pintaResultats(int nivell, int punts, int vides)//DONE
{
    // TODO
    // Pinta el grafic de fons dels resultats i mostra el nivell i els punts (que es passen com a par�metres)
    // utilitzant el m�tode escriuNumero
    m_resultats.Draw(POS_NIV_RESX-175,POS_RESY);
    escriuNumero(nivell,POS_NIV_RESX,POS_NIV_RESY,PAS_DIGIT_X);
    escriuNumero(punts,POS_PUNTS_RESX,POS_PUNTS_RESY,PAS_DIGIT_X);
    escriuNumero(vides, POS_VIDES_RESX,POS_VIDES_RESY,PAS_DIGIT_X);
}

void Resultats::escriuDigit(int n, int posX, int posY)//DONE
{
    // TODO
    // Escriu un digit a la posicio x,y que es passa com a par�metre.
    // Els gr�fics de cada d�git estan a l''atribut m_digits que s'inicialitza al constructor
    m_digits[n].Draw(posX,posY);
}

//Escriu numeros de fins a 3 xifres donant-li el numero i la posiciox i y de les centenes i la
// distancia entre unitats decenes i centenes en l'eix de les x
// No s'ha de modificar
void Resultats::escriuNumero(int n,int posX,int posY,int pasDigit)
{
    int divisor = 100;
    int posXActual = posX;
    int nActual =n;
    bool primerDigit = true;

    while (divisor > 0)
    {
        int d = nActual / divisor;
        nActual = nActual % divisor;
        divisor = divisor / 10;

        if ( (d > 0) || !primerDigit || (divisor == 0) )
        {
            escriuDigit( d , posXActual, posY);
            primerDigit = false;
        }

        posXActual += pasDigit;
    }
}
