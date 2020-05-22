#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED




typedef struct{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED


/** \brief harcodea los colores
 *
 * \param vecColor es el array de colore
 * \param cantColor es la cantidad de colores

 *
 */

void hardcodearColor(eColor vecColor[],int cantColor);


/** \brief muestra los colores
 *
 * \param vecColor es el array de colore
 * \param cantColor es la cantidad de colores

 *
 */

void mostrarColores(eColor vecColor[],int cantColor);
