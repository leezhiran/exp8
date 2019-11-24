#pragma once
#include "iostream"
#include "Kruskal.h"
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

};
bool cmp(Edge a, Edge b) {
	return a.cost < b.cost;
}
class Graph {

	bool undirectedIndex;
	int vertexCount;
	bool** adjacencyMatrix;
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
		adjacencyMatrix = new bool*[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			adjacencyMatrix[i] = new bool[vertexCount];
		}
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < vertexCount; j++) {
				adjacencyMatrix[i][j] = false;
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
		adjacencyMatrix[i][j] = true;
		if (undirectedIndex == true) {
			adjacencyMatrix[j][i] = true;
		}
	}
	/*
	输出邻接矩阵
	*/
	void printAdjacencyMatrix() {
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < vertexCount; j++) {
				cout << adjacencyMatrix[i][j];
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
	void drawGraph(int entrance) {
		bool first = true;
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < i; j++) {
				if (adjacencyMatrix[i][j] == true) {
					Edge cache=findPathByPoints(j, i);
					if (first == true) {
						cout << cache.from;
						cout << "<=" << cache.cost << "=>";
						cout << cache.to;
						first = false;
					}
					else {
						cout << "<=" << cache.cost << "=>";
						cout << cache.to;
					}
				}
			}
		}
	}
};