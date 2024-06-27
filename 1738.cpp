#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 4e18;

void solve(int n, int s, int t) {
    int sz = 1 << n;
    vector<int> w(sz);
    for (int i = 0; i < sz; i++) {
        cin >> w[i];
    }
    vector g(sz, vector<int>());
    vector<ll> dis(sz, inf);
    dis[s] = 0;
    for (int i = 0; i < sz; i++) {
        int b = 1;
        for (int j = 0; j < n; j++) {
            g[i].push_back(i ^ b);
            // g[i ^ b].push_back(i);
            b <<= 1;
        }
    }
    // dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = w[s];
    pq.push({dis[s], s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] < d) continue;
        for (auto v : g[u]) {
            if (dis[u] + w[v] < dis[v]) {
                dis[v] = dis[u] + w[v];
                pq.push({dis[v], v});
            }
        }
    }
    cout << dis[t] << "\n";

    // for (int i = 0; i < sz; i++) {
    //     cout << i << ", ";
    //     for (auto i : g[i]) {
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, t;
    while (true) {
        cin >> n >> s >> t;
        if (n + s + t == 0) break;
        solve(n, s, t);
    }
}