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
	//vector<Edge>complenmentary;
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
	int findEdge(vector<int> &pointNew, vector<Edge> &edgeOld){
		vector<Edge>::iterator i;
		vector<int>::iterator m;
		for (i = edges.begin(); i < edges.end(); i++) {
			vector<int>::iterator it;
			for (it = pointNew.begin(); it < pointNew.end(); it++) {
				if (pointNew.size() == 1) {
					if (*it == i->from  || *it == i->to ) {
						if (*it == i->from) {
							pointNew.push_back(i->to);
						}
						else if (*it == i->to) {
							pointNew.push_back(i->from);
						}
						connectionMap->connect(i->from, i->to);
						return i->cost;
					}
				}
				else {
					if ((*it == i->from && find(pointNew.begin(), pointNew.end(), i->to) == pointNew.end()) || (*it == i->to && find(pointNew.begin(), pointNew.end(), i->from) == pointNew.end())) {
						if (*it == i->from) {
							pointNew.push_back(i->to);
						}
						else if (*it == i->to) {
							pointNew.push_back(i->from);
						}
						connectionMap->connect(i->from, i->to);
						return i->cost;
					}
				}
			}
			
		}
		
	}
	//初始化处理
	void add(int temp,vector<int> &pointOld, vector<int> &pointNew){
		vector<int>::iterator i;  
		for (i = pointOld.begin(); i < pointOld.end(); i++)
			if (*i == temp) {
				pointOld.erase(i);
				pointNew.push_back(temp);
				return;
			}
		return; 
	}
	/*生成最小生成树
	返回值： -1:不存在连通的最小生成树
			（int）：最小生成树的权值和
	*/
	int generateTree(int chosenPoint){
		vector<int> pointOld;
		vector<int> pointNew;
		vector<Edge>edgesOld=edges;
		for (int i = 0; i < vertexCount; i++) {
			pointOld.push_back(i);
		}
		int sum = 0;
		add(chosenPoint,pointOld,pointNew);
		for (int i = 0; i < edgeCount  ; i++) {
			sum += findEdge(pointNew, edgesOld);
		}
		connectionMap->printAdjacencyMatrix();
		connectionMap->drawGraphWrapper(0);
		return sum;
	}

};