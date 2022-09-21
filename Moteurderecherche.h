#ifndef MOTEURDERECHERCHE_H_INCLUDED
#define MOTEURDERECHERCHE_H_INCLUDED
#include "Indexe.h"
#include "Stat.h"
#include <vector>
#include "Analyseur.h"
#include "Ordonnanceur.h"
#include "Lecteur.h"

#include "LecteurFichier.h"
#include "OrdonnanceurOccurence.h"
#include "TraiteurPonctuations.h"
#include "LecteurRepertoire.h"
#include "AnalyseurBinaire.h"
#include "AnalyseurFrequentiel.h"
#include "IndexeVector.h"
#include "IndexeMap.h"
#include "IndexeList.h"
#include "IndexeDeque.h"
#include "LecteurString.h"
#include "Moteurderecherche.h"
#include <string_view>
#include <dirent.h>
#include "AnalyseurOccurence.h"
#include "OrdonnanceurBinaire.h"

class MoteurRecherche{
    Lecteur* lecteur;
    vector<Traiteur*> traiteurs;
    Analyseur* analyseur;
    Indexe* indexe;
    Ordonnanceur* ordonnanceur;
public:
    Indexe* getIndexe(){return indexe;};
    MoteurRecherche(Lecteur* lect, vector<Traiteur*> traits, Analyseur* analy, Indexe* ind, Ordonnanceur* ord);
    void rechercher(vector<string> wordsReq);
    void indexer(string chemin);
};
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
MoteurRecherche::MoteurRecherche(Lecteur* lect, vector<Traiteur*> traits, Analyseur* analy, Indexe* ind, Ordonnanceur* ord):lecteur(lect),traiteurs(traits),analyseur(analy),
indexe(ind),ordonnanceur(ord){
        LecteurFichier lecteur_fichier;
        vector<Stat> vectStat;
        vector<string> stats = lecteur_fichier.lire("indexe.txt");
        for (string stat:stats){
            vector<string> prov = split(stat,"|");
            Stat s;
            s.mot = prov[0];
            s.fichier = prov[1];
            s.stat = stof(prov[2]);
            vectStat.push_back(s);
        }

        indexe->addStats(vectStat);

}


void MoteurRecherche::rechercher(vector<string> wordsReq){
    for (Traiteur* trait:traiteurs){
        wordsReq = trait->traiter(wordsReq);
        }
    ordonnanceur->ordonnancer(indexe,wordsReq);
}
void MoteurRecherche::indexer(string chemin){

            if (chemin[chemin.size()-1]=='/')
            {
                vector<string> mots;
                string fileName="";
                DIR *dr;
                struct dirent *en;
                dr = opendir(chemin.c_str());
                if (dr) {
                    while ((en = readdir(dr)) != NULL) {
                        int i = 0;
                        while(true){
                                    if(en->d_name[i]=='.'){
                                            if((en->d_name[i+1]=='t')&&(en->d_name[i+2]=='x')&&(en->d_name[i+3]=='t')){
                                                fileName=chemin;
                                                fileName.append(en->d_name);
                                                mots = lecteur->lire(fileName);
                                                for (Traiteur* trait:traiteurs){
                                                    mots = trait->traiter(mots);
                                                }
                                                vector<Stat> stats = analyseur->analyser(mots,fileName);
                                                indexe->addStats(stats);
                                                break;
                                        }
                                   }
                        i++;
                        if (i>260){break;}
                      }
                  }
                    closedir(dr);
               }


            }
            else
            {
                vector<string> mots = lecteur->lire(chemin);
                for (Traiteur* trait:traiteurs){
                    mots = trait->traiter(mots);
                }
                vector<Stat> stats = analyseur->analyser(mots,chemin);
                indexe->addStats(stats);

            }


}
#endif // MOTEURDERECHERCHE_H_INCLUDED
