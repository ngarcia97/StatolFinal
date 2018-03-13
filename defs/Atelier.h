#include <exception>
#include <vector>
#include <string>
#include <cstring>


#ifndef __Atelier
#define __Atelier

#include "Unite.h"
#include "C_Informations.h"
#include "Information.h"

namespace Communication
{
	class Information;
	class C_Informations;
}

namespace Metier
{
	class Unite;
	class Atelier;
}

namespace Metier
{
	class Atelier
	{
		public: Atelier(Communication::C_Capteur *leCCapteur);
		public : std::list<Metier::Unite*>  getUnite();
		private: Communication::C_Capteur *leCCapteur;
		private: Communication::C_Informations *laCommunication;
		private: Metier::Unite *lUnite;  
		private: long _periodicite;
		private: std::list<Metier::Unite*> listUnite;
		public: int verifierClimat();
		public: void verifierIncidents(Unite *unite, char codeIncident[3]);
		public: void transmettreInformations(Unite *unite);
		private : char codeIncident[3];
		private : string adresseGestion;
		private : int port;
		public: void addUnite(Unite *unite);
	};
}

#endif
