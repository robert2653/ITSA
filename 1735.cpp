#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    set<int> st{0};
    for (int i = 0; i < n; i++) {
        vector<int> add;
        for (auto x : st) {
            if (x + a[i] <= 200000 && st.count(x + a[i]) == 0) {
                add.push_back(x + a[i]);
            }
        }
        for (auto x : add) {
            st.insert(x);
        }
    }
    int ans = 0;
    for (int x : b) {
        if (st.count(x)) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}