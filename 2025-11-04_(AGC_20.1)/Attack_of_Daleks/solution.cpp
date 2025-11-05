#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int main() {
    // These are for taking inputs efficiently.
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // XOR operator results 0 for same bit values:
    // 1010
    // 1001
    // ---- XOR
    // 0011
    //
    // So, a XOR b XOR c XOR d = 0 can be written as a XOR b = c XOR d

    int n;
    cin >> n;

    // Stores results of every a ^ b, a and b are random elements of given array.
    vector<int> values(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // (each element in input) <= 10^5
    // 2^16 <= 10^5 <= 2^17
    // 2^17 guarantees possible different creatable XOR combinations.

    // C(n, 2) is our creatable XOR combination according to N:
    // you need to selects 2 elements in array from N-sized array for making XOR operation.

    // 2^17 <= C(513, 2)
    // in other words, if (possible different creatable XOR combinations) <= (total creatable XOR combinations) is valid,
    // the N-sized array includes two same a XOR b results for different a and b values.
    if (n >= 513) {
        puts("Yes");
        return 0;
    }

    unordered_map<int, vector<pair<int, int>>> A;

    for (int i = 0; i < n; ++i) {
        for (int j = (i + 1); j < n; ++j) {
            A[values[i] ^ values[j]].push_back({i, j});
        }
    }

    for (auto& data : A) {
        int _xor = data.first;
        vector<pair<int, int>>& pairs = data.second;

        // Taking as reference prevents copying pair, it helps decreasing execution time.
        auto& cmp = pairs[0];

        for (int i = 1; i < pairs.size(); ++i) {
            // Taking as reference prevents copying pair, it helps decreasing execution time.
            auto& pair = pairs[i];

            if (pair.first != cmp.first && pair.first != cmp.second && pair.second != cmp.first && pair.second != cmp.second) {
                puts("Yes");
                return 0;
            }
        }
    }

    puts("No");
    return 0;
}
