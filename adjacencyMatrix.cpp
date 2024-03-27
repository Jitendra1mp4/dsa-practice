#include <iostream>
using namespace std;

class Graph {
  bool** adjMatrix;
  int numberOfVertices;

 public:
  Graph(const int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;

    adjMatrix = new bool*[numberOfVertices];
    for (size_t i = 0; i < numberOfVertices; i++) {
      adjMatrix[i] = new bool[numberOfVertices];
      for (size_t j = 0; j < numberOfVertices; j++) {
        adjMatrix[i][j] = false;
      }
    }
  }

  void addEdge(int i, int j) {
    if (i >= numberOfVertices or j >= numberOfVertices) {
      printf("invalid value of node\n");
      return;
    }

    adjMatrix[i][j] = adjMatrix[j][i] = true;
  }

  void removeEdge(int i, int j) {
    if (i >= numberOfVertices or j >= numberOfVertices) {
      printf("invalid value of node\n");
      return;
    }

    adjMatrix[i][j] = adjMatrix[j][i] = false;
  }

  void printGraph() {
    char colVert;
    char rowVert = colVert = 'A';
    printf(" ");
    for (size_t i = 0; i <= numberOfVertices; i++) {
      if (i != 0) printf("%c", rowVert++);

      for (size_t j = 0; j < numberOfVertices; j++) {
        if (i == 0)
          printf(" %c", colVert++);
        else
          printf(" %d", adjMatrix[i - 1][j]);
      }
      printf("\n");
    }
  }

  ~Graph() {
    for (size_t i = 0; i < numberOfVertices; i++) delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main(int argc, char const* argv[]) {
  Graph g(9);
  //   g.printGraph();
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(0, 7);

  g.addEdge(1, 8);
  g.addEdge(1, 3);
  g.addEdge(1, 4);

  g.addEdge(2, 3);
  g.addEdge(2, 6);
  g.addEdge(2, 0);

  g.addEdge(3, 0);
  g.addEdge(3, 1);
  g.addEdge(3, 2);
  g.addEdge(3, 5);

  g.addEdge(4, 1);
  g.addEdge(4, 8);
  g.addEdge(4, 5);

  g.addEdge(5, 3);
  g.addEdge(5, 6);
  g.addEdge(5, 4);

  g.addEdge(6, 2);
  g.addEdge(6, 5);

  g.addEdge(7, 0);
  g.addEdge(7, 8);

  g.addEdge(8, 1);
  g.addEdge(8, 4);
  g.addEdge(8, 7);

  printf("after adding\n");
  g.printGraph();

  g.removeEdge(8, 7);
  printf("after removing H, I Edge\n");
  g.printGraph();

  return 0;
}
