#ifndef ORDONNANCEURBINAIRE_H_INCLUDED
#define ORDONNANCEURBINAIRE_H_INCLUDED
#include "Ordonnanceur.h"
#include <map>
class OrdonnanceurBinaire:public Ordonnanceur{
    public:
        void ordonnancer(Indexe* ind,vector<string> req);
};
void OrdonnanceurBinaire::ordonnancer(Indexe* ind,vector<string> req){

    map<string,int> resultat;
    for (string word:req){
        for (Stat stat:ind->getStats(word)){
                if (resultat.find(stat.fichier)==resultat.end()){resultat[stat.fichier] = 1;}
                else{resultat[stat.fichier]++;}

        }
    }
    while(resultat.size()!=0){
        int maximumInt = 0;
        string maximumFichier = "";

        for(auto it = resultat.begin();it!=resultat.end();++it){
            if (it->second>maximumInt){
                maximumInt = it->second;
                maximumFichier = it->first;
            }
    }
    cout << maximumFichier <<endl;
    resultat.erase(maximumFichier);
    }

}
#endif // ORDONNANCEURBINAIRE_H_INCLUDED
