#ifndef INFORMATION_H
#define INFORMATION_H

#include <exception>
#include <string>
#include "../defs/NatureInfo.h"
using namespace std;

namespace Communication
{
	class Information;
}

namespace Communication
{
       /* enum class NatureInfo {
                      T_REQUETE = 1,
                      T_REPONSE = 2,
                      CF_TEMP_HUM = 4, //Code Fonction
                      CL_TEMP = 1,
                      CL_TEMPINCIDENT_MIN = 2,
                      CL_TEMPINCIDENT_MAX = 3,
                      CL_TEMP_DEFECTUEUX = 4,
                      CL_TEMP_FININCIDENT = 255,
                      CL_HUM = 1,
                      CL_HUMINCIDENT_MIN = 2,
                      CL_HUMINCIDENT_MAX = 3,
                      CL_HUM_DEFECTUEUX = 4,
                      CL_HUM_FININCIDENT = 255,
                      CL_HUMNONINSTAL = 5,
                      CL_QAIR = 1,
                      CL_QAIRINCIDENT = 2,
                      CL_QAIR_DEFECTUEUX = 3,
                      CL_QAIR_FININCIDENT = 255,
                      CL_QAIRNONINSTAL = 5,
                      CL_PASDETRANSMISSION
                  };*/
	class Information
	{

		public: unsigned char _valeurTemp;
		private: unsigned char _valeurHumid;
		private: unsigned char _valeurGaz;
		private: NatureInfo _natureTemp;
		private: NatureInfo _natureHumid;
		private: NatureInfo _natureGaz;
		private: char _salle;
		private: string _date;

		public: char getValeurTemp();

		public: void setValeurTemp(char aValeurTemp);

		public: char getValeurHumid();

		public: void setValeurHumid(char aValeurHumid);

		public: char getValeurGaz();

		public: void setValeurGaz(char aValeurGaz);

		public: NatureInfo getNatureTemp();

		public: void setNatureTemp(NatureInfo aNatureTemp);

		public: NatureInfo getNatureHumid();

		public: void setNatureHumid(NatureInfo aNatureHumid);

		public: NatureInfo getNatureGaz();

		public: void setNatureGaz(NatureInfo aNatureGaz);

		public: void setSalle(char aSalle);

		public: char getSalle();

		public: void setDate(string aDate);

		public: string getDate();

		public: Information(unsigned char temp, unsigned char humid, unsigned char gaz);

		public: Information();
	};
}

#endif	// INFORMATION_H

