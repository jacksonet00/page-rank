#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using std::map;
using std::unordered_map;
using std::string;
using std::vector;

class AdjacencyList {
   unordered_map<int, vector<int> > graph;
   map<string, int> key;
   int incrementer;

   float out_degree(string node);
   void normalize(vector<float>& matrix);
   
public:
   AdjacencyList();
   void insert_edge(string from, string to);
   void page_rank(int p);
};