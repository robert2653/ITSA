#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    while (cin >> n) {
        cout << n << " " << n * n << " " << n * n * n << "\n";
    }
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