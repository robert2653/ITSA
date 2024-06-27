#include <bits/stdc++.h>
using namespace std;

void solve(int n, int caseNum) {
    int s; 
    cin >> s;
    int u, v;
    vector<vector<int>> g(n + 1);
    while (cin >> u >> v) {
        if (u == 0 && v == 0) break;
        g[u].push_back(v);
    }
    
    vector<int> dis(n + 1, INT_MIN);
    dis[s] = 0;
    
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dis[v] < dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    
    int maxLength = 0;
    int endPoint = s;
    
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > maxLength) {
            maxLength = dis[i];
            endPoint = i;
        }
    }
    
    cout << "Case " << caseNum << ": The longest path from " << s << " has length " << maxLength << ", finishing at " << endPoint << ".\n\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int caseNum = 1;
    int n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n, caseNum++);
    }
    return 0;
}
