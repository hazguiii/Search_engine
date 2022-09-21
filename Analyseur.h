#ifndef ANALYSEUR_H_INCLUDED
#define ANALYSEUR_H_INCLUDED
#include "Stat.h"
class Analyseur{
public:
    virtual vector<Stat> analyser(vector<string> motsTraitees,string fichier) = 0;
};

#endif // ANALYSEUR_H_INCLUDED
