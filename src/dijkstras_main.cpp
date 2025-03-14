#include "dijkstras.h"

int main(int argc, char * argv[]) {
    string filename = get_arg(argc, argv, "./largest.txt");
    Graph G;
    file_to_graph(filename, G);

    vector<int> v;
    vector<int> distance = dijkstra_shortest_path(G, 0, v);

    for (int i = 0; i < G.numVertices; i++) {
        if (i != 0) {
            vector<int> path = extract_shortest_path(distance, v, i);
            print_path(path, distance[i]);
        }
    }
    return 0;
}
