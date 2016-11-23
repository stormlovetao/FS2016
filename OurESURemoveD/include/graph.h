#ifndef GRAPH_H
#define GRAPH_H
#define MAXN 100/* maximum allowed n value; use 0 for dynamic sizing. */
				//#define MAXM ((MAXN+WORDSIZE-1)/WORDSIZE)  /* max setwords in a set */
#include <vector>
#include <algorithm>
#include <string>
#include "nauty.h"



using namespace std;

class Subgraph {
public:
	unsigned int *children;
	bool *visited;
	unsigned int *vertices;//
	//unsigned int *verticesEdges;// Tao add : save added edges for each newly added vertice
	string* verticesAdj;
	unsigned int lastVertex;
	long childCounter;
	int subgraphSize;


	void AddChild(int vertex);
	Subgraph(int subgraphSize, int maxDegree, int graphSize);
	Subgraph() {childCounter = 0;}
	~Subgraph();//definition in graph.cpp
	bool Print();
};


typedef int vertex;
typedef long long Entry;

class Graph {
public:
    Graph(const int n, int k);
    ~Graph();
	graph * nauty_g;
	int* lab;
	int* ptn;
	int* orbits;
	long long unsigned int* ID;
	//QTree* quaT;
	double printingTime;
	void Nexts(Subgraph *sub, int maxSize, int startChild);//extends the subgraph sub
    void  setPath(char *path);
	void addEdgeAdjMat(vertex u, vertex v);
	
	
	void  addEdge(vertex u, vertex v);
	int* getNeighbours(vertex v);
	bool isConnected(vertex u, vertex v);
	void Print();
	void Finalize(bool directed);
	int Size() { return nV; }
	int Edges() { return nE; }
	int MaxDegree() { return maxDegree; }
	std::string GetTreeString(unsigned int* subVertices);
	std::string GetAdjMatString(unsigned int* subVertices);
	std::string subGetTreeString(unsigned int* subVertices, int root, int rootInd );
	

	int M;
	long long unsigned subgraphCounter;
	long long unsigned notClassSubCounter;
	int nV;
	int subgraphSize;
	
private:
    FILE *am;
	vector< vector<vertex> > E_temp;
	int *degree;
	int **E;
	int h;
	int nE;
	char *adjMat;
	int rowSize;
	int nEd;
	int maxDegree;
};
#endif //GRAPH_H
