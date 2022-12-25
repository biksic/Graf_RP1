#include <iostream> 
#include <vector> 
#include <utility> 
#include <map> 
#include <set> 
#include <stack> 
#include <queue> 
#include <list>

using namespace std; 

vector <pair<char, int> > susjedni (pair<char, int> n, map<pair<char, int>, set<pair<char, int> > > G);
list<pair<char, int> > dostupni (pair<char, int> n, map<pair<char, int>, set<pair<char, int> > > G);
stack<pair<char, int> > dostupniN (queue<pair<char, int> > Q, map<pair<char, int>, set<pair<char, int> > > G);
map<pair<char, int>, set<pair<char, int> > > pov (map<pair<char, int>, set<pair<char, int> > > G);
set<char> povezani (map<pair<char, int>, set<pair<char, int> > > G);