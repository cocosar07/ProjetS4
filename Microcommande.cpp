#include "Microcommande.hpp"

Microcommande::Microcommande(std::string &code, std::vector<Parametre> &params) : m_code(code), m_params(params)
{
}

std::vector<Microcommande>* Microcommande::loadFromFile(std::string filename)
{
    std::ifstream file(filename.c_str(), std::ifstream::in);

    if(!file.is_open())
    {
        std::cerr << "Fichier inconnu";
        return NULL;
    }

    std::vector<Microcommande>* microcommandes = new std::vector<Microcommande>;
    std::string commandeDescription;

    while(std::getline(file, commandeDescription))
    {
        std::vector<std::string> elems = split(commandeDescription, PARAM_SEPARATOR);

        std::string code(elems[COMMANDE_CODE]);
        std::cout << code << ": " << std::endl; /// Affichage
        std::vector<Parametre> params;
        for(unsigned int i(COMMANDE_CODE+1); i<elems.size(); i++)
        {
            params.push_back(Parametre());

            if(elems[i] == NUMBER_CHARACTER)
            {
                params.back().push_back(NUMBER_CHARACTER);
                std::cout << NUMBER_CHARACTER << std::endl; /// Affichage
            }
            else
            {
                std::vector<std::string> choix = split(elems[i], CHOICE_SEPARATOR);

                for(unsigned int j(0); j<choix.size(); j++)
                {
                    params.back().push_back(choix[j]);
                    std::cout << choix[j] << " "; /// Affichage
                }
                std::cout << std::endl; /// Affichage
            }
        }

        microcommandes->push_back(Microcommande(code, params));
    }

    file.close();

    return microcommandes;
}
