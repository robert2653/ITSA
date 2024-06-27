#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<string> ordered(n);
    map<string, ll> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ordered[i] = s;
        mp[s];
    }
    string out;
    while (cin >> out) {
        if (out == "0") break;
        ll sum; cin >> sum;
        int num; cin >> num;
        mp[out] -= sum;

        for (int i = 0; i < num; i++) {
            string in; cin >> in;
            mp[in] += sum / num;
        }
    }

    for (string &i : ordered) {
        cout << i << " " << mp.lower_bound(i)->second << "\n";
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