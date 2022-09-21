#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class Lecteur{
public:
    virtual vector<string> lire(string path) = 0;
};

#endif // LECTEUR_H_INCLUDED
