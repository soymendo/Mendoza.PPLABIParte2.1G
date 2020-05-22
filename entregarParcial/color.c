#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "dataColor.h"
#include "color.h"




void hardcodearColor(eColor vecColor[],int cantColor)
{
    for(int i=0; i<cantColor; i++)
    {
        vecColor[i].id=idColores[i];
        strcpy(vecColor[i].nombreColor,nombreColoeres[i]);

    }
}




void mostrarColores(eColor vecColor[],int cantColor)
{
    printf("Colores: \n");
    printf(" ID    Nombre\n");
    for(int i=0; i<cantColor; i++)
    {
        printf("%d %s\n",vecColor[i].id,vecColor[i].nombreColor );
    }

}

