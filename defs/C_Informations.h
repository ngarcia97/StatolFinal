

#ifndef __C_Informations_h__
#define __C_Informations_h__

#include "Information.h"
#include <cstddef>
using namespace std;

namespace Communication
{
	//enum NatureInfo;
	class Information;
	class C_Informations;
}

namespace Communication
{
	class C_Informations
	{
		private: 
                    std::string _adresseGestion;
                    int _portTCP;
                    int creerSocket();
                    bool connexion(int nCanal);
                public:
                    C_Informations(string adresse, int port);
                    C_Informations();
                    int ecrire(Communication::Information aInformation);
                    bool tramer(Communication::Information aInformation, unsigned char lesInformations[13]);
               
	};
}

#endif
