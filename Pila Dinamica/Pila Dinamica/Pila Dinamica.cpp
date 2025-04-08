#include <iostream> //Entrada y Salida de datos
using namespace std; //Evita usar std:: en la libreria estandar
struct Nodo { //Definicion de la estructura 
    int dato; // Variable de tipo entero
    Nodo* siguiente; //Punteri llamado siguiente 
};
class PilaDinamica { //Clase que representa la pila
private: //Acceso mediante el codigo
    Nodo* cima; // Apunta al nodo en la cima  de la pila

public: // Acceso libre
    PilaDinamica() : cima(nullptr) {} //Inicializacion del puntero cima cuando se crea un objeto en la PilaDinamica

    ~PilaDinamica() { // Destructor para liberar la memoria de la pila 
        while (cima != nullptr) { // Bucle para verificar que cima sea diferente a nulo
            pop(); // Elimina y devuelve el elemento que esta en la parte superior de la pila
        }
    }

    void push(int valor) { //Busca el valor en la pila 
        Nodo* nuevo = new Nodo; // Crea el nodo en la memoria y la alamacena en el puntero nuevo
        nuevo->dato = valor; // Asigna un valor a la variable dato
        nuevo->siguiente = cima; // El nuevo nodo apunta a la antigua cima
        cima = nuevo; // Actualiza la cima a este nuevo nodo 
    }
    int pop() { // 
        if (cima == nullptr) { //Ciclo para ver si cima es igual a nulo
            cout << "Pila Vacia (underflow)" << endl; // Imprime el mensaje en la consola 
            return -1; // Valor de error 
        }
        Nodo* temp = cima; // Declara puntero que apunte a cima
        int valor = temp->dato; //Declara la vaiable valor que apunte a temp dato
        cima = cima->siguiente; //La nueva cima es el siguiente nodo 
        delete temp; //Libera la memoria del nodo removido 
        return valor; //Retorna el valor y termina la ejecucion 
    }

    int peek() const { // Elimina y Devuelve un elemento  de la pila 
        if (cima== nullptr){ //Ciclo para verificar que cima sea igual a nulo
            cout << "Pila Vacia. " << endl; //Imprime el mensaje en la consola
            return -1; //Retorna -1 y finaliza la ejecucion
        }
        return cima->dato; //Retorna cima->dato y finaliza la ejecuucion 
    }
};

int main(){ // Incio del programa 
    PilaDinamica pila; // Se crea un llamado pila en la piladinamica 
    pila.push(100); // Se agrega una pila con el valor de 100
    pila.push(200); // Se agrega una pila con el valor de 200. Esta sera la cima de la pila 
    pila.push(300); // Se agrega una pila con el valor de 300. Esta sera la cima de la pila 
    cout << "Elemento en la cima: " << pila.peek() << endl; //Deberia mostrar 300
    cout << "Elemento eliminado: " << pila.pop() << endl; //300
    cout << "Elemento eliminado: " << pila.pop() << endl; //200
}
