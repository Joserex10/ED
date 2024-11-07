#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
int evaluarExpresionPostfix(const string& expresion);



int main() {

    string expresion = "6 5 2 3 + 8 * + 3 + *";     //Definimos la entrada de datos a calcular
    int resultado = evaluarExpresionPostfix(expresion);
    cout << "El resultado de la expresion es: " << resultado << endl;
    return 0;
}

int evaluarExpresionPostfix(const string& expresion) {
    stack<int> pila;

    // Se crea un stringstream para leer la expresión token por token.
    stringstream ss(expresion);
    string token;


    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Se extraen los dos operandos superiores de la pila.
            int op2 = pila.top();
            pila.pop();
            int op1 = pila.top();
            pila.pop();

            // Dependiendo del tipo de operador, se realiza la operación correspondiente y se coloca el resultado en la pila.
            if (token == "+")
                pila.push(op1 + op2);
            else if (token == "-")
                pila.push(op1 - op2);
            else if (token == "*")
                pila.push(op1 * op2);
            else if (token == "/")
                pila.push(op1 / op2);
        } else {
            // Si el token no es un operador, se convierte en un entero y se coloca en la pila como un operando.
            int valor;
            stringstream(token) >> valor;
            pila.push(valor);
        }
    }
    return pila.top();
}

//SEUDOCODIGO

/*
Inicio del programa:

    Definir la expresión postfix a evaluar
    Llamar a la función evaluarExpresionPostfix con la expresión como argumento
    Mostrar el resultado obtenido

Función evaluarExpresionPostfix(expresion):
    Crear una pila de enteros
    Crear un stringstream para leer la expresión token por token
    Mientras haya tokens en la expresión:
        Leer el próximo token
        Si el token es un operador (+, -, *, /):
            Desapilar el segundo operando (op2)
            Desapilar el primer operando (op1)
            Realizar la operación correspondiente (op1 operador op2)
            Apilar el resultado en la pila
        Sino:
            Convertir el token en un entero
            Apilar el entero en la pila
    Devolver el elemento en la cima de la pila (que será el resultado de la expresión)

Fin del programa
 */

