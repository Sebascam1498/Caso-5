#ifndef GRPPALABRAS_H
#define GRPPALABRAS_H

#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>



class GrpPalabras
{
    public:

    std::string textoOrigen;
    int cantidadPalabras;
    std::vector<std::string> grupoPalabras;

    GrpPalabras(std::string textoOrigen,int cantidadPalabras,std::vector<std::string> grupoPalabras);

    
};

#endif
