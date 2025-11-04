//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e7 + 2;

vector<bool> asal(N, 1);
vector<int> kuvvet(N, 0);


void sieve() {
    ll i, j;
    for (i = 2; i < N; i++) {
        if (asal[i]) {
            for (j = 2*i; j < N; j += i) {
                asal[j] = 0;
            }
            
            for (j = i; j < N; j *= i) {
                kuvvet[j] = i;
            }
        }
    }
}

int main() {
// write your code here
    int n, i;
    ll cevap = 0;
    cin>>n;
    
    sieve();
    
    for (i = 2; i < n + 2; i++) {
        if (asal[i]) {
            cevap += i;
        }
        else {
            if (kuvvet[i]) {
                cevap += kuvvet[i];
            }
            else {
                cevap++;
            }
        }
        
    }
    
    cout<<cevap;
	return 0;
}
