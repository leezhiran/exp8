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
	edges.push_back(Edge(4, 5, 1));
	edges.push_back(Edge(4, 6, 1));
	edges.push_back(Edge(4, 7, 1));
	edges.push_back(Edge(7, 8, 1));
	edges.push_back(Edge(2, 9, 1));
	edges.push_back(Edge(8, 10, 1));
	Prim k(11, 11, edges);
    k.generateTree(0);

//	Kruskal k(3,3,edges); 
//	k.generateTree();
}