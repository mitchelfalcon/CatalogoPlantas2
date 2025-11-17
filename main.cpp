/*
 * main.cpp
 * Programa Principal - Sistema de Gestión de Plantas Premium
 * Implementa operaciones CRUD con estructuras anidadas
 * Vivero Encanto - Los Cabos
 */

#include <iostream>
#include <cstring>
#include "ProductoPlanta.h"

using namespace std;

// Catálogo de plantas (array estático)
ProductoPlanta catalogo[100];
int totalPlantas = 0;

// Prototipos de funciones
void menu();
void altaPlanta();
void bajaPlanta();
void modificacionPlanta();
void consultaPlantas();
void inicializarDatos();

int main() {
    // Inicializar datos de ejemplo
    inicializarDatos();
    
    int opcion;
    do {
        menu();
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
            case 1:
                altaPlanta();
                break;
            case 2:
                bajaPlanta();
                break;
            case 3:
                modificacionPlanta();
                break;
            case 4:
                consultaPlantas();
                break;
            case 5:
                cout << "\n¡Gracias por usar SGPP!\n";
                break;
            default:
                cout << "\nOpción no válida\n";
        }
    } while(opcion != 5);
    
    return 0;
}

void menu() {
    cout << "\n+--------------------------------------------------+\n";
    cout << "| Sistema de Gestión de Plantas Premium (SGPP)   |\n";
    cout << "| Vivero Encanto - Los Cabos                      |\n";
    cout << "+--------------------------------------------------+\n";
    cout << "| 1. Alta de Planta                               |\n";
    cout << "| 2. Baja de Planta                               |\n";
    cout << "| 3. Modificación de Planta                       |\n";
    cout << "| 4. Consulta de Plantas                          |\n";
    cout << "| 5. Salir                                         |\n";
    cout << "+--------------------------------------------------+\n";
    cout << "Seleccione una opción [1-5]: ";
}

void altaPlanta() {
    if(totalPlantas >= 100) {
        cout << "\nCatálogo lleno\n";
        return;
    }
    
    ProductoPlanta nueva;
    
    cout << "\n--- ALTA DE PLANTA ---\n";
    cout << "ID de Producto: ";
    cin.getline(nueva.idProducto, 20);
    
    cout << "Categoría: ";
    cin.getline(nueva.categoria, 50);
    
    cout << "Precio: ";
    cin.getline(nueva.precio, 20);
    
    cout << "Stock: ";
    cin.getline(nueva.stock, 10);
    
    cout << "Estatus: ";
    cin.getline(nueva.estatus, 20);
    
    cout << "\n--- ESPECIE BOTÁNICA ---\n";
    cout << "Nombre Científico: ";
    cin.getline(nueva.especie.nombreCientifico, 100);
    
    cout << "Nombre Común: ";
    cin.getline(nueva.especie.nombreComun, 100);
    
    cout << "Familia: ";
    cin.getline(nueva.especie.familia, 50);
    
    cout << "Origen: ";
    cin.getline(nueva.especie.origen, 50);
    
    cout << "\n--- CUIDADOS REQUERIDOS ---\n";
    cout << "Riego: ";
    cin.getline(nueva.especie.cuidados.riegoMl, 50);
    
    cout << "Horas de Luz: ";
    cin.getline(nueva.especie.cuidados.horasLuz, 30);
    
    cout << "Temperatura: ";
    cin.getline(nueva.especie.cuidados.temperatura, 30);
    
    cout << "Humedad: ";
    cin.getline(nueva.especie.cuidados.humedad, 20);
    
    cout << "Fertilizante: ";
    cin.getline(nueva.especie.cuidados.fertilizante, 50);
    
    catalogo[totalPlantas] = nueva;
    totalPlantas++;
    
    cout << "\n✓ Planta registrada exitosamente\n";
}

void bajaPlanta() {
    char id[20];
    cout << "\n--- BAJA DE PLANTA ---\n";
    cout << "ID de Producto a eliminar: ";
    cin.getline(id, 20);
    
    for(int i = 0; i < totalPlantas; i++) {
        if(strcmp(catalogo[i].idProducto, id) == 0) {
            // Mostrar información
            cout << "\nPlanta encontrada: " << catalogo[i].especie.nombreComun << "\n";
            
            char confirma;
            cout << "¿Eliminar? (S/N): ";
            cin >> confirma;
            cin.ignore();
            
            if(confirma == 'S' || confirma == 's') {
                // Desplazar elementos
                for(int j = i; j < totalPlantas - 1; j++) {
                    catalogo[j] = catalogo[j + 1];
                }
                totalPlantas--;
                cout << "\n✓ Planta eliminada\n";
                return;
            }
        }
    }
    cout << "\nPlanta no encontrada\n";
}

void modificacionPlanta() {
    char id[20];
    cout << "\n--- MODIFICACIÓN DE PLANTA ---\n";
    cout << "ID de Producto: ";
    cin.getline(id, 20);
    
    for(int i = 0; i < totalPlantas; i++) {
        if(strcmp(catalogo[i].idProducto, id) == 0) {
            cout << "\nPlanta: " << catalogo[i].especie.nombreComun << "\n";
            cout << "1. Modificar Precio\n";
            cout << "2. Modificar Stock\n";
            cout << "3. Modificar Estatus\n";
            cout << "Opción: ";
            
            int op;
            cin >> op;
            cin.ignore();
            
            switch(op) {
                case 1:
                    cout << "Nuevo precio: ";
                    cin.getline(catalogo[i].precio, 20);
                    break;
                case 2:
                    cout << "Nuevo stock: ";
                    cin.getline(catalogo[i].stock, 10);
                    break;
                case 3:
                    cout << "Nuevo estatus: ";
                    cin.getline(catalogo[i].estatus, 20);
                    break;
            }
            cout << "\n✓ Modificación guardada\n";
            return;
        }
    }
    cout << "\nPlanta no encontrada\n";
}

void consultaPlantas() {
    cout << "\n--- CATÁLOGO DE PLANTAS ---\n";
    for(int i = 0; i < totalPlantas; i++) {
        cout << "\n[" << catalogo[i].idProducto << "] ";
        cout << catalogo[i].especie.nombreComun << "\n";
        cout << "  Precio: " << catalogo[i].precio;
        cout << " | Stock: " << catalogo[i].stock << "\n";
        cout << "  Riego: " << catalogo[i].especie.cuidados.riegoMl << "\n";
    }
}

void inicializarDatos() {
    // Planta 1
    strcpy(catalogo[0].idProducto, "P-001");
    strcpy(catalogo[0].categoria, "Suculenta Premium");
    strcpy(catalogo[0].precio, "$850");
    strcpy(catalogo[0].stock, "25");
    strcpy(catalogo[0].estatus, "Disponible");
    strcpy(catalogo[0].especie.nombreCientifico, "Echeveria elegans");
    strcpy(catalogo[0].especie.nombreComun, "Suculenta Rosa");
    strcpy(catalogo[0].especie.familia, "Crassulaceae");
    strcpy(catalogo[0].especie.origen, "México");
    strcpy(catalogo[0].especie.cuidados.riegoMl, "200ml semanal");
    strcpy(catalogo[0].especie.cuidados.horasLuz, "6-8 horas");
    strcpy(catalogo[0].especie.cuidados.temperatura, "18-24°C");
    strcpy(catalogo[0].especie.cuidados.humedad, "40-50%");
    strcpy(catalogo[0].especie.cuidados.fertilizante, "Mensual");
    
    totalPlantas = 1;
}