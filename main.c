#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "combinatoria.h"

int main(void)
{
    const uint32_t n = 5U;
    const uint32_t r = 3U;
    uint64_t resultado = 0U;

    (void)printf("--- Pruebas de Libreria de Combinatoria ---\n");

    if (combinatoria_factorial(n, &resultado) == true)
    {
        (void)printf("Factorial (%u!): %lu\n", n, resultado);
    }

    if (combinatoria_permutacion(n, r, &resultado) == true)
    {
        (void)printf("Permutaciones P(%u, %u): %lu\n", n, r, resultado);
    }

    if (combinatoria_combinacion(n, r, &resultado) == true)
    {
        (void)printf("Combinaciones C(%u, %u): %lu\n", n, r, resultado);
    }

    return EXIT_SUCCESS;
}