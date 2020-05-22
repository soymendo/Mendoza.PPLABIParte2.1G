#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "mascota.h"
#include "trabajo.h"







void mascotaXColorIngresado(eMascota vecMascota[],int cantidadMascota, eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor)
{

    int cont=0;
    int colorAux;
    int i;
    mostrarColores(vecColor,cantidadColor);
    colorAux=validarEntero("Ingrese idColor: "," idColor en numeros: ",5000,5004);
    printf("  Id      Nombre         Tipo         Color          Edad\n");
    for(i=0; i<cantidadMascota; i++)
    {
        if(vecMascota[i].estado ==1 && vecMascota[i].idColor==colorAux)//=1
        {

            mostrarMascota(vecMascota[i],vecColor,cantidadColor,vecTipo,cantidadTipo);
            cont++;
        }
    }
    if(cont ==0)
    {
        printf("No hay Mascota para mostrar!!");
    }

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void mascotaXTipoIngresado(eMascota vecMascota[],int cantidadMascota, eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor)
{

    int cont=0;
    int i;
    int TipoAux;

    mostrarTipos(vecTipo,cantidadTipo);
    TipoAux=validarEntero("Ingrese idTipo: ","idTipo en numeros: ",1000,1004);

    printf("  Id      Nombre         Tipo         Color          Edad\n");


    for(i=0; i<cantidadMascota; i++)
    {
        if(vecMascota[i].estado ==1 && vecMascota[i].idTipo==TipoAux)//=1
        {

            mostrarMascota(vecMascota[i],vecColor,cantidadColor,vecTipo,cantidadTipo);

            cont++;
        }
    }
    if(cont ==0)
    {
        printf("No hay Mascota para mostrar!!");
    }
}




//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void listarMascotasMenorEdad(eMascota vecMascota[], int cantMascota, eTipo vecTipos[], int cantTipos, eColor vecColor[], int cantColor)
{
    int edadMin;
    int flag = 0;


    printf("*** Mascotas menor edad ***\n");


    for(int i=0; i<cantMascota; i++)
    {
        if(flag == 0 && vecMascota[i].estado == 1)
        {
            edadMin = vecMascota[i].edad;
            flag = 1;
        }
        else if(vecMascota[i].estado == 1 &&  vecMascota[i].edad < edadMin)
        {
            edadMin = vecMascota[i].edad;
        }
    }




    if(edadMin==1)
    {
        printf("\nLa o las mascotas con menor edad tienen %d anio y son : \n", edadMin);
    }
    else
    {
        printf("\nLa o las mascotas con menor edad tienen %d anios y son : \n", edadMin);
    }


    printf("Id      Nombre         Tipo         Color          Edad\n");

    for(int i= 0; i<cantMascota; i++)
    {
        if(vecMascota[i].edad== edadMin&&vecMascota[i].estado==1)
        {
            mostrarMascota(vecMascota[i],vecColor,cantColor,vecTipos,cantTipos);
        }
    }

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void listarMascotasSeparadasPorTipos(eMascota vecMascota[], int cantMascota, eTipo vecTipo[], int cantTipo, eColor vecColor[], int cantColor)
{
    int flag;

    for(int t=0; t<cantTipo; t++)
    {
        flag=0;
        printf("-------------------------------------------------------------------------------------------------------------------\n\n");
        printf("Tipo: %s\n",vecTipo[t].descripcion);
        printf("Id      Nombre         Tipo         Color          Edad\n");


        for(int m=0; m<cantMascota; m++)
        {
            if(vecMascota[m].estado==1&&vecMascota[m].idTipo==vecTipo[t].id)
            {
                mostrarMascota(vecMascota[m],vecColor,cantColor,vecTipo,cantTipo);
                flag=1;
            }
        }
    }

    if(flag==0)
    {
        printf("No hay mascotas para mostrar!!");
    }

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void listarCantidadMascotasColorYTipo(eMascota vecMascota[], int cantMascota, eTipo vecTipo[], int cantTipo, eColor vecColor[], int cantColor)
{
    int color;
    int tipo;
    int cantidad= 0;
    int flag = 0;


    printf("** Mascotas por color y tipo **\n");

    mostrarColores(vecColor,cantColor);
    color=validarEntero("ingrese color: ","color en numeros: ",5000,5004);

    mostrarTipos(vecTipo,cantTipo);
    tipo=validarEntero("ingrese Tipo : ","Tipo en numeros : ",1000,1004);

    for(int i=0; i<cantMascota; i++)
    {
        if(vecMascota[i].estado == 1 && vecMascota[i].idColor == color && vecMascota[i].idTipo == tipo)
        {
            cantidad++;
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No existen mascotas con el color y tipo elegidos\n");
    }
    else
    {
        printf("\n***Cantidad de mascotas con el color y tipo elegido: %d ***\n", cantidad);
        printf("  Id      Nombre         Tipo         Color          Edad\n");

        for(int i= 0; i<cantMascota; i++)
        {
            if(vecMascota[i].estado == 1 && vecMascota[i].idColor == color && vecMascota[i].idTipo == tipo)
            {
                mostrarMascota(vecMascota[i],vecColor,cantColor,vecTipo,cantTipo);
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void coloresConMasMascotas(eMascota vecMascota[], int cantMascota, eTipo vecTipo[], int cantTipo, eColor vecColor[], int cantColor)
{


    int totales[cantColor];
    int mayor;
    int flag = 0;

    for(int i=0; i < cantColor; i++)

    {

        totales[i] = 0;
        for(int j=0; j < cantMascota; j++)
        {
            if( vecColor[i].id == vecMascota[j].idColor && vecMascota[j].estado == 1)
            {
                totales[i]++;
            }
        }
    }

    for(int i=0; i < cantColor; i++)
    {
        if( flag == 0 || mayor < totales[i])
        {
            mayor = totales[i];
            flag = 1;
        }
    }

    printf("Cantidad mayor de mascotas %d\n\n", mayor);
    printf("En el o los siguientes colores\n\n");

    for(int i=0; i < cantColor; i++)
    {
        if( totales[i] == mayor)
        {
            printf("%s\n", vecColor[i].nombreColor);
        }

    }

}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int cargarDescripcionMascota(char descripcion[],int id,eMascota vecMascota[],int cantMascota)
{
    int todoOk=0;
    for(int i=0; i<cantMascota; i++)
    {
        if(vecMascota[i].id==id)
        {
            strcpy(descripcion,vecMascota[i].nombre);
            todoOk=1;
        }
    }

    return todoOk;

}





void mostrarTrabajosMascota(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio)
{

    int id;
    int flag=0;
    char descripcion[20];


    ordenarMascotasPorId(vecMascota,cantidadMascota);
    mostrarMascotas(vecMascota,cantidadMascota,vecColor,cantidadColor,vecTipo,cantidadTipo);

    id=validarEntero("Ingrese el id de la mascota: ","Id en numeros: ",100,1000);
    cargarDescripcionMascota(descripcion,id,vecMascota,cantidadMascota);



    if(encontrarMascotaPorId(vecMascota,cantidadMascota,id)== -1)
    {
        printf("la mascota no existe!!\n\n");

    }
    else
    {
        printf("  *** Listado de trabajos a mascota %s  ***\n\n",descripcion);

        printf("IdTrabajo   Mascota     Servicio    Precio    Fecha\n");

        for(int i=0; i <cantidadTrabajo; i++)
        {


            if(vecTrabajo[i].idMascota==id &&vecTrabajo[i].estado==1)
            {
                for(int j=0; j<cantidadServicio; j++)
                {
                    if( vecServicio[j].id== vecTrabajo[i].idServicio)
                    {
                        mostrarTrabajo(vecTrabajo[i],vecServicio,cantidadServicio,vecMascota,cantidadMascota);
                    }
                }

                flag = 1;
            }


        }

        if(flag == 0)
        {
            printf("La Mascota no presenta trabajos");
        }
        printf("\n\n");
    }

}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void importesDeMascota(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio)
{
    int id;
    int flag = 0;
    float total=0;
    char descripcion[20];


    ordenarMascotasPorId(vecMascota,cantidadMascota);
    mostrarMascotas(vecMascota,cantidadMascota,vecColor,cantidadColor,vecTipo,cantidadTipo);
    id=validarEntero("Ingrese id de la mascota : ","Id en numeros: ",100,1000);
    cargarDescripcionMascota(descripcion,id,vecMascota,cantidadMascota);

    if(encontrarMascotaPorId(vecMascota,cantidadMascota,id)== -1)
    {
        printf("La mascota  no existe!!\n\n");

    }
    else
    {
        printf("  *** Importe de trabajos a mascota %s\n\n",descripcion);

        for(int i=0; i <cantidadTrabajo; i++)
        {
            if(vecTrabajo[i].idMascota==id&& vecTrabajo[i].estado==1)
            {
                for(int j=0; j < cantidadServicio; j++)
                {
                    if( vecServicio[j].id == vecTrabajo[i].idServicio)
                    {
                        total+=vecServicio[j].precio;
                    }
                }
                flag = 1;
            }


        }

        if(flag == 0)
        {
            system("cls");
            printf("La mascota no presenta trabajos");
        }

        printf("               $%.2f\n ",total);
        printf("\n\n");
    }

}



//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int cargarDescripcionServicio(char descripcion[],int id,eServicio vecServicio[],int cantServicio)
{
    int todoOk=0;
    for(int i=0; i<cantServicio; i++)
    {
        if(vecServicio[i].id==id)
        {
            strcpy(descripcion,vecServicio[i].descripcion);
            todoOk=1;
        }
    }

    return todoOk;

}


void mostrarServiciosMascota(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio)
{

    int id;
    char descripcion[20];
    mostrarServicios(vecServicio,cantidadServicio);
    id=validarEntero("ingrese servicio: ","Servicio en numeros: ",20000,20002);
    cargarDescripcionServicio(descripcion,id,vecServicio,cantidadServicio);


    system("cls");
    printf("Servicio : %s\nNombre Mascota        Fecha\n",descripcion);

    for(int j=0; j < cantidadMascota; j++)
        {
            if( vecMascota[j].estado == 1)
            {
                for(int k=0;k<cantidadTrabajo;k++)
                {
                    if(vecTrabajo[k].idMascota==vecMascota[j].id&&vecTrabajo[k].estado==1&&vecTrabajo[k].idServicio==id)
                    {

                       printf("%s                  %d/%d/%d\n",vecMascota[j].nombre,vecTrabajo[k].Fecha.dia,vecTrabajo[k].Fecha.mes,vecTrabajo[k].Fecha.anio);

                    }
                }
            }

        }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void listarServiciosPorFechaDeterminada(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio)
{
    int dia;
    int mes;
    int anio;
    int flag = 0;


    dia=validarEntero("ingrese dia: ","dia en numeros: ",1,31);
    mes=validarEntero("ingrese mes: ","mes en numeros :",1,12);
    anio=validarEntero("ingrese anio: ","anio en numeros: ",1900,2020);

    printf("*** Servicios hechos por fecha seleccionada  %d/%d/%d  ***\n",dia,mes,anio);
    printf("IdTrabajo   Mascota       Servicio    Precio    Fecha\n");
    for(int i=0; i<cantidadTrabajo; i++)
    {
        if(vecTrabajo[i].estado == 1 && vecTrabajo[i].Fecha.anio == anio && vecTrabajo[i].Fecha.mes == mes && vecTrabajo[i].Fecha.dia == dia)
        {
            mostrarTrabajo(vecTrabajo[i],vecServicio,cantidadServicio,vecMascota,cantidadMascota);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        system("cls");
        printf("*** No hay trabajos que mostrar ***\n");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void informes(eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo,eTrabajo vecTrabajo[],int cantTrabajo,eServicio vecServicio[],int cantServicio)
{

    int opcion=0;

    while(opcion!=11)
    {
        system("cls");

        opcion=validarOpcion("\n\n*****INFORMES*****\n\n1 -Mostrar mascotas de un color seleccionado\n2 -Mostrar mascotas de un tipo seleccionado\n3 -Informar  mascotas de menor edad\n4 -Listar de las mascotas separadas por tipo\n5 -Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo \n6 -Mostrar el o los colores con mas cantidad de mascotas\n7 -Pedir una mascota y mostrar los trabajos realizados a la misma\n8 -Pedir una mascota y mostrar importes de sus servicios\n9 -Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.\n10 -Pedir servicios por fecha determinada\n11 -SALIR AL MENU ABM\n\n\n","Opcion incorrecta, reingrese opcion :", 1,11);
        switch(opcion)
        {

        case 1:
            system("cls");
            mascotaXColorIngresado(vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor);
            system("pause");
            break;

        case 2:
            system("cls");
            mascotaXTipoIngresado(vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor);
            system("pause");
            break;

        case 3:
            system("cls");
            listarMascotasMenorEdad(vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor);
            system("pause");
            break;

        case 4:
            system("cls");
            listarMascotasSeparadasPorTipos(vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor);
            system("pause");
            break;

        case 5:
            system("cls");
            listarCantidadMascotasColorYTipo(vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor);
            system("pause");
            break;

        case 6:
            system("cls");
            coloresConMasMascotas(vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor);
            system("pause");
            break;

        case 7:
            system("cls");
            mostrarTrabajosMascota(vecTrabajo,cantTrabajo,vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor,vecServicio,cantServicio);
            system("pause");
            break;

        case 8:
            system("cls");
            importesDeMascota(vecTrabajo,cantTrabajo,vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor,vecServicio,cantServicio);
            system("pause");
            break;

        case 9:
            system("cls");
            mostrarServiciosMascota(vecTrabajo,cantTrabajo,vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor,vecServicio,cantServicio);
            system("pause");
            break;

        case 10:
            system("cls");
            listarServiciosPorFechaDeterminada(vecTrabajo,cantTrabajo,vecMascota,cantMascota,vecTipo,cantTipo,vecColor,cantColor,vecServicio,cantServicio);
            system("pause");
            break;
        }

    }
}






