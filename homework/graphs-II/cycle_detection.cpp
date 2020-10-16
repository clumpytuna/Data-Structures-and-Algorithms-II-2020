// You are given a directed graph. (A graph can be disconnected).
// Vertices are numbered from 1. Print YES if graph contains a cycle,
// print NO otherwise.

// Input format:
// First line: n (number of vertices)
// Second line: m (number of edges)
// Next m lines: e f (edges line by line)

// Output format:
// Print "YES" if graph has a cycle, print "NO" otherwise.

// To test the problem submit it here:
// https://contest.yandex.ru/contest/21057/problems/A/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Graph {
 public:
  Graph(int number_of_nodes) : adjacency_list(number_of_nodes + 1) {}

  void AddEdge(int from, int to) {
    adjacency_list[from].push_back(to);
    ++edges_number_;
  };

  std::vector<int> GetAdjacencyNodes(int node_number) const {
    return adjacency_list[node_number];
  }

  bool HasCycle() {
    // Write your code here
    return false;
  }

  int Size() const {
    return adjacency_list.size();
  }

  int EdgesNumber() const {
    return edges_number_;
  }

 private:
  std::vector<std::vector<int>> adjacency_list;
  int edges_number_ = 0;

};

int main() {

  int number_of_nodes;
  int number_of_edges;

  std::cin >> number_of_nodes >> number_of_edges;

  Graph g(number_of_nodes);
  for (int i = 0; i < number_of_edges; ++i) {
    int from;
    int to;
    std::cin >> from >> to;
    g.AddEdge(from, to);
  }

  if (g.HasCycle()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}
