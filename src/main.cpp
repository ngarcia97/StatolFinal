/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g2
 *
 * Created on 15 février 2018, 16:42
 */

#include <cstdlib>
#include "../defs/Atelier.h"
#include "../defs/C_Capteur.h"
#include "../defs/Capteur.h"
#include "../defs/Information.h"
#include "../defs/C_Informations.h"
#include "../defs/Incident.h"
#include "../defs/Climat.h"
#include "../defs/TClimat.h"
#include "../defs/Adresse.h"
#include "../defs/C_BDD.h"
#include "../defs/C_Consignes.h"
#include "../defs/Consignes.h"
#include "../defs/NatureInfo.h"
#include "../defs/ProtocoleCapteurs.h"
#include "../defs/serialib.h"
#include "../defs/Unite.h"
#include <iostream>
#include <list>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	char codeIncident[]= {Communication::NatureInfo::CL_TEMPINCIDENT_MIN ,Communication::NatureInfo::CL_HUMINCIDENT_MAX ,Communication::NatureInfo::CL_QAIRINCIDENT};
	char dateHeure[]= {12,21,21,21};
	string type="CL_QAIRINCIDENT";
	vector<Metier::Incident*> lesIncidents;
	Communication::C_Capteur* leCCapteur = new Communication::C_Capteur();
	thread releverClimat = leCCapteur->activerReception();
	Metier::Incident* lIncident = new Metier::Incident(type ,dateHeure, codeIncident[0]);
	Metier::Atelier* lAtelier = new Metier::Atelier(leCCapteur);
	std::list<Metier::Unite*> lesUnite = lAtelier->getUnite();
	
	//Metier::Unite* lUnite = new Metier::Unite(1, "0x6785",lAtelier->getUnite());
	
	int error;
for (list<Metier::Unite*>::iterator it = lesUnite.begin(); it != lesUnite.end(); ++it){
	Metier::Unite * laUnite = dynamic_cast<Metier::Unite*>(*it);
	lAtelier->verifierIncidents(laUnite, codeIncident);
	lAtelier->transmettreInformations(laUnite);
	lesIncidents = laUnite->getIncidents();
	error = lAtelier->verifierClimat();

}
	for (int i = 0; i < lesIncidents.size()-1; i++) {
            cout << lesIncidents[i] << " ";
        }
	releverClimat.join();
    return 0;
}

