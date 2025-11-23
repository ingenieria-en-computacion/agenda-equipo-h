#include "agenda.h"
#include <stdio.h>
#include <string.h>

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if (agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    } else {
        printf("Error fatal, No se pueden agregar más contactos.\n");
    }

}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0){
            return i;
        }
    }
    return -1;
}




/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
 for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].telefono, telefono) == 0){
            return i;
        }
    }
    return -1;
}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){ 
 int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;

   
        }
    }
}
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto c){
    printf("Nombre: %s %s\n", c.nombre, c.apellido);
    printf("Cumpleaños: %d/%d\n", c.dianaci, c.mes + 1);
    printf("Teléfono: %s\n", c.telefono);
    printf("Tipo de teléfono: %d\n", c.tipo);
}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){
    printf("Nombre: ");
    scanf("%s", c->nombre);

    printf("Apellido: ");
    scanf("%s", c->apellido);

    printf("Mes de nacimiento (0 a 11): ");
    scanf("%d", (int*)&c->mes);

    printf("Dia de nacimiento: ");
    scanf("%d", &c->dianaci);

    printf("Telefono: ");
    scanf("%s", c->telefono);

    printf("Tipo de teléfono (0=CASA,1=MOVIL,2=OFICINA,3=OTRO): ");
    scanf("%d", (int*)&c->tipo);

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){
if(agenda.num_contactos == 0){
        printf("No hay nada en tu agenda\n");
        return;
    }

    for(int i = 0; i < agenda.num_contactos; i++){
        printf("\nContacto %d\n", i + 1);
        mostrar_contacto(agenda.contactos[i]);
    }
}


/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){
FILE *f = fopen(filename, "r");
    if(!f){
        printf(" Error fatal. No se pudo abrir el archivo.\n");
        return;
    }

    Contacto temp;
    agenda->num_contactos = 0;

    while(fscanf(f, "%s %s %d %d %s %d",
                 temp.nombre,
                 temp.apellido,
                 (int*)&temp.mes,
                 &temp.dianaci,
                 temp.telefono,
                 (int*)&temp.tipo) == 6)
    {
        agregar_contacto(agenda, temp);
    }

    fclose(f);
}



/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda *agenda){
 FILE *f = fopen(filename, "w");
    if(!f){
        printf("Error fatal al abrir archivo para guardar.\n");
        return;
    }

    for(int i = 0; i < agenda->num_contactos; i++){
        Contacto c = agenda->contactos[i];
        fprintf(f, "%s %s %d %d %s %d\n",
                c.nombre, c.apellido, c.mes, c.dianaci, c.telefono, c.tipo);
    }

    fclose(f);
}

