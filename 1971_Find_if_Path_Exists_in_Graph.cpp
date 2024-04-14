class Solution {
public:
    bool getPath(int src, int des, vector<vector<int>> &adj, vector<int> &visited){
        // base case
        if(src == des){
            return true;
        }

        visited[src] = 1;

        for(auto node:adj[src]){
            if(visited[node] == 0){
                visited[node] = 1;
                if(getPath(node, des, adj, visited)){
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, 0);
        return getPath(source, destination, adj, visited);
    }
};



// class Solution {
// public:
//     bool getPath(int src, int des, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited){
//         if(src == des){
//             return true;
//         }
            
//         for(auto node:adj[src]){
//             if(visited[node] == false){
//                 visited[node] = true;
                
//                 if(getPath(node, des, adj, visited)) return true;
//             }
//         }

//         return false;
//     }

//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         unordered_map<int,list<int>> adj;

//         for(auto edge:edges){
//             int u = edge[0];
//             int v = edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }   

//         unordered_map<int,bool> visited;
//         visited[source] = true;

//         return getPath(source, destination, adj, visited);
//     }
// };