//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    string S; cin>>S;
    
    int i=0; n--;
    bool x=true;
    
    while(i<=n && x)
    {
        if(S[i] != S[n])
        {
            if(S[i] == '#')
            {
                S[i]= S[n];
            }
            else if( S[n] == '#')
            {
                S[n]= S[i];
            }
            else x=false;
        }
        else if(S[i] == '#') x=false;
        i++;
        n--;
    }
    
    if(x) cout << S;
    else cout << -1;

	return 0;
}
