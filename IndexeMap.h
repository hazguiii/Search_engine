#ifndef INDEXEMAP_H_INCLUDED
#define INDEXEMAP_H_INCLUDED
#include "Indexe.h"
#include <unordered_map>
#include "Stat.h"
#include <vector>
class IndexeMap:public Indexe{
public:
    unordered_map<int,Stat> Data;
    void addStats(vector<Stat> data) ;
    vector<Stat> getStats(string word) ;
    vector<Stat> getAllStats();
};

void IndexeMap::addStats(vector<Stat> data){
    for (Stat stat:data){
        Data[Data.size()] = stat;
    }
}
vector<Stat> IndexeMap::getStats(string word){
    vector<Stat> resultat;
    for(auto it = Data.begin();it!=Data.end();++it){
        if(it->second.mot == word){
            resultat.push_back(it->second);
        }
    }
    return resultat;
}

vector<Stat> IndexeMap::getAllStats(){
    vector<Stat> resultat;
    for (auto it = Data.cbegin();it!=Data.end();++it){

            resultat.push_back(it->second);


    }
    return resultat;
}

#endif // INDEXEMAP_H_INCLUDED
