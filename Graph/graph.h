/*Implementação de um Grafo Não Orientado*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
#include <locale.h>
#include <stdlib.h>
#include <vector>

#define vertex int

class Graph{

    private:

        int N;
        int M;
        //Adjacency List
        vector < vector<int> > adj;
        
    public: 

    Graph(int N, int M){

        this->N = N; this->M = M;

        adj.resize(N);

        this->adj = adj;

    }

    void addEdge(vertex v, vertex w){

        adj[v].push_back(w);
        adj[w].push_back(v);

    }

    void lerGraph(){

        vertex v, w;

        adj.clear(); //limpa
        adj.resize(N);

        for (int i = 0; i < M; i++){

            scanf("%d %d", &v, &w);
            addEdge(v, w);
            
        }

    }

    void printGraph(){

        for (int i = 0; i < N; i++){
            cout << i << " ----> ";
            for (int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }

    }

};

#endif
