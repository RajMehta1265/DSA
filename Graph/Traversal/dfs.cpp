// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   private: 
//     void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
//         vis[node] = 1; 
//         ls.push_back(node); 
//         // traverse all its neighbours
//         for(auto it : adj[node]) {
//             // if the neighbour is not visited
//             if(!vis[it]) {
//                 dfs(it, adj, vis, ls); 
//             }
//         }
//     }
//   public:
//     // Function to return a list containing the DFS traversal of the graph.
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//         int vis[V] = {0}; 
//         int start = 0;
//         // create a list to store dfs
//         vector<int> ls; 
//         // call dfs for starting node
//         dfs(start, adj, vis, ls); 
//         return ls; 
//     }
// };

// void addEdge(vector <int> adj[], int u, int v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void printAns(vector <int> &ans) {
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
// }

// int main() 
// {
//     vector <int> adj[5];
    
//     addEdge(adj, 0, 2);
//     addEdge(adj, 2, 4);
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 3);

//     Solution obj;
//     vector <int> ans = obj.dfsOfGraph(5, adj);
//     printAns(ans);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Depth First Traversal of given graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); 
        stack<int> s;
        vector<int> dfs; 
        s.push(0); 
        while (!s.empty()) {
            int node = s.top(); 
            s.pop(); 
            if (!vis[node]) {
                vis[node] = 1; 
                dfs.push_back(node); 
                // Traverse all its neighbours
                for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                    if (!vis[*it]) {
                        s.push(*it); 
                    }
                }
            }
        }
        return dfs; 
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vector<int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
