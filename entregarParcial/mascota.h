#include "tipo.h"
#include "color.h"
#include "servicio.h"



#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED


typedef struct{
    int dia;
    int mes;
    int anio;

}eFecha;



typedef struct{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int estado;

}eMascota;




typedef struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha Fecha;
    int estado;



}eTrabajo;





#endif // MASCOTA_H_INCLUDED


/** \brief harcodea las mascotas
 *
 * \param vecMAscota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \return
 *
 */

void hardcodearMascotas(eMascota vecMascota[],int cantMascota);




/** \brief setea el estado de mascota
 *
 * \param vecMascota es el array de mascota
 * \param cantMascota es la cantidad de mascotas
* \param        valor es el valor a asignarle
 * \return
 *
 */

void setearMascota(eMascota vecMascota[],int cantMascota,int valor);



/** \brief Encuentra el lugar libre en el array
 *
 * \param vecMascota es el array de mascota
 * \param cantMascota es la cantidad de mascotas
 * \return
 *
 */

int encontrarLugarLibreMascota(eMascota vecMascota[],int cantMascota);


/** \brief Encuentra a mascota por id
 *
 * \param vecMascota es el array de mascota
 * \param cantMascota es la cantidad de mascotas
  * \param id  es el id a encontrar
 * \return devuelve -1 si no encontro o el indice si lo encontro
 *
 */

int encontrarMascotaPorId(eMascota vecMascota[],int cantMascota,int id);


/** \brief muestra una mascota
 *
 * \param aut es una mascota
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo

 * \return devuelve el indice encontrado
 *
 */

void mostrarMascota(eMascota aut,eColor vecColor[],int cantColor,eTipo VecTipo[],int cantTipo);


/** \brief muestra todas las mascotas
 *
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param vecMAscota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 *
 */

void mostrarMascotas(eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo);


/** \brief Da de alta a una mascota
 *
 * \param vecMAscota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param lastId asigna el id de la mascota
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \return devuelve 1 si se pudo dar de alta, 0 si no se pudo
 *
 */

int altaMascota(int lastId,eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo);



/** \brief da de baja una mascota
 *
 * \param vecMAscota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
* \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */

void bajaMascota(eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo);


/** \brief modifica una mascota
 *
 *
 * \param vecMAscota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 *
 */

void modificacionMascota(eMascota vecMascota[],int cantMascota,eTipo vecTipo[],int cantTipo,eColor vecColor[],int cantColor);





/** \brief carga la descripcion de una cadena de caracteres
 *
  * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param char cadena es la cadena a cargar
 * \param
 *
 */

void cargarDescripcionTipo(eTipo vecTipo[],int cantTipo, int idTipo, char cadena[]);



/** \brief ordena a las mascotas
 *
 * \param vecMAscota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
  * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */

void ordenarMascotas(eMascota vecMascota[],int cantMascota,eTipo vecTipo[],int cantTipo);
