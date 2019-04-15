//
// Created by ruben on 4/5/19.
//
#include <iostream>
#include <string>
#include <sstream>
#include "Location.h"


Location::Location (std::string linea){
using namespace std;
string segmento[7];
		int c = 0; //Ubicación en el string (linea)
		for (int i = 0; i < 7; i++){
			while (c<linea.length()-1){
				if (linea[c]!= ','){
					segmento[i]=segmento[i]+linea[c];//Se añade letra por letra
					c++;
				}else{
					c++;
					break;//Fin de la manipulación del segmento
				}
			}//Se guarda un segmento
		}//Se guarda en un array de tipo string los 7 segmentos de una linea.
		stringstream _id(segmento[0]);
		stringstream _la(segmento[3]);
		stringstream _lo(segmento[4]);
		int id = 0;
		double la = 0;
		double lo = 0;
		_id>>id;
		_la>>la;
		_lo>>lo;
		position_id = id;
		state_code = segmento[1];
		county = segmento[2];
		latitude = la;
		longitude = lo;
		line = segmento[5];
		construction = segmento[6];// Se convierte y se inserta los segmentos en la variables correspondientes

}

// Defina los metodos que crea necesario
