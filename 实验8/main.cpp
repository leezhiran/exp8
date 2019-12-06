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
	edges.push_back(Edge(0, 11, 1));
	Print solve;
	while (1) {	
		solve.Menu1();
		char flag;
		cout << endl << ">";
		cin >> flag;
		Kruskal k(12, 12, edges);
		Prim p(12, 12, edges);
		switch (flag) {
		case '1':
			k.generateTree();
			cout << endl;
			system("pause");
			system("cls");
			break;
		case '2':
			p.generateTree(0);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case '3':exit(0); break;
		default: break;
		}
	}
}