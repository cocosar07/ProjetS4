#include "Macrocommande.hpp"

Macrocommande::Macrocommande(std::string name, std::vector<std::string> microcommandes) : m_name(name), m_microcommandes(microcommandes), m_curseur(0)
{

}

std::vector<Macrocommande>* Macrocommande::loadFromFile(std::string filename)
{
    std::ifstream file(filename.c_str(), std::ifstream::in);

    if(!file.is_open())
    {
        std::cerr << "Fichier inconnu";
        return NULL;
    }

    std::vector<Macrocommande>* macrocommandes = new std::vector<Macrocommande>;
    std::string commandeDescription;

    while(std::getline(file, commandeDescription))
    {
        std::vector<std::string> elems = split(commandeDescription, MICROCOMMANDE_SEPARATOR);

        std::string name = elems[COMMANDE_NAME];
        std::cout << name << ": " << std::endl; /// Affichage
        std::vector<std::string> microcommandes;
        for(unsigned int i(COMMANDE_NAME+1); i<elems.size(); i++)
        {
            microcommandes.push_back(elems[i]);
            std::cout << elems[i] << std::endl; /// Affichage
        }

        macrocommandes->push_back(Macrocommande(name, microcommandes));
    }

    file.close();

    return macrocommandes;
}

void Macrocommande::resetCurseur()
{
    m_curseur = 0;
}

std::string Macrocommande::recupProchaineMicrocommande()
{
    std::string microcommande;
    if(m_curseur < m_microcommandes.size())
    {
        microcommande = m_microcommandes[m_curseur];
    }

    m_curseur += 1;

    if(m_curseur >= m_microcommandes.size())
        resetCurseur();

    return microcommande;
}

unsigned int Macrocommande::getMicrocommandeNumber() const
{
    return m_microcommandes.size();
}

std::string Macrocommande::getName() const
{
    return m_name;
}
