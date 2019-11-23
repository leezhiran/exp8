#pragma once
#include "iostream"
using namespace std;
class Graph {
	bool undirectedIndex;
	int vertexCount;
	bool** adjacencyMatrix;
	
public:
	/*���캯��
	��������int��vertexCountͼ�нڵ����
		��bool��undirectCount ��ͼ�Ƿ�Ϊ����ͼ
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
	/*��������*/
	~Graph() {
		for (int i = 0; i < vertexCount; i++) {
			delete[]adjacencyMatrix[i];
		}
		delete[]adjacencyMatrix;
	}
};