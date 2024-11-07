#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Estructura para representar un proceso
struct Process {
    string name;
    int id;
};

// Función para agregar un proceso a la cola
void addProcess(queue<Process>& processQueue, const Process& process) {
    processQueue.push(process);
    cout << "Proceso " << process.name << " agregado a la cola." << endl;
}

// Función para ejecutar procesos en el orden de llegada (FIFO)
void executeProcesses(queue<Process>& processQueue) {
    while (!processQueue.empty()) {
        Process currentProcess = processQueue.front();
        processQueue.pop();
        cout << "Ejecutando proceso " << currentProcess.name << " (ID: " << currentProcess.id << ")" << endl;
    }
    cout << "Todos los procesos han sido ejecutados." << endl;
}

int main() {
    queue<Process> processQueue;

    int numProcesses;
    cout << "Ingrese el numero de procesos a agregar: ";
    cin >> numProcesses;

    for (int i = 0; i < numProcesses; ++i) {
        Process process;
        cout << "Ingrese el nombre del proceso " << i + 1 << ": ";
        cin >> process.name;
        cout << "Ingrese el ID del proceso " << i + 1 << ": ";
        cin >> process.id;
        addProcess(processQueue, process);
    }

    // Ejecutar procesos en orden de llegada
    executeProcesses(processQueue);

    return 0;
}

// SEUDOCODIGO

/*Estructura Proceso:
    Cadena nombre
    Entero id

Función agregarProceso(colaProcesos, proceso):
    colaProcesos.insertar(proceso)
    Imprimir "Proceso " + proceso.nombre + " agregado a la cola."

Función ejecutarProcesos(colaProcesos):
    Mientras colaProcesos no esté vacía:
        procesoActual = colaProcesos.frente()
        colaProcesos.eliminar()
        Imprimir "Ejecutando proceso " + procesoActual.nombre + " (ID: " + procesoActual.id + ")"
    Imprimir "Todos los procesos han sido ejecutados."

Función principal:
    Cola<Proceso> colaProcesos
    Entero numProcesos
    Imprimir "Ingrese el número de procesos a agregar: "
    Leer numProcesos

    Para cada i desde 1 hasta numProcesos:
        Proceso proceso
        Imprimir "Ingrese el nombre del proceso " + i + ": "
        Leer proceso.nombre
Imprimir "Ingrese el ID del proceso " + i + ": "
        Leer proceso.id
        agregarProceso(colaProcesos, proceso)

    Ejecutar procesos en orden de llegada
    ejecutarProcesos(colaProcesos)*/