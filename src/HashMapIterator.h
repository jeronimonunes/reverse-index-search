#ifndef HASHMAPITERATOR_H_INCLUDED
#define HASHMAPITERATOR_H_INCLUDED
#include "Iterator.h"
#include "ArrayIterator.h"
#include "LinkedListIterator.h"
template<class KeyType,class ValueType>
class HashMapIterator:public Iterator<Registry<KeyType,ValueType> >{
    private:
        Iterator<LinkedMap<KeyType,ValueType> >* tableIterator;
        Iterator<Registry<KeyType,ValueType> >* setIterator;
        bool tableHasNext;
        bool setHasNext;
        int tableSize;

    public:
        HashMapIterator(LinkedMap<KeyType,ValueType>* table, int tableSize, int size){
            this->size = size;
            this->tableSize = tableSize;
            this->tableIterator = new ArrayIterator<LinkedMap<KeyType,ValueType> >(table,tableSize);
            this->setIterator == NULL;
            while(tableIterator->hasNext() && setIterator == NULL){
                setIterator = tableIterator->next()->getIterator();
                if(!setIterator->hasNext()) setIterator = NULL;
            }
            if(setIterator == NULL) this->size = 0;
            setIterator->hasNext();
//            while(setIterator->hasNext()){
//                Registry<string,string>* reg = setIterator->next();
//                cout<<reg->getKey()<<endl;
//            }
        }
        Registry<KeyType,ValueType>* next(){
        return NULL;
            Registry<KeyType,ValueType>* registry;
            if(setIterator->hasNext()){
                registry = setIterator->next();
            } else {
                this->setIterator == NULL;
                while(tableIterator->hasNext() && setIterator == NULL){
                    setIterator = tableIterator->next()->getIterator();
                    if(!(setIterator->hasNext())) setIterator = NULL;
                }
            }
            this->i++;
            return registry;
        }

};

#endif // HASHMAPITERATOR_H_INCLUDED
