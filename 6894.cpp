#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll s; cin >> s;
    ll m = 60;
    ll h = m * 60;
    ll d = h * 24;
    cout << s / d << " days\n";
    s %= d;
    cout << s / h << " hours\n";
    s %= h;
    cout << s / m << " minutes\n";
    s %= m;
    cout << s << " seconds\n";
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