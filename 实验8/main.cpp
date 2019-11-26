#include "iostream"
#include "Kruskal.h"
using namespace std;
int main() {
	vector<Edge> edges;
	edges.push_back(Edge(0, 1, 1));
	edges.push_back(Edge(1, 2, 4));
	edges.push_back(Edge(0, 2, 2));
	edges.push_back(Edge(1, 3, 1));
	edges.push_back(Edge(1, 4, 1));
	Kruskal k(5,5,edges);
	k.generateTree();
}