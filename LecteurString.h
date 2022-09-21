#ifndef LECTEURSTRING_H_INCLUDED
#define LECTEURSTRING_H_INCLUDED
#include "Lecteur.h"
class LecteurString{
public:
    vector<string> lire(string str);
};
vector<string> LecteurString::lire(string str){
    vector<string> words;
    string temp = "";
	for(unsigned i=0;i<str.size();++i){

		if(str[i]==' '){
			words.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(str[i]);
		}

	}
	words.push_back(temp);
	return words;
}


#endif // LECTEURSTRING_H_INCLUDED
