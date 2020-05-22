


#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED



#endif // TRABAJO_H_INCLUDED


/** \brief hardcodea los trabajos
 *
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo

 *
 */

void hardcodearTrabajos(eTrabajo vecTrabajo[],int cantTrabajo);



/** \brief setea el estado de trabajo
 *
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param valor es el valor a asignarle

 *
 */

void setearTrabajo(eTrabajo vecTrabajo[],int cantTrabajo,int valor);


/** \brief encuentraun lugar libre en el array
 *
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \return devuelve -1 si no encontro o el indice si lo encontro
 */

int encontrarLugarLibreTrabajo(eTrabajo vecTrabajo[],int cantTrabajo);


/** \brief encuentra a un trabajo por el id
 *
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param id es el id a buscar
 *
 */

int encontrarTrabajoPorId(eTrabajo vecTrabajo[],int cantTrabajo,int id);



/** \brief muetra un trabajo
 *
 * \param trab es un trabajo
 * \param VecServicio es el array de servicio
 * \param cantServicio es la cantidad de servicio
 * \param vecMascota es el array de mascota
 * \param cantMascota es la cantidad de mascota

 *
 */

void mostrarTrabajo(eTrabajo trab,eServicio VecServicio[],int cantServicio,eMascota vecMascota[],int cantMascota);



/** \brief muetra todos los trabajo
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param VecServicio es el array de servicio
 * \param cantServicio es la cantidad de servicio
 * \param vecMascota es el array de mascota
 * \param cantMascota es la cantidad de mascota
 *
 */

void mostrarTrabajos(eTrabajo vecTrabajo[],int cantTrabajo,eServicio vecServicio[],int cantServicio,eMascota vecMascota[],int cantMascota);



/** \brief da de alta un trabajo
 *
 * \param vecTrabajo es el array de trabajo
 * \param cantTrabajo es la cantidad de trabajo
 * \param VecServicio es el array de servicio
 * \param cantServicio es la cantidad de servicio
 * \param vecMascota es el array de mascota
 * \param cantMascota es la cantidad de mascota
  * \param vecColor es el array de color
 * \param cantColor es la cantidad de color
  * \return devuelve 1 si se pudo dar de alta, 0 si no se pudo

 *
 */

int altaTrabajo(int lastId,eTrabajo vecTrabajo[],int cantTrabajo,eMascota vecMascota[],int cantMascota,eServicio vecServicio[],int cantServicio,eTipo vecTipo[],int cantTipo,eColor vecColor[],int cantColor);
void ordenarMascotasPorId(eMascota vecMascota[],int cantMascota);
