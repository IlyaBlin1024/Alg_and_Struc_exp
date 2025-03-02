#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int from, to, cost, owner;
};

bool operator<(const Edge& a, const Edge& b) {
    return a.cost > b.cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].owner >> edges[i].cost;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        adj[edges[i].from].push_back(i);
        adj[edges[i].to].push_back(i);
    }

    priority_queue<Edge> pq;

    vector<int> dist(n + 1, 1e9);
    vector<int> pred(n + 1, -1);
    edgeTo[1] = 0;
    dist[1] = 0;
    pq.push({1, 0, 0, 0});

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if (cur.cost != dist[cur.to]) continue;

        for (int i : adj[cur.to]) {
            Edge next = edges[i];
            int newCost = cur.cost + next.cost + r[next.to] - r[cur.to];
            if (next.owner == cur.owner && dist[next.to] > newCost) {
                pred[next.to] = i;
                dist[next.to] = newCost;
                pq.push({next.from, next.to, newCost, next.owner});
            }
        }
    }

    if (dist[n] == 1e9) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> sell;
    vector<int> buy;
    vector<int> path;

    int cur = n;
    while (cur != 0) {
        path.push_back(cur);
        if (pred[cur] != -1) {
            sell.push_back(pred[cur]);
        }
        cur = edges[pred[cur]].from;
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

    cout << sell.size() << " ";
    for (int i : sell) {
        cout << i + 1 << " ";
    }
    cout << endl;

    cout << buy.size() << " ";
    for (int i : buy) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}