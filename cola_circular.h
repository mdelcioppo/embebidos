#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Capacidad máxima de la cola circular.
 */
#define COLA_CAPACIDAD (10U)

/**
 * @brief Estructura que representa el estado de la cola circular.
 */
typedef struct
{
    int32_t buffer[COLA_CAPACIDAD];
    uint32_t indice_cabeza;  /* Apunta a la posicion del proximo elemento a sacar (Pop) */
    uint32_t indice_cola;    /* Apunta a la posicion donde se insertara el dato (Push) */
    uint32_t cantidad;       /* Elementos actualmente en la cola */
} cola_circular_t;

/**
 * @brief Inicializa la cola circular reseteando sus indices y contador.
 */
bool cola_inicializar(cola_circular_t * const p_cola);

/**
 * @brief Agrega un entero a la cola.
 */
bool cola_poner_dato(cola_circular_t * const p_cola, const int32_t dato);

/**
 * @brief Remueve y devuelve el entero mas antiguo de la cola.
 */
bool cola_sacar_dato(cola_circular_t * const p_cola, int32_t * const p_dato);

/**
 * @brief Devuelve la cantidad de datos almacenados actualmente.
 */
uint32_t cola_obtener_cantidad(const cola_circular_t * const p_cola);

/**
 * @brief Devuelve la cantidad de espacios disponibles.
 */
uint32_t cola_obtener_espacio_libre(const cola_circular_t * const p_cola);

/**
 * @brief Verfica si la cola esta llena.
 */
bool cola_esta_llena(const cola_circular_t * const p_cola);

/**
 * @brief Verifica si la cola esta vacia.
 */
bool cola_esta_vacia(const cola_circular_t * const p_cola);

/**
 * @brief Muestra el contenido de la cola en orden de llegada por consola.
 */
void cola_mostrar_contenido(const cola_circular_t * const p_cola);

#endif /* COLA_CIRCULAR_H */