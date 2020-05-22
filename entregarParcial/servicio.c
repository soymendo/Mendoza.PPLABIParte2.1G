#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "dataServicio.h"
#include "servicio.h"






void harcdocdearServicios(eServicio vecServicio[],int cantServicio)
{
    for(int i=0; i<cantServicio; i++)
    {
        vecServicio[i].id=idServicios[i];
        strcpy(vecServicio[i].descripcion,descripcionServicios[i]);
        vecServicio[i].precio=precios[i];

    }
}





void mostrarServicios(eServicio vecServicio[],int cantServicio)
{
    printf("Servicios: \n");
    printf(" ID    Nombre    Precio\n");
    for(int i=0; i<cantServicio; i++)
    {
        printf("%d %s  %.2f\n",vecServicio[i].id,vecServicio[i].descripcion,vecServicio[i].precio );
    }

}


