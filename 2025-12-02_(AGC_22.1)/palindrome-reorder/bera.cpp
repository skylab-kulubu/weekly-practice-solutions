//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
int n; cin>>n;
    string s;
    cin>>s;
    int arr[26]={};
    
    for(char ch : s)
    {
        arr[ch-'A'] ++;
    }
    
    int odd_cnt=0;
    char mid= '@';
    
    for(int i=0; i<26; ++i)
    {
        if(arr[i]%2==1)
        {
            if(odd_cnt==0) mid= 'A'+i;
            odd_cnt++;
        } 
        if(odd_cnt>1)break;
    }
    
    if(odd_cnt>1)
    {
       cout << "NO SOLUTION"; 
    }
    // 0 1 2 3 
    else
    {
        if(odd_cnt==1)
        {
            s[n/2]= mid;    // place the middle
            arr[mid-'A']--; 
        }
// 1 2 3 2 1    n=5 n/2=2    
        int i=0;
        for(int j=0; j<26; ++j)
        {
           while(arr[j]>0)
           {
               char ch= 'A'+ j;
               s[i]= ch;
               s[n-i-1]= ch;
               i++;
               arr[j]-=2;
               if(i == n/2) break;
           }
        }
        
        cout<< s;
    }
    
    
    

	return 0;
}
