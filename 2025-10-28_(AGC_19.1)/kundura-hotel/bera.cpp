//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int> capacity(n,0);
    for(int i=0; i<n; ++i)
    {
        cin>> capacity[i];
        capacity[i]-= i+1;
    }
    
    for(int i=0; i<n; ++i)
    {
        int x; cin>>x;
        capacity[i]-=x;
    }
    sort(capacity.begin(), capacity.end());
    int q; cin>>q;
    
    while (q--)
    {
        int k; cin>>k;
        int cnt= capacity.end()- lower_bound(capacity.begin(), capacity.end(),k);
      
        cout<< cnt<< endl;
    }
    
	return 0;
}
