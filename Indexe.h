#ifndef INDEXE_H_INCLUDED
#define INDEXE_H_INCLUDED
#include <vector>
class Indexe{
public:
    virtual void addStats(vector<Stat> data) = 0;
    virtual vector<Stat> getStats(string word) = 0;
    virtual vector<Stat> getAllStats() = 0;
};



#endif // INDEXE_H_INCLUDED
