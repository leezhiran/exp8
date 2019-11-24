#pragma once
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
#include "Graph.h"
using namespace std;
#define INF 0x3f3f3f3f
/*KRUSKAL O(n)=nlogn*/

class Kruskal {
private:
	Graph* connectionMap;
	int costSum;
	int vertexCount;
	int edgeCount;
	int unionedPoint;
	vector<Edge>edges;     
	int fatherSet[101]; 
	int findRoot(int i) {
		if (fatherSet[i] != i)
			fatherSet[i] = findRoot(fatherSet[i]);
		return fatherSet[i];
	}
	int mergeTree(int i, int j)
	{
		int iRoot = findRoot(i);
		int jRoot = findRoot(j);
		if (iRoot == jRoot)
			return 0;
		fatherSet[jRoot] = iRoot;
		unionedPoint++;
		return 1;
	}
public:
	/*���캯��
	������(int)vertexCount ͼ�еĽڵ����
		 (int)edgeCount ͼ�б߸���
		 (vector<Edge>)edgeInfo ͼ�и�������Ϣ
	*/
	Kruskal(int vertexCount,int edgeCount,vector<Edge> edgeInfo){
		connectionMap = new Graph(vertexCount, true,edgeInfo);
		for (int i = 0; i < vertexCount;i++) {
			fatherSet[i] = i;
		}
		this->edges=vector<Edge>(edgeInfo);
		this->edgeCount = edgeCount;
		this->vertexCount = vertexCount;
		costSum = 0;
		sort(edges.begin(), edges.end(),cmp);
	}
	/*������С������
	����ֵ�� -1:��������ͨ����С������
			��int������С��������Ȩֵ��
	*/
	int generateTree() {
		for (int i = 0; i < vertexCount; i++) {
			if (mergeTree(edges.at(i).from, edges.at(i).to)==true) {
				costSum += edges.at(i).cost;
				connectionMap->connect(edges.at(i).from, edges.at(i).to);
			}
		}
		connectionMap->printAdjacencyMatrix();
		connectionMap->drawGraph(0);
		if (unionedPoint == vertexCount - 1) {
			return costSum;
		}
		else {
			return -1;
		}
		
	}
	~Kruskal() {
		delete connectionMap;
	}
};

