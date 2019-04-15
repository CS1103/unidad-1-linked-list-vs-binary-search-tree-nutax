#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    // Grabar Datos del archivo "Locations.csv" en bst
load_locations(&ll, LOCATION_FILE);
load_locations2(&bst, LOCATION_FILE);
    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
std::ifstream file1(SEARCH_FILE);
std::string line;
while(getline(file1,line)){
		std::stringstream _line(line);
		int id2 = 0;
		_line>>id2;   
		vsearch.push_back(id2);
}
file1.close();
    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    ll.print();
	bst.print(bst.get_root());
	Node* test = nullptr;
	Node_bi* test2 = nullptr;
for (const auto& id: vsearch) {
        // Buscar en ll
	auto start = std::chrono::high_resolution_clock::now();
	test = ll.search(id);
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = stop - start;
	avgtime_ll = avgtime_ll + elapsed.count();
        // Buscar en bsd
	auto start2 = std::chrono::high_resolution_clock::now();
	test2 = bst.search(id, bst.get_root());
	auto stop2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed2 = stop2 - start2;
	avgtime_bst = avgtime_bst + elapsed2.count();
    }

avgtime_ll = avgtime_ll/vsearch.size();
avgtime_bst = avgtime_bst/vsearch.size();
std::cout<<"Tiempo promedio de lista enlazada: "<<avgtime_ll<<" segundos"<<std::endl<<"Tiempo promedio de busqueda binaria: "<<avgtime_bst<<" segundos"<<std::endl;
ll.~LinkedList();
//bst.~BinarySearchTree();//Revisar el destructor, teòricamente no parece tener problemas la soluciòn recursiva que planteo.
std::cout<<"Fin del programa"<<std::endl;
    return 0;
}
