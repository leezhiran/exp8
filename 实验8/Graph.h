#pragma once
#include "iostream"
#include "Kruskal.h"
#include "iomanip"
using namespace std;
class Edge {
public:
	int from;
	int to;
	int cost;
	Edge(int from, int to, int cost) {
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
	Edge() {
		this->from = -1;
		this->to = -1;
		this->cost = -1;
	}
};

class Graph {

	bool undirectedIndex;
	int vertexCount;
	pair<bool,Edge>** adjacencyMatrix;
	vector<Edge> edges;
public:
	/*构造函数
	参数：（int）vertexCount图中节点个数
		（bool）undirectCount 该图是否为无向图
		(vector<Edge>)edges 边信息
	*/
	Graph(int vertexCount,bool undirectedIndex,vector<Edge> edges) {
		this->edges =vector<Edge>(edges);
		this->undirectedIndex = undirectedIndex;
		this->vertexCount = vertexCount;
		adjacencyMatrix = new pair<bool,Edge>*[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			adjacencyMatrix[i] = new pair<bool,Edge>[vertexCount];
		}
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < vertexCount; j++) {
				adjacencyMatrix[i][j].first = false;
			}
		}
	}

	explicit Graph() {

	}
	/*
	将图中两个点设置为相临
	（int）i 点1
	（int）j 点2
	对于无向图，也会使j和i相邻
	*/
	void connect(int i, int j) {
		if (i > vertexCount || j > vertexCount) {
			cerr << "VertexIndex:Out of Range" << endl;
			return;
		}
		adjacencyMatrix[i][j].first = true;
		if (undirectedIndex == true) {
			adjacencyMatrix[j][i].first = true;
			adjacencyMatrix[j][i].second = Edge(findPathByPoints(i,j));
		}
	}
	/*
	输出邻接矩阵
	*/
	void printAdjacencyMatrix() {
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < vertexCount; j++) {
				cout << adjacencyMatrix[i][j].first;
				cout << adjacencyMatrix[i][j].second.from;
			}
			cout << endl;
		}
	}
	Edge findPathByPoints(int from, int to) {
		for (vector<Edge>::iterator iti = edges.begin(); iti < edges.end(); iti++) {
			if (iti->from == from && iti->to == to) {
				return *iti;
			}
		}
		return Edge(-1, -1, -1);
	}
	/*析构函数*/
	~Graph() {
		for (int i = 0; i < vertexCount; i++) {
			delete[]adjacencyMatrix[i];
		}
		delete[]adjacencyMatrix;
	}
	void drawGraphWrapper(int entrance) {
		bool* visited = new bool[vertexCount];
		fill(visited, visited + vertexCount, false);
		for (int i = 0; i < vertexCount; i++) {
			if (visited[i]==false) {
				drawGraph(entrance, visited,i,0);
			}
			
		}
	}
	void drawGraph(int entrance,bool* visited,int index,int tabs) {
		static bool thisIsFirstOutput = true;
		visited[entrance] = true;
		if (adjacencyMatrix[entrance][index].second.from != -1) {
			if (thisIsFirstOutput == true) {
				cout <<setw(2)<< adjacencyMatrix[entrance][index].second.from << "=(" <<setw(2)<< adjacencyMatrix[entrance][index].second.cost << ")=>" <<setw(2) <<adjacencyMatrix[entrance][index].second.to;
				thisIsFirstOutput = false;
			}
			else {
				cout << "=(" <<setw(2)<< adjacencyMatrix[entrance][index].second.cost << ")=>" <<setw(2)<< adjacencyMatrix[entrance][index].second.to;
			}
		}
		cout << endl;
		for (int i = 0; i < tabs; i++) {
			cout << "         ";
		}
		thisIsFirstOutput = true;
		for (int j = 0; j < vertexCount; j++) {
			if (visited[j] == false && adjacencyMatrix[entrance][j].first == true) {
				drawGraph(j, visited,entrance,tabs++);
			}
		}

	}
};