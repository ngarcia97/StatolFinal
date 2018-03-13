#include <exception>
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

#define PORT 3121

using namespace std;

Communication::C_Informations::C_Informations(){
    
}

Communication::C_Informations::C_Informations(string adresse, int port){
    this->_adresseGestion = adresse;
    this->_portTCP = port;
}

int Communication::C_Informations::creerSocket() {
        int leSocket;
        if((leSocket = socket(AF_INET,SOCK_STREAM, 0)) < 0){
            perror("Erreur lors de la création du socket");
            exit(EXIT_FAILURE);
        }
        return leSocket;
}

bool Communication::C_Informations::connexion(int nCanal) {
	struct sockaddr_in sock;
	sock.sin_family=AF_INET;
        sock.sin_port=htons(_portTCP);
	//char * adresseFinal = new char[_adresseGestion.length() + 1];
	//strcpy(adresseFinal,_adresseGestion.c_str());
        const char * adresse = _adresseGestion.c_str();
	sock.sin_addr.s_addr = inet_addr(adresse);
	//inet_aton("10.10.33.158", &(sock.sin_addr));
	if(connect(nCanal, (struct sockaddr *) &sock, sizeof(sock)) < 0){
        	perror("Problème de connexion");
        	return false;
    	}
        return true;
}

int Communication::C_Informations::ecrire(Communication::Information aInformation) {
    int leSocket = creerSocket();
    unsigned char envoi[13];
    connexion(leSocket);
    tramer(aInformation,envoi);
    int renvoi = send(leSocket, envoi ,13 , 0);
    return renvoi;
}

bool Communication::C_Informations::tramer(Communication::Information aInformation, unsigned char lesInformations[13]) {
    lesInformations[0] = (char)Communication::NatureInfo::T_REQUETE;
    lesInformations[1] = (char)Communication::NatureInfo::CF_TEMP_HUM;
    lesInformations[2] = (char)aInformation.getNatureTemp();
    lesInformations[3] = (char)aInformation.getValeurTemp();
    lesInformations[4] = (char)aInformation.getNatureHumid();
    lesInformations[5] = (char)aInformation.getValeurHumid();
    lesInformations[6] = (char)aInformation.getNatureGaz();
    lesInformations[7] = (char)aInformation.getValeurGaz();
    lesInformations[8] = (char)aInformation.getSalle();
    string date = aInformation.getDate();
    string mois = date.substr(0,date.find("/"));
    string jours = date.substr(date.find("/") + 1, date.find(";") -2 );
    string heures = date.substr(date.find(";")+1, date.find("h") - 4);
    string minutes = date.substr(date.find("h")+1, date.find("mn") - 7);
    string::size_type sz;
    int moisFinal = std::stoi(mois,&sz);
    int joursFinal = std::stoi(jours,&sz);
    int heuresFinal = std::stoi(heures,&sz);
    int minutesFinal = std::stoi(minutes,&sz);
    
    lesInformations[9] = (char)moisFinal;
    lesInformations[10] = (char)joursFinal;
    lesInformations[11] = (char)heuresFinal;
    lesInformations[12] = (char)minutesFinal;
}

