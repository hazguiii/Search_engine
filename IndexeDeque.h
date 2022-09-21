#ifndef INDEXEDEQUE_H_INCLUDED
#define INDEXEDEQUE_H_INCLUDED
#include "Indexe.h"
#include <deque>
#include <vector>
#include "Stat.h"
class IndexeDeque:public Indexe{
public:
    deque<Stat> Data;
    void addStats(vector<Stat> data) ;
    vector<Stat> getStats(string word) ;
    vector<Stat> getAllStats();
};

void IndexeDeque::addStats(vector<Stat> data){
    for (Stat stat:data){
        Data.push_back(stat);
    }
}

vector<Stat> IndexeDeque::getStats(string word){
    vector<Stat> resultat;
    for (auto it = Data.cbegin();it!=Data.end();++it){
        if(it->mot == word){
            resultat.push_back(*it);
        }
    }
    return resultat;
}

vector<Stat> IndexeDeque::getAllStats(){
    vector<Stat> resultat;
    for (auto it = Data.cbegin();it!=Data.end();++it){

            resultat.push_back(*it);

    }
    return resultat;
}

#endif // INDEXEDEQUE_H_INCLUDED
