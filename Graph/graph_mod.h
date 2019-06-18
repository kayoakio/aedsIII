/*Grafo Orientado 
  DFS modificada
  Função de de achar o Grafo Transposto
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <locale.h>
#include <utility>
#include <stdlib.h>
#include <iostream>
using namespace std; 

#define vertex int 

#define white 0
#define grey  1
#define black 2

//Graph
class Graph{

    private:
        int N, M; 
        vector < vector <int> > adj;

    public:

    Graph(int N, int M){

        this->N = N; this->M = M;

        adj.resize(N);

    }

    void addEdge(vertex v, vertex w){

        adj[v].push_back(w);

    }

    void readGraph(){

        adj.clear();

        vertex v, w;

        for (int i = 0; i < M; i++){

            scanf ("%d %d", &v, &w);
            addEdge(v, w);

        }

    }

    void printGraph(){

        for (int i = 0; i < N; i++){

            cout << i << " ---> ";

            for (int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << " ";
            }

            cout << endl;

        }

    }

    int dfs(){

        vector < vertex > colors (N, white);
        vector < pair < int, int > > times (N);    
        int cont = 0;

        for (int i = 0; i < N; i++){

            if (colors[i] == white){
                dfs_recursive(i, colors, times, cont);
            }
            
            //cout << endl;

        }

        cout << endl;
        printTimes(times);

    }

    void dfs_recursive(vertex v, vector < vertex > &colors, vector < pair <int, int> > &times, int &cont){
        
        colors[v] = grey;
        
        cont = cont + 1;

        times[v].first = cont;
        
        cout << v << " ";

        for (int i = 0; i < adj[v].size(); i++){

            if (colors[adj[v][i]] == white){

                dfs_recursive(adj[v][i], colors, times, cont);
              
            }
            
            cont = cont + 1;
            times[adj[v][i]].second = cont;   
            
        }

        times[v].second = cont;
        
        colors[v] = black;

    }

    Graph trans(){

        Graph trans(N, M);

        for (int i = 0; i < N; i++){

            for (int j = 0; j < adj[i].size(); j++){

                //trans.adj[]
                trans.adj[adj[i][j]].push_back(i);

            }

        }

        return trans;
    }

    void printTimes(vector <pair < int, int > > times){

        times.resize(N);

        for (int i = 0; i < times.size(); i++){

            cout << i << ": " << times[i].first << "," << times[i].second << endl;

        }
    }
};

#endif //GRAPH_H
