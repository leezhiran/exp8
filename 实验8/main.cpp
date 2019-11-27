#include "iostream"
#include "Kruskal.h"
#include "Prim.h"
#include "Print.h"
using namespace std;
int main() {
	vector<Edge> edges;
	edges.push_back(Edge(0, 1, 1));
	edges.push_back(Edge(0, 2, 2));
	edges.push_back(Edge(1, 2, 4));
	edges.push_back(Edge(2, 3, 1));
	edges.push_back(Edge(2, 4, 1));
	Prim k(5, 5, edges);
    k.generateTree(0);

//	Kruskal k(3,3,edges); 
//	k.generateTree();
}