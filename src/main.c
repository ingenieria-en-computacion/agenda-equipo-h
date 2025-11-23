#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "agenda.h" 

// Constante para el nombre del archivo de contactos
#define ARCHIVO_CONTACTOS "contactos.txt"

// === PROTOTIPOS DE FUNCIONES LOCALES ===
void mostrar_menu(); 
int procesar_opcion(int opcion, Agenda *agenda); 

// === FUNCIÓN PRINCIPAL ===
int main() {
    Agenda agenda;
    int opcion = 0;
    int salir = 0; 

    // Inicialización de la Agenda (siempre es lo primero)
    iniciar_agenda(&agenda); 

    // Bucle principal del menú
    while (!salir) {
        mostrar_menu();
        
        // Lee la opción
        if (scanf("%d", &opcion) != 1) {
            // Manejo de error: Limpiar buffer
            while (getchar() != '\n'); 
            opcion = 0; 
        }
        
        // Llama a la función que maneja los cases
        salir = procesar_opcion(opcion, &agenda);
        printf("\n"); 
    }

    printf("Saliendo del programa. ¡Hasta pronto!\n");
    return 0;
}

// === DEFINICIÓN DE mostrar_menu() ===
void mostrar_menu() {
    printf("\n=============================================\n");
    printf("=           Menú de la Agenda             =\n");
    printf("=============================================\n");
    printf("1. Agregar contacto\n");
    printf("2. Mostrar todos los contactos\n");
    printf("3. Buscar contacto por Nombre\n");
    printf("4. Buscar contacto por Teléfono\n");
    printf("5. Ordenar contactos (Ascendente)\n");
    printf("6. Ordenar contactos (Descendente)\n");
    printf("7. Guardar contactos en archivo\n");
    printf("8. Cargar contactos desde archivo\n");
    printf("9. Salir del programa\n");
    printf("=============================================\n");
    printf("Ingrese su opción: ");
}

// === DEFINICIÓN DE procesar_opcion() ===
int procesar_opcion(int opcion, Agenda *agenda) {
    Contacto nuevo_contacto;
    char busqueda[30];
    int indice;

    switch (opcion) {
        case 1: // Agregar contacto
            // Llama a las funciones implementadas en agenda.c
            // NOTA: Debes implementar leer_contacto en agenda.c
            // leer_contacto(&nuevo_contacto); 
            // agregar_contacto(agenda, nuevo_contacto);
            printf("Opción 1: Lógica de Agregar contacto (Falta implementar leer_contacto)\n");
            break;
            
        case 2: // Mostrar todos los contactos
            // Llama a la función implementada en agenda.c
            // imprimir_agenda(agenda); 
            printf("Opción 2: Lógica de Mostrar todos los contactos\n");
            break;
            
        case 3: // Buscar contacto por Nombre
            // Lógica de búsqueda (Llama a buscar_contacto en agenda.c)
            printf("Opción 3: Lógica de Buscar por Nombre\n");
            break;

        case 4: // Buscar contacto por Teléfono
            // Lógica de búsqueda (Llama a buscar_contacto_x_telefono en agenda.c)
            printf("Opción 4: Lógica de Buscar por Teléfono\n");
            break;
            
        case 5: // Ordenar contactos (Ascendente)
            // Lógica de ordenamiento (Llama a ordenar_contactos en agenda.c)
            printf("Opción 5: Lógica de Ordenar Ascendente\n");
            break;
            
        case 6: // Ordenar contactos (Descendente)
            // Lógica de ordenamiento (Llama a ordenar_contactos_inv en agenda.c)
            printf("Opción 6: Lógica de Ordenar Descendente\n");
            break;

        case 7: // Guardar contactos en archivo
            // Lógica de guardado (Llama a guardar_contactos en agenda.c)
            printf("Opción 7: Lógica de Guardar en archivo\n");
            break;
            
        case 8: // Cargar contactos desde archivo
            // Lógica de carga (Llama a cargar_contactos en agenda.c)
            printf("Opción 8: Lógica de Cargar desde archivo\n");
            break;
            
        case 9: // Salir del programa
            return 1; // Devuelve 1 para salir del bucle en main
            
        default:
            printf("Opción inválida. Ingrese un número del 1 al 9.\n");
            break;
    }
    return 0; // Devuelve 0 para continuar en el bucle
}