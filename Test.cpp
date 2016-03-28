#include "Test.hpp"

Test::Test(std::string name, std::vector<Macrocommande> macrocommandes) : m_name(name), m_macrocommandes(macrocommandes), m_curseur(0), m_macrocommandeCurseur(0)
{

}

std::vector<Test>* Test::loadFromFile(std::string filename, std::vector<Macrocommande> listeMacrocommandes)
{
    std::ifstream file(filename.c_str(), std::ifstream::in);

    if(!file.is_open())
    {
        std::cerr << "Fichier inconnu";
        return NULL;
    }

    std::vector<Test>* tests = new std::vector<Test>;
    std::string testDescription;

    while(std::getline(file, testDescription))
    {
        std::vector<std::string> elems = split(testDescription, COMMANDES_SEPARATOR);

        std::string name = elems[TEST_NAME];
        std::cout << name << ": " << std::endl; /// Affichage
        std::vector<Macrocommande> macrocommandes;
        for(unsigned int i(TEST_NAME+1); i<elems.size(); i++)
        {
            std::string nomMacrocommande = elems[i];

            //on a le nom de chaque commande, il faut récuperer les macrocommandes dans la liste qu'on aura chargé
            for(unsigned int j(0); j<listeMacrocommandes.size(); j++)
            {
                if(nomMacrocommande == listeMacrocommandes[j].getName())
                {
                    macrocommandes.push_back(listeMacrocommandes[j]);
                    std::cout << nomMacrocommande << std::endl;
                    break;
                }
            }
        }

        tests->push_back(Test(name, macrocommandes));
    }

    file.close();

    return tests;
}

void Test::resetCurseur()
{
    m_curseur = 0;
}

void Test::resetMacrocommandeCurseur()
{
    m_macrocommandeCurseur = 0;
}

std::string Test::recupProchaineMicrocommande()
{
    std::string microcommande = m_macrocommandes[m_curseur].recupProchaineMicrocommande();

    m_macrocommandeCurseur += 1;
    if(m_macrocommandeCurseur >= m_macrocommandes[m_curseur].getMicrocommandeNumber())
    {
        resetMacrocommandeCurseur();
        m_curseur += 1;
    }

    if(m_curseur >= m_macrocommandes.size())
    {
        resetCurseur();
    }

    return microcommande;
}

unsigned int Test::getMacrocommandeNumber() const
{
    return m_macrocommandes.size();
}

unsigned int Test::getMicrocommandeNumber() const
{
    unsigned int microcommandeNumber(0);

    for(unsigned int i(0); i<m_macrocommandes.size(); i++)
    {
        microcommandeNumber += m_macrocommandes[i].getMicrocommandeNumber();
    }

    return microcommandeNumber;
}
