#ifndef SYSTEMFACTORY_H
#define SYSTEMFACTORY_H

#include <vector>
#include "System.h"

class SystemFactory
{
    public:
        std::vector<System *> *createSystems();
    protected:
    private:
};

#endif 
