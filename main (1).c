#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "cola_circular.h"

int main(void)
{
    cola_circular_t mi_cola;
    int32_t dato_extraido = 0;

    (void)printf("--- Prueba de Cola Circular (Barr Group Style) ---\n");

    if (cola_inicializar(&mi_cola) == true)
    {
        (void)printf("Vacia: %s | Llenos: %u | Libres: %u\n",
                     cola_esta_vacia(&mi_cola) ? "Si" : "No",
                     cola_obtener_cantidad(&mi_cola),
                     cola_obtener_espacio_libre(&mi_cola));

        /* Insertar 5 datos */
        for (int32_t i = 1; i <= 5; ++i)
        {
            (void)cola_poner_dato(&mi_cola, i * 10);
        }
        cola_mostrar_contenido(&mi_cola);

        /* Sacar 2 datos */
        if (cola_sacar_dato(&mi_cola, &dato_extraido) == true)
        {
            (void)printf("Dato sacado: %d\n", dato_extraido);
        }
        if (cola_sacar_dato(&mi_cola, &dato_extraido) == true)
        {
            (void)printf("Dato sacado: %d\n", dato_extraido);
        }
        cola_mostrar_contenido(&mi_cola);

        /* Llenar la cola hasta el limite para probar envolvimiento */
        (void)printf("\nLlenando la cola al maximo...\n");
        for (int32_t i = 1; i <= 8; ++i)
        {
            (void)cola_poner_dato(&mi_cola, i * 100);
        }
        cola_mostrar_contenido(&mi_cola);

        (void)printf("Llena: %s | Llenos: %u | Libres: %u\n",
                     cola_esta_llena(&mi_cola) ? "Si" : "No",
                     cola_obtener_cantidad(&mi_cola),
                     cola_obtener_espacio_libre(&mi_cola));
    }

    return EXIT_SUCCESS;
}