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
 * @brief Cuenta la cantidad de bits en 1 (bits activos) de un entero de 32 bits.
 * 
 * @param[in] valor_entrada Entero sin signo a evaluar.
 * @return uint8_t Cantidad de bits en 1 presentes en el valor.
 */
static uint8_t contar_bits_en_uno(const uint32_t valor_entrada)
{
    uint32_t registro_temporal = valor_entrada;
    uint8_t contador_bits      = 0U;

    /* Algoritmo de Brian Kernighan: apaga el bit en 1 menos significativo en cada iteracion y todos los anteriores 0s pasan a unos, al hacer el and solo quedan los unos originales restantes */
    while (registro_temporal > 0U)
    {
        registro_temporal &= (registro_temporal - 1U);
        contador_bits++;
    }

    return contador_bits;
}

/**
 * @brief Imprime el valor y su conteo correspondiente de bits en 1.
 */
static void probar_conteo_bits(const uint32_t valor_prueba)
{
    const uint8_t cantidad_bits = contar_bits_en_uno(valor_prueba);
    (void)printf("Valor: 0x%08X (Decimal: %10u) -> Bits en 1: %u\n", 
                 valor_prueba, 
                 valor_prueba, 
                 cantidad_bits);
}

int main(void)
{
    (void)printf("--- Pruebas de Conteo de Bits (Hamming Weight) ---\n");

    /* Casos de prueba */
    probar_conteo_bits(0x00000000U); /* 0 bits */
    probar_conteo_bits(0x00000001U); /* 1 bit */
    probar_conteo_bits(0x00000007U); /* 3 bits (0111) */
    probar_conteo_bits(0xF000000FU); /* 8 bits (1111 ... 1111) */
    probar_conteo_bits(0xFFFFFFFFU); /* 32 bits */

    return EXIT_SUCCESS;
}