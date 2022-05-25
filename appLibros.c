// Nombre			: appLibros.c
// Proposito		: Catalogo de libros
// Autores			: 
// FCreacion		: 22/05/2022
// FModif			: 24/05/2022

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct tLibro {
	char titulo[51];
	char autor[51];
	struct tLibro *siguiente;
} tLibro;

typedef struct {
	tLibro *primero;
} tListaLibros;

// Declarar catalogo de Libros
tListaLibros *miCatalogo = NULL;

// Leer datos
void leerDatos() {
	char tit[51];
	char aut[51];

	printf("Ingrese el titulo: ");
	scanf("%[^\n]%*c", tit);

	printf("Ingrese el autor: ");
	scanf("%[^\n]%*c", aut);

	// Creacion del nodo "nuevo" que contendra los datos anteriores
	tLibro *nuevo = (tLibro *) malloc(sizeof(tLibro)); //Recervamos una cantidad  de memoria para un nodo de estructura tLibro
	strcpy(nuevo -> titulo, tit); // Uso de la libreria string.h para hacer copia
	strcpy(nuevo -> autor, aut);  // Uso de la libreria string.h para pasar datos de tit a titulo

	// Campo que apunta al siguiente nodo es un nulo
	nuevo -> siguiente = NULL;

	// Llenado de datos al catalogo
	if(miCatalogo -> primero == NULL) {
		miCatalogo -> primero = nuevo; // Se anade nuevo como primer elemento
	}
	else {
		tLibro *aux = miCatalogo -> primero; // Se crea campo aux que recorre el catalogo a partir del primero libro
		while(aux -> siguiente != NULL) {
			aux = aux -> siguiente;
		}

		aux -> siguiente = nuevo;	// Cuando el campo siguiente de aux es nulo, entonces ahora siguiente apuntara a nuevo
	}
}

// Listar los libros del catalogo
void listarCatalogo() {
	if(miCatalogo -> primero == NULL)	// Si el catalogo esta vacia
		printf("El catalogo esta vacio");
	else {
		tLibro *aux = miCatalogo -> primero; // Se crea un campo aux que recorra los elementos del catalogo
		do {
			printf("Titulo: %s\t -> Autor: %s\n", aux -> titulo, aux -> autor);
			aux = aux -> siguiente;
		}while(aux != NULL);
	}
}

// Bucar por titulo
void buscarTitulo() {
	// Declaracion de la variable que almacenara el dato a buscar
	char datos[51];
	printf("Ingrese el titulo del texto: ");
	scanf("%[^\n]%*c", datos);  // Ingreso de datos por consola

	if(miCatalogo -> primero == NULL)
		printf("La lista esta vacia\n");
	else {
		tLibro *aux = miCatalogo -> primero;  // Creacion de un campo auxiliar que recorre los elementos del catalogo
		do {
			if(strcmp(aux -> titulo, datos) == 0) {  // 0 = son iguales, 1 = son diferentes
				printf("\nEl titulo existe en la biblioteca\n\n");
				break;
			}
			else {
				aux = aux -> siguiente;
				if (aux == NULL)
					printf("\nEl titulo no existe en la biblioteca\n\n");
			}
		}while(aux != NULL);
	}
}

// Buscar un libro por autor
void buscarAutor() {
	char datos[51];

	if(miCatalogo -> primero == NULL)
		printf("\nLa lista esta vacia\n");
	else {
		printf("Ingrese el autor del texto: ");
		scanf("%[^\n]%*c", datos);

		tLibro *aux = miCatalogo -> primero;
		do {
			if(strcmp(aux -> autor, datos) == 0) {
				printf("\nEl autor existe en la biblioteca\n\n");
				break;
			}
			else {
				aux = aux -> siguiente;
				if (aux == NULL)
					printf("\nEl autor no existe en la biblioteca\n\n");
			}
		}while(aux != NULL);
	}
}


// Menu
void mostrarMenu() {
	puts("");
	puts("**SISTEMA DE GESTION DE LIBROS **");
	puts("*                                               *");
	puts("*    1. Insertar Libros *");
	puts("*    2. Mostrar Catalogo *");
	puts("*    3. Buscar por titulo *");
	puts("*    4. Buscar por autor *");
	puts("*    5. Salir  *");
	puts("*                                               *");
	puts("**");
}

int main () {
	// Variable para recorrer la opcion menu
	int opcion;
	char aux[2];

	// Inicializar de nuestro catalogo de libros
	miCatalogo = (tListaLibros *) malloc(sizeof(tListaLibros)); // Reservar memoria para un tipo tListaLibros
	miCatalogo -> primero = NULL;  // Primer elemento inicia en nullo

	// Mostar el menu, solicitar la opcion y acutar
	do {
		// Indicar que hacer al programa
		mostrarMenu();

		// Leer opcion
		printf("\nIngrese una opcion: ");
		scanf("%[^\n]%*c", aux);
		opcion = atoi(aux);  // Castear el tipo de dato char a numerico

		// Evalucion de opciones
		switch(opcion) {
			case 1:
				// Leer datos de consola
				leerDatos();
				break;
			case 2:
				// Mostrar catalogo en consola
				listarCatalogo();
				break;
			case 3:
				// Mostrar buscar por titulo
				buscarTitulo();
				break;
			case 4:
				// Mostrar buscar por autor
				buscarAutor();
				break;
			case 5:
				break;
			default:
				puts("La opcion no es correcta");
				break;
		}
	} while(opcion != 5);
}
