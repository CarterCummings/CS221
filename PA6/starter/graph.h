#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    private:
        unordered_map<int, unordered_map<int, int>> adjList;

    public:
        Graph() {};

        bool contains_vertex(int u) {
            return adjList.find(u) != adjList.end();
        }

        bool contains_edge(int u, int v) {
            if (!contains_vertex(v) || !contains_vertex(v)) {
                return false;
            }
            return adjList[u].find(v) != adjList[u].end();
        }

        void addVertex(int u) {
            if (!contains_vertex(u)) {
                adjList[u] = unordered_map<int,int>();
            }
        }

        void addEdge(int u, int v, int w) {
            if (!contains_vertex(u) || !contains_vertex(v)) {
                throw std::out_of_range("u or v doesnt exist");
            }
            adjList[u][v] = w;
            adjList[v][u] = w;
        }

        void removeEdge(int u, int v) {
            adjList[u].erase(v);
            adjList[v].erase(u);
        }

        void removeVertex(int id) {
            unordered_map<int, unordered_map<int, int>>::iterator itr;
            for(itr = adjList.begin(); itr != adjList.end(); itr++) {
                itr->second.erase(id);
            }
            adjList.erase(id);
        }

        int numVertices() {
            return adjList.size();
        }

        int getEdgeWeight(int u, int v) {
            return adjList[u][v];
        }

        vector<pair<int, int>> primMST() {
            vector<pair<int, int>> p;
            unordered_map<int, bool> visited;
            priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > Edgespq; // (w,(vertexA, vertexB))

            if (adjList.size() <= 0) {
                return p;
            }

            unordered_map<int, int>::iterator itr;
            for(itr = adjList.begin()->second.begin(); itr != adjList.end()->second.end(); itr++) { // push all edges for vertex 1
                //Edgespq.push(weight,make_pair(u,v));
                Edgespq.push(make_pair(itr->second,make_pair(adjList.begin()->first,itr->first)));
            }
            visited[adjList.begin()->first] = true;

            while(!Edgespq.empty()) {
                // Edgespq.top().first; weight
                // Edgespq.top().second; edge
                // Edgespq.top().second.first; vertexA
                // Edgespq.top().second.second; VertexB

                pair<int, int> nextEdge = Edgespq.top().second;
                Edgespq.pop();

                if(visited[nextEdge.second]) {continue;}

                visited[nextEdge.second] = true;
                
                p.push_back(nextEdge);
   
                for(itr = adjList[nextEdge.second].begin(); itr != adjList[nextEdge.second].end(); itr++) { // push all edges for vertex 1
                    Edgespq.push(make_pair(itr->second,make_pair(nextEdge.second,itr->first)));
                }

            }
            
            return p;
        }
};