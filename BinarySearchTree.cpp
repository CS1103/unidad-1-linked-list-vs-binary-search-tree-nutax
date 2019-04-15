//
// Created by ruben on 4/5/19.
//

#include "BinarySearchTree.h"
#include "Location.h"
#include <iostream>
#include <fstream>


UTEC::BinarySearchTree::~BinarySearchTree(){
if (!is_empty()){clear(root);}
}

void UTEC::BinarySearchTree::clear(Node_bi* ro){

if (ro->left != nullptr){clear(ro->left);}
if (ro->right != nullptr){clear(ro->right);}
delete ro;

}

void UTEC::BinarySearchTree::print(UTEC::Node_bi* ro){
if (!is_empty()){
UTEC::print_node(ro);
if (ro->left != nullptr){print(ro->left);}
if (ro->right != nullptr){print(ro->right);}
}
}

bool UTEC::BinarySearchTree::is_empty(){return root==nullptr;}

UTEC::Node_bi *UTEC::BinarySearchTree::get_root(){return root;}

void UTEC::BinarySearchTree::insert(const Location& data){
Node_bi* temp = new Node_bi(data);
if (is_empty()){root = temp;}else{
Node_bi* madre = search(temp->data.get_id(), root);
if (temp->data.get_id() < madre->data.get_id()){madre->left = temp;}
if (temp->data.get_id() > madre->data.get_id()){madre->right = temp;}
}

}//Fin de la funciòn


UTEC::Node_bi *UTEC::BinarySearchTree::search(int position_id, UTEC::Node_bi* ro){

if ((position_id < ro->data.get_id()) && ro->left != nullptr){ro = search(position_id, ro->left);}

if ((position_id > ro->data.get_id()) && ro->right != nullptr){ro = search(position_id, ro->right);}


return ro;

}//Fin de la funciòn

void UTEC::load_locations2(UTEC::BinarySearchTree* linked_list, std::string file_name){

std::ifstream inFile;
    inFile.open(file_name);
	std::string linea;
	bool primero = true;
    while (getline(inFile, linea)) {
if (primero == false){
        Location li(linea);
        linked_list->insert(li); //Se añade la nueva (Location)
	}else{
	primero = false;
	}
    }//Fin de la lectura del archivo
inFile.close();

}

void UTEC::print_node(UTEC::Node_bi* node){

using namespace std;

cout<<"Data: "<<node->data.get_id()<<endl;
if (node->left != nullptr){
cout<<"Left: "<<(node->left)->data.get_id()<<endl;
}
if (node->right != nullptr){
cout<<"Right: "<<(node->right)->data.get_id()<<endl;
}
cout<<endl<<endl;
}
