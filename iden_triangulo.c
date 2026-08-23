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
 * @brief Tipos de triángulos según la longitud de sus lados.
 */
typedef enum
{
    TRIANGULO_INVALIDO = 0,
    TRIANGULO_EQUILATERO,
    TRIANGULO_ISOSCELES,
    TRIANGULO_ESCALENO
} triangulo_tipo_t;

/**
 * @brief Evalúa si tres longitudes forman un triángulo válido.
 */
static bool es_triangulo_valido(const uint32_t lado_a, 
                                const uint32_t lado_b, 
                                const uint32_t lado_c)
{
    bool es_valido = false;

    if ((lado_a > 0U) && (lado_b > 0U) && (lado_c > 0U))
    {
        if (((lado_a + lado_b) > lado_c) &&
            ((lado_a + lado_c) > lado_b) &&
            ((lado_b + lado_c) > lado_a))
        {
            es_valido = true;
        }
    }

    return es_valido;
}

/**
 * @brief Determina el tipo de triángulo dados sus tres lados.
 */
triangulo_tipo_t determinar_tipo_triangulo(const uint32_t lado_a,
                                           const uint32_t lado_b,
                                           const uint32_t lado_c)
{
    triangulo_tipo_t resultado = TRIANGULO_INVALIDO;

    if (es_triangulo_valido(lado_a, lado_b, lado_c) == true)
    {
        if ((lado_a == lado_b) && (lado_b == lado_c))
        {
            resultado = TRIANGULO_EQUILATERO;
        }
        else if ((lado_a == lado_b) || (lado_a == lado_c) || (lado_b == lado_c))
        {
            resultado = TRIANGULO_ISOSCELES;
        }
        else
        {
            resultado = TRIANGULO_ESCALENO;
        }
    }

    return resultado;
}
static void imprimir_resultado(const uint32_t lado_a,
                               const uint32_t lado_b,
                               const uint32_t lado_c)
{
    const triangulo_tipo_t tipo = determinar_tipo_triangulo(lado_a, lado_b, lado_c);

    (void)printf("Lados: %u, %u, %u -> Resultado: ", lado_a, lado_b, lado_c);

    switch (tipo)
    {
        case TRIANGULO_EQUILATERO:
        {
            (void)printf("Equilatero\n");
            break;
        }
        case TRIANGULO_ISOSCELES:
        {
            (void)printf("Isosceles\n");
            break;
        }
        case TRIANGULO_ESCALENO:
        {
            (void)printf("Escaleno\n");
            break;
        }
        case TRIANGULO_INVALIDO:
        default:
        {
            (void)printf("Invalido\n");
            break;
        }
    }
}

int main(void)
{
    (void)printf("--- Pruebas de Clasificacion de Triangulos ---\n");

    /* Casos de prueba */
    imprimir_resultado(5U, 5U, 5U);   /* Equilátero */
    imprimir_resultado(5U, 5U, 3U);   /* Isósceles */
    imprimir_resultado(3U, 4U, 5U);   /* Escaleno */
    imprimir_resultado(1U, 2U, 10U);  /* Inválido (desigualdad) */
    imprimir_resultado(0U, 4U, 5U);   /* Inválido (lado cero) */

    return EXIT_SUCCESS;
}