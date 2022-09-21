#ifndef ORDONNANCEUR_H_INCLUDED
#define ORDONNANCEUR_H_INCLUDED
#include <vector>
#include "Stat.h"
#include "Indexe.h"
class Ordonnanceur{
public:
    virtual void ordonnancer(Indexe* ind, vector<string> req) = 0;
};

#endif // ORDONNANCEUR_H_INCLUDED
