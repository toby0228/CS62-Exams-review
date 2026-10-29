
# include <queue>
# include <set>
# include <unordered_set>
# include <vector>
# include <cstddef>

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

    std::size_t getsize() const{
        return data_.size();
    }

    bool is_biparite();

private:
    std::vector<std::unordered_set<std::size_t>> data_;

    bool dfs_helper(std::size_t source, std::vector<int>& visited) const{
        for(auto neighbor : data_[source]){ // same with old dfs, loop through neighbors
            if(visited[neighbor]==0){
                visited[neighbor]=3-visited[source]; // the neighbor of 1 must be 2, because group 1's vertex in not connected with each other. works same in the other way

                if(!dfs_helper(neighbor, visited)){// recursive call the funtion with neighbor, if false, then the function should be false
                    return false;
                }
            }
            else if(visited[neighbor]==visited[source]){ // if the neighbor is in same group, no bipartite
                return false;
            }
        }
        return true;
    }
};
 // bipartite means we can devide a graph into two groups, inside each group, the vetecies are not connected
 // so the approach is to make visited have 0,1,2 0 unvisited, 1 group 1, 2 group 2
bool graph::is_biparite(){
    std::vector<int> visited(getsize(),0); // use the approach list above

    for(std::size_t current=0;current<getsize();current++){ // loop through all the element in vector
        if(visited[current]==0){
            visited[current]=1; // if the current is not visited mark them group 1

            if(!dfs_helper(current, visited)){
                return false; // if the helper find no bipartite return false
            }
        }
    }
    return true; // true other wise
}
