// codeforces 237E
// https://codeforces.com/problemset/problem/237/E
#include <bits/stdc++.h>
using namespace std;

template<typename FlowType, typename CostType>
class MCMF {
    struct Edge {
        int to;
        FlowType capacity;
        CostType cost;
        int rev;
    };

    int V;
    vector<vector<Edge>> adj;
    vector<CostType> dist;
    vector<int> previous, edgeIndex;

public:
    MCMF(int V) : V(V), adj(V) {}

    void addEdge(int from, int to, FlowType cap, CostType cost) {
        adj[from].push_back({to, cap, cost, (int)adj[to].size()});
        adj[to].push_back({from, 0, -cost, (int)adj[from].size() - 1});
    }

    bool SPFA(int src, int sink) {
        dist.assign(V, numeric_limits<CostType>::max());
        previous.assign(V, -1);
        edgeIndex.assign(V, -1);
        vector<bool> inQueue(V, false);

        queue<int> Q;
        dist[src] = 0;
        Q.push(src);
        inQueue[src] = true;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inQueue[u] = false;

            for(int i = 0; i < adj[u].size(); ++i) {
                Edge &e = adj[u][i];
                if(e.capacity > 0 && dist[u] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[u] + e.cost;
                    previous[e.to] = u;
                    edgeIndex[e.to] = i;

                    if(!inQueue[e.to]) {
                        Q.push(e.to);
                        inQueue[e.to] = true;
                    }
                }
            }
        }
        return previous[sink] != -1;
    }
    pair<FlowType, CostType> getMCMF(int src, int sink) {
        FlowType maxFlow = 0;
        CostType minCost = 0;

        while (SPFA(src, sink)) {
            FlowType flow = numeric_limits<FlowType>::max();
            for(int v = sink; v != src; v = previous[v]) {
                int u = previous[v];
                flow = min(flow, adj[u][edgeIndex[v]].capacity);
            }
            for(int v = sink; v != src; v = previous[v]) {
                int u = previous[v];
                Edge &e = adj[u][edgeIndex[v]];
                e.capacity -= flow;
                adj[v][e.rev].capacity += flow;
                minCost += flow * e.cost;
            }

            maxFlow += flow;
        }
        return {maxFlow, minCost};
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    string str; cin >> str;
    int strsize = str.size();
    vector<int> cnt(27, 0);
    for(int i = 0; i < strsize; i++) cnt[str[i] - 'a' + 1]++;
    // flow network 구성, mcmf 계산. 
    int n; cin >> n;
    int s = 0, t = n + 27;
    MCMF<int, int> mcmf(n + 28);
    for(int i = 1; i <= 26; i++) mcmf.addEdge(n + i, t, cnt[i], 0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> str >> x;
        mcmf.addEdge(s, i, x, i);
        for(int j = 0; j < str.size(); j++) mcmf.addEdge(i, n + str[j] - 'a' + 1, 1, 0);
    }
    pair<int, int> res = mcmf.getMCMF(s, t);
    if(res.first != strsize) cout << -1;
    else cout << res.second;
    return 0;
}
