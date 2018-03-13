#include <exception>
#include <iostream>
#include "../defs/Climat.h"
#include "../defs/C_BDD.h"

using namespace std;
using namespace Metier;

void Metier::Climat::ajouterClimat(int Salle) {
	laBDD->enregistrerClimat(Salle, _temperature, _humidity, _gaz, _dateHeureReleve);
}

void Metier::Climat::supprimer() {
	throw "Not yet implemented";
}

void Metier::Climat::getDateHeureReleve(char dateHeureReleve[4]) {
	for (int i = 0; i<4 ; i++)
        {
                dateHeureReleve[i]= _dateHeureReleve[i];
        }
}

float Metier::Climat::getTemperature() {
	return this->_temperature;
}

int Metier::Climat::getHumidity() {
	return this->_humidity;
}

int Metier::Climat::getGaz() {
	return this->_gaz;
}

Metier::Climat::Climat(float temperature, int humidity, int gaz, char dateHeureReleve[4]) {
	this->_temperature = temperature;
	this->_humidity = humidity;
	this->_gaz = gaz;
	for (int i = 0; i<4 ; i++)
	{
		_dateHeureReleve[i]=dateHeureReleve[i];
	}

}

