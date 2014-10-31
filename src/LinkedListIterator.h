#ifndef LINKEDLISTITERATOR_INCLUDED
#define LINKEDLISTITERATOR_INCLUDED

#include "Node.h"
#include "Iterator.h"
/**
* Implementation of Iterator to be used with linkedList.
* @author Jerônimo Nunes Rocha
* @see Iterator
*/
template<class Type>
class LinkedListIterator:public Iterator<Type>{
    private:
        Node<Type>* list;
    public:
        LinkedListIterator(Node<Type>* list,int size){
            this->list = list;
            this->size = size;
        }
        Type* next(){
        this->i++;
            return &((this->list = list->next)->key);
        }

};


#endif // LINKEDLISTITERATOR_INCLUDED
