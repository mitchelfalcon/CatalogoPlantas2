/*
 * EspecieBotanica.h
 * Estructura para información científica de la planta
 * ANIDA: CuidadosRequeridos
 * Proyecto: Sistema de Gestión de Plantas Premium (SGPP)
 * Vivero Encanto - Los Cabos
 */

#ifndef ESPECIE_BOTANICA_H
#define ESPECIE_BOTANICA_H

#include "CuidadosRequeridos.h"

struct EspecieBotanica { 
    char nombreCientifico[100];
    char nombreComun[100];
    char familia[50];
    char origen[50];
    // ANIDACIÓN: Estructura de nivel inferior
    CuidadosRequeridos cuidados;
};

#endif