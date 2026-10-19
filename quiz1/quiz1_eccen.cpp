#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

class Graph{
public:
    Graph(){}
    int num_of_vertices() const{
        return adjlist.size();
    }

    void add_edge(int u, int v){
        adjlist[u].insert(v); // add the number to both num's set
        adjlist[v].insert(u);
    }

    void add_vertex(){
        adjlist.push_back(std::set<int>()); // add new set to the vector
    }


    int eccentricity(int id){
        std::vector<bool> visited (num_of_vertices(),false); // we can don't use this, since distance[i]=-1 means unvisited
        std::vector<int> distance (num_of_vertices(),-1); // -1 means not visited yet
        std::queue<int> q; // for distance questions, we use bfs

        distance[id]=0; // initialize the distance to start = 0
        q.push(id);
        visited[id]=true;

        int max_distance=0; // assign an max distance value

        while(!q.empty()){
            int current=q.front();
            q.pop(); // bfs queue
            for(auto neighbor : adjlist[current]){
                if(distance[neighbor]==-1){ // if the neighbor is not visited yet(smae with if(!visited[neighbor]))
                    distance[neighbor]=distance[current]+1; // distance of this neighbor equals to distance to current + 1

                    if(distance[neighbor]>max_distance){ // if the distance is more than max then make max this distance
                        max_distance=distance[neighbor];
                    }
                    visited[neighbor]=true; // mark visited
                    q.push(neighbor); // push it to queue, following bfs algorithm
                }

            }
        }

        for(int i=0;i<num_of_vertices();i++){
            if(distance[i]==-1){ // check if there are vertex unvisited
                return -1;
            }
        }
        return max_distance;
 
    }


private:
    std::vector<std::set<int>> adjlist;
};

int main(){
    Graph g;
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,5);
    g.add_edge(3,5);
    g.add_edge(4,3);
    g.add_edge(0,4);

    int out = g.eccentricity(0);

    std::cout<< out << "\n";
}