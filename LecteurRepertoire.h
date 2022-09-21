#ifndef LECTEURREPERTOIRE_H_INCLUDED
#define LECTEURREPERTOIRE_H_INCLUDED
#include "Lecteur.h"
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include "LecteurFichier.h"



class LecteurRepertoire:public Lecteur{
    public:
    vector<string> lire(string path);
};

vector<string> LecteurRepertoire::lire(string path){

    vector<string> mots,prov;
    LecteurFichier lecteur_fichier;
    string fileName="";
    DIR *dr;
    struct dirent *en;
    dr = opendir(path.c_str());
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            int i = 0;
            while(true){
                        if(en->d_name[i]=='.'){
                                if((en->d_name[i+1]=='t')&&(en->d_name[i+2]=='x')&&(en->d_name[i+3]=='t')){
                                    //in case he found a txt file
                                    fileName=path;
                                    fileName.append(en->d_name);
                                    prov = lecteur_fichier.lire(fileName);
                                    mots.insert(mots.end(),prov.begin(),prov.end());
                                    break;
                            }
                       }
            i++;
            if (i>260){break;}
          }
      }
        closedir(dr);
   }
         return mots;

}

#endif // LECTEURREPERTOIRE_H_INCLUDED
