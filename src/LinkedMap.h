#ifndef LINKEDMAP_H_INCLUDED
#define LINKEDMAP_H_INCLUDED

#include "set.h"
#include "AbstractMap.h"
#include "Registry.h"
#include "Iterator.h"
#include "LinkedListIterator.h"
#include "Node.h"

/**
* Implementation of a Map estructure.
* This implementation uses a registry object to link keys to values,
* and it uses a set to store registries.
* @author Jerônimo Nunes Rocha
* @see Map
*/
template<class KeyType,class ValueType>
class LinkedMap:public Map<KeyType,ValueType>{
    private:
        Set< Registry<KeyType,ValueType> >* index;

        ValueType remove(Registry<KeyType,ValueType> reg){
            this->size--;
            return index->erase(reg).getValue();
        }
        ValueType insert(Registry<KeyType,ValueType> reg){
            index->insert(reg);
            this->size++;
            return reg.getValue();
        }
        ValueType get(Registry<KeyType,ValueType> reg){
            return index->find(reg)->key.getValue();
        }
    public:
        LinkedMap(){
            this->index = new Set< Registry<KeyType,ValueType> >;
        }
        ~LinkedMap(){
            delete this->index;
        }
        ValueType put(KeyType key,ValueType value){
            Registry<KeyType,ValueType> registry;
            registry.setKey(key);
            registry.setValue(value);
            return this->insert(registry);
        }
        ValueType get(KeyType key) {
            Registry<KeyType,ValueType> registry;
            registry.setKey(key);
            return this->get(registry);
        }
        ValueType remove(KeyType key){
            Registry<KeyType,ValueType> registry;
            registry.setKey(key);
            return this->remove(registry);
        }
        LinkedListIterator<Registry<KeyType,ValueType> >* getIterator(){
            return this->index->getIterator();
        }
        Set<Registry<KeyType,ValueType> >* getIndex(){
            return this->index;
        }

};

#endif
