#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct project {
    int from, end, gain, id;
};

void solve() {
    int n; cin >> n;
    vector<string> proj_name(n);
    vector<project> projects(n + 1);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        proj_name[i] = s;
        int f, e, g; cin >> f >> e >> g;
        projects[i + 1] = {f, e, g, i};
    }
    sort(projects.begin(), projects.end(), [](project a, project b) {
        if (a.end == b.end) return a.gain < b.gain;
        return a.end < b.end;
    });
    vector<int> dp(n + 1); // gain
    vector<int> par(n + 1, 0), ans, add(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int id = --upper_bound(projects.begin(), projects.begin() + i, project({0, projects[i].from, 0, 0}), [](project a, project b) {
            return a.end < b.end;
        }) - projects.begin();   // 二分搜最接近 from 的 end
        dp[i] = dp[i - 1];
        par[i] = i - 1;
        if (dp[i] < dp[id] + projects[i].gain) {
            dp[i] = dp[id] + projects[i].gain;
            par[i] = id;
            add[i] = projects[i].id;
        }
    }
    for (int now = n; now > 0; now = par[now]) {
        if (add[now] != -1) {
            ans.push_back(add[now]);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto &i : ans) {
        cout << proj_name[i] << " ";
    }
    cout << dp[n] << "\n";
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