#include <iostream>
#include "src/Iterator.h"
#include "src/LinkedMap.h"
#include "src/SearchMachine.h"
#include "src/Registry.h"
#include "src/Util.h"

using namespace std;


/**
* A search machine, enter the word to search or :q to quite;
* It will automatically read the file list.txt on the program path.
* @author Jerônimo Nunes Rocha
*/
int main()
{
    try{
        SearchMachine sm;
        sm.insertList("list.txt");
        string buffer;
        while(buffer!=":q"){
            getline(cin,buffer,'\n');
            if(buffer!=":q"){
                try{
                    string words[11];
                    int wordsNumber = split(buffer,words,11);
                    Set<string>* array[wordsNumber];
                    for(int i=0;i<wordsNumber;i++){
                        array[i] = sm.search(words[i]);
                    }
                    Set<string>* answear = interseption(array,wordsNumber);
                    answear->print();
                    bool del=true;
                    for(int i=0;i<wordsNumber;i++){
                        if(array[i]==answear) del=false;
                    }
                    if(del) delete answear;
                } catch (Exception e){
                    e.print();
                }
            }
        }
    } catch(Exception e) {
        e.print();
    }

    return 0;
}
