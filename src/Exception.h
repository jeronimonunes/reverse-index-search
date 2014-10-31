#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include "iostream"

using namespace std;
/**
* Class that defines a exception on the normal aspect.
* Should be used when throwing stuff.
* @author Jerônimo Nunes Rocha
*/
class Exception {
    private:
        string message;
    public:
        Exception(string message){
            this->setMessage(message);
        }

        Exception(){ }

        string getMessage(){
            return this->message;
        }

        void setMessage(string message){
            this->message = message;
        }

        /**
        * Prints the error message on stdout.
        */
        void print(){
            cout<<this->getMessage()<<endl;
        }
};


#endif // EXCEPTION_H_INCLUDED
