#include <iostream>
#include <queue> 
using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Tree {
private:
    Node* root;
public:
    Tree() { root = nullptr; }
    ~Tree();
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Preorder(Node* p);
    void Inorder() { Inorder(root); }
    void Inorder(Node* p);
    void Postorder() { Postorder(root); }
    void Postorder(Node* p);
    void Levelorder();
    int Height() { return Height(root); }
    int Height(Node* p);
    Node* getRoot() { return root; }
};

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x, numNodes;

    cout << "Ingrese el numero de nodos: ";
    cin >> numNodes;

    queue<Node*> q;
    root = new Node;
    cout << "Ingrese el valor de la raiz ";
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.push(root);

    while (numNodes > 1 && !q.empty()) {
        p = q.front();
        q.pop();
        
        cout << "Ingresa el hijo izquierdo " << p->data << " o -1 para no no tener hijo: ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
            numNodes--;
        }

        cout << "Ingresa el hijo derecho" << p->data << " o -1 para no no tener hijo: ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
            numNodes--;
        }
    }
}

void Tree::Preorder(Node* p) {
    if (p) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Levelorder() {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        cout << p->data << " ";

        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
}

int Tree::Height(Node* p) {
    if (p == nullptr)
        return 0;
    else {
        int lHeight = Height(p->lchild);
        int rHeight = Height(p->rchild);

        if (lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}

Tree::~Tree() {
}

int main() {
    Tree t;
    t.CreateTree();

    cout << "Preorden: ";
    t.Preorder();
    cout << endl;

    cout << "Inorden: ";
    t.Inorder();
    cout << endl;

    cout << "Postorden: ";
    t.Postorder();
    cout << endl;

    cout << "nivel orden: ";
    t.Levelorder();
    cout << endl;

    cout << "Altura del arbol: " << t.Height() << endl;

    return 0;
}



//SEUDOCODIGO:

/*Clase Nodo:
    Variables:
        Nodo* lchild   // Puntero al hijo izquierdo
        Entero data    // Datos del nodo
        Nodo* rchild   // Puntero al hijo derecho

Clase Árbol:
    Variables:
        Nodo* root     // Puntero a la raíz del árbol

    Métodos:
        Método Constructor:
            root = nullptr // Inicialización de la raíz como nula

        Método Destructor:
            // Liberación de memoria (opcionalmente)

        Método CrearÁrbol():
            Entero numNodos
            Cola de Nodos q
            Nodo* p
            Nodo* t
            Entero x

            Mostrar "Ingrese el número de nodos: "
            Leer numNodos

            Mostrar "Ingrese el valor de la raíz: "
            Leer x
            root = Nuevo Nodo
            root->data = x
            root->lchild = nullptr
            root->rchild = nullptr
            q.Encolar(root)

            Mientras numNodos > 1 y la cola q no esté vacía hacer:
                p = q.Desencolar()

                Mostrar "Ingrese el hijo izquierdo de " + p->data + " o -1 para no tener hijo: "
                Leer x
                Si x ≠ -1 entonces:
                    t = Nuevo Nodo
                    t->data = x
                    t->lchild = nullptr
                    t->rchild = nullptr
                    p->lchild = t
                    q.Encolar(t)
                    numNodos = numNodos - 1

                Mostrar "Ingrese el hijo derecho de " + p->data + " o -1 para no tener hijo: "
                Leer x
                Si x ≠ -1 entonces:
                    t = Nuevo Nodo
                    t->data = x
                    t->lchild = nullptr
                    t->rchild = nullptr
                    p->rchild = t
                    q.Encolar(t)
                    numNodos = numNodos - 1

        Método Preorden(Nodo* p):
            Si p no es nulo entonces:
                Mostrar p->data + " "
                Preorden(p->lchild)
                Preorden(p->rchild)

        Método Inorden(Nodo* p):
            Si p no es nulo entonces:
                Inorden(p->lchild)
                Mostrar p->data + " "
                Inorden(p->rchild)

        Método Postorden(Nodo* p):
            Si p no es nulo entonces:
                Postorden(p->lchild)
                Postorden(p->rchild)
                Mostrar p->data + " "

        Método NivelOrden():
            Si root es nulo entonces:
                Retornar

            Cola de Nodos q
            q.Encolar(root)

            Mientras la cola q no esté vacía hacer:
                Nodo* p = q.Desencolar()
                Mostrar p->data + " "

                Si p->lchild no es nulo entonces:
                    q.Encolar(p->lchild)
                Si p->rchild no es nulo entonces:
                    q.Encolar(p->rchild)

        Método Altura(Nodo* p):
            Si p es nulo entonces:
                Retornar 0
            Sino:
                Entero lHeight = Altura(p->lchild)
                Entero rHeight = Altura(p->rchild)

                Si lHeight > rHeight entonces:
                    Retornar lHeight + 1
                Sino:
                    Retornar rHeight + 1

        Método ObtenerRaiz():
            Retornar root

Funcion Principal:
    Árbol t
    t.CrearÁrbol()

    Mostrar "Preorden: "
    t.Preorden(t.ObtenerRaiz())
    Mostrar nueva línea

    Mostrar "Inorden: "
    t.Inorden(t.ObtenerRaiz())
    Mostrar nueva línea

    Mostrar "Postorden: "
    t.Postorden(t.ObtenerRaiz())
    Mostrar nueva línea

    Mostrar "Nivel Orden: "
    t.NivelOrden()
    Mostrar nueva línea

    Mostrar "Altura del árbol: "
    Mostrar t.Altura(t.ObtenerRaiz())
    Mostrar nueva línea

*/