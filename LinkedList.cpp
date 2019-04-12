//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"
#include <fstream>
#include <sstream>

UTEC::LinkedList::LinkedList() {

}

UTEC::LinkedList::~LinkedList() {

}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::load_locations(UTEC::LinkedList *linked_list, std::string file_name) {
    using namespace std;
    ifstream inFile;
    inFile.open(file_name);
	string linea;
    while (getline(inFile, linea)) {
        string segmento[7];
		int c = 0; //Ubicación en el string (linea)
		for (int i = 0; i < 7; i++){
			while (linea[c]){
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
		Location l(id, segmento[1], segmento[2], la, lo, segmento[5], segmento[6]);
        linked_list->add_tail(l); //Se añade al final de la lista enlazada la nueva (Location)
    }//Fin de la lectura del archivo

}
