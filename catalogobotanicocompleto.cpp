#include <iostream>
#include <string>
#include <vector> // Usamos vector para un manejo de datos más flexible que un array estático
#include <limits> // Para limpiar el buffer de entrada (cin)

// Usar std para no tener que escribir std:: en todos lados
using namespace std;

/**
 * @struct ParametrosCuidado
 * @brief Almacena los rangos óptimos de cuidado para una planta.
 * Es una estructura "novedosa" porque anida parámetros complejos.
 */
struct ParametrosCuidado {  
    // Humedad del suelo en porcentaje (ej. 30-50%)
    int humedadMin;
    int humedadMax;

    // Temperatura ambiente en grados Celsius (ej. 18-25C)
    int tempMin;
    int tempMax;

    // Horas de luz directa por día (ej. 4-6h)
    int luzMin;
    int luzMax;
};

/**
 * @struct Planta
 * @brief Estructura principal que define una planta en el catálogo.
 * Contiene información básica y la estructura anidada de parámetros.
 */
struct Planta {
    int id; // Identificador único
    string nombreComun;
    string nombreCientifico;
    ParametrosCuidado cuidados; // Estructura anidada
};

// ---- Base de Datos (Temporal en Memoria) ----
// Un vector global que actuará como nuestro catálogo (base de datos)
vector<Planta> catalogo;

// ---- Prototipos de Funciones ----
// Estos son los requerimientos para Etapas 2 y 3, los definimos aquí.

/**
 * @brief Muestra el menú principal de la aplicación.
 */
void mostrarMenu();

/**
 * @brief Función para dar de alta (agregar) una nueva planta al catálogo.
 * (Corresponde a Etapa 2)
 */
void altaPlanta();

/**
 * @brief Función para dar de baja (eliminar) una planta por su ID.
 * (Corresponde a Etapa 2)
 */
void bajaPlanta();

/**
 * @brief Función para modificar los datos de una planta existente por su ID.
 * (Corresponde a Etapa 3)
 */
void modificarPlanta();

/**
 * @brief Función para consultar (mostrar) todas las plantas del catálogo.
 * (Corresponde a Etapa 3)
 */
void consultarCatalogo();

/**
 * @brief Función para buscar una planta específica (por nombre o ID).
 * (Corresponde a Etapa 3)
 */
void buscarPlanta();

/**
 * @brief Limpia la pantalla de la consola (simulación).
 */
void limpiarPantalla() {
    // Simulación simple para mantener la consola limpia
    // En Windows se usaría system("cls"), en Linux/Mac system("clear")
    // Por portabilidad, solo imprimimos líneas nuevas.
    cout << string(50, '\n');
}

/**
 * @brief Pausa la ejecución hasta que el usuario presione Enter.
 */
void pausarConsola() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia buffer
    cin.get(); // Espera a que el usuario presione Enter
}

// ---- Función Principal (main) ----
int main() {
    // Llama al menú principal para iniciar el bucle de la aplicación
    mostrarMenu();
    return 0;
}

// ---- Implementación de Funciones ----

void mostrarMenu() {
    int opcion = -1;

    while (opcion != 0) {
        limpiarPantalla();
        cout << "+------------------------------------------+" << endl;
        cout << "|      CATÁLOGO BOTÁNICO INTELIGENTE       |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "|                                          |" << endl;
        cout << "|  Seleccione una opción:                  |" << endl;
        cout << "|                                          |" << endl;
        cout << "|  1. Alta de Nueva Planta                 |" << endl;
        cout << "|  2. Baja de Planta (por ID)              |" << endl;
        cout << "|  3. Modificar Datos de Planta (por ID)   |" << endl;
        cout << "|  4. Consultar Catálogo Completo          |" << endl;
        cout << "|  5. Buscar Planta Específica             |" << endl;
        cout << "|                                          |" << endl;
        cout << "|  0. Salir                                |" << endl;
        cout << "|                                          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "> ";

        // Validar entrada numérica
        while (!(cin >> opcion)) {
            cout << "Opción no válida. Por favor, ingrese un número." << endl;
            cin.clear(); // Limpia el flag de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << "> ";
        }
        
        // Limpiar el buffer después de leer el número
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (opcion) {
            case 1:
                altaPlanta();
                break;
            case 2:
                bajaPlanta();
                break;
            case 3:
                modificarPlanta();
                break;
            case 4:
                consultarCatalogo();
                break;
            case 5:
                buscarPlanta();
                break;
            case 0:
                cout << "\nSaliendo del programa. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "\nOpción no válida. Inténtelo de nuevo." << endl;
                pausarConsola();
                break;
        }
    }
}

// --- Implementaciones de Etapa 1 (Conceptos) ---
// Dejamos las funciones de Etapa 2 y 3 como "stubs" (pendientes)
// pero implementamos Alta y Consulta para demostrar el prototipo.

void altaPlanta() {
    limpiarPantalla();
    cout << "+------------------------------------------+" << endl;
    cout << "|            ALTA DE NUEVA PLANTA          |" << endl;
    cout << "+------------------------------------------+" << endl;

    Planta nuevaPlanta; // Crea una instancia temporal de la estructura

    cout << "Ingrese el ID único (ej. 101): ";
    while (!(cin >> nuevaPlanta.id)) {
        cout << "Entrada inválida. Ingrese un número para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

    cout << "Ingrese el Nombre Común: ";
    getline(cin, nuevaPlanta.nombreComun); // Lee la línea completa (permite espacios)

    cout << "Ingrese la Especie (Científico): ";
    getline(cin, nuevaPlanta.nombreCientifico);

    cout << "\n--- Parámetros de Cuidado ---" << endl;
    cout << "Humedad Suelo (MIN %): ";
    cin >> nuevaPlanta.cuidados.humedadMin;
    cout << "Humedad Suelo (MAX %): ";
    cin >> nuevaPlanta.cuidados.humedadMax;

    cout << "Temperatura (MIN C): ";
    cin >> nuevaPlanta.cuidados.tempMin;
    cout << "Temperatura (MAX C): ";
    cin >> nuevaPlanta.cuidados.tempMax;

    cout << "Horas de Luz (MIN): ";
    cin >> nuevaPlanta.cuidados.luzMin;
    cout << "Horas de Luz (MAX): ";
    cin >> nuevaPlanta.cuidados.luzMax;

    // Añadir la nueva planta al vector (nuestra "base de datos")
    catalogo.push_back(nuevaPlanta);

    cout << "\n...Planta \"" << nuevaPlanta.nombreComun << "\" [ID: " << nuevaPlanta.id << "] guardada exitosamente." << endl;
    pausarConsola();
}

void consultarCatalogo() {
    limpiarPantalla();
    cout << "+------------------------------------------+" << endl;
    cout << "|          CATÁLOGO DE PLANTAS (" << catalogo.size() << ")         |" << endl;
    cout << "+------------------------------------------+" << endl;

    if (catalogo.empty()) {
        cout << "\nEl catálogo está vacío. Agregue plantas primero." << endl;
    } else {
        // Iterar sobre el vector y mostrar cada planta
        for (const Planta& p : catalogo) {
            cout << "\n[ID: " << p.id << "] " << p.nombreComun << " (" << p.nombreCientifico << ")" << endl;
            cout << "    - Humedad: " << p.cuidados.humedadMin << "-" << p.cuidados.humedadMax << "%" << endl;
            cout << "    - Temp:    " << p.cuidados.tempMin << "-" << p.cuidados.tempMax << "C" << endl;
            cout << "    - Luz:     " << p.cuidados.luzMin << "-" << p.cuidados.luzMax << "h" << endl;
        }
        cout << "\n...Fin del catálogo." << endl;
    }

    pausarConsola();
}

// --- Stubs (Pendientes) para Etapas Futuras ---

void bajaPlanta() {
    limpiarPantalla();
    cout << "+------------------------------------------+" << endl;
    cout << "|             BAJA DE PLANTA             |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "\nFunción de BAJA (Etapa 2) aún no implementada." << endl;
    // Aquí iría la lógica para pedir un ID y eliminarlo del vector `catalogo`
    pausarConsola();
}

void modificarPlanta() {
    limpiarPantalla();
    cout << "+------------------------------------------+" << endl;
    cout << "|          MODIFICACIÓN DE PLANTA          |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "\nFunción de MODIFICAR (Etapa 3) aún no implementada." << endl;
    // Aquí iría la lógica para pedir un ID, buscarlo, y sobreescribir sus datos
    pausarConsola();
}

void buscarPlanta() {
    limpiarPantalla();
    cout << "+------------------------------------------+" << endl;
    cout << "|            BÚSQUEDA DE PLANTA            |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "\nFunción de BÚSQUEDA (Etapa 3) aún no implementada." << endl;
    // Aquí iría la lógica para pedir un nombre o ID y mostrar solo esa planta
    pausarConsola();
}
````````

g++ -std=c++17 -Wall -Wextra -O2 -o catalogo catalogobotanicocompleto.cpp
./catalogo