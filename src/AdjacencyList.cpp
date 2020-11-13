#include <iostream>
#include <iomanip>
#include "AdjacencyList.h"
using std::setprecision;
using std::fixed;
using std::showpoint;
using std::cout;
using std::endl;

float AdjacencyList::out_degree(string node) {
   if (key.find(node) == key.end()) return -1; // node does not exist
   if (graph.find(key[node]) == graph.end()) return 0; // node has no out links
   return graph[key[node]].size();
}

void AdjacencyList::normalize(vector<float>& matrix) {
   float total = 0;
   for (int i = 0; i < matrix.size(); i++) {
      total += matrix[i];
   }
   for (int i = 0; i < matrix.size(); i++) {
      matrix[i] /= total; // adjust matrix values to be relative to a total of 1
   }
}

AdjacencyList::AdjacencyList() {
   incrementer = 0;
}

void AdjacencyList::insert_edge(string from, string to) {
   // Add new vertices to key
   if (key.find(from) == key.end()) {
      key[from] = incrementer;
      incrementer++;
   }
   if (key.find(to) == key.end()) {
      key[to] = incrementer;
      incrementer++;
   }

   // Add edge to graph
   graph[key[from]].push_back(key[to]);
}

void AdjacencyList::page_rank(int p) {
   vector<float> r1(key.size(), (1 / (float)key.size())); // O(V)
   for (int x = 0; x < p - 1; x++) { // O(p)
      vector<float> r2(key.size(), 0); // O(V)
      // Matrix multiplication using adjacency list
      for (map<string, int>::iterator i = key.begin(); i != key.end(); i++) { // O(V)
         for (int j = 0; j < graph[i->second].size(); j++) { // O(E)
            r2[graph[i->second][j]] += (1 / out_degree(i->first)) * r1[i->second]; // O(log(v) + k)
         }
      }
      r1 = r2; // O(V)
   }
   normalize(r1); // O(V)

   // Print ranks
   for (map<string, int>::iterator iter = key.begin(); iter != key.end(); ++iter) { // O(V)
      cout << iter->first << " ";
      cout << fixed << showpoint;
      cout << setprecision(2);
      cout << r1[iter->second] << endl;
   }
}