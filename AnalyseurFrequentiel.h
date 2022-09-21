#ifndef ANALYSEURFREQUENTIEL_H_INCLUDED
#define ANALYSEURFREQUENTIEL_H_INCLUDED
#include "Analyseur.h"
#include "AnalyseurOccurence.h"
#include "Stat.h"
#include "LecteurFichier.h"
#include <vector>
class AnalyseurFrequentiel:public Analyseur{
public:
    vector<Stat> analyser(vector<string> motsTraitees, string cheminFichier );

};

vector<Stat> AnalyseurFrequentiel::analyser(vector<string> motsTraitees, string cheminFichier){

    LecteurFichier lect;
    vector<string> mots_totales_fichier = lect.lire(cheminFichier);
    int totale = mots_totales_fichier.size();
    AnalyseurOccurence Analy;
    vector<Stat> nombres_occurence_mots = Analy.analyser(motsTraitees,cheminFichier),resultat;
    for (Stat stat : nombres_occurence_mots){
        Stat statistique_provisoire;
        statistique_provisoire.mot = stat.mot;
        statistique_provisoire.fichier = stat.fichier;
        statistique_provisoire.stat = stat.stat/totale;
        resultat.push_back(statistique_provisoire);
    }

    return resultat;
}

#endif // ANALYSEURFREQUENTIEL_H_INCLUDED
