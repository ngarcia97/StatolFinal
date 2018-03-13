#include <exception>
#include <string>
#include <iostream>

using namespace std;

#include "../defs/Capteur.h"


string trameCherchee;

int Metier::Capteur::getTempHumid(float& aTemperature, int& aHumidity) {
	int error = -1;
	error = leCapteur->extraireTrame(_adresse, trameCherchee);
	if (error <=0) return error;
	string temp = trameCherchee.substr(0, trameCherchee.find(_separateur));
	trameCherchee = trameCherchee.erase(0, trameCherchee.find(_separateur) + 1);
	float tttp = stof(temp);
	tttp = ((tttp * 4.88)-0.4 * 1000) / 19.5;
	aTemperature = tttp;
	string hum = trameCherchee.substr(0, trameCherchee.find(_separateur));
	float Rh = stof(hum);
	Rh = (Rh / 1023 - 0.16) / 0.0062;
	Rh = Rh / (1.0546 - 0.00216*aTemperature);	// Compensation en température (voir documentation) : /(1.0546-0.00216*tttp)
	aHumidity = Rh;
	return OK;
}

int Metier::Capteur::getGaz(int& aValeur) {
	string gazTab;

	int error = leCapteur->extraireTrame(_adresse, trameCherchee);
	if (error <=0) return error;
	gazTab=trameCherchee.substr(trameCherchee.find_last_of(_separateur) +1,trameCherchee.size() -1);
	aValeur=stoi(gazTab,NULL,10);
	return OK;
}


void Metier::Capteur::supprimerEnregistrement() {
	leCapteur->remettreAZeroLaSalve();

}

Metier::Capteur::Capteur(string adresse,Communication::C_Capteur *unCapteur)
{
    leCapteur=unCapteur;
	_adresse= adresse;
}

