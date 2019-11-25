#include "iostream"
#include "Kruskal.h"
#include "Prim.h"
using namespace std;
int main() {
	vector<Edge> edges;
	edges.push_back(Edge(0, 1, 1));
	edges.push_back(Edge(1, 2, 4));
	edges.push_back(Edge(0, 2, 2));
	Kruskal k(3,3,edges); 
	k.generateTree();
}