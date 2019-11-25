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
	/*生成最小生成树
	返回值： -1:不存在连通的最小生成树
			（int）：最小生成树的权值和
	*/
	int generateTree(int chosenPoint){
		 find
	}
};