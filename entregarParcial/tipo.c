#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "dataTipo.h"
#include "tipo.h"






void hardcodearTipo(eTipo vecTipo[],int cantTipo)
{
    for(int i=0; i<cantTipo; i++)
    {
        vecTipo[i].id=idTipos[i];
        strcpy(vecTipo[i].descripcion,descripcionTipos[i]);

    }
}




void mostrarTipos(eTipo vecTipo[],int cantTipo)
{
    printf("Tipos: \n");
    printf(" ID    Nombre\n");
    for(int i=0; i<cantTipo; i++)
    {
        printf("%d %s\n",vecTipo[i].id,vecTipo[i].descripcion );
    }

}
