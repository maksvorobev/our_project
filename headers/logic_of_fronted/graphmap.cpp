#include "graphmap.h"

graphmap::graphmap()
{

}

std::map<int, Block*> graphmap::getMap()
{
    return mp;
}

void graphmap::addItem(int i, Block* m)
{
    mp[i] = m;
}
