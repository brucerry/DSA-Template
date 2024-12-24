#include <bits/stdc++.h>
using namespace std;

/*
 * Undirected tree
 *
 * Number of nodes n = size of edges + 1
 * Nodes are numbered from 0 to n - 1
 * edges[i] = [a, b] where node 'a' and node 'b' are connected with an edge
 */
int diameter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> al (n);
    vector<int> cnt (n);
    for (auto& e : edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
        ++cnt[e[0]];
        ++cnt[e[1]];
    }
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1)
            que.push(i);
    }
    vector<int> depth (n), seen (n);
    int res = 0;
    while (que.size()) {
        int cur = que.front();
        que.pop();
        seen[cur] = 1;
        for (int next : al[cur]) {
            if (--cnt[next] == 1)
                que.push(next);
            if (!seen[next]) {
                res = max(res, depth[cur] + depth[next] + 1);
                depth[next] = max(depth[next], depth[cur] + 1);
            }
        }
    }
    return res;
}
