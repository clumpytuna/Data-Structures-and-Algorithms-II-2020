//
// You are given a weighted undirected graph. The vertices are enumerated from 1 to n.
// Your task is to find the shortest path between the vertex 1 and the vertex n.
//
// Input:
// The first line contains two integers n and m (2 ≤ n ≤ $10^5$, 0 ≤ m ≤ $10^5$),
// where n is the number of vertices and m is the number of edges.
// Following m lines contain one edge each in form $a_i$,
// $b_i$ and $w_i$ (1 ≤ $a_i$, $b_i$ ≤ n, 1 ≤ $w_i$ ≤ $10^6$),
// where $a_i$, $b_i$ are edge endpoints and $w_i$ is the length of the edge.
//
// It is possible that the graph has loops and multiple edges between pair of vertices.
//
// Output:
// Write the only integer -1 in case of no path.
// Write the shortest path length in opposite case.
//

#include <stdio.h>
#include <iostream>

// Class to store information about distances in Dijkstra Algorithm.
// Every node can be represented as its number (key)
// and a distance (value).
// Extract min operation must take O(1) time.
class Heap {
 public:
  // Constructor to build a heap from array
  Heap(const std::vector<std::pair<int, int>>& array) {}

  // Insert an element in heap
  void Insert(int key, int value) {}

  // Get the minimum element and delete from a heap
  std::pair<int, int> ExtractMin() {}

  // Decrease a key by a new value. If there is no a key,
  // return false, otherwise return true
  bool DecreaseKey(int key, int new_value) {}
};


class Graph {
 public:
  Graph(int number_of_nodes) : adjacency_list(number_of_nodes + 1) {}

  void AddEdge(int source, int destination, int weight) {}

  int GetDistanceDijkstra(int source, int target) const {}

 private:
  std::vector<std::vector<std::pair<int, int>>> adjacency_list;
};


int main() {
  int number_of_nodes;
  int number_of_edges;
  std::cin >> number_of_nodes >> number_of_edges;

  Graph g(number_of_nodes);

  for (int i = 0; i < number_of_edges; ++i) {
    int from;
    int to;
    int weight;
    std::cin >> from >> to >> weight;
    g.AddEdge(from, to, weight);
  }

  std::cout << g.GetDistanceDijkstra(1, number_of_nodes);

  return 0;
}
