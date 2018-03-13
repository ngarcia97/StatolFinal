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
#include <fstream>

using namespace std;

int main (){
/*
	FILE * pFile;
	string::size_type sz;
	pFile=fopen("Consignes.csv","r");
char numSalle[721];
size_t len = 2;
//fseek(pFile, 0, SEEK_CUR);
if( pFile != NULL && numSalle != NULL )
      {
		int i=0;
		char c;

		while(fscanf(pFile,"%c",&c) != EOF)
		{
			numSalle[i]=c;
			i++;
		}

		numSalle[i]=0;
}*/
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
		cout << ligne << endl;
		numero = ligne.substr(0,ligne.find(";"));
		capteur = ligne.substr(ligne.find(";")+1, ligne.find(";")+4);
		num = std::stoi(numero,&sz);
		cout << num << endl;
		cout << capteur << endl;
	}
}
else
{
	cout << "ERREUR: Impossible à ouvrir le fichier en lecture."<< endl;
}
return 0;
/*

string fichierFinal = numSalle;
string numero1 = fichierFinal.substr(0,fichierFinal.find(";"));
string capteur1 = fichierFinal.substr(fichierFinal.find(";")+1, fichierFinal.find(";")+4);
string numero2 = fichierFinal.substr(fichierFinal.find("\n"), fichierFinal.find(";")+1);
string capteur2 = fichierFinal.substr(fichierFinal.find("\n")+3, fichierFinal.find(";")+4);
*/

	//char numSalle[] = (char)fgetc(pFile);
	/*cout << fichierFinal << endl;
	cout << numero1 << endl;
	cout << capteur1 << endl;
	cout << numero2 << endl;*/
	//cout << numSalle << endl;
	//cout << siroTest << endl;
	//cout << numCapteur << endl;
}
