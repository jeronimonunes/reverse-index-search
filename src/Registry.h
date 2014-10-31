#ifndef REGISTRY_H_INCLUDED
#define REGISTRY_H_INCLUDED

/**
* Object that links a certain key to a value.
* @author Jerônimo Nunes Rocha
*/
template<class KeyType,class ValueType>
class Registry {
    private:
        KeyType key;
        ValueType value;
    public:
    void setKey(KeyType key){
        this->key = key;
    }
    KeyType getKey(){
        return this->key;
    }
    void setValue(ValueType value){
        this->value = value;
    }
    ValueType getValue(){
        return this->value;
    }
    /**
    * Returns true if the two objects share the same key.
    */
    bool operator==(Registry<KeyType,ValueType> reg){
        return reg.getKey()==this->getKey();
    }
    /**
    * Returns true if the two objects don't share the same key.
    */
    bool operator!=(Registry<KeyType,ValueType> reg){
        return reg.getKey()!=this->getKey();
    }
    /**
    * Returns true if the the given object has a bigger key.
    */
    bool operator<(Registry<KeyType,ValueType> reg){
        return this->getKey()<reg.getKey();
    }
    /**
    * Returns true if the the given object has a smaller key.
    */
    bool operator>(Registry<KeyType,ValueType> reg){
        return this->getKey()>reg.getKey();
    }
};

#endif
