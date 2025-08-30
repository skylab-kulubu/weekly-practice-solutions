//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
// write your code here
    int n;
    if (!(std::cin >> n)) return 0;

    std::vector <long long> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    std::vector <long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    long long answer = 0;

    if (n % 2 == 0) {
        int k = n / 2;
        long long smaller  = prefixSum[k];    
        long long bigger = prefixSum[n] - prefixSum[k];
        answer = 2 * (bigger - smaller) - (a[k] - a[k-1]);
    }
    else {                           // N = 2k+1
        int k = n / 2;
        long long smaller = prefixSum[k];             // b1..bk
        long long bigger   = prefixSum[n] - prefixSum[k + 1]; // b{k+2}..bN
        long long penalty = std::min(a[k] - a[k - 1], a[k + 1] - a[k]);
        answer = 2 * (bigger - smaller) - penalty;
    }

    std::cout << answer << '\n';
    
	return 0;
}