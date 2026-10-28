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

    std::vector<std::size_t> distance_from_vertex(std::size_t from, int dis) const;

private:
    std::vector<std::unordered_set<std::size_t>> data_;
};

// q1: method using BFS returns a vector of all vertices that are the given distance from the given vertex. 

std::vector<std::size_t> graph::distance_from_vertex(std::size_t from, int dis) const{
    std::vector<std::size_t> out; // an output vector
    std::vector<int> dist_to_from(getsize(),-1); // a vector to keep track of distance
    std::queue<std::size_t> q; // queue for bfs

    dist_to_from[from]=0;
    q.push(from);

    while(!q.empty()){
        std::size_t current = q.front();
        q.pop();
        if(dist_to_from[current]==dis){
            out.push_back(current);
        }
        for(auto neighbor : data_[current]){
            if(dist_to_from[neighbor]==-1){
                dist_to_from[neighbor]=dist_to_from[current]+1;
                q.push(neighbor);
            }
        }
    }
    return out;
}