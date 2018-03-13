// thread example
#include <iostream>       // std::cout
#include <iomanip>
#include <chrono>
#include <thread>         // std::thread
#include <string>
#include <cstdlib>
#include <ctime>       /* time */
#include <list> 
#include "../defs/Capteur.h"
#include "../defs/Unite.h"
#include "../defs/NatureInfo.h"
#include "../defs/Climat.h"
#include "../defs/Incident.h"
#include "../defs/Information.h"
#include "../defs/C_Capteur.h"

using namespace std;
using namespace Communication;
using namespace Metier;

int main() 
{
	
	//-lpthread			-std=c++0x
	
	
	int stop =15;
	char dateHeure [4]={0};
	int incidents[3];
	string incident;
	string var;
	string var2;
	
	C_Capteur * maComCapteur = new C_Capteur();
	Unite monUnite(1,"668AC",maComCapteur);
	
	cout << "///////////////horodater///////////"<<endl;
	monUnite.horodater(dateHeure);
	
	for (int i=0;i<4;i++)
	{
		cout << "date"<<i<<" = "<< (int)dateHeure[i]<<endl;
	}

	monUnite.verifierClimatSalle(incidents);
	
	for (int i=0;i<3;i++)
	{
		cout << "incidents"<<i<<" = "<< incidents[i]<<endl;
	}

	cout << "///////////////vérification des incidents premier passage///////////"<<endl;
	
    switch (incidents[0])	
    {
		
		case CL_TEMPINCIDENT_MIN :
		  	incident = "Température minimale dépassée";
            break;
        case CL_TEMPINCIDENT_MAX:
            incident = "Température maximale dépassée";
            break;
        case CL_TEMP_DEFECTUEUX:
            incident = "Température Capteur défectueux";
            break;
        default:
			incident = "RAS";
            break;
    }
    
	cout << "Température " << monUnite.verifierPresenceIncident(incident)<<endl;
		
    switch (incidents[1])
    {
		case CL_HUMINCIDENT_MIN :
			incident= "Humidité minimale dépassée";
             break;
        case CL_HUMINCIDENT_MAX :
             incident= "Humidité maximale dépassée";
             break;
        case CL_HUM_DEFECTUEUX :
             incident= "Humidité Capteur défectueux";
             break;
        default:
			 incident = "RAS";
             break;
    }
    
    cout <<"Humidité " <<  monUnite.verifierPresenceIncident(incident)<<endl;
	    
    switch (incidents[2])
    {
         case CL_QAIRINCIDENT:
              incident= "Qualité de l'air à vérifier";
              break;
         case CL_HUM_DEFECTUEUX:
              incident= "Qualité de l'air Capteur défectueux";
              break;
         default:
			  incident = "RAS";
              break;
    }
    
    cout << "Qualité " << monUnite.verifierPresenceIncident(incident)<<endl;

	cout << "//////////////ajouter les incidents////////////// "<<endl;
	
    switch (incidents[0])
    {
		case CL_TEMPINCIDENT_MIN :
			 incident = "Température minimale dépassée";
		     monUnite.ajouterIncident(incident,CL_TEMPINCIDENT_MIN);
             break;
        case CL_TEMPINCIDENT_MAX:
             incident = "Température maximale dépassée";
		     monUnite.ajouterIncident(incident,CL_TEMPINCIDENT_MAX);
             break;
        case CL_TEMP_DEFECTUEUX:
             incident = "Température Capteur défectueux";
		     monUnite.ajouterIncident(incident,CL_TEMP_DEFECTUEUX);
             break;
        default:
             break;
     }

     switch (incidents[1])
     {
		case CL_HUMINCIDENT_MIN :
			incident= "Humidité minimale dépassée";
		    monUnite.ajouterIncident(incident,CL_HUMINCIDENT_MIN);
            break;
        case CL_HUMINCIDENT_MAX :
            incident= "Humidité maximale dépassée";
		    monUnite.ajouterIncident(incident,CL_HUMINCIDENT_MAX);
            break;
        case CL_HUM_DEFECTUEUX :
            incident= "Humidité Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_HUM_DEFECTUEUX);
            break;
       default:
            break;
     }

     switch (incidents[2])
     {
		case CL_QAIRINCIDENT:
			incident= "Qualité de l'air à vérifier";
		    monUnite.ajouterIncident(incident,CL_QAIRINCIDENT);
            break;
        case CL_QAIR_DEFECTUEUX:
            incident= "Qualité de l'air Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_QAIR_DEFECTUEUX);
            break;
        default:
            break;
     }

	 cout << "vérification des incidents deuxième passage "<<endl;
	 
     switch (incidents[0])
     {
		case CL_TEMPINCIDENT_MIN :
			incident = "Température minimale dépassée";
            break;
        case CL_TEMPINCIDENT_MAX:
            incident = "Température maximale dépassée";
            break;
        case CL_TEMP_DEFECTUEUX:
            incident = "Température Capteur défectueux";
            break;
        default:
			incident = "RAS";
            break;
     }
     
	 cout<< "Température "  << monUnite.verifierPresenceIncident(incident)<<endl;
	 
     switch (incidents[1])
     {
		case CL_HUMINCIDENT_MIN :
			incident= "Humidité minimale dépassée";
            break;
        case CL_HUMINCIDENT_MAX :
            incident= "Humidité maximale dépassée";
            break;
        case CL_HUM_DEFECTUEUX :
            incident= "Humidité Capteur défectueux";
            break;
        default:
			incident = "RAS";
            break;
      }
            
	  cout<< "Humidité "  << monUnite.verifierPresenceIncident(incident)<<endl;
	  
      switch (incidents[2])
      {
		case CL_QAIRINCIDENT:
			incident= "Qualité de l'air à vérifier";
            break;
        case CL_QAIR_DEFECTUEUX:
            incident= "Qualité de l'air Capteur défectueux";
            break;
        default:
			incident = "RAS";
            break;
      }
      
      cout << "Qualité "  <<  monUnite.verifierPresenceIncident(incident)<<endl;

/*
	cout << "/////////Simuler une fin d'incident en vue du test de extraireIncidents//////////" << endl;
	
	cout << "Entrer le code incident souhaité pour :"<<endl;
	cout << "la température (avec 1 : aucun incident; 2 : température trop faible, 3 température trop élevée) : "<<endl;
	cin>>incidents[0];
	cout << "l'humidité (avec 1 : aucun incident; 2 : humidité trop faible, 3 humidité trop élevée) : "<<endl;
	cin>>incidents[1];
	cout << "le gaz (avec 1 : aucun incident; 2 : gaz trop élevé) : "<<endl;
	cin>>incidents[2];
	
*/
	char dateFin[4];
	for (int i=0;i<4;i++)
	{
		dateFin[i]=dateHeure[i];
	}
	if (dateFin [3]+20 <60) dateFin [3] = dateFin [3]+20; 
	else {
		dateFin [3]= dateFin [3]-39;
		dateFin [2]= dateFin [2]+1;
	
	}
	cout << "dateFin = " << (int) dateFin[0]<<"/"<< (int)dateFin[1]<<";"<< (int)dateFin[2]<<"h"<< (int)dateFin[3]<<"m" <<endl;////////////
	monUnite.setDateHeureCourante(dateFin);

	
	cout << "finir incident(s) "<<endl;
            switch (incidents[0])
            {
                case CL_TEMPINCIDENT_MIN :
                    incident = "Température minimale dépassée";
		    monUnite.ajouterIncident(incident,CL_TEMPINCIDENT_MIN);
                    break;
                case CL_TEMPINCIDENT_MAX:
                    incident = "Température maximale dépassée";
		    monUnite.ajouterIncident(incident,CL_TEMPINCIDENT_MAX);
                    break;
                case CL_TEMP_DEFECTUEUX:
                    incident = "Température Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_TEMP_DEFECTUEUX);
                    break;
                case CL_TEMP:
                    incident = "Température";
		    monUnite.finirIncident(incident);
                    break;
                default:
			incident = "RAS";
                    break;
            }

            switch (incidents[1])
            {
                case CL_HUMINCIDENT_MIN :
                    incident= "Humidité minimale dépassée";
		    monUnite.ajouterIncident(incident,CL_HUMINCIDENT_MIN);
                    break;
                case CL_HUMINCIDENT_MAX :
                    incident= "Humidité maximale dépassée";
		    monUnite.ajouterIncident(incident,CL_HUMINCIDENT_MAX);
                    break;
                case CL_HUM_DEFECTUEUX :
                    incident= "Humidité Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_HUM_DEFECTUEUX);
                    break;
                case CL_HUM:
                    incident = "Humidité";
		    monUnite.finirIncident(incident);
                    break;
                default:
			incident = "RAS";
                    break;
            }

            switch (incidents[2])
            {
                case CL_QAIRINCIDENT:
                    incident= "Qualité de l'air à vérifier";
		    monUnite.ajouterIncident(incident,CL_QAIRINCIDENT);
                    break;
                case CL_QAIR_DEFECTUEUX:
                    incident= "Qualité de l'air Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_QAIR_DEFECTUEUX);
                    break;
                case CL_QAIR:
                    incident = "Qualité";
		    monUnite.finirIncident(incident);
                    break;
                default:
			incident = "RAS";
                    break;
            }

	cout << "vérification des incidents troisième passage "<<endl;
            switch (incidents[0])
            {
                case CL_TEMPINCIDENT_MIN :
                    incident = "Température minimale dépassée";
                    break;
                case CL_TEMPINCIDENT_MAX:
                    incident = "Température maximale dépassée";
                    break;
                case CL_TEMP_DEFECTUEUX:
                    incident = "Température Capteur défectueux";
                    break;
                default:
			incident = "RAS";
                    break;
            }
	    cout<< "Température "  << monUnite.verifierPresenceIncident(incident)<<endl;
            switch (incidents[1])
            {
                case CL_HUMINCIDENT_MIN :
                    incident= "Humidité minimale dépassée";
                    break;
                case CL_HUMINCIDENT_MAX :
                    incident= "Humidité maximale dépassée";
                    break;
                case CL_HUM_DEFECTUEUX :
                    incident= "Humidité Capteur défectueux";
                    break;
                default:
			incident = "RAS";
                    break;
            }
	    cout<< "Humidité "  << monUnite.verifierPresenceIncident(incident)<<endl;
            switch (incidents[2])
            {
                case CL_QAIRINCIDENT:
                    incident= "Qualité de l'air à vérifier";
                    break;
                case CL_QAIR_DEFECTUEUX:
                    incident= "Qualité de l'air Capteur défectueux";
                    break;
                default:
			incident = "RAS";
                    break;
            }
            cout << "Qualité "  <<  monUnite.verifierPresenceIncident(incident)<<endl;



cout << "////////////////Extraire incidents////////////////" << endl;
	list<Incident*> listIncidents;
	char dateHeureEnreg [4];
	cout << "cas n° 1 : date = " << (int) dateHeure[0]<<"/"<< (int)dateHeure[1]<<";"<< (int)dateHeure[2]<<"h"<< (int)dateHeure[3]<<"m" <<endl;
	monUnite.extraireIncidentsA(dateHeure , listIncidents);
	if (!listIncidents.empty())
		for(list<Incident*>::iterator it=listIncidents.begin(); it!=listIncidents.end(); ++it)
		{
			cout << "type incident : " <<(*it)->getTypeIncident()<<endl;
			(*it)->getDateHeureIncident(dateHeureEnreg);

			cout << "à " << (int) dateHeureEnreg[0]<<"/"<< (int)dateHeureEnreg[1]<<";"<< (int)dateHeureEnreg[2]<<"h"<< (int)dateHeureEnreg[3]<<"m" <<endl;
			if  ((*it)->getEtat()) cout << "son état est : fini" <<endl;
			else cout << "son état est : en cours" <<endl;

		}
	listIncidents.clear();
	cout << "cas n° 2 : date = " << (int) dateFin[0]<<"/"<< (int)dateFin[1]<<";"<< (int)dateFin[2]<<"h"<< (int)dateFin[3]<<"m" <<endl;

	monUnite.extraireIncidentsA(dateFin , listIncidents);
	if (!listIncidents.empty())
		for(list<Incident*>::iterator it=listIncidents.begin(); it!=listIncidents.end(); ++it)
		{
			cout << "type incident : " <<(*it)->getTypeIncident()<<endl;
			(*it)->getDateHeureIncident(dateHeureEnreg);

			cout << "à " << (int) dateHeureEnreg[0]<<"/"<< (int)dateHeureEnreg[1]<<";"<< (int)dateHeureEnreg[2]<<"h"<< (int)dateHeureEnreg[3]<<"m" <<endl;

		}
//

/*
	cout << "Associer Climat et incidents "<<endl;
	list<Incident*> listIncidents;
	listIncidents.push_back(new Incident("Humidité minimale dépassée", dateHeure,CL_HUMINCIDENT_MIN));
	listIncidents.push_back(new Incident("Qualité de l'air à vérifier", dateHeure,CL_HUMINCIDENT_MIN));
	Climat * leClimat = new Climat(18.6, 20, 536, dateHeure);
	Information aInformation;
	monUnite.associerIncidentDonneeClimat(leClimat, listIncidents, aInformation);
	cout << "Informations à transmettre : \n" <<(int)aInformation.getNatureTemp()<< " " << (int) (aInformation.getValeurTemp() & 0xFF)<< "\n "<<(int)aInformation.getNatureHumid()<< " " <<(int)aInformation.getValeurHumid() << "\n "<<(int)aInformation.getNatureGaz()<< " " <<(int)(aInformation.getValeurGaz() & 0xFF)<< endl;
*/


cout << "/////////TransmettreIncidents//////////" << endl;

	cout << "/////////finir incidents attente 3 mn //////////" << endl;
	std::this_thread::sleep_for (std::chrono::seconds(180));

	monUnite.verifierClimatSalle(incidents);

	for (int i=0;i<3;i++)
	{
	cout << "incidents"<<i<<" = "<< incidents[i]<<endl;
	}
	
	cout << "finir incident(s) "<<endl;
            switch (incidents[0])
            {
                case CL_TEMPINCIDENT_MIN :
                    incident = "Température minimale dépassée";
		    monUnite.ajouterIncident(incident,CL_TEMPINCIDENT_MIN);
                    break;
                case CL_TEMPINCIDENT_MAX:
                    incident = "Température maximale dépassée";
		    monUnite.ajouterIncident(incident,CL_TEMPINCIDENT_MAX);
                    break;
                case CL_TEMP_DEFECTUEUX:
                    incident = "Température Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_TEMP_DEFECTUEUX);
                    break;
                case CL_TEMP:
                    incident = "Température";
		    monUnite.finirIncident(incident);
                    break;
                default:
			incident = "RAS";
                    break;
            }

            switch (incidents[1])
            {
                case CL_HUMINCIDENT_MIN :
                    incident= "Humidité minimale dépassée";
		    monUnite.ajouterIncident(incident,CL_HUMINCIDENT_MIN);
                    break;
                case CL_HUMINCIDENT_MAX :
                    incident= "Humidité maximale dépassée";
		    monUnite.ajouterIncident(incident,CL_HUMINCIDENT_MAX);
                    break;
                case CL_HUM_DEFECTUEUX :
                    incident= "Humidité Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_HUM_DEFECTUEUX);
                    break;
                case CL_HUM:
                    incident = "Humidité";
		    monUnite.finirIncident(incident);
                    break;
                default:
			incident = "RAS";
                    break;
            }

            switch (incidents[2])
            {
                case CL_QAIRINCIDENT:
                    incident= "Qualité de l'air à vérifier";
		    monUnite.ajouterIncident(incident,CL_QAIRINCIDENT);
                    break;
                case CL_QAIR_DEFECTUEUX:
                    incident= "Qualité de l'air Capteur défectueux";
		    monUnite.ajouterIncident(incident,CL_QAIR_DEFECTUEUX);
                    break;
                case CL_QAIR:
                    incident = "Qualité";
		    monUnite.finirIncident(incident);
                    break;
                default:
			incident = "RAS";
                    break;
            }

	cout << "vérification des incidents troisième passage "<<endl;
            switch (incidents[0])
            {
                case CL_TEMPINCIDENT_MIN :
                    incident = "Température minimale dépassée";
                    break;
                case CL_TEMPINCIDENT_MAX:
                    incident = "Température maximale dépassée";
                    break;
                case CL_TEMP_DEFECTUEUX:
                    incident = "Température Capteur défectueux";
                    break;
                default:
			incident = "RAS";
                    break;
            }
	    cout<< "Température "  << monUnite.verifierPresenceIncident(incident)<<endl;
            switch (incidents[1])
            {
                case CL_HUMINCIDENT_MIN :
                    incident= "Humidité minimale dépassée";
                    break;
                case CL_HUMINCIDENT_MAX :
                    incident= "Humidité maximale dépassée";
                    break;
                case CL_HUM_DEFECTUEUX :
                    incident= "Humidité Capteur défectueux";
                    break;
                default:
			incident = "RAS";
                    break;
            }
	    cout<< "Humidité "  << monUnite.verifierPresenceIncident(incident)<<endl;
            switch (incidents[2])
            {
                case CL_QAIRINCIDENT:
                    incident= "Qualité de l'air à vérifier";
                    break;
                case CL_QAIR_DEFECTUEUX:
                    incident= "Qualité de l'air Capteur défectueux";
                    break;
                default:
			incident = "RAS";
                    break;
            }
            cout << "Qualité "  <<  monUnite.verifierPresenceIncident(incident)<<endl;

	C_Informations *laCommunication=new C_Informations("127.0.0.1",3121);
	monUnite.transmettreInformations(laCommunication);


  return 0;
}
