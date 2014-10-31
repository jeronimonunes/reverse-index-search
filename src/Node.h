#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<class SType>
struct Node{
  SType key;
  Node<SType>* prev;
  Node<SType>* next;
};

#endif // NODE_H_INCLUDED
