#pragma once
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
#include "Graph.h"
class Prim {
private:
	Graph* connectionMap;
	vector<Edge>edges;
	vector<Edge>complenmentary;
	int vertexCount;
	int edgeCount;
	int unionedPoint;
	int chosenPoint;
	int close;
public:
	Prim(int vertexCount, int edgeCount, vector<Edge> edgeInfo) {
		connectionMap = new Graph(vertexCount, true, edgeInfo);
		this->edges = vector<Edge>(edgeInfo);
		this->edgeCount = edgeCount;
		this->vertexCount = vertexCount;
		sort(edges.begin(), edges.end(), cmp);
		chosenPoint = 0;
	}
	int find(vector<Edge> complenmentary, vector<Edge> edges){

	}
	/*������С������
	����ֵ�� -1:��������ͨ����С������
			��int������С��������Ȩֵ��
	*/
	int generateTree(int chosenPoint){
		 find
	}
};