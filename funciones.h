struct Libro 
{
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[50];
};

int menu();
void registrarLibros(struct Libro libros[20], int i);
void mostrarLibros(struct Libro libros[20], int n);
void buscarLibroId(struct Libro libros[20], int id);
void buscarLibroTitulo(struct Libro libros[20], const char *titulo);
void cambiarEstadoLibro(struct Libro libros[20], int id);
void eliminarLibroPorId(struct Libro libros[20], int id);