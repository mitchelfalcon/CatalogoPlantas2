/*
 * ProductoPlanta.h
 * Estructura principal del catálogo
 * ANIDA: EspecieBotanica (que a su vez anida CuidadosRequeridos)
 * Proyecto: Sistema de Gestión de Plantas Premium (SGPP)
 * Vivero Encanto - Los Cabos
 */

#ifndef PRODUCTO_PLANTA_H
#define PRODUCTO_PLANTA_H

#include "EspecieBotanica.h"

struct ProductoPlanta {
    char idProducto[20];     // Ej: "P-001"
    char categoria[50];      // Ej: "Suculenta Premium"
    char precio[20];         // Ej: "$850"
    char stock[10];          // Ej: "25"
    char estatus[20];        // Ej: "Disponible"
    
    // ANIDACIÓN: Estructura de nivel medio
    EspecieBotanica especie;
};

#endif