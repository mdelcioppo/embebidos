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
 * @brief Enciende (pone en 1) un bit especifico dentro de un entero de 32 bits
 *        e imprime el resultado.
 * 
 * @param[in] entero   Valor de entrada de 32 bits.
 * @param[in] posicion Posicion del bit a encender (0 a 31).
 */
static void poner_en_uno(const uint32_t entero, const uint32_t posicion)
{
    /* Barr Group: validar precondiciones antes de operar */
    if (posicion < 32U)
    {
        /* 1. Armar la mascara con un 1 en la posicion deseada */
        const uint32_t mascara = (uint32_t)(1U << posicion);
        
        /* 2. Aplicar el OR bit a bit para encender el bit */
        const uint32_t modificado = entero | mascara;
        
        /* 3. Imprimir el valor resultante en formato Hexadecimal (32-bit) y Decimal */
        (void)printf("Original: 0x%08X | Bit %2u en 1 -> Resultado: 0x%08X (Dec: %u)\n",
                     entero,
                     posicion,
                     modificado,
                     modificado);
    }
    else
    {
        (void)printf("Error: La posicion %u esta fuera del rango (0-31).\n", posicion);
    }
}

int main(void)
{
    (void)printf("--- Pruebas de Modificacion de Bits ---\n");

    /* Casos de prueba */
    poner_en_uno(0x00000000U, 0U);   /* Encender bit LSB (0) */
    poner_en_uno(0x00000000U, 4U);   /* Encender bit 4 -> 0x00000010 */
    poner_en_uno(0x00000000U, 31U);  /* Encender bit MSB (31) */
    poner_en_uno(0x12345678U, 0U);   /* Mantener otros bits intactos */

    return EXIT_SUCCESS;
}