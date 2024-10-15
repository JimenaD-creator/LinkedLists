#include <iostream>
using namespace std;

struct Node{
    int data; //Entero que almacena el valor del nodo
    Node* next; //Un puntero al siguiente nodo
};
class LinkedList{
    private:
    Node *head;
    public:
    LinkedList(){ //Constructor para inicializar la cabeza
        head = nullptr;
    }
    void addNode(Node* &head, int value){ //"Head" identificar la cabeza actual del nodo
     Node* newNode = new Node(); //Crear un nuevo Nodo dinámicamente en memoria
     //*newNode.data = value
     newNode -> data = value; //Asignación del valor pasado a la función (value) al campo data del nuevo nodo
     newNode -> next = nullptr; //El siguiente nodo es un nullptr
     if(head == nullptr){
        head = newNode; // Si la lista está vacía el nuevo nodo es la head
     }else{
        Node* temp = head; //Crear una variable temporal que almacene el current head
        //Recorrer toda la lista para añadir un nuevo valor y se detiene hasta encontrar el último nodo
        while(temp -> next != nullptr){ 
            temp = temp -> next; //Avanza al siguiente nodo de la lista 

        }
        temp -> next = newNode; //Enlaza el último nodo de la lista al nuevo nodo
     }

}

void removeNode(Node *&head, int value){
    if(head == nullptr){
        cout << "La lista está vacía" <<endl;
        return;
    }
    Node *temp = head;
    Node *prev = nullptr;

    while(temp != nullptr && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    //Si no se encuentra el nodo
    if(temp == nullptr){
        cout << "Nodo con valor " << value << "no encontrado" <<endl;
        return;
    }
    //Si el nodo a eliminar es la cabeza
    if(prev == nullptr){
        head = temp ->next;
    }else{
        prev->next = temp->next;
    }
    delete temp;
    cout << "\nNodo con valor " <<value<< " eliminado"<<endl;



};
Node* searchNode(Node *&head, int value){
    Node *temp = head;
    while(temp != nullptr){
        if(temp->data == value){ //Si encuentra el valor retorna el nodo
            return temp;
        }
        temp = temp->next; //Avanza al siguiente nodo

    }
    return nullptr; //Retorna nullptr si no encuentra el valor

}
void showList(Node* head){
    Node* temp = head;
    while(temp != nullptr){ //Recorre la lista hasta que no haya más nodos
        cout << temp -> data << "-> "; //Muestra el valor almacenado en el nodo actual
        temp = temp -> next; //Avanza al siguiente nodo en la lista
    }

}


};

int main(){
    Node* list = nullptr;
    LinkedList linkedlist;
    linkedlist.addNode(list, 40);
    linkedlist.addNode(list, 50);
    linkedlist.addNode(list, 100);

    cout << "\nLista de valores: "<<endl;
    linkedlist.showList(list);

    linkedlist.removeNode(list, 50);
    cout << "Lista de valores: "<<endl;
    linkedlist.showList(list);

    int searchValue = 100;
    Node *foundNode = linkedlist.searchNode(list, searchValue);

    if(foundNode != nullptr){
        cout << "\nNodo con valor " << searchValue << " encontrado." << endl <<endl;
    }else{
        cout << "\nNodo con valor " << searchValue << " no encontrado." << endl<<endl;
    }


}