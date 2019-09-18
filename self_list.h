#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;
        unsigned int nodes;

    public:
        SelfList(Method method) : head(nullptr), nodes(0), method(method) {};

        void insert(T data) {
            auto newNode = new Node<T>(data);
            if (head != nullptr) {
                newNode->next = head;
                head = newNode;
            } else
                head = newNode;
            nodes++;
        }
             
        void remove(T data) {
            if (head != nullptr) {
                auto temp = head;
                if (head->data == data) {
                    if (head->next == nullptr) {
                        delete temp;
                        head = nullptr;
                    } else {
                        head = temp->next;
                        delete temp;
                    }
                    nodes--;
                }
                else {
                    auto tempPrev = head;
                    temp = temp->next;
                    for (unsigned int i = 1; i < size(); ++i, temp = temp->next) {
                        if (temp->data == data) {
                            while (tempPrev->next != temp)
                                tempPrev = tempPrev->next;
                            tempPrev->next = temp->next;
                            delete temp;
                            nodes--;
                        }
                    }
                }
            }
            if (size() == 0)
                head = nullptr;
        }  

        bool find(T data) {
            if (size() == 0)
                return false;
            //auto currentNode = head;
            switch (method) {
                case Move:
                    if (head->data == data)
                        return true;
                    else {
                        auto currentNode = head;
                        while (currentNode != nullptr) {
                            if (currentNode->next->data == data) {
                                auto node = currentNode->next;
                                currentNode->next = currentNode->next->next;
                                node->next = head;
                                head = node;
                                return true;
                            }
                            currentNode = currentNode->next;
                        }
                    }
                    break;
                case Transpose:
                    if (head->data == data)
                        return true;
                    else {
                        auto currentNode = head;
                        while (currentNode != nullptr) {
                            if (currentNode->next->data == data) {
                                swap(currentNode->data, currentNode->next->data);
                                return true;
                            }
                            currentNode = currentNode->next;
                        }
                    }
                    break;
                case Count:
                    if (head->data == data and size() == 1) {
                        head->count++;
                        return true;
                    } else {
                        auto currentNode = head;
                        while (currentNode != nullptr) {
                            if (currentNode->data == data) {
                                currentNode->count++;
                                Node<T>* temp = this->head;
                                bool isSorted = false;
                                while(!isSorted){
                                    if (currentNode->count >= temp->count ){
                                        std::swap(currentNode->data, temp->data);
                                        std::swap(currentNode->count, temp->count);
                                        isSorted = true;
                                    }
                                    temp = temp->next;
                                }
                            }
                            currentNode = currentNode->next;
                        }
                    }
                    break;
            }
            return false;
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

        ~SelfList() {
            if (head != nullptr)
                head->killSelf();
        }  
};

#endif