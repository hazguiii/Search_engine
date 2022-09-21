#ifndef TRAITEURMINISCULE_H_INCLUDED
#define TRAITEURMINISCULE_H_INCLUDED
#include "Traiteur.h"

class TraiteurMiniscule:public Traiteur{
    public:
        vector<string> traiter (vector<string> mots);
};

vector<string> TraiteurMiniscule::traiter(vector<string> mots){
    for(unsigned i=0;i<mots.size();i++){
        transform(mots[i].begin(),mots[i].end(),mots[i].begin(),::tolower);
    };
    return mots;
};

#endif // TRAITEURMINISCULE_H_INCLUDED
