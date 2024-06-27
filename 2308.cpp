#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 幹，題本可以再爛一點 multiple case 也不講

void solve(int k) {
    char c; cin >> c;
    int type; cin >> type;
    if (type == 1) type = 17;
    else type = 25;
    cin >> c;
    int n; cin >> n;

    k -= type * n;
    map<int, int> ans;
    if (k / 50) ans[50] = k / 50; k %= 50;
    if (k / 10) ans[10] = k / 10; k %= 10;
    if (k / 5) ans[5] = k / 5; k %= 5;
    if (k) ans[1] = k;
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << "Coin " << it->first << ":" << it->second;
        if (it != (--ans.end())) cout << ",";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int k = 1;
    while (cin >> k) {
        solve(k);
    }
}