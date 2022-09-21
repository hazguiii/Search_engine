#ifndef INDEXEVECTOR_H_INCLUDED
#define INDEXEVECTOR_H_INCLUDED
#include "Indexe.h"
#include <vector>
#include "LecteurFichier.h"
#include "TraiteurMiniscule.h"
#include "LecteurRepertoire.h"
#include "AnalyseurBinaire.h"
#include "Stat.h"
class IndexeVector:public Indexe{
public:
    vector<Stat> Data;
    void addStats(vector<Stat> data);
    vector<Stat> getStats(string word);
    vector<Stat> getAllStats();

};

void IndexeVector::addStats(vector<Stat> data){

    for (Stat stat : data){
        Data.push_back(stat);
}
}
vector<Stat> IndexeVector::getStats(string word){
    vector<Stat> Res;
    for (Stat stat: Data){
        if (stat.mot == word){
            Res.push_back(stat);
        }
    }

    return Res;
}
vector<Stat> IndexeVector::getAllStats(){
    vector<Stat> resultat;
    for (auto it = Data.cbegin();it!=Data.end();++it){

            resultat.push_back(*it);

    }
    return resultat;
}
#endif // INDEXEVECTOR_H_INCLUDED
