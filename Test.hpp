#ifndef TEST_HPP_INCLUDED
#define TEST_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Macrocommande.hpp"

#define COMMANDES_SEPARATOR ';'
#define TEST_NAME 0

class Test
{
public:
    Test(std::string name, std::vector<Macrocommande> macrocommandes);

    static std::vector<Test>* loadFromFile(std::string filename, std::vector<Macrocommande> listeMacrocommandes);

    void resetCurseur();
    void resetMacrocommandeCurseur();
    std::string recupProchaineMicrocommande();
    unsigned int getMacrocommandeNumber() const;
    unsigned int getMicrocommandeNumber() const;

private:
    std::string m_name;
    std::vector<Macrocommande> m_macrocommandes;

    unsigned int m_curseur;
    unsigned int m_macrocommandeCurseur;
};

#endif // TEST_HPP_INCLUDED
