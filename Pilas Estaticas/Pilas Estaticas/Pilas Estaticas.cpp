#include <iostream> // Entrada y salida de datos 
using namespace std; //Evita usar std:: en la libreria estandar

class PilaEstatica { //Clase que representa la pila
private: //Acceso mediante el codigo
    static const int MAX = 10; //Tamaño fijo de la pila 
    int arr[MAX]; // Declaracion de array de tipo entero con la constante max
    int top; // Indice del ultimo elemento insertado

public: // Acceso libre
    PilaEstatica() : top(-1) {} // //Inicializacion del la variable top cuando se crea un objeto en la PilaEstatica
    bool push(int valor) { // declara una función llamada push que toma la variable entera valor
        if (top >= MAX - 1) { //Ciclo para verificar si top es menor o igual a MAX -1
            cout << "Pila esta llena (overflow). " << endl; // Imprime mensaje en la consola 
            return false; // Retorna falso y termina la ejecucion 
        }
        arr[++top] = valor; //Incrementa top e inserta el valor 
        return true; // Retorna verdadero y termina la ejecucion 
    }

    int pop() { // Declaracion de una funcion 
        if (top < 0) { //Ciclo para verificar si top es menor que 0
            cout << "Pila esta Vacia (underflow). " << endl; //Imprime el mensaje en la consola 
            return -1; //Valor de error 
        }
        return  arr[top--]; // Devuelve el elemento y decremento top
    }

    int peek() const { // Declaracion de una funcion constante 
        if (top < 0) { //Ciclo para veririfcar si top es menor que 0
            cout << "Pila Vacia" << endl; //Imprime el mensaje en la consola 
            return -1; //Retorna -1 y termina la ejecucion 
        }
        return arr[top]; // Retorna el array conla variable top dentro 
    }
};

int main() // Inicio del programa 
{
    PilaEstatica pila; // Se crea un llamado pila en la pilaestatica 
    pila.push(10); // Se agrega una pila con el valor de 10
    pila.push(20);// Se agrega una pila con el valor de 20. Esta sera la cima de la pila
    pila.push(30);// Se agrega una pila con el valor de 20. Esta sera la cima de la pila
    cout << "Elemento en la cima: " << pila.peek() << endl;  //Deberia mostrar 30
    cout << "Elemento eliminado: " << pila.pop() << endl; //30
    cout << "Elemento eliminado: " << pila.pop() << endl; //20

}
