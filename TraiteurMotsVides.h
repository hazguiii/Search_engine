#ifndef TRAITEURMOTSVIDES_H_INCLUDED
#define TRAITEURMOTSVIDES_H_INCLUDED
#include "Traiteur.h"

class TraiteurMotsVides:public Traiteur{
    public:
        vector<string> traiter (vector<string> mots);
};

vector<string> TraiteurMotsVides::traiter(vector<string> mots){
    LecteurFichier lecteurEmptyWords;
    vector<string> emptyWords = lecteurEmptyWords.lire("EmptyWords.txt");

    unsigned i = 0;
    while(i<mots.size()){
        if (find(emptyWords.begin(),emptyWords.end(),mots[i]) != emptyWords.end()){
            mots.erase(mots.begin()+i);
        }
        else{
        i++;
        }
    }
    return mots;
};


#endif // TRAITEURMOTSVIDES_H_INCLUDED
