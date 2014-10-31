#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED

#include "set.h"
#include "LinkedMap.h"
#include "Hash.h"
#include "Iterator.h"
#include "ArrayIterator.h"
#include "LinkedListIterator.h"
#include "stdio.h"
#include "stdlib.h"

/**
* A class that implements a HashMap.
* @author Jerônimo Nunes  Rocha
*/
template<class KeyType,class ValueType>
class HashMap:public Map<KeyType,ValueType> {
    private:
        LinkedMap<KeyType,ValueType>* table;
        int tableSize;

    public:
    HashMap(int tableSize){
        this->tableSize = tableSize;
        this->table = new LinkedMap<KeyType,ValueType>[tableSize];
    }
    /**
    * Inserts a new element on the HashMap.
    * @param key The key of the element.
    * @param value The value of the element.
    * @return the same value that had been given.
    */
    ValueType put(KeyType key,ValueType value){
//        if(this->tableSize == this->size) this->rehash(2*this->tableSize);
        this->table[Hash::getHash(key,this->tableSize)].put(key,value);
        this->size++;
        return value;
    };
    /**
    * Finds a element on the hashMap.
    * @param key The key of the element.
    * @return The value of the element.
    */
    ValueType get(KeyType key){
        return this->table[Hash::getHash(key,this->tableSize)].get(key);
    };
    /**
    * Removes the element with the given key.
    * @param key The key of the element.
    * @return The value of the deleted element.
    */
    ValueType remove(KeyType key){
        this->size--;
        return this->table[Hash::getHash(key,this->tableSize)].remove(key);
    }
    /**
    * Gives a object to be used as a iterator of the list.
    * @return Iterator
    */
    Iterator<LinkedMap<KeyType,ValueType> >* getIterator(){
        return new ArrayIterator<LinkedMap<KeyType,ValueType> >(table,tableSize);
    }
    /**
    * Não sei por que não funcionou, tentei fazer usando o iterator e também iterando diretamente
    * nos elementos mas simplesmente não funcionou, por isso pus um tamanho fixo para a tabela hash.
    * Changes the table hash size.
    * @param m the new table hash size.
    * @throw Exception
    */
    void rehash(int m){
        LinkedMap<KeyType,ValueType>* oldtable = this->table;
        LinkedMap<KeyType,ValueType>* newTable = new LinkedMap<KeyType,ValueType>[m];
        for(int i=0;i<this->tableSize;i++){
            Set<Registry<KeyType,ValueType> >* set = oldtable[i].getIndex();
            if(set->size()){
                Node<Registry<KeyType,ValueType> >* node;
                for(node = set->begin(); node!=set->end() ; node = set->next(node)){
                    Registry<KeyType,ValueType> registry = node->key;
                    KeyType key = registry.getKey();
                    ValueType value = registry.getValue();
                    newTable[Hash::getHash(key,m)].put(key,value);
                }
            }
        }
        this->table = newTable;
        this->tableSize = m;
        delete [] oldtable;
        std::cout<<"oi"<<endl;
//        exit(0);

    }
//    void rehash(int m){
//        LinkedMap<KeyType,ValueType>* oldtable = this->table;
//        Iterator<LinkedMap<KeyType,ValueType> >* iterator = this->getIterator();
//        LinkedMap<KeyType,ValueType>* newTable = new LinkedMap<KeyType,ValueType>[m];
//        if(newTable != NULL){
//            cout<<iterator->length()<<endl;
//            cout<<(iterator->hasNext()?"sim":"não") <<endl;
//            while(iterator->hasNext()){
//                LinkedMap<KeyType,ValueType>* list = iterator->next();
//                Iterator<Registry<KeyType,ValueType> >* listIterator = list->getIterator();
//
//                while(listIterator->hasNext()){
//                cout<<listIterator->length()<<endl;
//            cout<<(listIterator->hasNext()?"sim":"não") <<endl;
//                    Registry<KeyType,ValueType>* registry = listIterator->next();
//                    KeyType key = registry->getKey();
//                    ValueType value = registry->getValue();
//                    newTable[Hash::getHash(key,m)].put(key,value);
//                }
//            }
//            this->table = newTable;
//            this->tableSize = m;
//            delete [] oldtable;
//        }
//    }
};

#endif
