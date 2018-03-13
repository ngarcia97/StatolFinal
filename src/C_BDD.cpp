#include <exception>
#include <string>
#include "../defs/C_BDD.h"
#include "../defs/Climat.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace Communication;

/*#include "C_Consignes.h"

int Communication::C_BDD::deTramer(char aRequete[], string& aConsignes) {
	throw "Not yet implemented";
}

int Communication::C_BDD::enregistrerConsignes(string aConsignes) {
	throw "Not yet implemented";
}

int Communication::C_BDD::lireConsignes(int aSalle) {
	throw "Not yet implemented";
}*/

Communication::C_BDD::C_BDD() {
}

void Communication::C_BDD::enregistrerClimat(int Salle, float temperature, int humidity, int gaz, char dateHeureReleve[4]) {
	ofstream fichier("../DATA/BDD.txt", ios::out | ios::app);
	if (fichier)
	{
		fichier << "=========== Salle " << Salle <<  " ===========" << endl;
		fichier << "Temp : " << temperature << " C°"<< endl;
		fichier << "Hum : " <<  humidity << " %" << endl;
		fichier << "Gaz : " << gaz << " Ppm" << endl;
		fichier << "Date : ";
		fichier << (int)dateHeureReleve[0] << "/" << (int)dateHeureReleve[1] << " ";
		fichier << (int)dateHeureReleve[2] << ":" << (int)dateHeureReleve[3] << endl;
		fichier.close();
	}else {
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}
}

void Communication::C_BDD::enregistrerIncident(char dateHeureReleve[4], string type, int salle) {
        ofstream fichier("../DATA/BDD.txt", ios::out | ios::app);
        if (fichier)
        {
                fichier << "=========== Incidents ===========" << endl;
                fichier << "Salle : " << salle << endl;
                fichier << "Type : " <<  type << endl;
                fichier << "Date : ";
                fichier << (int)dateHeureReleve[0] << "/" << (int)dateHeureReleve[1] << " ";
                fichier << (int)dateHeureReleve[2] << ":" << (int)dateHeureReleve[3] << endl;
                fichier.close();
        }else {
                cout << "Impossible d'ouvrir le fichier !" << endl;
        }
}

