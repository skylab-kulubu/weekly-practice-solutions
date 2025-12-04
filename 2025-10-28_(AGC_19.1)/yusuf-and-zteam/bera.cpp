//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n,w;
    cin>>n>>w;
    vector<int>v(n,0);
    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    
    vector<bool> dp(w+1,0);
    dp[0]=true;
    
    for(int val : v)
    {
        for(int i=val; i<=w ; i++)
        {
            dp[i]= dp[i-val] || dp[i];
        }
    }
    
    while(!dp[w]) w--;
    
    cout<<w;
	return 0;
}
