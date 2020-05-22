


#include "mascota.h"
#include "trabajo.h"


#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief Menu de informes
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de Servicio
 *
 */


void informes(eMascota vecMascota[],int cantMascota,eColor vecColor[],int cantColor,eTipo vecTipo[],int cantTipo,eTrabajo vecTrabajo[],int cantTrabajo,eServicio vecServicio[],int cantServicio);




/** \brief Muestra a las mascotas del color seleccionado por el usuario.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */


void mascotaXColorIngresado(eMascota vecMascota[],int cantidadMascota, eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor);



/** \brief Muestra a  las mascotas de un tipo seleccionado.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */
void mascotaXTipoIngresado(eMascota arrayMascota[],int cantidadMascota, eTipo arrayTipo[], int cantidadTipo,eColor arrayColor[],int cantidadColor);


/** \brief Informa la o las mascotas de menor edad.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */
void listarMascotasMenorEdad(eMascota vecMascota[], int cantMascota, eTipo vecTipos[], int cantTipos, eColor vecColor[], int cantColor);


/** \brief Lista de las mascotas separadas por tipo.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */
void listarMascotasSeparadasPorTipos(eMascota vecMascota[], int cantMascota, eTipo vecTipo[], int cantTipo, eColor vecColor[], int cantColor);


/** \brief Elige un color y un tipo y cuentar cuantas mascotas hay de ese color y ese tipo.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */
void listarCantidadMascotasColorYTipo(eMascota vecMascota[], int cantMascota, eTipo vecTipo[], int cantTipo, eColor vecColor[], int cantColor);


/** \brief Muestra el o los colores con mas cantidad de mascotas
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */
void coloresConMasMascotas(eMascota vecMascota[], int cantMascota, eTipo vecTipo[], int cantTipo, eColor vecColor[], int cantColor);


/** \brief Pide una mascota y muestra todos los trabajos que se le hicieron a la misma.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de Servicio
 *
 */


void mostrarTrabajosMascota(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio);
int cargarDescripcionMascota(char descripcion[],int id,eMascota vecMascota[],int cantMascota);


/** \brief Pide una mascota e informa la suma de los importes de los servicios que se le hicieron a la misma.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de Servicio
 *
 */
void importesDeMascota(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio);


/** \brief Pide un servicio y muestra las mascotas a las que se les realizo ese servicio y la fecha.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de Servicio
 *
 */
void mostrarServiciosMascota(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio);
int cargarDescripcionServicio(char descripcion[],int id,eServicio vecServicio[],int cantServicio);


/** \brief Pide una fecha y muestra todos los servicios realizados en la misma.
 *
 *
 * \param vecMascota es el array de mascotas
 * \param cantMascota es la cantidad de mascotas
 * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
 * \param vectipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de Servicio
 *
 */
void listarServiciosPorFechaDeterminada(eTrabajo vecTrabajo[], int cantidadTrabajo, eMascota vecMascota[], int cantidadMascota,eTipo vecTipo[], int cantidadTipo,eColor vecColor[],int cantidadColor,eServicio vecServicio[],int cantidadServicio);




