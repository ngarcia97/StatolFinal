#include <exception>

using namespace std;

#ifndef __C_BDD_h__
#define __C_BDD_h__

#include "Climat.h"
#include <string>

namespace Communication
{
	class C_BDD;
}
namespace Metier
{
	class Climat;
}
namespace Communication
{
	class C_BDD
	{
		/*private: string _bddConsignes;
		public: Communication::C_Consignes* _unnamed_C_Consignes_;

		public: int deTramer(char aRequete[], string& aConsignes);

		public: int enregistrerConsignes(string aConsignes);

		public: int lireConsignes(int aSalle);*/
		private : Metier::Climat *leClimat;
		
		public : C_BDD();
		
		public: void enregistrerClimat(int Salle, float temperature, int humidity, int gaz, char dateHeureReleve[4]);
		
		public: void enregistrerIncident(char dateHeure[4], string type, int salle);
	};
}

#endif
