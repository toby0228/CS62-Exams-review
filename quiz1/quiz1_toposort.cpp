// A topological sort is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for
// every directed edge from vertex u to vertex v, u comes before v in the sequence.

// We use DFS traversal for this sorting algorithm

// to keep track of things that is fully visited, visited by have neighor unexploreed, and unvisited
// we use 0,1,2 in visited vector instead of true and false

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

    std::vector<int> toposort(int start){
        std::vector<int> traversal;
        std::vector<int> visited(num_of_vertices(),0);

        visited[start]=1;
        int current=start;
        traversal.push_back(start); // same with bfs until here

        toposort_recursive(current, visited, traversal); // call the recursive function

        return traversal;
        
    }


private:
    std::vector<std::set<int>> adjlist;
    bool toposort_recursive(int source, std::vector<int>& visited, std::vector<int>& traversal){ // call by reference to make sure change the vale in vector
        // this helper function ditermined if there is cycle, and also do traversal
        for(auto neighbor : adjlist[source]){ // loop through neighbor of current
            if(visited[neighbor]==1){ // the neighbor is current means there is a cycle
                return false; // so return false
            }
            else if(visited[neighbor]==0){
                visited[neighbor]=1; // if detected unvisited neighbor mark them visited
                if(!toposort_recursive(neighbor,visited,traversal)){ // call the recursive on this neighbor
                    return false; // if the recursive call on this neighbor return false then return false
                }
            }
        }
        traversal.push_back(source);
        visited[source]=2;
        return true; // return true and add to the vector if no cycle detected
    }
};

int main(){
    Graph G;
    G.add_vertex();
    G.add_vertex();
    G.add_vertex();
    G.add_vertex();
    G.add_vertex();
    G.add_edge(0,1);
    //G.addEdge(2,1);//this one adds a cycle
    G.add_edge(1,3);
    G.add_edge(3,2);
    G.add_edge(4,0);
    G.add_edge(4,1);
    G.add_edge(4,3);
    
    std::vector<int> order = G.toposort(4);
    std::cout<<"ordering: ";
    for(int i=0; i<order.size(); ++i)
        std::cout<<order[i]<<" ";
    return 0;
}