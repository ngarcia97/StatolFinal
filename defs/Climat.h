#include <exception>

using namespace std;

#ifndef __Climat_h__
#define __Climat_h__

#include "C_BDD.h"

namespace Metier
{
	class Climat;
}
namespace Communication
{
	class C_BDD;
}
namespace Metier
{
	class Climat
	{
		private: float _temperature;
		private: int _humidity;
		private: int _gaz;
		private: char _dateHeureReleve[4];
		private: Communication::C_BDD *laBDD;
	
		public: void ajouterClimat(int Salle);

		public: void supprimer();

		public: float getTemperature();

		public: int getHumidity();

		public: int getGaz();

		public: void getDateHeureReleve(char dateHeureReleve[4]);

		public : Climat(float temperature, int humidity, int gaz, char dateHeureReleve[4]);
	};
}

#endif
