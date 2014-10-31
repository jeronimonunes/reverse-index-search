#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include "set.h"

int split(string s, string words[],int size){
    string word;
    int j=0;
    bool end = true;
    for(int i=0;end;i++){
        if(s[i]==' ' || !s[i] ){
            if(!s[i]) end = false;
            if(j==size) throw Exception("Your string has too much words");
            words[j] = word;
            j++;
            word="";
        } else {
            word+=s[i];
        }
    }
    return j;
}

template<class T>
Set<T>* interseption(Set<T>* array[], int n){
    if(!n) throw Exception("The given vector is empty");
    Set<T>* first = NULL;
    int j;
    for(j=0; first == NULL; j++){
        if(array[j]->size()) first = array[j];
    }
    Set<T>* i1 = first;
    for(int i=j;i<n;i++){
        if(array[i]->size()){
            Set<T>* i2 = i1->interseption(array[i]);
            if(i1!=first) delete i1;
            i1 = i2;
        }
    }
    return i1;
}

#endif // UTIL_H_INCLUDED
