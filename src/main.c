#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "agenda.h" 

void mostrar_menu(){
    printf("\nAgenda:\n");
    printf("1. Agregar un nuevo contacto\n");
    printf("2. Buscar un contacto por nombre\n");
    printf("3. Mostrar agenda\n");
    printf("4. Guardar contactos en archivo\n");
    printf("5. Cargar los contactos desde archivo\n");
    printf("6. Salir\n");
    
}

int main(){
    Agenda agenda;
    iniciar_agenda(&agenda);

    int opcion;
    char nombre[30];
    char telefono[12];
    char archivo[100];

    do{
        mostrar_menu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{
                Contacto c;
                printf("Agregar contacto\n");
                leer_contacto(&c);
                agregar_contacto(&agenda,c);
                break;
            }
            case 2:{
                printf("Ingrese el nombre que quiere buscar:");
                scanf("%s",nombre);
                int pos = buscar_contacto(&agenda, nombre);
                if(pos == -1)printf(" Error fatal, no se encuentra el contacto\n");
                else mostrar_contacto(agenda.contactos[pos]);
                break;
            }
            case 3:
            printf("Agenda:)");
            imprimir_agenda(agenda);
            break;

            case 4:
                printf("Nombre del archivo a guardar: ");
                scanf("%s", archivo);
                guardar_contactos(archivo,&agenda);
                printf("Contactos guardados.\n");
                break;
            
            case 5: 
                printf("Nombre del archivo a cargar: ");
                scanf("%s", archivo);
                guardar_contactos(archivo, &agenda);
                printf("Contactos cargados.\n");
                break;
            
            case 6:
            printf("ha salido de su agenda");
            break;

            default:
                printf("error fatal");
    
        }


    }while (opcion !=9);
    
return 0;
}