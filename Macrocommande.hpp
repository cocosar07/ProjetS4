#ifndef MACROCOMMANDE_HPP_INCLUDED
#define MACROCOMMANDE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "stringFunctions.hpp"

#define COMMANDE_NAME 0
#define MICROCOMMANDE_SEPARATOR ';'

class Macrocommande
{
public:
    Macrocommande(std::string name, std::vector<std::string> microcommandes);

    static std::vector<Macrocommande>* loadFromFile(std::string filename);

    void resetCurseur();
    std::string recupProchaineMicrocommande();
    unsigned int getMicrocommandeNumber() const;
    std::string getName() const;

private:
    std::string m_name;
    std::vector<std::string> m_microcommandes;

    unsigned int m_curseur;
};

#endif // MACROCOMMANDE_HPP_INCLUDED
