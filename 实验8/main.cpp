#include "iostream"
#include<algorithm>
#include<vector>
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
	Print solve;
	while (1) {	
		system("cls");
		int i = solve.division();
		if (i == '1') {
			cout << endl;
			Prim a(11, 11, edges);
			a.generateTree(0);
			cout << endl;
			getchar();
			getchar();
		}
		else if (i == '2') {
			cout << endl;
			Kruskal k(11, 11, edges);
			k.generateTree();
			cout << endl;
			getchar();
			getchar();
		}
		else if (i == '3')
			exit(1);
	}
}