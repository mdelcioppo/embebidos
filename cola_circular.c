#include "cola_circular.h"
#include <stdio.h>
#include <stddef.h>

bool cola_inicializar(cola_circular_t * const p_cola)
{
    bool estado_exito = false;

    if (p_cola != NULL)
    {
        p_cola->indice_cabeza = 0U;
        p_cola->indice_cola   = 0U;
        p_cola->cantidad        = 0U;

        for (uint32_t i = 0U; i < COLA_CAPACIDAD; ++i)
        {
            p_cola->buffer[i] = 0;
        }

        estado_exito = true;
    }

    return estado_exito;
}

bool cola_esta_vacia(const cola_circular_t * const p_cola)
{
    bool esta_vacia = true;

    if (p_cola != NULL)
    {
        esta_vacia = (p_cola->cantidad == 0U);
    }

    return esta_vacia;
}

bool cola_esta_llena(const cola_circular_t * const p_cola)
{
    bool esta_llena = false;

    if (p_cola != NULL)
    {
        esta_llena = (p_cola->cantidad == COLA_CAPACIDAD);
    }

    return esta_llena;
}

uint32_t cola_obtener_cantidad(const cola_circular_t * const p_cola)
{
    uint32_t cantidad = 0U;

    if (p_cola != NULL)
    {
        cantidad = p_cola->cantidad;
    }

    return cantidad;
}

uint32_t cola_obtener_espacio_libre(const cola_circular_t * const p_cola)
{
    uint32_t espacio_libre = 0U;

    if (p_cola != NULL)
    {
        espacio_libre = COLA_CAPACIDAD - p_cola->cantidad;
    }

    return espacio_libre;
}

bool cola_poner_dato(cola_circular_t * const p_cola, const int32_t dato)
{
    bool estado_exito = false;

    if ((p_cola != NULL) && (cola_esta_llena(p_cola) == false))
    {
        p_cola->buffer[p_cola->indice_cola] = dato;
        p_cola->indice_cola = (p_cola->indice_cola + 1U) % COLA_CAPACIDAD;
        p_cola->cantidad++;

        estado_exito = true;
    }

    return estado_exito;
}

bool cola_sacar_dato(cola_circular_t * const p_cola, int32_t * const p_dato)
{
    bool estado_exito = false;

    if ((p_cola != NULL) && (p_dato != NULL) && (cola_esta_vacia(p_cola) == false))
    {
        *p_dato = p_cola->buffer[p_cola->indice_cabeza];
        p_cola->indice_cabeza = (p_cola->indice_cabeza + 1U) % COLA_CAPACIDAD;
        p_cola->cantidad--;

        estado_exito = true;
    }

    return estado_exito;
}

void cola_mostrar_contenido(const cola_circular_t * const p_cola)
{
    if (p_cola != NULL)
    {
        (void)printf("Contenido Cola (%u/%u): [ ", p_cola->cantidad, COLA_CAPACIDAD);

        if (cola_esta_vacia(p_cola) == false)
        {
            uint32_t idx = p_cola->indice_cabeza;

            for (uint32_t i = 0U; i < p_cola->cantidad; ++i)
            {
                (void)printf("%d ", p_cola->buffer[idx]);
                idx = (idx + 1U) % COLA_CAPACIDAD;
            }
        }

        (void)printf("]\n");
    }
}