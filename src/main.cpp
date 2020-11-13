#include <iostream>
#include <string>
#include "AdjacencyList.h"
using std::cin;

int main() {
   int no_lines, power_iterations;
   string from, to;
   AdjacencyList *graph = new AdjacencyList();
   cin >> no_lines;
   cin >> power_iterations;

   for (int i = 0; i < no_lines; i++) {
      cin >> from;
      cin >> to;
      graph->insert_edge(from, to);
   }
   graph->page_rank(power_iterations);

   delete graph;
   return 0;
}