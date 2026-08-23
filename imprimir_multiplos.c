/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Imprime los primeros N múltiplos de un número dado.
 * 
 * @param[in] limite_multiplos Cantidad de múltiplos a generar.
 * @param[in] numero_base      Número del cual se calcularán los múltiplos.
 */
static void imprimir_multiplos(const uint32_t limite_multiplos,
                               const uint32_t numero_base)
{
    /* Barr indica declarar variables en el ámbito donde se usan */
    for (uint32_t i = 0U; i <= limite_multiplos; ++i)
    {
        const uint32_t multiplo_calculado = numero_base * i;
        (void)printf("Multiplo %u: %u\n", i, multiplo_calculado);
    }
}

int main(void)
{
    (void)printf("--- Pruebas de Calculo de Multiplos ---\n");

    /* Casos de prueba */
    imprimir_multiplos(10U, 3U);

    return EXIT_SUCCESS;
}