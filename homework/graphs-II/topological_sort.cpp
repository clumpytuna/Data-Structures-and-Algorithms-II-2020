// You are given unweighted oriented graph.
// You have to topologically sort its nodes.

// Complete the code implementing GetTopologicalSortedNodes() method
// that returns any topological sort of the graph as a sequence of vertex.
// If the graph cannot be topologically sorted, then output -1.

#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>
#include <time.h>
#include <string>
#include <algorithm>

class Graph {
 public:
  Graph(int number_of_nodes) : adjacency_list(number_of_nodes + 1) {}

  void AddEdge(int from, int to) {
    adjacency_list[from].push_back(to);
  };

  std::vector<int> GetAdjacencyNodes(int node_number) const {
    return adjacency_list[node_number];
  }

  std::vector<int> GetTopologicalSortedNodes() const {
    // Write your code here
    // Return empty vector if a graph cannot be sorted
    return {};
  }

 private:
  std::vector<std::vector<int>> adjacency_list;
};

// Code to test your solution
bool Check(const Graph& g, const std::vector<int>& sorted_nodes) {
  std::map<int, int> nodes_to_indices;
  for (int i = 0; i < sorted_nodes.size(); ++i) {
    nodes_to_indices[sorted_nodes[i]] = i;
  }

  for (auto node: sorted_nodes) {
    for (auto adj_node: g.GetAdjacencyNodes(node)) {
      if (nodes_to_indices[adj_node] < nodes_to_indices[node]) {
        std::cout << "Broke topological order!" << std::endl;
        exit(-1);
      }
    }
  }

  std::cout << "Checked successful" << std::endl;
  return true;
}

void TestSolution() {
  std::cout << "Run test #1: ";
  {
    Graph g(10);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(1, 3);
    g.AddEdge(3, 4);
    g.AddEdge(2, 4);

    g.AddEdge(5, 6);
    g.AddEdge(5, 7);
    g.AddEdge(5, 8);
    g.AddEdge(6, 7);
    g.AddEdge(6, 8);
    g.AddEdge(8, 9);

    Check(g, g.GetTopologicalSortedNodes());
  }

  std::cout << "Run test #2: ";
  {
    Graph g(10);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(1, 3);
    g.AddEdge(3, 4);
    g.AddEdge(2, 4);
    g.AddEdge(3, 5);
    g.AddEdge(3, 6);
    g.AddEdge(3, 7);
    g.AddEdge(3, 8);
    g.AddEdge(3, 10);

    Check(g, g.GetTopologicalSortedNodes());
  }

  std::cout << "Run test #3: ";
  {
    Graph g(6);
    g.AddEdge(1, 2);
    g.AddEdge(3, 2);
    g.AddEdge(4, 2);
    g.AddEdge(2, 5);
    g.AddEdge(6, 5);
    g.AddEdge(4, 6);

    Check(g, g.GetTopologicalSortedNodes());
  }
}

int main() {
  // Run test
  TestSolution();
  return 0;
}
