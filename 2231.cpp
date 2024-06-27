#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    // dp[i][j] 考慮第 i 種時，總和 j 的方法
    int n; cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    vector<int> coin{50, 10, 5, 1};
    for (int i = 0; i < coin.size(); i++) {
        for (int j = 0; j <= n; j++) {
            if (j - coin[i] >= 0) {
                dp[j] += dp[j - coin[i]];
            }
        }
    }
    // 1 2 3 4 5 6 7 8 9 10
    // 1 0 0 0 1 0 0 0 0 1
    // 1 1 
    cout << dp[n] << "\n";
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