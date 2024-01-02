#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tateti.h"

int main()
{
    srand(time(0));
    char tabl[TAMANIO][TAMANIO];
    repetirJuego(tabl);
    return 0;
}
