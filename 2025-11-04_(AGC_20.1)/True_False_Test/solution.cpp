#include <bits/stdc++.h>

using namespace std;

const uint64_t MOD = (1e9 + 7);

// Equalivent to pow(base, exp), only more performant and doing job with %MOD
uint64_t power(uint64_t base, int exp) {
    uint64_t res = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    // t: count of lines ends with T and *do not* include TTTTT and FFFFF
    // f: count of lines ends with F and *do not* include TTTTT and FFFFF
    // index represents length of line, for example t[3] includes TTT TFT FFT...
    vector<uint64_t> t(n + 1, 0), f(n + 1, 0);

    for (int i = 1; i <= 4; ++i) {
        t[i] = 1ULL << (i - 1); // 2^(i - 1)
        f[i] = 1ULL << (i - 1); // 2^(i - 1)
    }

    for (int i = 5; i <= n; ++i) {
        /*
         * Equalivent form of this block without %MOD
         * t[i] = f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4];
         * f[i] = t[i - 1] + t[i - 2] + t[i - 3] + t[i - 4];
         */
        uint64_t sum_f = (f[i - 1] + f[i - 2]) % MOD;
        sum_f = (sum_f + f[i - 3]) % MOD;
        sum_f = (sum_f + f[i - 4]) % MOD;
        t[i] = sum_f;

        uint64_t sum_t = (t[i - 1] + t[i - 2]) % MOD;
        sum_t = (sum_t + t[i - 3]) % MOD;
        sum_t = (sum_t + t[i - 4]) % MOD;
        f[i] = sum_t;
    }

    // total count of n-sized lines *do not* include TTTTT and FFFFF
    uint64_t g_n_mod = (t[n] + f[n]) % MOD;

    // total creatable line count as n-sized
    uint64_t total = power(2, n);

    // total - (total count of lines *do not* include TTTTT and FFFFF) = total count of lines include TTTTT or FFFFF
    // Modular Subtraction: (A - B) % M = (A - B + M) % M
    uint64_t result = (total - g_n_mod + MOD) % MOD;

    cout << result << endl;
    return 0;
}
