#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 4e18;

void solve(int n) {
    vector<pair<ll, ll>> a(n);
    vector dp(n, vector<ll>(n, inf));
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        dp[i][i] = 0;
    }
    vector backtrack(n, vector<ll>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (dp[i][k] + dp[k + 1][j] + a[i].first * a[k].second * a[j].second < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + a[i].first * a[k].second * a[j].second;
                    backtrack[i][j] = k;
                }
            }
        }
    }
    auto dfs = [&](auto self, int l, int r) -> void {
        if (l == r) {
            cout << "M" << l + 1;
            return;
        }
        cout << "(";
        self(self, l, backtrack[l][r]);
        self(self, backtrack[l][r] + 1, r);
        cout << ")";
    };

    dfs(dfs, 0, n - 1);
    cout << "\n" << dp[0][n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    while (cin >> t) {
        solve(t);
    }
}