#include "combinatoria.h"
#include <stddef.h>

bool combinatoria_factorial(const uint32_t n, uint64_t * const p_resultado)
{
    bool estado_exito = false;

    if (p_resultado != NULL)
    {
        /* 20! es el máximo factorial que cabe en un uint64_t */
        if (n <= 20U)
        {
            uint64_t acumulador = 1U;

            for (uint32_t i = 1U; i <= n; ++i)
            {
                acumulador *= i;
            }

            *p_resultado = acumulador;
            estado_exito = true;
        }
    }

    return estado_exito;
}

bool combinatoria_permutacion(const uint32_t n, 
                              const uint32_t r, 
                              uint64_t * const p_resultado)
{
    bool estado_exito = false;

    if ((p_resultado != NULL) && (r <= n))
    {
        uint64_t fact_n = 0U;
        uint64_t fact_n_r = 0U;

        if ((combinatoria_factorial(n, &fact_n) == true) &&
            (combinatoria_factorial((n - r), &fact_n_r) == true))
        {
            *p_resultado = fact_n / fact_n_r;
            estado_exito = true;
        }
    }

    return estado_exito;
}

bool combinatoria_combinacion(const uint32_t n, 
                              const uint32_t r, 
                              uint64_t * const p_resultado)
{
    bool estado_exito = false;

    if ((p_resultado != NULL) && (r <= n))
    {
        uint64_t perm_n_r = 0U;
        uint64_t fact_r = 0U;

        if ((combinatoria_permutacion(n, r, &perm_n_r) == true) &&
            (combinatoria_factorial(r, &fact_r) == true))
        {
            *p_resultado = perm_n_r / fact_r;
            estado_exito = true;
        }
    }

    return estado_exito;
}