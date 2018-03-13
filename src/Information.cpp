#include "../defs/Information.h"

char Communication::Information::getValeurTemp() {
        //_valeurTemp = 25;
        //_valeurTemp = (int)_valeurTemp;
	return this->_valeurTemp;
}

void Communication::Information::setValeurTemp(char aValeurTemp) {
	this->_valeurTemp = aValeurTemp;
}

char Communication::Information::getValeurHumid() {
       // _valeurHumid = 70;
	return this->_valeurHumid;
}

void Communication::Information::setValeurHumid(char aValeurHumid) {
	this->_valeurHumid = aValeurHumid;
}

char Communication::Information::getValeurGaz() {
        //_valeurGaz = 250;
	return this->_valeurGaz;
}

void Communication::Information::setValeurGaz(char aValeurGaz) {
	this->_valeurGaz = aValeurGaz;
}

Communication::NatureInfo Communication::Information::getNatureTemp() {
        //_natureTemp = Communication::NatureInfo::CL_TEMPINCIDENT_MIN;
	return this->_natureTemp;
}

void Communication::Information::setNatureTemp(NatureInfo aNatureTemp) {
	this->_natureTemp = aNatureTemp;
}

Communication::NatureInfo Communication::Information::getNatureHumid() {
        //_natureHumid = Communication::NatureInfo::CL_HUMINCIDENT_MIN;
	return this->_natureHumid;
}

void Communication::Information::setNatureHumid(NatureInfo aNatureHumid) {
	this->_natureHumid = aNatureHumid;
}

Communication::NatureInfo Communication::Information::getNatureGaz() {
        //_natureGaz = Communication::NatureInfo::CL_QAIRINCIDENT;
	return this->_natureGaz;
}

void Communication::Information::setNatureGaz(NatureInfo aNatureGaz) {
	this->_natureGaz = aNatureGaz;
}

string Communication::Information::getDate(){
    //_date = "2/12;12h25mn";
    return _date;
}

void Communication::Information::setDate(string aDate){
    this->_date = aDate;
}

void Communication::Information::setSalle(char aSalle){
    this->_salle=aSalle;
}

char Communication::Information::getSalle(){
    //_salle = 4;
    return _salle;
    
}

Communication::Information::Information(unsigned char temp, unsigned char humid, unsigned char gaz) {
	_valeurTemp = temp;
	_valeurHumid = humid;
	_valeurGaz = gaz;
}

Communication::Information::Information(){
    
}

