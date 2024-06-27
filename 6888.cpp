#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    double x;
    double s = 1 - 30 * 2.54 / 100;
    while (cin >> x) {
        cout << ceil(x / s) << "\n";
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