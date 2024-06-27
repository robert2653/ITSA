#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Catalan Number
vector<ll> fac;
void buildFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
}
ll C(int m, int n) {
    return m < n ? 0 : fac[m] / fac[n] / fac[m - n];
}
void solve() {
    int x; cin >> x;
    char c; cin >> c;
    int y; cin >> y;

    // if (x < y) {
    //     cout << 0 << "\n";
    //     return;
    // }
    // buildFac(x + y);
    // int a = x + 1, b = y - 1;
    // cout << C(x + y, x) - C(a + b, a) << "\n";

    vector dp(x + 1, vector<ll>(y + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i < j) continue;
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[x][y] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}