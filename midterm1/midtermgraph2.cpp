# include <queue>
# include <set>
# include <unordered_set>
# include <vector>

class graph
{
public:
    graph(){
    data_ = std::vector<std::unordered_set<std::size_t> >();
    }
    void add_vertex(){
    data_.push_back(std::unordered_set<std::size_t>());
    }
    void add_edge(std::size_t i, std::size_t j) {
    data_[i].insert(j);
    data_[j].insert(i);
    }
    bool is_edge(std::size_t i, std::size_t j) const{
    return data_[i].find(j)!=data_[i].end();
    }

    size_t getsize() const{ // new getter function to get the size of the vector
        return data_.size(); 
    }

    int num_of_components() const;

private:
    std::vector<std::unordered_set<std::size_t>> data_;
    
    void dfs_helper(std::size_t source, std::vector<std::size_t>& traversal, std::vector<bool>& visited) const{
        for(auto neighbor : data_[source]){
            while(!visited[neighbor]){
                visited[neighbor]=true;
                traversal.push_back(neighbor);
                dfs_helper(neighbor, traversal, visited);
            }
        }
    }// a helper function that helps the dfs call 
    // specific see the dfs file in quiz 1
};

// q2: method using DFS returns the number of connected components in a graph.
int graph::num_of_components() const{
    std::vector<std::size_t> traversal;
    std::vector<bool> visited (getsize(),false); // two vectors for dfs
    int components = 0; // a return value

    for(std::size_t current = 0; current < getsize(); current++){ // loop through all th element in the data_, not just one 
        if(!visited[current]){
            visited[current]=true;
            traversal.push_back(current);
            dfs_helper(current, traversal, visited);
            ++components;
        }
    }

    return components;
}