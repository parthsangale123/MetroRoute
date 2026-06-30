#ifndef METRO_GRAPH_H
#define METRO_GRAPH_H

#include <vector>
#include <string>
#include <queue>

struct Edge { int to, time; };

class MetroGraph {
public:
    MetroGraph(int n);
    void add_station(int id, std::string name);
    void add_edge(int u, int v, int time);
    void load_from_file(std::string filename);
    void find_fastest_route(int start, int end);
    void find_fewest_stops(int start, int end);

private:
    int stations;
    std::vector<std::vector<Edge>> adj;
    std::vector<std::string> station_names;
    void print_path(const std::vector<int>& parent, int end, int cost, std::string type);
};
#endif