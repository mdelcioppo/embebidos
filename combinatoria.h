#ifndef COMBINATORIA_H
#define COMBINATORIA_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Calcula el factorial de un número entero no negativo.
 * 
 * @param[in]  n             Número n.
 * @param[out] p_resultado   Puntero al resultado almacenado.
 * @return true Si el cálculo fue exitoso (sin desbordamiento).
 * @return false Si p_resultado es NULL o ocurrió desbordamiento (overflow).
 */
bool combinatoria_factorial(const uint32_t n, uint64_t * const p_resultado);

/**
 * @brief Calcula las permutaciones de n elementos tomados de r en r (nPr).
 */
bool combinatoria_permutacion(const uint32_t n, 
                              const uint32_t r, 
                              uint64_t * const p_resultado);

/**
 * @brief Calcula las combinaciones de n elementos tomados de r en r (nCr).
 */
bool combinatoria_combinacion(const uint32_t n, 
                              const uint32_t r, 
                              uint64_t * const p_resultado);

#endif /* COMBINATORIA_H */