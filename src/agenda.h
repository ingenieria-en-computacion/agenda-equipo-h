#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes{ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

//tipo de contacto
typedef struct {
    char nombre[30];
    char apellido[30];
    enum Mes mes;// mes de nacimiento
    int dianaci;// dia de nacimiento
    char telefono[12]; // numero de telefono
    enum TipoTelefono tipo;// tipo de numero

} Contacto;


//Tipo Agenda
typedef struct Agenda{
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);
void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename,Agenda *agenda);

#endif // __AGENDA_H_