#ifndef ARRAYITERATOR_H_INCLUDED
#define ARRAYITERATOR_H_INCLUDED

#include "Iterator.h"
/**
* Implementation of Iterator to be used with arrays.
* @author Jerônimo Nunes Rocha
* @see Iterator
*/
template<class Type>
class ArrayIterator:public Iterator<Type>{
    private:
        Type* list;
    public:
        ArrayIterator(Type* list,int size){
            this->list = list;
            this->size = size;
        }
        Type* next(){
            this->i++;
            return &list[this->i-1];
        }
};

#endif // ARRAYITERATOR_H_INCLUDED
