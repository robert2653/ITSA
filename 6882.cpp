#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    double n;
    while (cin >> n) {
        n = n * 9 / 5 + 32;
        cout << fixed << setprecision(1) << n << "\n";
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