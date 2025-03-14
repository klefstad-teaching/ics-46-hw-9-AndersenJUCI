#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int vert = G.numVertices;
    vector<int> distance(vert, INF);
    vector<bool> visited(vert, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    previous.assign(vert, -1);
    pq.push({0, source});
    distance[source] = 0;

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (!visited[v]) {
            visited[v] = true;
        } else {
            continue;
        }

        for (const auto & neighbor : G[v]) {
            int u = neighbor.dst;
            int weight = neighbor.weight;
            if (!visited[u] && distance[v] + weight < distance[u]) {
                distance[u] = distance[v] + weight;
                previous[u] = v;
                pq.push({distance[u], u});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int i = destination; i != -1; i = previous[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}

string get_arg(int argc, char *argv[], string def) {
    if (argc > 1) {
        return argv[1];
    } else {
        return def;
    }
}