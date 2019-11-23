#pragma once
#include "iostream"
using namespace std;
class Graph {
	bool undirectedIndex;
	int vertexCount;
	bool** adjacencyMatrix;
	
public:
	/*构造函数
	参数：（int）vertexCount图中节点个数
		（bool）undirectCount 该图是否为无向图
	*/
	Graph(int vertexCount,bool undirectedIndex) {
		this->undirectedIndex = undirectedIndex;
		this->vertexCount = vertexCount;
		adjacencyMatrix = new bool*[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			adjacencyMatrix[i] = new bool[vertexCount];
		}
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < vertexCount; j++) {
				adjacencyMatrix[i][j] = false;
				cout << adjacencyMatrix[i][j];
			}
		}
	}
	Graph() {

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
	/*析构函数*/
	~Graph() {
		for (int i = 0; i < vertexCount; i++) {
			delete[]adjacencyMatrix[i];
		}
		delete[]adjacencyMatrix;
	}
};