/*
 * CuidadosRequeridos.h
 * Estructura para almacenar requerimientos de mantenimiento
 * Proyecto: Sistema de Gestión de Plantas Premium (SGPP)
 * Vivero Encanto - Los Cabos
 */

#ifndef CUIDADOS_REQUERIDOS_H
#define CUIDADOS_REQUERIDOS_H

struct CuidadosRequeridos {
    char riego[100];
    char luz[100];
    char temperatura[50];
    char abonado[100];
};

#endif