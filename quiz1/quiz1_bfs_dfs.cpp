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

    std::vector<int> bfs(int start){
        std::vector<int> traversal; // the vector we will return at the end
        std::vector<bool> visited(num_of_vertices(),false); // the vector to trace which vertex is vistied
        std::queue<int> q; // the queue for bfs need

        visited[start]=true; // mark the first element visited
        q.push(start); // push the first element into queue
        traversal.push_back(start); // push the first element into traversal

        while(!q.empty()){ 
            int current=q.front(); // make first element current
            q.pop(); // every time pop on element out of the queue
            for(auto neighbor : adjlist[current]){ // loop through the neighbor of the current
                if(!visited[neighbor]){ 
                    q.push(neighbor); // push the unvisited neighbor into queue(in order to check their neighbors later)
                    visited[neighbor]=true; // mark them visited
                    traversal.push_back(neighbor); // and push them into traversal
                }
            }
        }
        return traversal;
    }

    std::vector<int> dfs(int start){
        std::vector<int> traversal;
        std::vector<bool> visited(num_of_vertices(),false);

        visited[start]=true;
        int current=start;
        traversal.push_back(start); // same with bfs until here

        dfs_recursive(current, visited, traversal); // call the recursive function

        return traversal;
        
    }


private:
    std::vector<std::set<int>> adjlist;
    void dfs_recursive(int source, std::vector<bool>& visited, std::vector<int>& traversal){ // call by reference to make sure change the vale in vector
        for(auto neighbor : adjlist[source]){ // loop through neighbor of current
            if(!visited[neighbor]){
                visited[neighbor]=true; // mark the unvisited neighbor visited
                traversal.push_back(neighbor); // and push_back this neighbor into traversal
                dfs_recursive(neighbor,visited,traversal); // and do the samething with the neighbor of the current
                /* this follows the rule of stack, when a neighbor of current is push to traversal, it will check the neighbor of this neighbor
                directly instead of add all the neighbor of current into travelsal*/
            }
        }
    }
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

    std::cout<< "bfs:" << "\n";
    std::vector<int> traversal = g.bfs(0);
    for(int i=0;i<traversal.size();i++){
        std::cout<< traversal[i]<< " ";
    }
    std::cout<< "\n";

    std::cout<< "dfs:" << "\n";
    std::vector<int> traversal2 = g.dfs(0);
    for(int i=0;i<traversal2.size();i++){
        std::cout<< traversal2[i]<< " ";
    }

    std::cout<< "\n";

}
