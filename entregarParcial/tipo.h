#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED



typedef struct{
    int id;
    char descripcion[20];


}eTipo;


#endif // TIPO_H_INCLUDED




/** \brief harcodea un tipo 
 *
 * \param vecTipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 
 *
 */     

void hardcodearTipo(eTipo vecTipo[],int cantTipo);

/** \brief muestra los tipos de mascotas
 *
 * \param vecTipo es el array de tipo
 * \param cantTipo es la cantidad de tipo
 *
 */     
void mostrarTipos(eTipo vecTipo[],int cantTipo);
