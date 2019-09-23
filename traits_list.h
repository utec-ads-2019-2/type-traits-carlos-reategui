#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        unsigned int nodes;

        bool find(T data, Node<T> **&pointer) {
            pointer = &head;
            while(*pointer != nullptr) {
                if (cmp((*pointer)->data, data)) {
                    if ((*pointer)->data == data)
                        return true;
                }
                // Podrías agregar esto a la condición del while para reducir esta línea
                else
                    return false;
                pointer = &((*pointer)->next);
            }
            return false;
        }
              
    public:
        TraitsList() : head(nullptr), nodes(0) {};
             
        bool insert(T data) {
            Node<T> **pointer = nullptr;
            if(!find(data,pointer)){
                auto newNode = new Node<T>(data);
                newNode->next = *pointer;
                *pointer = newNode;
                nodes++;
                return true;
            }
            return false;
        }
             
        bool remove(T data) {
            Node<T> **pointer = &head;
            if (find(data, pointer)){
                Node<T>* toDelete = *pointer;
                *pointer = (*pointer)->next;
                delete toDelete;
                nodes--;
                return true;
            }
            return false;
        }  

        bool find(T data) {
            Node<T> **pointer = nullptr;
            return find(data, pointer);
        }

        T operator [] (int index) {
            if (size() >= 0 and index < size()){
                auto currentNode = head;
                for (unsigned int i = 0; i < index; ++i)
                    currentNode = currentNode->next;
                return currentNode->data;
            }
            throw out_of_range("Index out of range.");
        }
             
        int size() {
            return nodes;
        }

        void print() {
            if (head != nullptr) {
                auto currentNode = head;
                for (unsigned int i = 0; i < size(); ++i, currentNode = currentNode->next)
                    cout << currentNode->data << ' ';
                cout << '\n';
            } else
                cout << "The list is empty.\n";
        }

        ~TraitsList() {
            if (head != nullptr)
                head->killSelf();
        }         
};

#endif