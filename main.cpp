#include "MetroGraph.h"
#include <iostream>

int main() {
    MetroGraph metro(50);
    metro.load_from_file("stations.txt");
    // Add this temporarily to debug
    std::cout << "DEBUG: Checking edges for node 0..." << std::endl;

    int s, e, c;
    std::cout << "Start/End IDs: "; std::cin >> s >> e;
    std::cout << "1. Fastest, 2. Fewest Stops: "; std::cin >> c;
    if (c == 1) metro.find_fastest_route(s, e);
    else metro.find_fewest_stops(s, e);
    return 0;
}