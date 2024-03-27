#include <iostream>
#include <set>
using namespace std;

class Graph {
 private:
  int numberOfNodes;
  set<int> *nodes;

 public:
  Graph(int numberOfNodes);
  void addEdge(int i, int j);
  void removeEdge(int i, int j);
  void printGraph();
  ~Graph();
};

Graph::Graph(const int numberOfNodes) {
  this->numberOfNodes = numberOfNodes;
  nodes = new set<int>[numberOfNodes];
}

void Graph::addEdge(int i, int j) {
  nodes[i].insert(j);
  nodes[j].insert(i);
}

void Graph ::removeEdge(int i, int j) {
  nodes[i].erase(j);
  nodes[j].erase(i);
}

void Graph ::printGraph() {
  for (size_t i = 0; i < numberOfNodes; i++) {
    for (auto &item : nodes[i]) {
      cout << item << " ";
    }
    cout << endl;
  }
}

Graph::~Graph() { delete[] nodes; }

int main(int argc, char const *argv[]) {
  Graph ng(3);
  ng.addEdge(0, 2);
  ng.addEdge(1, 0);
  ng.removeEdge(2, 0);
  ng.addEdge(1, 2);
  ng.printGraph();
  return 0;
}
