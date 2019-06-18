#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
#include <locale.h>
#include <stdlib.h>
#include <vector>

#define vertex int 
#define branco 0
#define cinza  1
#define preto  2

class Graph{

    //Attributes
    private:

        int N; // # vertices
        int M; // # edges
        vector < vector < int > > adj; //Adjacency List
        
        void searchdfs(vertex v, vector <vertex> &cor){

            cor[v] = cinza;

            for (int i = 0; i < adj[v].size(); i++){

                vertex w = adj[v][i];

                if (cor[w] == branco){

                    cout << w << endl;

                    searchdfs(w, cor);
                
                }
                
            }

            cor[v] = preto;
            
        }

    public:

        //Constructor
        Graph(int N, int M){

            this->N = N;
            this->M = M;

            adj.resize(N); //Initialization

            this->adj = adj;

        }

        //Methods

        void addEdge(vertex v, vertex w){

            adj[v].push_back(w);
            adj[w].push_back(v);

        }

        void readGraph(){

            adj.clear();
            adj.resize(N);

            int i;
            vertex v, w;

            for (i = 0; i < M; i++){

                scanf("%d %d", &v, &w);
                addEdge(v, w);              

            }        

        }

        void printGraph(){

            int i, j;

            for(i = 0; i < N; i++){

                cout << i << " ----> ";

                for (j = 0; j < adj[i].size(); j++){

                    cout << adj[i][j] << " ";

                }
                
                cout << endl;

            }
        }
        
        //DFS - Depth-First Search

        void dfs (){

            vector <vertex>  cor(N, 0);

            for (vertex v = 0; v < N; v++){

                if(cor[v] == branco){

                    cout << v << endl;

                    searchdfs(v, cor);

                }

                //cout << cor[v] << endl;

            }

        }

        


};

#endif //GRAPH_H