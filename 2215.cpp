#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<array<ll, 2>> dp(n + 1); // 公, 母
    dp[0][1] = 1;
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + 1;
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n][0] << " " << dp[n][1] + 1 << "\n";
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