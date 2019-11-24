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
	/*���캯��
	��������int��vertexCountͼ�нڵ����
		��bool��undirectCount ��ͼ�Ƿ�Ϊ����ͼ
		(vector<Edge>)edges ����Ϣ
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
	��ͼ������������Ϊ����
	��int��i ��1
	��int��j ��2
	��������ͼ��Ҳ��ʹj��i����
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
	����ڽӾ���
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
	/*��������*/
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