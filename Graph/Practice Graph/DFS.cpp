#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:
    vector <int> DFS(int V , vector <int> adj[6])
    {
        int vis[V] = {0};
        vis[0] ={1};
        stack <int> s;

    }
};

void addEdge(vector <int> adj[] , int u ,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector <int> adj[6];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);

    return 0;
}