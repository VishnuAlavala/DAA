#include <stdio.h>
#include <stdlib.h>

void floydWarshall(int **graph, int n) {
  int i, j, k;

  // Initialize the shortest paths between any 2 vertices with Infinity.
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = 99999;
      }
    }
  }

  // Find the shortest paths that use 0, 1, 2, ... intermediate vertices.
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        // If the shortest path from i to j goes through k, then update the shortest path.
        if (graph[i][k] + graph[k][j] < graph[i][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}

int main() {
  int n, e, u, v, w, i, j;

  // Get the number of vertices and edges.
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of edges:\n");
  scanf("%d", &e);

  // Create the graph adjacency matrix.
  int **graph = (int **)malloc((long unsigned) n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc((long unsigned) n * sizeof(int));
  }

  // Initialize the edge weights.
  for (i = 0; i < e; i++) {
    printf("Enter the end vertices of edge%d with its weight \n", i + 1);
    scanf("%d%d%d", &u, &v, &w);
    graph[u][v] = w;
  }

  // Perform Floyd-Warshall algorithm.
  floydWarshall(graph, n);

  // Print the shortest paths between all the pairs of vertices.
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        printf("%d ", 0);
      } else {
        printf("%d ", graph[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
