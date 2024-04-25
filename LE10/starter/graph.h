#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

#define INF 2147000000

class Graph {
    private:
        int n;
        typedef pair<int, int> Edge;
        vector<list<Edge>> v;
        
    public:
        Graph(int size = 2) {
            n = size;
            v.resize(n);
        }

        void addEdge(int x, int y, int w) {
            v[x].push_back(Edge(y,w));
            v[y].push_back(Edge(x,w));
        }

        void print() {
            for(int i = 0; i < n; i++) {
                cout << "Node " << i << " is connected to: ";
                for (pair<int,int> j : v[i]) {
                    if(j.first != -1){
                        cout << j.first << " : "<< j.second<<", ";
                    }
                }
                cout << endl;
            }
        }

        vector<pair<int, int>> dijkstra(int startNode) {
            vector<pair<int, int>> p(n);

            priority_queue< pair<int,int> > pq;

            for(int i = 0; i < n; i++) { // set all distances to INF and paths to -1
                p[i].first = INF;
                p[i].second = -1;
            }

            p[startNode].first = 0;
            int currNode = startNode;
            pq.push(make_pair(0,startNode));

            while(!pq.empty()) {
                currNode = pq.top().second;
                pq.pop();
                // Update paths
                for(list<Edge>::iterator it = v[currNode].begin(); it != v[currNode].end(); it++) { // for each edge of curr node

                    if (p[currNode].first + it->second < p[it->first].first ) {// if new distance is less than curr update it
                        p[it->first].first = p[currNode].first + it->second;
                        p[it->first].second = currNode;
                        pq.push(make_pair(p[currNode].first + it->second,it->first));
                    }
                }
            }

            return p;
        } 

        string printShortestPath(int startNode, int endNode) {
            vector<pair<int, int>> paths = dijkstra(startNode);
            string ret = "";
            int currLocation = endNode;
            while(currLocation != -1 && paths[currLocation].first < INF) {
                ret = to_string(currLocation) + " " + ret;
                currLocation = paths[currLocation].second;
            }

            return ret;
        }
};



