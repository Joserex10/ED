#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <chrono> // Biblioteca para medir el tiempo

using namespace std;
using namespace std::chrono;

//Validaciones
/*---------------------------------------------------------------------------------------------------*/
short validarDigito(short& n) {
    while (cin.fail() || n < 0) {
        cout << "\n\n\t\t\t\t\t+------------------------------------------------+";
        cout << "\n\t\t\t\t\t *Error: El valor introducido no es valido." << endl;
        cin.clear(); // Limpiar el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
        cout << "\t\t\t\t\t *Por favor, introduzca un numero valido: ";
        cout << "\n\t\t\t\t\t+------------------------------------------------+\n";
        cin >> n;
    }
    return n;
}

char validarEstadoTarea(char& estado) {
    while (estado != 'A' && estado != 'P' && estado != 'E' && estado != 'a' && estado != 'p' && estado != 'e') {
        cout << "\n\t\t\t\t\t| *Error: El estado de la tarea no es valido." << endl;
        system("pause");
        cout << "\t\t\t\t\t|    (A: Activa, P: Pendiente, E: En progreso,  \n";
        cout << "\t\t\t\t\t|    C: Completada): "; cin >> estado;
    }
    return estado;
}

void ingresarTarea(string &nombreTarea,  short &diasEntrega, char &estadoTarea) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer antes de leer cualquier entrada
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t\t|               * Ingresar Tarea *               |\n";
    cout << "\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t\t *Ingresa el nombre de la tarea: ";
    getline(cin, nombreTarea);
    cout << "\n\t\t\t\t\t *Ingresa los dias para la entrega: ";
    cin >> diasEntrega;
    validarDigito(diasEntrega);

    cout << "\n\t\t\t\t\t *Ingresa el estado de la tarea";
    cout << "\n\t\t\t\t\t (A: Activa, P: Pendiente, E: En progreso): ";
    cin >> estadoTarea;
    validarEstadoTarea(estadoTarea);
    cout << "\n\t\t\t\t\t+------------------------------------------------+\n";
    cout <<"\n\n\n\n";
}

/*---------------------------------------------------------------------------------------------------*/

//Structs
/*---------------------------------------------------------------------------------------------------*/
struct Tarea {
    string name;
    short DiasEntrega;
    char estadoTarea;
    int prioridad;  // Nuevo campo de prioridad
    Tarea* siguiente;
    Tarea* anterior;

    Tarea(string name, short DiasEntrega, char estadoTarea) {
        this->name = name;
        this->DiasEntrega = DiasEntrega;
        this->estadoTarea = estadoTarea;
        this->prioridad = 0;  // Inicializar la prioridad
        this->siguiente = nullptr;
        this->anterior = nullptr;
    }
};

struct Nodo {
    string name;
    Tarea* tarea;
    Nodo* left;
    Nodo* right;

    Nodo(string name, Tarea* tarea) {
        this->name = name;
        this->tarea = tarea;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Definir el BST como un struct
struct Arbol {
    Nodo* root;

    Arbol() {
        root = nullptr;
    }

    Nodo* insert(Nodo* node, string name, Tarea* tarea) {
        if (node == nullptr) {
            return new Nodo(name, tarea);
        }
        if (name < node->name) {
            node->left = insert(node->left, name, tarea);
        } else {
            node->right = insert(node->right, name, tarea);
        }
        return node;
    }

    void insert(string name, Tarea* tarea) {
        root = insert(root, name, tarea);
    }

    Nodo* search(Nodo* node, string name) {
        if (node == nullptr || node->name == name) {
            return node;
        }
        if (name < node->name) {
            return search(node->left, name);
        } else {
            return search(node->right, name);
        }
    }

    Tarea* search(string name) {
        Nodo* node = search(root, name);
        return (node != nullptr) ? node->tarea : nullptr;
    }

    Nodo* minValueNode(Nodo* node) {
        Nodo* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Nodo* remove(Nodo* node, string name) {
        if (node == nullptr) {
            return node;
        }
        if (name < node->name) {
            node->left = remove(node->left, name);
        } else if (name > node->name) {
            node->right = remove(node->right, name);
        } else {
            if (node->left == nullptr) {
                Nodo* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Nodo* temp = node->left;
                delete node;
                return temp;
            }
            Nodo* temp = minValueNode(node->right);
            node->name = temp->name;
            node->tarea = temp->tarea;
            node->right = remove(node->right, temp->name);
        }
        return node;
    }

    void remove(string name) {
        root = remove(root, name);
    }
};

struct ListaTareas {
    Tarea* primera_tarea;
    Arbol bst; 

    ListaTareas() {
        primera_tarea = nullptr;
    }

    void agregarTarea(string name, short DiasEntrega, char estadoTarea);
    void eliminarTarea(string name);
    void mostrarTareas();
    void modificarTarea(string name);
    void mergeSort();
    Tarea* merge(Tarea* left, Tarea* right);
};

//Funcion Para Calcular Las prioridades
/*---------------------------------------------------------------------------------------------------*/
int calcularPrioridad(short diasRestantes, int porcentajeEnMalla, char estado) {
    int prioridad = 0;

    // 1. Calcular prioridad basada en días restantes
    if (diasRestantes <= 1) {
        prioridad += 20;
    } else if (diasRestantes <= 10) {
        prioridad += (20 - (diasRestantes - 1) * 2); // Decrece de 2 en 2
    } else {
        prioridad += 2;  // Mínimo de 2 puntos si es más de 10 días
    }

    // 2. Sumar prioridad basada en el porcentaje en la malla
    prioridad += porcentajeEnMalla;

    // 3. Sumar prioridad basada en el estado de la tarea
    switch (estado) {
        case 'A':
        case 'a':
            prioridad += 5;
            break;
        case 'P':
        case 'p':
            prioridad += 10;
            break;
        case 'E':
        case 'e':
            prioridad += 2;
            break;
        default:
            // Manejar caso por defecto si es necesario
            break;
    }

    return prioridad;
}
/*---------------------------------------------------------------------------------------------------*/

//Funciones de las tareas
/*---------------------------------------------------------------------------------------------------*/

void ListaTareas::agregarTarea(string name, short DiasEntrega, char estadoTarea) {
    int porcentajeEnMalla = 50;  // Porcentaje en la malla predeterminado
    int prioridad = calcularPrioridad(DiasEntrega, porcentajeEnMalla, estadoTarea);
    
    Tarea* nueva_tarea = new Tarea(name, DiasEntrega, estadoTarea);
    nueva_tarea->prioridad = prioridad;  // Asignar la prioridad calculada

    if (!primera_tarea) {
        primera_tarea = nueva_tarea;
    } else {
        Tarea* actual = primera_tarea;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nueva_tarea;
        nueva_tarea->anterior = actual;
    }
    bst.insert(name, nueva_tarea); // Insertar en el BST

    mergeSort();  // Ordenar la lista de tareas por prioridad
}

void ListaTareas::eliminarTarea(string name) {

    if (!primera_tarea) {
        cout << "\n\t\t\t\t\t+-----------------------------------------------+";
        cout << "\n\t\t\t\t\t|                No Hay Tareas                  |" << endl;
        cout << "\t\t\t\t\t+-----------------------------------------------+\n\n";
        return;
    } else {
        Tarea* actual = primera_tarea;
        while (actual) {
            if (actual->name == name) {
                if (actual->anterior) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    primera_tarea = actual->siguiente;
                }
                if (actual->siguiente) {
                    actual->siguiente->anterior = actual->anterior;
                }
                delete actual;
                cout << "\n\t\t\t\t\tTarea eliminada con exito..." << endl;
                bst.remove(name); // Eliminar del BST
                return;
            }
            actual = actual->siguiente;
        }
    }

    cout << "\n\t\t\t\t\tLa tarea no se encontro en la lista" << endl;
}

void ListaTareas::mostrarTareas() {
    unsigned short contador = 0;
    if (!primera_tarea) {
        cout << "\n\t\t\t\t\t+-----------------------------------------------+";
        cout << "\n\t\t\t\t\t|           No Hay Tareas Pendientes            |" << endl;
        cout << "\t\t\t\t\t+-----------------------------------------------+\n";
        return;
    }

    Tarea* actual = primera_tarea;
    while (actual) {
        cout <<"\n";
        cout << "\t\t\t\t\t+-----------------------------------------------+\n";
        cout << "\t\t\t\t\t|               Tareas pendientes               |\n";
        cout << "\t\t\t\t\t+-----------------------------------------------+\n";
        cout << "\t\t\t\t\t|  Nombre: " << actual->name << "\n";
        cout << "\t\t\t\t\t|  Dias para entrega: " << actual->DiasEntrega << "\n";
        cout << "\t\t\t\t\t|  Estado: " << actual->estadoTarea << "\n";
        cout << "\t\t\t\t\t+-----------------------------------------------+\n";


        actual = actual->siguiente;
        contador++;
    }
    cout <<"\n\t\t\t\t\tTiene " << contador << " tareas pendientes.\n";
}

void ListaTareas::modificarTarea(string name) {
    if (!primera_tarea) {
        cout << "\n\t\t\t\t\t+-----------------------------------------------+";
        cout << "\n\t\t\t\t\t|           No Hay Tareas A Modificar           |" << endl;
        cout << "\t\t\t\t\t+-----------------------------------------------+\n\n";
        return;
    }

    string nombreTarea;
    cout << "\n\t\t\t\t\t Ingresa el nombre de la tarea que deseas modificar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreTarea);

    Tarea* actual = bst.search(nombreTarea); // Buscar en el BST
    if (actual) {
        string nuevoNombre;
        short nuevosDiasEntrega;
        char nuevoEstadoTarea;

        cout << "\n\t\t\t\t\t Ingresa el nuevo nombre de la tarea (dejar vacio para no cambiar): ";
        getline(cin, nuevoNombre);
        if (!nuevoNombre.empty()) {
            bst.remove(nombreTarea); // Eliminar el nombre antiguo del BST
            actual->name = nuevoNombre;
            bst.insert(nuevoNombre, actual); // Insertar el nuevo nombre en el BST
        }

        cout << "\n\t\t\t\t\t Ingresa los nuevos dias para la entrega (0 para no cambiar): ";
        cin >> nuevosDiasEntrega;
        if (nuevosDiasEntrega != 0) {
            actual->DiasEntrega = nuevosDiasEntrega;
        }

        cout << "\n\t\t\t\t\t Ingresa el nuevo estado de la tarea (A: Activa, P: Pendiente, E: En progreso): ";
        cin >> nuevoEstadoTarea;
        actual->estadoTarea = nuevoEstadoTarea;

        // Recalcular y actualizar la prioridad
        int porcentajeEnMalla = 50;  // Porcentaje en la malla predeterminado
        actual->prioridad = calcularPrioridad(actual->DiasEntrega, porcentajeEnMalla, actual->estadoTarea);

        cout << "\n\t\t\t\t\t Tarea modificada con exito..." << endl;

        mergeSort();  // Ordenar la lista de tareas por prioridad
    } else {
        cout << "\t\tLa tarea no se encontro en la lista..." << endl;
    }
}

void ListaTareas::mergeSort() {
    if (!primera_tarea || !primera_tarea->siguiente) {
        return; // La lista está vacía o tiene solo un elemento, ya está ordenada
    }

    // Dividir la lista en dos mitades
    Tarea* middle = primera_tarea;
    Tarea* fast = primera_tarea->siguiente;
    while (fast && fast->siguiente) {
        middle = middle->siguiente;
        fast = fast->siguiente->siguiente;
    }

    Tarea* secondHalf = middle->siguiente;
    middle->siguiente = nullptr; // Dividir la lista en dos partes

    // Recursivamente ordenar cada mitad
    ListaTareas leftList;
    leftList.primera_tarea = primera_tarea;
    leftList.mergeSort();

    ListaTareas rightList;
    rightList.primera_tarea = secondHalf;
    rightList.mergeSort();

    // Combinar las dos mitades ordenadas
    primera_tarea = merge(leftList.primera_tarea, rightList.primera_tarea);
}

Tarea* ListaTareas::merge(Tarea* left, Tarea* right) {
    if (!left) return right;
    if (!right) return left;

    Tarea* result;
    if (left->prioridad >= right->prioridad) {  // Ordenar por prioridad en orden descendente
        result = left;
        result->siguiente = merge(left->siguiente, right);
    } else {
        result = right;
        result->siguiente = merge(left, right->siguiente);
    }
    return result;
}

/*---------------------------------------------------------------------------------------------------*/



//Funcion Tareas Predeterminadas
/*---------------------------------------------------------------------------------------------------*/
void predeterminadas(ListaTareas &listaTareas) {
    // Verificar si la lista de tareas está vacía antes de agregar tareas predeterminadas
    if (listaTareas.primera_tarea == nullptr) {
        listaTareas.agregarTarea("Completar informe de ventas", 2, 'P');
        listaTareas.agregarTarea("Preparar presentacion para reunion", 4, 'A');
        listaTareas.agregarTarea("Enviar propuestas a clientes potenciales", 6, 'E');
        listaTareas.agregarTarea("Revisar documentos legales", 3, 'P');
        listaTareas.agregarTarea("Organizar evento de equipo", 5, 'A');
        listaTareas.agregarTarea("Actualizar base de datos de clientes", 7, 'E');

        listaTareas.mergeSort();  // Ordenar la lista de tareas por prioridad después de agregar las tareas predeterminadas
    }
}
/*---------------------------------------------------------------------------------------------------*/


//Login(NO TOCAR NADA DE ACA)
/*---------------------------------------------------------------------------------------------------*/
bool login() {
    string username, password, storedUser, storedPass;
    cout << "\n\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t\tIngrese su nombre de usuario: ";
    cin >> username;
    cout << "\n\t\t\t\t\tIngrese su password: ";
    cin >> password;
    cout << "\n\t\t\t\t\t+------------------------------------------------+\n";

    ifstream usersFile("users.txt");
    if (usersFile.is_open()) {
        while (usersFile >> storedUser >> storedPass) {
            if (storedUser == username && storedPass == password) {
                usersFile.close();
                return true;
            }
        }
        usersFile.close();
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "\n\n\n";
    cout << "\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\n\t\t\t\t\tIngrese un nombre de usuario: ";
    cin >> username;
    cout << "\n\t\t\t\t\tIngrese una password: ";
    cin >> password;
    cout << "\n\t\t\t\t\t+------------------------------------------------+\n";

    ofstream usersFile("users.txt", ios::app);
    if (usersFile.is_open()) {

        usersFile << username << "\n" << password << endl;
        usersFile << '\n';

        usersFile.close();
        cout << "\n\n\n";
        cout << "\t\t\t\t\t+------------------------------------------------+\n";
        cout << "\t\t\t\t\t|        Usuario registrado exitosamente!        |  ";
        cout << "\n\t\t\t\t\t+------------------------------------------------+\n";
    } else {
        cout << "\n\t\t\t\t\tNo se pudo abrir el archivo para registro." << endl;
        exit(0);
    }
}

void menuLogin(){
    short choice;

    cout << R"(
                                   ____ _____ ______ _   ___      ________ _   _ _____ _____   ____
                                  |  _ \_   _|  ____| \ | \ \    / /  ____| \ | |_   _|  __ \ / __ \
                                  | |_) || | | |__  |  \| |\ \  / /| |__  |  \| | | | | |  | | |  | |
                                  |  _ < | | |  __| | . ` | \ \/ / |  __| | . ` | | | | |  | | |  | |
                                  | |_) || |_| |____| |\  |  \  /  | |____| |\  |_| |_| |__| | |__| |
                                  |____/_____|______|_| \_|   \/   |______|_| \_|_____|_____/ \____/
    )" << std::endl;


    cout << "\n";
    cout << "\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t\t|                   * LOGIN *                    |\n";
    cout << "\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t\t|  1. Iniciar sesion                             |\n";
    cout << "\t\t\t\t\t|  2. Registrarse                                |\n";
    cout << "\t\t\t\t\t|  3. SALIR                                      |\n";
    cout << "\t\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t\t  Ingresar opcion: ";
    cin >> choice;
    validarDigito(choice);

    switch (choice) {
        case 1:
            if (login()) {
                cout << "\t\t\t\t\tInicio de sesion exitoso!" << endl;
            } else {
                cout << "\n\t\t\t\t\tNombre de usuario o password incorrectos." << endl;
                cout << "\t\t\t\t\t";system("pause");
                menuLogin();
            }
            break;
        case 2:
            registerUser();
            menuLogin();
            break;
        default:
            if(choice == 3){
                cout << R"(

      _____       ___                __             __     __
     / ___/____ _/ (_)__  ____  ____/ /___     ____/ /__  / /  ____  _________  ____ __________ _____ ___  ____ _
     \__ \/ __ `/ / / _ \/ __ \/ __  / __ \   / __  / _ \/ /  / __ \/ ___/ __ \/ __ `/ ___/ __ `/ __ `__ \/ __ `/
     ___/ / /_/ / / /  __/ / / / /_/ / /_/ /  / /_/ /  __/ /  / /_/ / /  / /_/ / /_/ / /  / /_/ / / / / / / /_/ / _ _
    /____/\__,_/_/_/\___/_/ /_/\__,_/\____/   \__,_/\___/_/  / .___/_/   \____/\__, /_/   \__,_/_/ /_/ /_/\__,_(_|_|_)
                                                            /_/               /____/

    )" <<endl;
                exit(0);
            }else{
                cout << "\n\t\t\t\t\tPorfavor Ingrese (1-3)\n";
                menuLogin();
            }

    }




}

/*---------------------------------------------------------------------------------------------------*/


//Menu(NO TOCAR NADA DE ACA)
/*---------------------------------------------------------------------------------------------------*/
void menu() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer antes de leer cualquier entrada
    // Declarar las variables fuera del switch
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // Variables para ingresar nuevas tareas y lista instanciada
    short opcion;
    string nombreTarea;
    short diasEntrega;
    char estadoTarea;

    ListaTareas listaTareas;
    //funcion agregar Tareas Predeterminadas
    predeterminadas(listaTareas);

    do {
        fflush(stdin);
        cout << "\n\n\n";
        cout << "\t\t\t\t\t+------------------------------------------------+\n";
        cout << "\t\t\t\t\t|                    * MENU *                    |\n";
        cout << "\t\t\t\t\t+------------------------------------------------+\n";
        cout << "\t\t\t\t\t|  1. Ver Tareas                                 |\n";
        cout << "\t\t\t\t\t|  2. Ingresar Nueva Tarea                       |\n";
        cout << "\t\t\t\t\t|  3. Modificar Tareas                           |\n";
        cout << "\t\t\t\t\t|  4. Marcar Tarea Completada                    |\n";
        cout << "\t\t\t\t\t|  5. Salir                                      |\n";
        cout << "\t\t\t\t\t+------------------------------------------------+\n";
        cout << "\t\t\t\t\t  Ingresar opcion: ";
        cin >> opcion;

        validarDigito(opcion);

        switch (opcion) {
            case 1:
            // Iniciar medición de tiempo
                start = high_resolution_clock::now();
                cout << "\n\n\n";
                listaTareas.mostrarTareas();
                // Detener medición de tiempo
                stop = high_resolution_clock::now();

                // Calcular la diferencia de tiempo
                duration = duration_cast<microseconds>(stop - start);

                // Imprimir tiempo de ejecución
                cout << "\n\t\t\t\t\tTiempo de ejecucion para mostrar tareas: " << duration.count() << " microsegundos" << endl;
                cout <<'\n';
                cout <<"\t\t\t\t\t";system("pause");
                break;
            case 2:
                ingresarTarea(nombreTarea, diasEntrega, estadoTarea);
                listaTareas.agregarTarea(nombreTarea, diasEntrega, estadoTarea);
                cout <<"\t\t\t\t\t";system("pause");
                break;
            case 3:
                listaTareas.modificarTarea(nombreTarea);
                cout <<"\t\t\t\t\t ";system("pause");
                break;
            case 4:
                cout << "\n\t\t\t\t\t Ingresa el nombre de la tarea a marcar como completada: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer antes de getline
                getline(cin, nombreTarea);
                listaTareas.eliminarTarea(nombreTarea);
                cout <<"\t\t\t\t\t";system("pause");

                break;
            case 5:
                cout << R"(

      _____       ___                __             __     __
     / ___/____ _/ (_)__  ____  ____/ /___     ____/ /__  / /  ____  _________  ____ __________ _____ ___  ____ _
     \__ \/ __ `/ / / _ \/ __ \/ __  / __ \   / __  / _ \/ /  / __ \/ ___/ __ \/ __ `/ ___/ __ `/ __ `__ \/ __ `/
     ___/ / /_/ / / /  __/ / / / /_/ / /_/ /  / /_/ /  __/ /  / /_/ / /  / /_/ / /_/ / /  / /_/ / / / / / / /_/ / _ _
    /____/\__,_/_/_/\___/_/ /_/\__,_/\____/   \__,_/\___/_/  / .___/_/   \____/\__, /_/   \__,_/_/ /_/ /_/\__,_(_|_|_)
                                                            /_/               /____/

    )" <<endl;
                break;
            default:
                cout << "\n\t\t\t\t\tNo existe el numero de opcion ingresado" << endl;
                break;
        }
    }while(opcion != 5);
}

/*---------------------------------------------------------------------------------------------------*/

//Funcion Principal
/*---------------------------------------------------------------------------------------------------*/
int main() {
    menuLogin();
    menu();
    return 0;
}
/*---------------------------------------------------------------------------------------------------*/
