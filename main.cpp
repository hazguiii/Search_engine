#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include "LecteurFichier.h"
#include "OrdonnanceurOccurence.h"
#include "TraiteurPonctuations.h"
#include "LecteurRepertoire.h"
#include "AnalyseurBinaire.h"
#include "AnalyseurFrequentiel.h"
#include "IndexeVector.h"
#include "IndexeMap.h"
#include "IndexeList.h"
#include "TraiteurMotsVides.h"
#include "IndexeDeque.h"
#include "LecteurString.h"
#include "Moteurderecherche.h"
#include <string_view>
#include <dirent.h>
#include "AnalyseurOccurence.h"
#include <sys/types.h>
#include <fstream>
#include <chrono>


using namespace std;



void saveIndexe(MoteurRecherche* moteur){
    ofstream file;
    file.open("indexe.txt",ios_base::out);
for (Stat stat: moteur->getIndexe()->getAllStats()){
    file << stat.mot << "|" << stat.fichier << "|" << stat.stat << endl ;
}

}




int main(int nbArguments, char *arguments[])
{
   auto start = chrono::high_resolution_clock::now();

    Lecteur* lect;
    vector<Traiteur*> traiteurs;
    Indexe* ind;
    Analyseur* analy;
    Ordonnanceur* ord;

    LecteurFichier* lectConfig = new LecteurFichier();
    vector<string> config = lectConfig->lire("config.txt");
    delete lectConfig;
    for (unsigned i = 0 ; i<5;i++){
    if (i == 0){

        if (config[i] == "fichier"){LecteurFichier* lectfich = new LecteurFichier(); lect =lectfich; }
    }
    if (i == 1){
        vector<string> traits = split(config[i],"/");
        for (string trait:traits){
            if (trait == "emptywords"){TraiteurMotsVides* trait_mots_vides = new TraiteurMotsVides(); traiteurs.push_back(trait_mots_vides);}
            else if (trait == "punctuations"){TraiteurPonctuations* trait_ponctuations = new TraiteurPonctuations(); traiteurs.push_back(trait_ponctuations);}
            else if (trait == "lowercase"){TraiteurMiniscule* trait_miniscule = new TraiteurMiniscule(); traiteurs.push_back(trait_miniscule);}
        }
    }
    if (i == 2){
        if (config[i] == "binaire"){AnalyseurBinaire* analy_binaire = new AnalyseurBinaire(); analy = analy_binaire;}
        else if (config[i] == "occurence"){AnalyseurOccurence* analy_occ = new AnalyseurOccurence(); analy = analy_occ;}
        else if (config[i] == "frequentiel"){AnalyseurFrequentiel* analy_freq = new AnalyseurFrequentiel(); analy = analy_freq;}
    }
    if (i == 3){
        if (config[i] == "vector"){IndexeVector* indvec = new IndexeVector(); ind = indvec;}
        else if (config[i] == "map"){IndexeMap* indmap = new IndexeMap(); ind = indmap;}
        else if (config[i] == "list"){IndexeList* indlist = new IndexeList(); ind = indlist;}
        else if (config[i] == "deque"){IndexeDeque* inddeque = new IndexeDeque(); ind = inddeque;}
            ;
        }
    if (i == 4){
        if (config[i] == "binaire"){OrdonnanceurBinaire* ord_binaire = new OrdonnanceurBinaire(); ord = ord_binaire;}
        else if (config[i] == "occurence" || config[i] == "frequentiel"){OrdonnanceurOccurence* ord_occ = new OrdonnanceurOccurence(); ord = ord_occ;}
    }
    }


    MoteurRecherche* moteur = new MoteurRecherche(lect,traiteurs,analy,ind,ord);
    switch (nbArguments)
    {
    case (1):
    {
        cout << "Nombre d'arguments invalide!";
        break;
    }
    case (2):
    {
        if ((strcmp(arguments[1], "indexer") == 0) || (strcmp(arguments[1], "add") == 0) || (strcmp(arguments[1], "delete") == 0))
        {
            cout << "Missing path";
            break;
        }
        else if (strcmp(arguments[1], "rechercher") == 0)
        {
            cout << "Missing Request";
            break;
        }
        else if (strcmp(arguments[1], "showIndex") == 0)
        {
            cout << "index :"<< endl;
                 for (Stat stat:moteur->getIndexe()->getAllStats()){
                    cout << stat.mot << endl << stat.fichier << endl << stat.stat << endl ;
                }
            break;
        }
    }
    case (3):
    {
        if (strcmp(arguments[1], "indexer") == 0)
        {
            moteur->indexer(arguments[2]);
            break;
        }


    }
    default:{
    if (strcmp(arguments[1], "rechercher") == 0)
        {
            vector<string> req ;
            for (unsigned i = 2; i < nbArguments; i++)
            {
                req.push_back(arguments[i]);

            }
            moteur->rechercher(req);
            break;
        }
    }


    }


    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    cout << duration.count() << " seconds" << endl;
    saveIndexe(moteur);
    return 0 ;

}
