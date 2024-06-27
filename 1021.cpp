#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector adj(n, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w; cin >> w;
            if (w) {
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
    }

    int ans = 0;
    
    int node_sz = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<bool> vis(n);
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ans += cost;
        node_sz++;
        for (auto [v, cost] : adj[u]) {
            if (!vis[v])
                pq.push({cost, v});
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