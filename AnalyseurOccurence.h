#ifndef ANALYSEUROCCURENCE_H_INCLUDED
#define ANALYSEUROCCURENCE_H_INCLUDED
#include "Analyseur.h"
class AnalyseurOccurence:public Analyseur{
public:
    vector<Stat> analyser(vector<string> motsTraitees,string fichier);
};

bool existe(string mot, vector<Stat> tab){
    for (Stat stat:tab){
        if (stat.mot==mot){
            return true;
        }
    }
    return false;
}

vector<Stat> AnalyseurOccurence::analyser(vector<string> motsTraitees,string fichier){
    vector<Stat> resultat;
    for (string word:motsTraitees){
        if(existe(word,resultat)){
            int i=0;
            while(true){
                if (resultat.size()==0){break;}
                if (resultat[i].mot == word){
                    resultat[i].stat+=1.0;
                    break;
                }
            i++;

            }
        }
        else{
            Stat motStat;
            motStat.mot = word;
            motStat.fichier = fichier;
            motStat.stat = 1.0;
            resultat.push_back(motStat);
        }
    }
    return resultat;
}




#endif // ANALYSEUROCCURENCE_H_INCLUDED
