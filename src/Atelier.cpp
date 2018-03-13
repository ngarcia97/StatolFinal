#include <exception>
#include <list>
#include "../defs/Atelier.h"
#include "../defs/Unite.h"
#include "../defs/Incident.h"
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "../defs/C_Informations.h"
#include "../defs/NatureInfo.h"
#include <arpa/inet.h> 
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cstddef>
#include <stdlib.h>
#include <vector>
#include <array>
#include <fstream>
using namespace std;


int Metier::Atelier::verifierClimat() {
	int codeIncident [3];
	char code[3];
	int error;

	for (list<Metier::Unite*>::iterator itr = listUnite.begin(); itr!=listUnite.end(); ++itr)
	{
		Unite* list = dynamic_cast<Unite*>(*itr);
		error = list->verifierClimatSalle(codeIncident);
		this->verifierIncidents(*itr,code);
		this->transmettreInformations(*itr);
	}
	return error;
}

void Metier::Atelier::verifierIncidents(Unite *unite, char codeIncident[3]) {
		
		if (codeIncident[0]=1) {

			switch (codeIncident[0]) {
				case 2 :  

					unite->finirIncident("CL_TEMPINCIDENT_MIN");
					break;
				case 3 :  
					unite->finirIncident("CL_TEMPINCIDENT_MAX");
					break;
				case 4 :  
					unite->finirIncident("CL_TEMP_DEFECTUEUX");
					break;
			 }
		} 
		else switch (codeIncident[0]) {
			case 2 :  
				unite->ajouterIncident("CL_TEMPINCIDENT_MIN", codeIncident[0]);
				break;
			case 3 :  
				unite->ajouterIncident("CL_TEMPINCIDENT_MAX", codeIncident[0]);
				break;
			case 4 :  
				unite->ajouterIncident("CL_TEMP_DEFECTUEUX", codeIncident[0]);
				break;
		 }


		if (codeIncident[1]=1) {
			
			switch (codeIncident[1]) {
				case 2 :  
					unite->finirIncident("CL_HUMINCIDENT_MIN");
					break;
				case 3 :  
					unite->finirIncident("CL_HUMINCIDENT_MAX");
					break;
				case 4 :  
					unite->finirIncident("CL_HUM_DEFECTUEUX");
					break;
				case 5 : 
					unite->finirIncident("CL_HUMNONINSTAL");
					break;
		 	}
		}  
		else switch (codeIncident[1]) {
			case 2 :  

				unite->ajouterIncident("CL_HUMINCIDENT_MIN", codeIncident[1]);
				break;
			case 3 :  
				unite->ajouterIncident("CL_HUMINCIDENT_MAX", codeIncident[1]);
				break;
			case 4 :  
				unite->ajouterIncident("CL_HUM_DEFECTUEUX", codeIncident[1]);
				break;
			case 5 :  
				unite->ajouterIncident("CL_HUMNONINSTAL", codeIncident[1]);
				break;
		 }


		if (codeIncident[2]=1) {
			switch (codeIncident[2]) {
				case 2 :  
					unite->finirIncident("CL_QAIRINCIDENT");
					break;
				case 3 :  
					unite->finirIncident("CL_QAIR_DEFECTUEUX");
					break;
				case 5 : 
					unite->finirIncident("CL_QAIRNONINSTAL");
					break;
		 	}
		}
		else switch (codeIncident[2]) {
			case 2 :  
				unite->ajouterIncident("CL_QAIRINCIDENT", codeIncident[2]);
				break;
			case 3 :  
				unite->ajouterIncident("CL_QAIR_DEFECTUEUX", codeIncident[2]);
				break;
			case 5 :  
				unite->ajouterIncident("CL_QAIRNONINSTAL", codeIncident[2]);
				break;
		 }
			
}

void Metier::Atelier::transmettreInformations(Unite *unite) {
		
		unite->transmettreInformations(laCommunication);
}

void Metier::Atelier::addUnite(Unite *unite){
	for (list<Unite*>::iterator itr = listUnite.begin(); itr!=listUnite.end(); ++itr){
		if(*itr != unite){	
			if (unite != NULL){
				listUnite.push_back(unite);
			}
		}
	}
}

Metier::Atelier::Atelier(Communication::C_Capteur* leCCapteur) {
	adresseGestion = "10.10.33.193";
	port = 3121;
	string::size_type sz;
	string numero;
	string capteur;
	int num;
	ifstream fichier("Consignes.csv");
	if(fichier)
	{
		string ligne;
		while(getline(fichier,ligne))
		{
		numero = ligne.substr(0,ligne.find(";"));
		capteur = ligne.substr(ligne.find(";")+1, ligne.find(";")+4);
		num = std::stoi(numero,&sz);
		lUnite = new Unite(num, capteur, leCCapteur);
		listUnite.push_front(lUnite);
		}
	}
	else
	{
		cout << "ERREUR: Impossible à ouvrir le fichier en lecture."<< endl;
	}
	//listUnite = new list<Unite>(num, capteur);
	laCommunication = new Communication::C_Informations(this->adresseGestion, this->port);
}

std::list<Metier::Unite*>  Metier::Atelier::getUnite(){
	return listUnite;  
}
 
