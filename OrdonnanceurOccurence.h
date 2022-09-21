#ifndef ORDONNANCEUROCCURENCE_H_INCLUDED
#define ORDONNANCEUROCCURENCE_H_INCLUDED
#include "Ordonnanceur.h"
#include <map>
#include "Indexe.h"
class OrdonnanceurOccurence:public Ordonnanceur{
public:
    void ordonnancer(Indexe* ind,vector<string> req);
};
void OrdonnanceurOccurence::ordonnancer(Indexe* ind, vector<string> req){
    for(string motReq: req){
            cout<< motReq<<" :"<<endl;
        map<string,double> resultat;
        for (Stat stat:ind->getStats(motReq)){
            resultat[stat.fichier] = stat.stat;
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
}

#endif // ORDONNANCEUROCCURENCE_H_INCLUDED
