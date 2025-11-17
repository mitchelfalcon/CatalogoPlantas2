# 🌿 Sistema de Gestión de Plantas Premium (SGPP)

**Vivero Encanto - Los Cabos**

## 📋 Descripción

Sistema de gestión de inventario botánico con interfaz web moderna y backend en C++ que implementa estructuras de datos anidadas para un catálogo premium de plantas.

## 🏗️ Arquitectura de Datos

### Estructura Anidada de 3 Niveles

```
ProductoPlanta (Nivel Superior)
  ├─ idProducto
  ├─ categoria
  ├─ precio
  ├─ stock
  ├─ estatus
  └─ EspecieBotanica (Nivel Medio)
      ├─ nombreCientifico
      ├─ nombreComun
      ├─ familia
      ├─ origen
      └─ CuidadosRequeridos (Nivel Base)
          ├─ riegoMl
          ├─ horasLuz
          ├─ temperatura
          ├─ humedad
          └─ fertilizante
```

## 🚀 Características

- ✅ **Alta de Plantas**: Registro completo con información botánica
- ✅ **Baja de Plantas**: Eliminación con confirmación de seguridad
- ✅ **Modificación**: Actualización de campos específicos
- ✅ **Consulta**: Visualización completa del catálogo

## 💻 Tecnologías

### Frontend
- React + TypeScript
- TailwindCSS
- Motion (Framer Motion)
- Glassmorphism Design

### Backend (C++)
- Estructuras anidadas
- Arrays estáticos
- Programación estructurada
- CRUD completo

## 📦 Archivos del Proyecto

```
/headers
  ├─ CuidadosRequeridos.h
  ├─ EspecieBotanica.h
  └─ ProductoPlanta.h

/src
  └─ main.cpp

/docs
  ├─ pseudocode.txt
  ├─ flowchart.png
  └─ README.md
```

## 🛠️ Compilación

### Compilar con g++
```bash
g++ -o sgpp main.cpp
./sgpp
```

### Compilar con Visual Studio
1. Crear nuevo proyecto C++ (Consola)
2. Agregar todos los archivos .h y main.cpp
3. Compilar y ejecutar (F5)

### Compilar con OnlineGDB
1. Ir a https://www.onlinegdb.com/online_c++_compiler
2. Copiar el contenido de main.cpp
3. Crear archivos de cabecera
4. Ejecutar

## 📊 Operaciones CRUD

### 1. Alta (Create)
```cpp
ProductoPlanta nueva;
strcpy(nueva.idProducto, "P-004");
strcpy(nueva.especie.nombreComun, "Monstera Deliciosa");
strcpy(nueva.especie.cuidados.riegoMl, "500ml semanal");
catalogo[totalPlantas++] = nueva;
```

### 2. Consulta (Read)
```cpp
for(int i = 0; i < totalPlantas; i++) {
    cout << catalogo[i].especie.nombreComun << endl;
}
```

### 3. Modificación (Update)
```cpp
strcpy(catalogo[i].precio, "$1200");
strcpy(catalogo[i].stock, "50");
```

### 4. Baja (Delete)
```cpp
for(int j = i; j < totalPlantas - 1; j++) {
    catalogo[j] = catalogo[j + 1];
}
totalPlantas--;
```

## 👥 Contribución

Este proyecto es parte del **Proyecto Integrador** de Lógica Computacional y Programación Estructurada.

## 📄 Licencia

Proyecto educativo - Vivero Encanto © 2024

## 🌐 Demo en Vivo

[Ver interfaz web en vivo](#)

## 📞 Contacto

**Vivero Encanto**  
Los Cabos, Baja California Sur  
Email: contacto@viveroencanto.com

---

Desarrollado por Nailea Falcon con 🌿 <3  para la Universidad del Valle de México
