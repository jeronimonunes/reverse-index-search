#ifndef SEARCHMACHINE_INCLUDED
#define SEARCHMACHINE_INCLUDED

#include "string"
#include "stdio.h"
#include "HashMap.h"
#include "Exception.h"

/**
* Class that represents a search machine.
*/
class SearchMachine{
        private:
            HashMap<string, Set<string>* >* index;

            /**
            * Makes shure that the string has only lower case letters.
            */
            string normalize(char* p){
                string word;
                for(int i=0;p[i];i++){
                    if(p[i]<='Z'&&p[i]>='A'){
                        word+=p[i]+32;
                    } else {
                        if(p[i]<='z'&&p[i]>='a') word+=p[i];
                    }
                }
                return word;
            }

        public:
            SearchMachine(){
                this->index = new HashMap<string, Set<string>* >(1000);
            }
            ~SearchMachine(){
                this->clear();
            }

            /**
            * Insert a file on the index.
            * @param fileName The name of the file to be read.
            * @param filePath The file directory.
            */
            void insertFile(string fileName, string filePath){
                FILE* file;
                file = fopen((filePath+fileName).c_str(), "r");
                if(file == NULL) throw Exception("It was not possible to read the file: " + fileName);
                char p[50];
                while((fscanf(file,"%s",p))!=EOF){
                    if(p[0]!=0){
                        string palavra = normalize(p);
                        Set<string>* set = index->get(palavra);
                        if(set == NULL) {
                            set = new Set<string>;
                            index->put(palavra,set);
                        }
                        set->insert(fileName);
                    }
                }

            };

            /**
            * Return the name of the files that contains the specified word.
            * @throw Exception when the word doesn't exist.
            */
            Set<string>* search(string word){
                Set<string>* set = index->get(normalize((char*)word.c_str()));
                if(set == NULL) throw Exception("The requested word \""+word+"\" is not present on the database");
                return set;
            };
            /**
            * Erases every single element inserted on the HashMap.
            */
            void clear(){
                Iterator<LinkedMap<string,Set<string>* > >* tableIterator = index->getIterator();
                while(tableIterator->hasNext()){
                    Iterator<Registry<string,Set<string>* > >* setIterator = tableIterator->next()->getIterator();
                    if(setIterator!=NULL && setIterator->hasNext()){
                        Registry<string,Set<string>* >* registry = setIterator->next();
                        Set<string>* set = registry->getValue();
                        delete set;
                    }
                }
            }

            void insertList(string listPath){
                FILE* file = fopen(listPath.c_str(),"r");
                if(file==NULL) throw Exception("It was not possible to read the list: "+listPath+"\n");
                char buffer[150];
                string fileName;
                string filePath;
                for(int i=0;fscanf(file,"%s",buffer)!=EOF;i++){
                    if(i%2){
                        fileName = string(buffer);
                        try{
                            this->insertFile(fileName,filePath);
                        } catch (Exception e){
                            throw Exception("It was not possible to insert the file please check if the file "+listPath+"\n Check if it has the format \"filePath fileName\"\n"+e.getMessage());
                        }
                    } else {
                        filePath = string(buffer);
                    }
                }
                fclose(file);
            }

};


#endif // SEARCHMACHINE_INCLUDED
