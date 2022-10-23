#include <iostream>
#include "../common.h"

using namespace std;

// number of vertix in the graph
#define V 4

// solves all pairs shortest path 
// problem using floyd warshall algorithm
void floydWarshall(int graph[][V]) {
   
   /* dist[][] will be the output matrix
      that will finally have the shortest
      distances between every pair of vertices */
   int dist[V][V], i, j, k;

   /* Intitiate the solution same as the input
     graph matrix. or we can say the initial value
     of shortest distances are based on shortest 
     path considering no intermediate vertex */
   for (i = 0; i < V; i++)
      for (j = 0; j < V; j++) 
         dist[i][j] = graph[i][j];

   /* add all vertices one by one to
     the set of intermediate vertices.
     --> Before the start of an iteration,
     we have shortest distances  between all
     pairs of vertices such that the shortest 
     distances consider only the vertices in
     the set {0, 1, 2, 3, .... k -1} as the 
     intermediate vertices.
     --> After the end of an iteration vertex 
     number k is added to the set of intermediate
     vertices and the set becomes {0, 1, 2, 3, ... k} */
     for (k =0; k < V; k++) {
      // pick all the vertices as source one by one 
      for (i = 0; i < V; i++ ) {
        // pick all the vertices as destination for 
        // above picked source one by one
        for (j = 0 ; j < V; j++) {
          // the given k value is the shortest path from 
          // the current source and desitnation i & j then 
          // udpate dist[i][j] with new value
          if (dist[i][j] > (dist[i][k] + dist[k][j])
              && dist[i][k] != INF && dist[k][j] != INF ) {
             dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
     }

    // printing the shortest distance matrix
    cout << "Shortest distane matrix" << endl;
    print(dist, V, V);
}

int main() {
  /* Let us create the following weighted graph
          10
    (0)------->(3)
     |         /|\
    5|          |
     |          | 1
    \|/         |
    (1)------->(2)
          3           */
  int graph[V][V]  = {{ 0, 5, INF, 10},
                      { INF, 0, 3, INF},
                      { INF, INF, 0, 1},
                      { INF, INF, INF, 0}}; 

  // printing the input graph matix as follows
  cout << "input graph matrix" << endl;
  print(graph, V, V);
  floydWarshall(graph);
}