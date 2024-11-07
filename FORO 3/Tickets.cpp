#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Definición de la estructura Ticket
struct Ticket {
    string nombre;
    int cantidad;
};

// Función para reservar un ticket
void reservarTicket(queue<Ticket>& cola) {
    Ticket nuevoTicket;
    cout << "Ingrese su nombre: ";
    cin >> nuevoTicket.nombre;
    cout << "Ingrese la cantidad de tickets a reservar: ";
    cin >> nuevoTicket.cantidad;
    cola.push(nuevoTicket);
    cout << "¡Ticket reservado con éxito!\n";
}

// Función para atender el siguiente ticket en la cola
void atenderSiguienteTicket(queue<Ticket>& cola) {
    if (!cola.empty()) {
        Ticket ticket = cola.front();
        cola.pop();
        cout << "Atendiendo a " << ticket.nombre << " por " << ticket.cantidad << " tickets.\n";
    } else {
        cout << "No hay tickets en espera.\n";
    }
}

int main() {
    queue<Ticket> colaTickets;
    int opcion;

    do {
        cout << "\nSistema de reserva de tickets\n";
        cout << "1. Reservar ticket\n";
        cout << "2. Atender siguiente ticket\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                reservarTicket(colaTickets);
                break;
            case 2:
                atenderSiguienteTicket(colaTickets);
                break;
            case 3:
                cout << "Saliendo del sistema.\n";
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione nuevamente.\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}

//SEUDOCODIGO

/*INICIO
    ESTRUCTURA Ticket
        nombre: cadena
        cantidad: entero
    FIN ESTRUCTURA

    PROCEDIMIENTO reservarTicket(cola: cola de Tickets)
        Ticket nuevoTicket
        IMPRIMIR "Ingrese su nombre: "
        LEER nuevoTicket.nombre
        IMPRIMIR "Ingrese la cantidad de tickets a reservar: "
        LEER nuevoTicket.cantidad
        cola.empujar(nuevoTicket)
        IMPRIMIR "¡Ticket reservado con éxito!"
    FIN PROCEDIMIENTO

    PROCEDIMIENTO atenderSiguienteTicket(cola: cola de Tickets)
        SI cola.no_vacía ENTONCES
            Ticket ticket = cola.frente()
            cola.desencolar()
            IMPRIMIR "Atendiendo a " CONCATENAR ticket.nombre CONCATENAR " por " CONCATENAR ticket.cantidad CONCATENAR " tickets."
        SINO
            IMPRIMIR "No hay tickets en espera."
        FIN SI
    FIN PROCEDIMIENTO

    colaTickets: cola de Tickets
    opcion: entero

    HACER
        IMPRIMIR "Sistema de reserva de tickets"
        IMPRIMIR "1. Reservar ticket"
        IMPRIMIR "2. Atender siguiente ticket"
        IMPRIMIR "3. Salir"
        IMPRIMIR "Seleccione una opción: "
        LEER opcion

        SEGÚN opcion HACER
            CASO 1:
                reservarTicket(colaTickets)
            CASO 2:
                atenderSiguienteTicket(colaTickets)
            CASO 3:
                IMPRIMIR "Saliendo del sistema."
            DE OTRO MODO:
                IMPRIMIR "Opción inválida. Por favor, seleccione nuevamente."
        FIN SEGÚN
    MIENTRAS opcion NO SEA 3
FIN*/