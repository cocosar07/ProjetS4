#ifndef MICROCOMMANDE_HPP_INCLUDED
#define MICROCOMMANDE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "stringFunctions.hpp"

typedef std::vector<std::string> Parametre;

#define COMMANDE_NAME 0
#define COMMANDE_CODE 1
#define PARAM_SEPARATOR ';'
#define CHOICE_SEPARATOR ' '
#define NUMBER_CHARACTER "?"

class Microcommande
{
public:
    Microcommande(std::string &code, std::vector<Parametre> &params);

    static std::vector<Microcommande>* loadFromFile(std::string filename);

private:
    std::string m_code;
    std::vector<Parametre> m_params;
};

#endif // MICROCOMMANDE_HPP_INCLUDED
