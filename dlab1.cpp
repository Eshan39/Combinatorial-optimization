#include<iostream>
#include<bits/stdc++.h>
#define inf 50000
using namespace std;

int dist[100];

struct Edge
{
    int src, dest, weight;

};

struct Graph{
	int V,E;
	struct Edge* edge;
};

struct Graph* creatGraph(int vertex, int edge){
	struct  Graph* graph = new Graph;
	graph->V = vertex;
	graph->E = edge;

	graph->edge = new Edge[edge];
};


void Dijkast(Graph *graph, int source){
	int v = graph->V;
	int e = graph->E;

	for(int i = 0; i<v; i++)dist[i]=inf;
		dist[source]=0;

	for(int i=1; i<=v-1; i++){
		for(int j=0; j<e; j++){
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight =graph->edge[j].weight;

			if(dist[v]>dist[u]+weight)
				dist[v] = dist[u]+weight;

		}
	}


}
void printCost(int node){
	cout<<"cost is: "<<dist[node];
}

int main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;

    if(m==0){
        cout<<"unreachable"<<endl;
        return 0;
    }

	Graph* graph = creatGraph(n,m);

	for(int i=0; i<m; i++){
		cin>>graph->edge[i].src;
		cin>>graph->edge[i].dest;
		cin>>graph->edge[i].weight;
	}

	Dijkast(graph,0);//source = 0;



	printCost(s);

	return 0;
}

