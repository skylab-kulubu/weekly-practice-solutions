#include <bits/stdc++.h>

using namespace std;
const int N=100001;
 bool visited[N+1];
 vector<int> adj[N+1];
void dfs(int a)
{
    visited[a]=1;
    for(int i : adj[a]){
        if(!visited[i]) dfs(i);
    }
}
int main() {
// write your code here
    int n,m;
    cin>>n>>m;
   
    int numberofCities=0;
    
    while(m--)
    {
        int x; int y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int i=1;
    while(i<=n)
    {
        if(!visited[i]){
        numberofCities++;
        dfs(i);
        }
        i++;
    }
    cout<<numberofCities;
    

	return 0;
}
