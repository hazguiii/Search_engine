#ifndef LECTEURFICHIER_H_INCLUDED
#define LECTEURFICHIER_H_INCLUDED
#include "Lecteur.h"

class LecteurFichier:public Lecteur{
    public:
        vector<string> lire(string path);
};

vector<string> LecteurFichier::lire(string path){
    vector<string> mots;
    string mot;
    ifstream fichier(path);
    if (!fichier.is_open()){
        cout << "Impossible d'ouvrir le fichier"<<endl;
        return mots;
    }
    while(fichier >> mot){
        mots.push_back(mot);
    }

    fichier.close();
    return mots;

}


#endif // LECTEURFICHIER_H_INCLUDED
