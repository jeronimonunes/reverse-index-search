#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

/**
* Abstract class used to iterate over list of elements.
* @author Jerônimo Nunes Rocha
*/
template<class Type>
class Iterator{
    protected:
        int size;
        int i;
    public:
        int length(){
            return this->size;
        }
        Iterator(){
            this->i=0;
        }
        /**
        * Returns true if there is more elements to iterate.
        * Auto closes the vector when the end of the list is achieved.
        */
        virtual bool hasNext(){
            bool value = i<size;
            if(!value) delete this;
            return value;
        }
        /**
        * Should be implemented by the child classes.
        * Returns the next element and moves the pointer forward.
        */
        virtual Type* next() = 0;
        /**
        * Closes the iterator.
        * Should be used only if the end of the vector hasn't been achieved.
        */
        void close(){
            delete this;
        }
};


#endif // ITERATOR_H_INCLUDED
