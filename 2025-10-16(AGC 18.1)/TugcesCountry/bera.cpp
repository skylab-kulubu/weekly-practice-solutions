#include <bits/stdc++.h>

using namespace std;

void DFS(int i,vector<vector<int>>&adj,vector<bool>&visited){
    visited[i] = true;

    for(auto j : adj[i]){
        if(!visited[j]){
            DFS(j,adj,visited);
        }
        
    }
    
}

int dfsOfGraph(vector<vector<int>>& adj){ 
    int count=0;
    vector<bool>visited(adj.size(),false);
    for (int i = 1; i < adj.size(); i++)
    {
        if(!visited[i]){ 
            count++;               
            DFS(i,adj,visited);
        }
        
    }
    return count;   
}
int main() {
int M,N;
cin >> N >> M;
vector<vector<int>>adj(N+1);
for (int i = 0; i < M; i++)
{
   int u ,v;
   cin >> u >> v;
   adj[u].push_back(v);
   adj[v].push_back(u);
}
int ans = dfsOfGraph(adj);
cout << ans;
	return 0;
}