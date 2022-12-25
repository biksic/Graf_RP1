#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

#include "graf.h"

using namespace std;


int main() {
	map<pair<char, int>, set<pair<char, int> > > G;

    list<pair<char, int> > L= dostupni(make_pair('a', 1), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=L.begin(); li!=L.end(); ++li)
        cout << li->first << li->second << " "; 
    cout << endl;
    //nista se ne ispise


	G[make_pair('b', 2)].insert(make_pair('a', 1));
    list<pair<char, int> > K= dostupni(make_pair('a', 1), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=K.begin(); li!=K.end(); ++li)
        cout << li->first << li->second << " ";
    cout << endl;
    //a1, b2


	G[make_pair('a', 1)].insert(make_pair('c', 3));
	G[make_pair('d', 4)].insert(make_pair('c', 3));

    list<pair<char, int> > Z= dostupni(make_pair('a', 1), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=Z.begin(); li!=Z.end(); ++li)
        cout << li->first << li->second << " ";
     cout << endl;
    // a1 b2 c3 d4


    list<pair<char, int> > P= dostupni(make_pair('e', 5), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=P.begin(); li!=P.end(); ++li)
        cout << li->first << li->second << " ";
     cout << endl;
    // prazno


    list<pair<char, int> > O= dostupni(make_pair('d', 4), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=O.begin(); li!=O.end(); ++li)
        cout << li->first << li->second << " ";
     cout << endl;
    // a1 b2 c3 d4


	G[make_pair('f', 6)].insert(make_pair('e', 5));
	list<pair<char, int> > W= dostupni(make_pair('e', 5), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=W.begin(); li!=W.end(); ++li)
        cout << li->first << li->second << " ";
     cout << endl;
    // e5 f6


    list<pair<char, int> > X= dostupni(make_pair('d', 4), G);
    //ispisi listu: 
    for(list<pair<char, int>>::iterator li=X.begin(); li!=X.end(); ++li)
        cout << li->first << li->second << " ";
     cout << endl;
    // a1 b2 c3 d4


	return 0;
}