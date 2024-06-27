#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x; cin >> x;
    vector<int> a;
    while (cin >> x) {
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (auto i : a) {
        cout << i << "\n";
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