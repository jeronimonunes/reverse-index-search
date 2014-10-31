#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "iostream"
#include "Node.h"
#include "Iterator.h"
#include "LinkedListIterator.h"

using namespace std;

template<class SType>
class Set {
      private:
       unsigned int size_;
       Node<SType>* end_;
     public:
      Set() {
      size_ = 0;
      end_ = new Node<SType>;
      end_->next = end_;
      end_->prev = end_;
    };

      bool empty() {
      return size_ == 0;
    };

      int size() {
      return size_;
    };

      Node<SType>* begin() {
      return end_->next;
    };

      Node<SType>* end() {
      return end_;
    };

      Node<SType>* next(Node<SType>* x) {
      return x->next;
    };

      Node<SType>* prev(Node<SType>* x) {
      return x->prev;
    };

      Node<SType>* find(SType k) {
      for (Node<SType>* i = begin(); i != end(); i = next(i)) {
        if (i->key == k) {
          return i;
        } else if (i->key > k) {
          return end();
        }
      }
      return end();  // k é maior que todos os elementos contidos no conjunto.
    };

      void insert(SType k) {
      Node<SType>* x = begin();
      while (x != end() && x->key < k) {
        x = next(x);
      }
      if (x == end() || x->key != k) {
        Node<SType>* node = new Node<SType>;
        node->key = k;
        node->prev = x->prev;
        node->next = x;
        x->prev->next = node;
        x->prev = node;
        size_++;
      }
    };

      SType erase(SType k) {
      Node<SType>* x = find(k);
      SType v = x->key;
      if (x != end()) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        delete x;
        size_--;
      }
      return v;
    };

    void clear() {
      while (!empty()) {
        erase(begin()->key);
      }
    };

    void operator=(Set<SType>& s) {
      clear();
      for (Node<SType>* i = s.begin(); i != s.end(); i = s.next(i)) {
        insert(s[i]);
      }
    };

    void print(){
        cout<<"{";
        Node<SType>* node=end_;
        while(node->next!=end()){
            node=node->next;
            cout<<node->key;
            if(node->next!=end()) cout<<",";
        }
        cout<<"}"<<endl;
    }

     SType operator[](Node<SType>* x) {
      return x->key;
    }

      ~Set() {
      clear();
      delete end_;
    };

    /**
    * Returns a Iterator Object to help iterate on the set.
    * @author Jerônimo Nunes Rocha
    */
    LinkedListIterator<SType>* getIterator(){
        return new LinkedListIterator<SType>(this->end_,this->size_);
    }

    /**
    * Returns the interseption of sets.
    * @param a The set to perform interseption with this.
    * return Set<SType> a new Set dynamically allocated that contains the interseption of the two ones.
    * @author Jerônimo Nunes Rocha
    */
    Set<SType>* interseption(Set<SType> *a){
        Set<SType>* interseption = new Set<SType>;
        Iterator<SType>* i = this->getIterator();
        while(i->hasNext()){
            SType* value = i->next();
            Node<SType>* found = a->find(*value);
            if(found != a->end()){
                interseption->insert(*value);
            }
        }
        return interseption;
    }

//    void operator=(Set<SType> &s){
//        this->clear();
//        Iterator<SType>* i = s.getIterator();
//        while(i->hasNext()){
//            this->insert(*i->next());
//        }
//    }
};

#endif
