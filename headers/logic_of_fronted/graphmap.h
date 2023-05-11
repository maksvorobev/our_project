#ifndef GRAPHMAP_H
#define GRAPHMAP_H
#include <map>
#include "./headers/block.h"

class graphmap
{
public:
    graphmap();
    std::map<int, Block*> getMap();
    void addItem(int i, Block* m);
private:
    std::map<int, Block*> mp;
};

#endif // GRAPHMAP_H
