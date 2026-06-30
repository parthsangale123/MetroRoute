# Metro Route Planner

A high-performance C++ CLI application designed to simulate a 50-station metro network. It calculates the fastest path (Dijkstra) and the fewest transfers (BFS) with sub-100ms latency.

## Key Features
- **Algorithm Benchmarking:** Compare weighted shortest-path vs. unweighted stop-count.
- **Scalable Architecture:** Decoupled graph logic from interface; dynamic file-based station loading.
- **Performance Optimized:** Uses `std::priority_queue` for $O(E \log V)$ pathfinding.

## Usage
1. Compile using CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   make