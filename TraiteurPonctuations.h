#ifndef TRAITEURPONCTUATIONS_H_INCLUDED
#define TRAITEURPONCTUATIONS_H_INCLUDED
#include "Traiteur.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "LecteurFichier.h"
using namespace std;

class TraiteurPonctuations:public Traiteur{
    public:
        vector<string> traiter (vector<string> mots);
};
vector<string> TraiteurPonctuations::traiter(vector<string> mots){
    LecteurFichier lec;
    vector<string> punctuations = lec.lire("Punctuations.txt");
    for(unsigned i=0;i<mots.size();i++){
        for (string punctuation : punctuations){
            if (mots[i].find(punctuation)<mots[i].size()){
                mots[i].replace(mots[i].find(punctuation),mots[i].find(punctuation)+1,"");
                }
            }
    }

    return mots;
};


#endif // TRAITEURTYPIQUE_H_INCLUDED
