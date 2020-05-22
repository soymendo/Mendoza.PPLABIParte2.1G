#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED



typedef struct{
    int id;
    char descripcion[25];
    float precio;

}eServicio;
#endif // SERVICIO_H_INCLUDED







/** \brief hardcodea los servicios
 *
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de servicio

 *
 */

void harcdocdearServicios(eServicio vecServicio[],int cantServicio);


/** \brief muestra los servicios
 *
 * \param vecServicio es el array de servicio
 * \param cantServicio es la cantidad de servicio
 *
 */

void mostrarServicios(eServicio vecServicio[],int cantServicio);
