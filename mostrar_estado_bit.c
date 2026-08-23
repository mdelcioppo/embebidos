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
 * @brief Cantidad de bits en un byte de ancho fijo de 8 bits.
 */
#define BITS_POR_BYTE (8U)

/**
 * @brief Imprime la representación binaria (8 bits) de un byte.
 * 
 * @param[in] byte_entrada Byte a inspeccionar.
 */
static void mostrar_bits_byte(const uint8_t byte_entrada)
{
    /* Recorrido desde el bit MSB (7) hasta el LSB (0) */
    for (int8_t i = (int8_t)(BITS_POR_BYTE - 1U); i >= 0; --i)
    {
        const uint8_t mascara = (uint8_t)(1U << (uint8_t)i); /* armo mascara de manera tal de tener 1 en posicion i*/
        
        if ((byte_entrada & mascara) != 0U)
        {
            (void)printf("1");
        }
        else
        {
            (void)printf("0");
        }
    }

    (void)printf("\n");
}

/**
 * @brief Prueba la impresión de bits para un byte dado, mostrando su valor HEX y DEC.
 */
static void probar_mostrar_byte(const uint8_t byte_prueba)
{
    (void)printf("Byte: 0x%02X (Decimal: %3u) -> Binario: ", byte_prueba, byte_prueba);
    mostrar_bits_byte(byte_prueba);
}

int main(void)
{
    (void)printf("--- Representacion de Bits de un Byte ---\n");

    /* Casos de prueba */
    probar_mostrar_byte(0x00U); /* 00000000 */
    probar_mostrar_byte(0x01U); /* 00000001 */
    probar_mostrar_byte(0xAAU); /* 10101010 */
    probar_mostrar_byte(0x55U); /* 01010101 */
    probar_mostrar_byte(0xFFU); /* 11111111 */

    return EXIT_SUCCESS;
}