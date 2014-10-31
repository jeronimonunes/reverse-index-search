#ifndef ABSTRACTMAP_H_INCLUDED
#define ABSTRACTMAP_H_INCLUDED

/**
* Abstract class that represents a Map estructure.
* All Map implementations should inherite it.
* @author Jerônimo Nunes Rocha
*/
template<class KeyType,class ValueType>
class Map {
    protected:
        unsigned int size;
    public:
        Map(){
            this->size=0;
        }
        virtual ValueType put(KeyType key,ValueType value) = 0;
        virtual ValueType get(KeyType key) = 0;
        virtual ValueType remove(KeyType key) = 0;
        int length(){
            return this->size;
        }
};

#endif
