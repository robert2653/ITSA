#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    cout << "NT10=" << n / 10 << "\n";
    n %= 10;
    cout << "NT5=" << n / 5 << "\n";
    n %= 5;
    cout << "NT1=" << n << "\n";
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