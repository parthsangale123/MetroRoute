#include "MetroGraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <algorithm>

MetroGraph::MetroGraph(int n) : stations(n), adj(n), station_names(n) {}


void MetroGraph::add_station(int id, std::string name) { station_names[id] = name; }

void MetroGraph::add_edge(int u, int v, int time) {
    adj[u].push_back({v, time});
    adj[v].push_back({u, time});
}

void MetroGraph::load_from_file(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return;
    }

    std::string line;
    // 1. Read station count
    std::getline(file, line);
    int num = std::stoi(line);

    // 2. Read Stations
    for (int i = 0; i < num; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);
        std::string id, name;
        std::getline(ss, id, ',');
        std::getline(ss, name);
        add_station(std::stoi(id), name);
    }

    // 3. Read Edges - Use a robust while loop
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines
        std::stringstream ss(line);
        std::string u, v, w;
        if (std::getline(ss, u, ',') && std::getline(ss, v, ',') && std::getline(ss, w)) {
            add_edge(std::stoi(u), std::stoi(v), std::stoi(w));
        }
    }
    file.close();
    std::cout << "Successfully loaded stations and edges." << std::endl;
}
void MetroGraph::find_fastest_route(int start, int end) {
    std::vector<int> dist(stations, INT_MAX), parent(stations, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    dist[start] = 0; pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for (auto& e : adj[u]) {
            if (dist[u] + e.time < dist[e.to]) {
                dist[e.to] = dist[u] + e.time; parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    print_path(parent, end, dist[end], "Time");
}

void MetroGraph::find_fewest_stops(int start, int end) {
    std::vector<int> stops(stations, -1), parent(stations, -1);
    std::queue<int> q; q.push(start); stops[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& e : adj[u]) {
            if (stops[e.to] == -1) {
                stops[e.to] = stops[u] + 1; parent[e.to] = u; q.push(e.to);
            }
        }
    }
    print_path(parent, end, stops[end], "Stops");
}

void MetroGraph::print_path(const std::vector<int>& parent, int end, int cost, std::string type) {
    if (cost == INT_MAX || cost == -1) { std::cout << "No path." << std::endl; return; }
    std::vector<int> path;
    for (int v = end; v != -1; v = parent[v]) path.push_back(v);
    std::reverse(path.begin(), path.end());
    std::cout << "Path: ";
    for (int i : path) std::cout << station_names[i] << " ";
    std::cout << "\nCost: " << cost << " (" << type << ")" << std::endl;
}