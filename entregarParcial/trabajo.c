#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "mascota.h"
#include "dataTrabajo.h"
#include "trabajo.h"

/*

void hardcodearTrabajos(eTrabajo vecTrabajo[],int cantTrabajo)
{
    for(int i=0; i<cantTrabajo; i++)
    {
        vecTrabajo[i].id=idTrabajos[i];
        vecTrabajo[i].idMascota=idMascotasTrabajos[i];
        vecTrabajo[i].idServicio=idServicioTrabajo[i];
        vecTrabajo[i].Fecha.dia=dias[i];
        vecTrabajo[i].Fecha.mes=meses[i];
        vecTrabajo[i].Fecha.anio=anios[i];
        vecTrabajo[i].estado=1;
    }
}

*/

void hardcodearTrabajos(eTrabajo vecTrabajo[],int cantTrabajo)
{
    eTrabajo trabajo []=
    {
        {1,103,20000,{12,3,2020},1},
        {2,101,20000,{2,4,2020},1},
        {3,111,20001,{7,2,2020},1},
        {4,102,20002,{9,11,2020},1},
        {5,122,20001,{12,12,2020},1},
        {6,112,20001,{21,7,2020},1},
        {7,113,20001,{29,8,2020},1},
        {8,103,20000,{31,5,2020},1},
        {9,120,20002,{2,2,2020},1},
        {10,115,20000,{18,2,2020},1},
        {11,110,20000,{17,3,2020},1},
        {12,105,20000,{17,4,2020},1},
        {13,109,20000,{2,6,2020},1},
        {14,107,20001,{7,3,2020},1},
        {15,106,20002,{21,7,2020},1},
        {16,121,20002,{11,9,2020},1},
        {17,121,20001,{3,7,2020},1},
        {18,110,20001,{21,8,2020},1},
        {19,121,20002,{28,5,2020},1},
        {20,117,20002,{2,8,2020},1},
        {21,116,20000,{8,2,2020},1},
        {22,111,20001,{17,3,2020},1},
        {23,101,20001,{17,4,2020},1},
        {24,103,20000,{21,3,2020},1},
        {25,109,20002,{16,4,2020},1},
        {26,107,20000,{17,4,2020},1},
        {27,105,20001,{23,3,2020},1},
        {28,112,20000,{12,2,2020},1},
        {29,110,20000,{2,3,2020},1},
        {30,118,20001,{7,2,2020},1},
        {31,120,20002,{9,12,2020},1},
        {32,101,20002,{12,9,2020},1},
        {33,106,20001,{21,5,2020},1},
        {34,103,20002,{12,2,2020},1},
        {35,102,20000,{21,1,2020},1},
    };

    for(int i=0; i<cantTrabajo; i++)
    {
        vecTrabajo[i]=trabajo[i];

    }

}

void setearTrabajo(eTrabajo vecTrabajo[],int cantTrabajo,int valor)
{
    for(int i=0; i<cantTrabajo; i++)
    {
        vecTrabajo[i].estado=valor;
    }

}





int encontrarLugarLibreTrabajo(eTrabajo vecTrabajo[],int cantTrabajo)
{
    int i;
    for(i=0; i<cantTrabajo; i++)
        if(vecTrabajo[i].estado==0)
        {
            return i;
            break;
        }

    return -1;
}




int encontrarTrabajoPorId(eTrabajo vecTrabajo[],int cantTrabajo,int id)
{
    int i;
    for(i=0; i<cantTrabajo; i++)
    {
        if(vecTrabajo[i].id==id&&vecTrabajo[i].estado==1)
        {
            return i;
        }
    }
    return -1;

}




void mostrarTrabajo(eTrabajo trab,eServicio VecServicio[],int cantServicio,eMascota vecMascota[],int cantMascota)
{

    int indice;
    int indice2;

    for(int i=0; i<cantMascota; i++)
    {
        if((trab.idMascota== vecMascota[i].id))
        {
            indice = i;
            break;
        }
    }

    for(int j=0; j<cantServicio; j++)
    {
        if((trab.idServicio== VecServicio[j].id ) )
        {
            indice2 = j;
            break;
        }
    }
    printf("%d     %10s     %10s       %.2f  %0d/%0d/%0d \n",trab.id,vecMascota[indice].nombre,VecServicio[indice2].descripcion,VecServicio[indice2].precio,trab.Fecha.dia,trab.Fecha.mes,trab.Fecha.anio );
}



void mostrarTrabajos(eTrabajo vecTrabajo[],int cantTrabajo,eServicio vecServicio[],int cantServicio,eMascota vecMascota[],int cantMascota)
{
    int cont=0;


    printf("****Listado de Trabajos*****\n\n");
    printf("  Id      Nombre Mascota   Servicio    Precio    Fecha\n");
    for(int i=0; i<cantTrabajo; i++)
    {
        if(vecTrabajo[i].estado ==1)// !=0
        {
            mostrarTrabajo(vecTrabajo[i],vecServicio,cantServicio,vecMascota,cantMascota);
            cont++;

        }

    }
    //printf("hay %d Trabajos",cont);

    if(cont==0)
    {
        system("cls");
        printf("\nNo hay Trabajos para mostrar!!");
    }


}



void ordenarMascotasPorId(eMascota vecMascota[],int cantMascota)
{

    eMascota auxMascota;
    for(int i=0; i<cantMascota-1; i++)
    {
        for(int j=i+1; j<cantMascota; j++)
            if(vecMascota[i].id>vecMascota[j].id)
            {
                auxMascota = vecMascota[i];
                vecMascota[i] = vecMascota[j];
                vecMascota[j] = auxMascota;
            }
    }
    printf("\n");
}


int altaTrabajo(int lastId,eTrabajo vecTrabajo[],int cantTrabajo,eMascota vecMascota[],int cantMascota,eServicio vecServicio[],int cantServicio,eTipo vecTipo[],int cantTipo,eColor vecColor[],int cantColor)
{

    int todoOk=0;

    eTrabajo nuevoTrabajo;
    int indiceLugarLibre;
    int id;

    indiceLugarLibre=encontrarLugarLibreTrabajo(vecTrabajo,cantTrabajo);
    if(indiceLugarLibre==-1)
    {
        printf("No quedan lugares libres\n");
    }
    else
    {
        nuevoTrabajo.id=lastId;

        ordenarMascotasPorId(vecMascota,cantMascota);
        mostrarMascotas(vecMascota,cantMascota,vecColor,cantColor,vecTipo,cantTipo);
        id=validarEntero("ingrese id de la mascota: ","id en numeros: ",100,1000);

        if(encontrarMascotaPorId(vecMascota,cantMascota,id)==-1)
        {
            printf("la Mascota no existe");
        }
        else
        {
            nuevoTrabajo.idMascota=id;

            mostrarServicios(vecServicio,cantServicio);
            nuevoTrabajo.idServicio=validarEntero("Ingrese servicio: ","servicio en numeros: ",20000,20002);
            nuevoTrabajo.Fecha.dia=validarEntero("ingrese dia: ","dia en numeros: ",1,31);
            nuevoTrabajo.Fecha.mes=validarEntero("ingrese mes: ","mes en numeros :",1,12);
            nuevoTrabajo.Fecha.anio=validarEntero("ingrese anio: ","anio en numeros: ",1900,2020);
            nuevoTrabajo.estado=1;
            vecTrabajo[indiceLugarLibre]=nuevoTrabajo;
            printf("Se ha dado de alta un nuevo trabajo con exito!!!\n");
            todoOk=1;
        }




    }


    return todoOk;
}



