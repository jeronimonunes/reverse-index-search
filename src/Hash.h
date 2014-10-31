#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

/**
* Class container to Hash funcions.
* Should not be instantiated just used to get static hash funcions.
* @author Jerônimo Nunes Rocha
*/
class Hash{
    public:
        static unsigned int getHash(string value,int maxLength){
            unsigned int hash=0;
            for(int i=0;value[i];i++){
                hash<<=2;
                hash+=value[i];
            }
            return hash%maxLength;
        }
        static unsigned int getHash(int value,unsigned int maxLength){
            return value%maxLength;
        }
        static unsigned int getHash(char value,unsigned int maxLength){
            return (int) value%maxLength;
        }
};

#endif // HASH_H_INCLUDED
