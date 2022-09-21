#ifndef ANALYSEURBINAIRE_H_INCLUDED
#define ANALYSEURBINAIRE_H_INCLUDED
#include "Analyseur.h"
#include "Stat.h"
#include <string.h>
class AnalyseurBinaire:public Analyseur{
public:
    vector<Stat> analyser(vector<string> motsTraitees,string fichier);
};

vector<Stat> AnalyseurBinaire::analyser(vector<string> motsTraitees,string fichier){
    vector<Stat> stats;
    for(string word:motsTraitees){
        if (stats.size() == 0){
            Stat stat;
            stat.mot = word;
            stat.fichier = fichier;
            stat.stat = 1.0;
            stats.push_back(stat);
        }
        else{
            bool stat = 0.0;
            for (unsigned i=0;i<stats.size();i++){
                if (stats[i].mot==word ){
                    stat = 1.0;
                    break;
                }

            }
        if (stat == 0.0){
            Stat stat;
            stat.mot = word;
            stat.fichier = fichier;
            stat.stat = 1.0;
            stats.push_back(stat);
        }
    }
}
    return stats;
};
#endif // ANALYSEURBINAIRE_H_INCLUDED
