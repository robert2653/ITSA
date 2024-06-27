#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, d; cin >> x >> d;
    vector<array<ll, 5>> dp(d + 1);
    dp[1][0] = x;
    for (int i = 2; i <= d; i++) {
        dp[i][0] = dp[i - 1][2] + dp[i - 1][3];
        for (int j = 1; j < 5; j++) {
            dp[i][j] = dp[i - 1][j - 1];
        }
    }
    cout << accumulate(dp[d].begin(), dp[d].end(), 0LL) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}