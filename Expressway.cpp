#include "../include/Expressway.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool Expressway::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string u, v;
    int d, t, c;
    while (file >> u >> v >> d >> t >> c) {
        addRoad(u, v, d, t, c);
    }
    file.close();
    return true;
}

void Expressway::addRoad(string u, string v, int d, int t, int c) {
    auto itU = find(city.begin(), city.end(), u);
    int uIdx = (itU == city.end()) ? (city.push_back(u), city.size() - 1) : distance(city.begin(), itU);

    auto itV = find(city.begin(), city.end(), v);
    int vIdx = (itV == city.end()) ? (city.push_back(v), city.size() - 1) : distance(city.begin(), itV);

    if (max(uIdx, vIdx) >= adj.size()) adj.resize(max(uIdx, vIdx) + 1);
    
    adj[uIdx].push_back({vIdx, d, t, c});
    adj[vIdx].push_back({uIdx, d, t, c});
}

// Dijkstra's Algorithm implementation
tuple<int,int,int,int,vector<string>> Expressway::shortestPath(string start, string end, char criteria) {
    int s = -1, e = -1;
    for(int i=0; i<city.size(); ++i) {
        if(city[i] == start) s = i;
        if(city[i] == end) e = i;
    }
    if(s == -1 || e == -1) return { -1, 0, 0, 0, {} };

    int n = city.size();
    vector<int> dist(n, 1e9), time(n, 1e9), toll(n, 1e9), parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0; time[s] = 0; toll[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(u == e) break;

        for(auto& edge : adj[u]) {
            int weight = (criteria == 'd') ? edge.dist : (criteria == 't' ? edge.time : edge.toll);
            if(dist[u] + weight < dist[edge.v]) {
                dist[edge.v] = dist[u] + weight;
                parent[edge.v] = u;
                // Track other metrics too
                time[edge.v] = time[u] + edge.time;
                toll[edge.v] = toll[u] + edge.toll;
                pq.push({dist[edge.v], edge.v});
            }
        }
    }

    vector<string> path;
    for(int v = e; v != -1; v = parent[v]) path.push_back(city[v]);
    reverse(path.begin(), path.end());

    return { dist[e], time[e], toll[e], 0, path };
}

// Kruskal's Algorithm for MST
pair<int, vector<tuple<string,string,int>>> Expressway::getMST() {
    vector<Road> roads;
    for (int i = 0; i < adj.size(); ++i) {
        for (auto& edge : adj[i]) {
            if (i < edge.v) roads.push_back({i, edge.v, edge.dist});
        }
    }
    sort(roads.begin(), roads.end());

    DSU dsu(adj.size());
    int totalWeight = 0;
    vector<tuple<string,string,int>> mstEdges;

    for (auto& r : roads) {
        if (dsu.unite(r.u, r.v)) {
            totalWeight += r.w;
            mstEdges.push_back({city[r.u], city[r.v], r.w});
        }
    }

    cout << "\n--- MST (Optimized Road Network) ---\n";
    for (auto& edge : mstEdges) {
        cout << get<0>(edge) << " -- " << get<1>(edge) << " (" << get<2>(edge) << "km)\n";
    }
    cout << "Total Connectivity Cost: " << totalWeight << "km\n";
    
    return {totalWeight, mstEdges};
}

bool Expressway::hasFuelArbitrage(vector<double>& rates) {
    // Basic Bellman-Ford style check for negative cycles (Arbitrage)
    return false; // Placeholder for advanced logic
}