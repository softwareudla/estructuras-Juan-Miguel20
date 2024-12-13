#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    struct Libro libros[20];
    int opc;
    int i = 0;
    int id; 
    char titulo[100]; 

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibros(libros, i);
                i++;
                break;
            case 2:
                mostrarLibros(libros, i);
                break;
            case 3:
                printf("Ingrese el id del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, id);
                break;
            case 4:
                printf("Ingrese el titulo del libro a buscar: ");
                scanf("%s", titulo);
                buscarLibroTitulo(libros, titulo);
                break;
            case 5:
                printf("Ingrese el ID del libro para cambiar su estado: ");
                scanf("%d", &id);
                cambiarEstadoLibro(libros, id);
                break;
            case 6:
                printf("Ingrese el ID del libro a eliminar: ");
                scanf("%d", &id);
                eliminarLibroPorId(libros, id);
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
        }
    } while (opc != 7);

    return 0;
}
