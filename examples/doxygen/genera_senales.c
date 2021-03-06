// genera_senales.c

/** @file
 * \brief Genera señales sintéticas para la prueba de la implementación del 
 * filtro FIR. Genera señales tipo escalón y tipo impulso.
*/

#include "genera_senales.h"

/** \fn step(sample_t *signal,int length,int t_up,sample_t amp)
 * \brief Genera una señal de tipo escalón.
 * \param *signal Puntero a un array de elementos de tipo sample_t,
 * donde se guardará la señal generada.
 * \param length Cantidad de muestras de la señal a generar (entero).
 * \param t_up Tiempo (número de muestra) en el cual sube el escalón. La salida
 * vale 0 antes de esa muestra, y <amp> a partir de esa muestra (entero).
 * \param amp Amplitud del escalón (tipo sample_t).
 * @return No tiene salida.
*/
void step(sample_t *signal,int length,int t_up,sample_t amp){
    int index;
    sample_t *psample = signal;
    for(index=0;index<length;index++){
        if (index<t_up){
            *psample = 0;
        } else {
            *psample = amp;
        }
        psample++;
    }
}

/** \fn impulse(sample_t *signal,int length)
 * \brief Genera una señal de tipo impulso.
 * \param *signal Puntero a un array de elementos de tipo sample_t,
 * donde se guardará la señal generada.
 * \param length Cantidad de muestras de la señal a generar (entero).
 * @return No tiene salida.
*/
void impulse(sample_t *signal,int length){
    sample_t *psample = signal;
    *psample = 1;
    psample++;
    int index;
    for(index=1;index<length;index++){
        *psample = 0;
        psample++;
    }
}