#ifndef INDEXELIST_H_INCLUDED
#define INDEXELIST_H_INCLUDED
#include "Indexe.h"
#include <list>
#include "Stat.h"
class IndexeList:public Indexe{
    public:
    list<Stat> Data;
    void addStats(vector<Stat> data) ;
    vector<Stat> getStats(string word) ;
    vector<Stat> getAllStats();

};

void IndexeList::addStats(vector<Stat> data){
    for (Stat stat:data){
        Data.push_back(stat);
    }
}

vector<Stat> IndexeList::getStats(string word){
    vector<Stat> resultat;
    for (auto it = Data.begin();it!= Data.end();++it){
        if (it->mot == word){
            resultat.push_back(*it);
        }
    }
    return resultat;
}
vector<Stat> IndexeList::getAllStats(){
    vector<Stat> resultat;
    for (auto it = Data.cbegin();it!=Data.end();++it){

            resultat.push_back(*it);

    }
    return resultat;
}
#endif // INDEXELIST_H_INCLUDED
