#include <exception>
#include <string>
using namespace std;

#ifndef __C_Consignes_h__
#define __C_Consignes_h__

// #include "C_BDD.h"

namespace Communication
{
	class C_BDD;
	class C_Consignes;
}

namespace Communication
{
	class C_Consignes
	{
		private: string _adresseTCP;
		private: string _portTCP;
		public: Communication::C_BDD* _unnamed_C_BDD_;

		public: void traitementSurReception();

		/// <summary>
		/// socket + bind
		/// </summary>
		public: bool creerSocket(int aPort);

		public: void accepterDemandeConnexion();

		public: int lire(char aRequete[]);

		public: int signalerChangement();

		public: static void activerReception() {
			throw "Not yet implemented";
		}
	};
}

#endif
