//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC {

    struct Node_bi {
        Location data;
        Node_bi* right;
        Node_bi* left;
	Node_bi(Location _data): data(_data){right=nullptr; left=nullptr;}
    };

    class BinarySearchTree {
        Node_bi* root;
    public:
        BinarySearchTree(){root=nullptr;}; //Check
        ~BinarySearchTree(); //Check
        void insert(const Location& data); //Check
        void clear(Node_bi* ro);//Check
        bool is_empty(); //Check
        Node_bi* get_root(); //Check
        Node_bi* search(int position_id, Node_bi* ro); //Check
        void print(Node_bi* ro);//Check
    };

    void load_locations2(BinarySearchTree* linked_list, std::string file_name); //Check
    void print_node(Node_bi* node);//Check
}
#include "BinarySearchTree.cpp"
#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
