#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){
    int opc;
    printf("Menu\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por id\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Cambiar estado\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void registrarLibros(struct Libro libros[], int i) {
   do {
        printf("Ingrese el id del libro (debe ser positivo): ");
        scanf("%d", &libros[i].id);
        if (libros[i].id < 0) {
            printf("El id no puede ser negativo. Intente de nuevo.\n");
        }
    } while (libros[i].id < 0);
    getchar();
    if (i<0){
        printf("Error, el id debe ser positivo.\n");
        return;
    }  
    printf("Ingrese el titulo del libro: ");
    fgets(libros[i].titulo, 100, stdin);
    int lenTitulo = strlen(libros[i].titulo) - 1;
    libros[i].titulo[lenTitulo] = '\0';
    printf("Ingrese el autor del libro: ");
    fgets(libros[i].autor, 50, stdin);
    int lenAutor = strlen(libros[i].autor) - 1;
    libros[i].autor[lenAutor] = '\0';
    do {
        printf("Ingrese el anio del libro (debe ser positivo): ");
        scanf("%d", &libros[i].anio);
        if (libros[i].anio < 0) {
            printf("El anio no puede ser negativo. Intente de nuevo.\n");
        }
    } while (libros[i].anio < 0);
    
    strcpy(libros[i].estado, "Disponible");
}

void mostrarLibros(struct Libro libros[20], int n){
    printf("Libros registrados:\n");
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libros[i].id,
                                              libros[i].titulo,
                                              libros[i].autor,
                                              libros[i].anio,
                                              libros[i].estado);
    }
}

void buscarLibroId(struct Libro libros[20], int id) {
    int encontrado = 0;
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontro un libro con el ID especificado.\n");
    }
}

void buscarLibroTitulo(struct Libro libros[20], const char *titulo) {
    int encontrado = 0;
    for (int i = 0; i < 20; i++) {
        if (libros[i].id != 0 && strcasecmp(libros[i].titulo, titulo) == 0) {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontro un libro con el titulo especificado.\n");
    }
}


void cambiarEstadoLibro(struct Libro libros[20], int id) {
    int encontrado = 0;
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            encontrado = 1;
            printf("Estado actual: %s\n", libros[i].estado);
            printf("Ingrese el nuevo estado: ");
            getchar();
            fgets(libros[i].estado, 50, stdin);
            int lenEstado = strlen(libros[i].estado) - 1;
            libros[i].estado[lenEstado] = '\0';
            printf("Estado cambiado exitosamente.\n");
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontro un libro con el ID especificado.\n");
    }
}

void eliminarLibroPorId(struct Libro libros[20], int id) {
    int encontrado = 0;
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            encontrado = 1;
            libros[i].id = 0;
            strcpy(libros[i].titulo, "");
            strcpy(libros[i].autor, "");
            libros[i].anio = 0;
            strcpy(libros[i].estado, "");
            printf("Libro eliminado exitosamente.\n");
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontro un libro con el ID especificado.\n");
    }
}