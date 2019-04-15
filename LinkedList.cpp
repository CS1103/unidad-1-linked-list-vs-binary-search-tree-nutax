//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"
#include "Location.h"
#include <iostream>
#include <fstream>
#include <sstream>

//UTEC::LinkedList::LinkedList() {

//}

UTEC::LinkedList::~LinkedList() {
if (!is_empty()){clear(head);}
}

void UTEC::LinkedList::clear(UTEC::Node* no){
if(no->next!=nullptr){clear(no->next);}
if(no->next==nullptr){delete no;}
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

void UTEC::LinkedList::print() {
    Node* actual = head;
    while(actual != nullptr) {
        std::cout<<actual->data.get_id()<<std::endl;
        actual = actual->next;
    }
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

UTEC::Node *UTEC::LinkedList::search(int position_id) { 
Node* temp = head;
    while (temp!=nullptr){
if (temp->data.get_id() == position_id ){
break;
}
temp = temp->next;
}
if (temp->data.get_id() != position_id){std::cout<<"ID inexistente"<<std::endl; temp = nullptr;}
return temp;
}

void UTEC::LinkedList::insert(int position, const Location& data) { 
if (position<=UTEC::LinkedList::size()){
Node* temp = head;
Node* temp2 = new Node(data);
int c = -1;
    while (temp!=nullptr){
if (position = c + 1){
break;
}
c++;
temp = temp->next;
}
temp2->next = temp->next;
temp->next = temp2;
}else{
std::cout<<"ERROR: Position>Size";
}
}



void UTEC::load_locations(UTEC::LinkedList *linked_list, std::string file_name) {
    //using namespace UTEC;
    std::ifstream inFile;
    inFile.open(file_name);
	std::string linea;
	bool primero = true;
    while (getline(inFile, linea)) {
if (primero == false){
        Location li(linea);
        linked_list->add_tail(li); //Se añade al final de la lista enlazada la nueva (Location)
	}else{
	primero = false;
	}
    }//Fin de la lectura del archivo
inFile.close();
}
