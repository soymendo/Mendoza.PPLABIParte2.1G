#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "mascota.h"
#include "trabajo.h"
#include "informes.h"


#define MAS 100
#define TIP 5
#define COL 5
#define TRAB 100
#define SER 3









int main()
{
    system("COLOR 0F");
    eMascota vecMascota[MAS];
    eTipo vecTipo[TIP];
    eColor vecColor[COL];

    eTrabajo vecTrabajo[TRAB];
    eServicio vecServicio[SER];

    setearMascota(vecMascota,MAS,0);
    setearTrabajo(vecTrabajo,TRAB,0);



    hardcodearTipo(vecTipo,TIP);
    hardcodearColor(vecColor,COL);
    harcdocdearServicios(vecServicio,SER);

    hardcodearMascotas(vecMascota,22);
    hardcodearTrabajos(vecTrabajo,35);





    int opcion=0;
    int flagA=1;
    int flagB=1;
    int lastId=36;
    int lastIdMascota=123;



    while(opcion!=11)
    {
        system("cls");

        opcion=validarOpcion("\n\n******ABM*********************\n\n1 -ALTA MASCOTA\n2 -MODIFICACION MASCOTA\n3 -BAJA MASCOTA\n4 -LISTAR Y ORDENAR MASCOTAS\n5 -LISTAR TIPOS  \n6 -LISTAR COLORES \n7 -LISTAR SERVICIOS \n8 -ALTA TRABAJO \n9 -LISTAR TRABAJOS \n10 -INFORMES \n11 -SALIR\n\n\n","Opcion incorrecta, reingrese opcion :", 1,11);
        switch(opcion)
        {
        case 1:
            system("cls");
            if(altaMascota(lastIdMascota,vecMascota,MAS,vecColor,COL,vecTipo,TIP))//alta
            {
                flagA=1;
            }
            system("pause");
            break;

        case 2://modificacion
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
            modificacionMascota(vecMascota,MAS,vecTipo,TIP,vecColor,COL);
            }
            system("pause");
            break;

        case 3://baja
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
            bajaMascota(vecMascota,MAS,vecColor,COL,vecTipo,TIP);
            }
            system("pause");
            break;

        case 4://listar y ordenar
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
                ordenarMascotas(vecMascota,MAS,vecTipo,TIP);
                mostrarMascotas(vecMascota,MAS,vecColor,COL,vecTipo,TIP);
            }
            system("pause");
            break;

        case 5://listar tipos
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
               mostrarTipos(vecTipo,TIP);
            }
            system("pause");
            break;

        case 6://listar colores
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
           mostrarColores(vecColor,COL);
            }
            system("pause");
            break;

        case 7://listar servicios
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
            mostrarServicios(vecServicio,SER);
            }
            system("pause");
            break;

        case 8://alta trabajo
            system("cls");
            if(flagA==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else
            {
            if(altaTrabajo(lastId,vecTrabajo,TRAB,vecMascota,MAS,vecServicio,SER,vecTipo,TIP,vecColor,COL))
            {
            lastId++;
            flagB=1;
            }
            }
            system("pause");
            break;

        case 9://listar trabajos
            system("cls");
            if(flagA==0&&flagB==0)
            {
                printf("Primero debe darse de alta una mascota\n");
            }
            else if(flagB==0)
            {
                printf("Primero debe darse de alta un trabajo\n");
            }
            else
            {
           mostrarTrabajos(vecTrabajo,TRAB,vecServicio,SER,vecMascota,MAS);
            }
            system("pause");
            break;

        case 10:
            system("cls");
            informes(vecMascota,MAS,vecColor,COL,vecTipo,TIP,vecTrabajo,TRAB,vecServicio,SER);
        break;

        }

    }

   return 0;

}


