#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "dataMascota.h"
#include "mascota.h"


void hardcodearMascotas(eMascota vecMascota[],int cantMascota)
{

    eMascota mascota[]=
    {
        {101, "Tito", 1000, 5004, 5, 1},
        {102, "Laica", 1003, 5000, 2, 1},
        {103, "Fiona", 1002, 5003, 7, 1},
        {104, "Pupi", 1002, 5003, 3, 1},
        {105, "Mia", 1004, 5002, 8, 1},
        {106, "Sheila", 1003, 5001, 9, 1},
        {107, "Luna", 1001, 5000, 2, 1},
        {108, "Roco", 1001, 5002, 3, 1},
        {109, "Pepe", 1000, 5003, 8, 1},
        {110, "Lilo", 1003, 5001, 1, 1},
        {111, "Jupo", 1003, 5001, 10, 1},
        {112, "Dido", 1004, 5002, 6, 1},
        {113, "Soli", 1001, 5003, 7, 1},
        {114, "Felpi", 1000, 5004, 6, 1},
        {115, "Pipi", 1000, 5001, 14, 1},
        {116, "Dic", 1002, 5001, 5, 1},
        {117, "Norberto", 1001, 5000, 9, 1},
        {118, "Chuc", 1004, 5002, 1, 1},
        {119, "Tyson", 1004, 5002, 3, 1},
        {120, "Junior", 1002, 5003, 2, 1},
        {121, "Bebe", 1003, 5004, 2, 1},
        {122, "Pria", 1001, 5000,4, 1},
    };
    for(int i=0; i<cantMascota; i++)
    {
        vecMascota[i]=mascota[i];

    }

}


/*
void hardcodearMascotas(eMascota vecMascota[],int cantMascota)
{
    for(int i=0; i<cantMascota; i++)
    {
        vecMascota[i].id=idMascotas[i];
        strcpy(vecMascota[i].nombre,nombreMascotas[i]);
        vecMascota[i].idTipo=idTiposMascotas[i];
        vecMascota[i].idColor=idColoresMascotas[i];
        vecMascota[i].edad=edades[i];
        vecMascota[i].estado=1;
    }
}
*/





void setearMascota(eMascota vecMascota[],int cantMascota,int valor)
{
    for(int i=0; i<cantMascota; i++)
    {
        vecMascota[i].estado=valor;
    }

}




int encontrarLugarLibreMascota(eMascota vecMascota[],int cantMascota)
{
    int i;
    for(i=0; i<cantMascota; i++)
        if(vecMascota[i].estado==0)
        {
            return i;
            break;
        }

    return -1;
}




int encontrarMascotaPorId(eMascota vecMascota[],int cantMascota,int id)
{
    int i;
    for(i=0; i<cantMascota; i++)
    {
        if(vecMascota[i].id==id&&vecMascota[i].estado==1)
        {
            return i;
        }
    }
    return -1;

}




void mostrarMascota(eMascota mas,eColor vecColor[],int cantColor,eTipo VecTipo[],int cantTipo)
{

    int indice;
    int indice2;

    for(int i=0; i<cantColor; i++)
    {
        if((mas.idColor== vecColor[i].id ) )
        {
            indice = i;
            break;
        }
    }

    for(int j=0; j<cantTipo; j++)
    {
        if((mas.idTipo == VecTipo[j].id ) )
        {
            indice2 = j;
            break;
        }
    }
    printf("%d    %10s    %10s   %10s           %d \n",mas.id,mas.nombre,VecTipo[indice2].descripcion,vecColor[indice].nombreColor,mas.edad);
}




void mostrarMascotas(eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo)
{
    int cont=0;


    printf("****Listado de Mascotas*****\n\n");
    printf("  Id      Nombre         Tipo         Color          Edad\n");
    for(int i=0; i<cantMascota; i++)
    {
        if(vecMascota[i].estado ==1)// !=0
        {
            mostrarMascota(vecMascota[i],vecColor,cantColor,vecTipo,cantTipo);
            cont++;
        }

    }
    //printf("hay %d Mascotas",cont);

    if(cont==0)
    {
        system("cls");
        printf("\nNo hay Mascotas para mostrar!!");
    }


}




int altaMascota(int lastId,eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo)
{

    int todoOk=0;

    eMascota nuevoMascota;
    int indiceLugarLibre;

    indiceLugarLibre=encontrarLugarLibreMascota(vecMascota,cantMascota);
    if(indiceLugarLibre==-1)
    {
        printf("No quedan lugares libres\n");
    }
    else
    {
        nuevoMascota.id=lastId;

        /*if(encontrarMascotaPorId(vecMascota,cantMascota,nuevoMascota.id)!=-1)
        {
            printf("La Mascota ya existe");
        }
        else*/
        //{
        validarLetras("Ingrese nombre: ","Nombre en letras: ",nuevoMascota.nombre);
        nuevoMascota.nombre[0]=toupper(nuevoMascota.nombre[0]);
        mostrarTipos(vecTipo,cantTipo);
        nuevoMascota.idTipo=validarEntero("ingrese Tipo : ","Tipo en numeros : ",1000,1004);
        mostrarColores(vecColor,cantColor);
        nuevoMascota.idColor=validarEntero("ingrese color: ","color en numeros: ",5000,5004);
        nuevoMascota.edad=validarEntero("ingrese edad: ","edad en numeros: ",1,100);

        nuevoMascota.estado=1;
        vecMascota[indiceLugarLibre]=nuevoMascota;
        printf("Se ha dado de alta una mascota con exito!!!\n");
        todoOk=1;
        //}

    }


    return todoOk;
}




void bajaMascota(eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo)
{
    int encontrarIndice;
    int id;
    char seguir;

    printf("****BAJA****\n\n");


    mostrarMascotas(vecMascota,cantMascota,vecColor,cantColor,vecTipo,cantTipo);
    id=validarEntero("Ingrese id a eliminar: ","Id en numeros: ",100,1000);

    encontrarIndice=encontrarMascotaPorId(vecMascota,cantMascota,id);

    if(encontrarIndice==-1)
    {
        printf("\n\nNo se encontro esa Mascota\n");
    }
    else
    {

        printf("\nDesea confirmar?: ");
        fflush(stdin);
        scanf("%c",&seguir);

        if(seguir=='s'||seguir=='S')
        {
            vecMascota[encontrarIndice].estado=0;
            printf("Dado de baja\n\n");
        }

    }
}




void modificacionMascota(eMascota vecMascota[],int cantMascota,eTipo vecTipo[],int cantTipo,eColor vecColor[],int cantColor)
{
    int encontrarIndice;
    int opcion;
    char modificar;
    int id;
    int tipo;
    int edad;

    mostrarMascotas(vecMascota,cantMascota,vecColor,cantColor,vecTipo,cantTipo);

    id=validarEntero("Ingrese id a modificar: ","Id en numeros: ",100,1000);

    encontrarIndice=encontrarMascotaPorId(vecMascota,cantMascota,id);
    if(encontrarIndice==-1)
    {
        printf("no se encuentra esa Mascota");

    }
    else
    {
        while(opcion!=3)
        {
            opcion=validarEntero("ingrese dato a modificar: \n\n -1.Tipo \n -2.Edad \n -3.Salir \n","en numeros por favor: ",1,3);
            switch(opcion)
            {
            case 1:
                printf("\nModifica Tipo?: ");
                fflush(stdin);
                scanf("%c", &modificar);
                if(modificar != 's'&&modificar!='S')
                {
                    printf("Modificacion cancelada\n\n");
                }
                else
                {
                    mostrarTipos(vecTipo,cantTipo);
                    tipo=validarEntero("Ingrese tipo: ","tipo en numeros:",1000,1004);
                    vecMascota[encontrarIndice].idTipo=tipo;
                    printf("Se ha modificado el tipo con exito\n\n");
                }
                break;

            case 2:
                printf("\nModifica edad?: ");
                fflush(stdin);
                scanf("%c", &modificar);
                if(modificar != 's'&&modificar!='S')
                {
                    printf("Modificacion cancelada\n\n");
                }
                else
                {
                    edad=validarEntero("Ingrese edad: ","edad en numeros:",1,100);
                    vecMascota[encontrarIndice].edad=edad;
                    printf("Se ha modificado la edad con exito\n\n");
                }

                break;
            }
        }
    }

}



void cargarDescripcionTipo(eTipo vecTipo[],int cantTipo, int idTipo, char cadena[])
{

    for(int i=0; i < cantTipo; i++)
    {
        if( vecTipo[i].id == idTipo)
        {
            strcpy(cadena, vecTipo[i].descripcion);
            break;
        }
    }
}




void ordenarMascotas(eMascota vecMascota[],int cantMascota,eTipo vecTipo[],int cantTipo)
{
    char descripcionI[20];
    char descripcionJ[20];
    eMascota auxMascota;

    for(int i=0; i<cantMascota -1; i++)
    {
        for(int j = i +1; j < cantMascota; j++)
        {
            cargarDescripcionTipo(vecTipo, cantTipo, vecMascota[i].idTipo, descripcionI);
            cargarDescripcionTipo(vecTipo, cantTipo, vecMascota[j].idTipo, descripcionJ);

            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxMascota = vecMascota[i];
                vecMascota[i] = vecMascota[j];
                vecMascota[j] = auxMascota;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(vecMascota[i].nombre,vecMascota[j].nombre) > 0)
            {
                auxMascota = vecMascota[i];
                vecMascota[i] = vecMascota[j];
                vecMascota[j] = auxMascota;
            }
        }
    }

    printf("\n");
}

