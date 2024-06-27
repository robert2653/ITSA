#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    return (y == 0 ? x : gcd(y, x % y));
}

void solve() {
    ll n, x; cin >> n >> x;
    if (x > n * 6) {
        cout << 0 << "\n";
        return;
    }
    vector<ll> dp(n * 6 + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<ll> _new(n * 6 + 1);
        for (int j = 1; j <= n * 6; j++) {
            for (int k = 1; k <= 6; k++) {
                if (j - k >= 0) {
                    _new[j] += dp[j - k];
                }
            }
        }    
        dp = _new;
    }
    ll u = accumulate(dp.begin() + x, dp.end(), 0LL);
    ll d = 1;
    for (int i = 0; i < n; i++) {
        d *= 6;
    }
    ll g = gcd(u, d);
    u /= g;
    d /= g;
    cout << u << " / " << d << "\n";
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