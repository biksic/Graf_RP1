#include <iostream>
#include "graf.h"
#include <vector> 
#include <utility> 
#include <map> 
#include <set> 
#include <stack> 
#include <queue> 
#include <list>

using namespace std; 

vector <pair<char, int> > susjedni ( pair<char, int> n, map<pair<char, int>, set<pair<char, int> > > G)
{
    vector<pair<char, int> > V; 
    map<pair<char, int>, set<pair<char, int> > >::iterator mi, mi1; 
    set<pair<char, int> > S=G[n]; 
    set<pair<char, int> >::iterator si, si1; 

    for(si=S.begin(); si!=S.end(); si++)  
    {
        pair<char, int> par;  
        par.first=si->first;
        par.second=si->second; 
        V.push_back(par); 

    }

    for(mi1=G.begin(); mi1!=G.end(); mi1++)
    {
        pair<char,int> vazan=mi1->first;
        set<pair<char, int> > S1=G[vazan];
        for(si1=S1.begin(); si1!=S1.end(); si1++)
        {
            int pom=0;
            pair<char,int> par2;
            par2.first=si1->first; 
            par2.second=si1->second; 
            if(n==par2)
            {
                for(int i=0; i<V.size();i++)
                {
                    if(vazan==V[i])
                    {
                        pom++; 
                    }
                }
                if(pom==0)
                {
                    V.push_back(vazan); 
                }
            }


        }
        
    }

    return V; 
}

     
list<pair<char, int> > dostupni (pair<char, int> n, map<pair<char, int>, set<pair<char, int> > > G)
{
    list<pair<char, int>> L;
    list<pair<char, int>>::iterator li, litemp; 
    vector<pair<char, int> > V = susjedni(n, G); 
    li=L.begin(); 
    for(int i=0; i<V.size(); i++)
    {
        L.push_back(V[i]); 
    }


    for(li=L.begin(); li!=L.end(); li++)
    {
        pair<char, int> par; 
        par.first=li->first; 
        par.second=li->second; 
        V=susjedni(par, G); 
        for(int i=0; i<V.size(); i++)
        {
            int pom=0; 
            
            for(litemp=L.begin(); litemp!=L.end(); litemp++)  
            {
                pair<char, int> par1;
                par1.first=litemp->first; 
                par1.second=litemp->second;  
                if(par1==V[i]) pom++; 
            }
            if(pom==0)
            {
                L.push_back(V[i]);
            } 

        }
    
    }

    return L; 
}

stack<pair<char, int> > dostupniN (queue<pair<char, int> > Q, map<pair<char, int>, set<pair<char, int> > > G)
{
    stack<pair<char, int>> S, S1; 

    while(!Q.empty())
    { 
        pair<char, int> par=Q.front();
        Q.pop(); 
        list<pair<char, int>> L;
        list<pair<char, int>>::iterator li; 
        L=dostupni(par, G); 
       
        for(li=L.begin(); li!=L.end(); li++)
        {
            int pom=0; 
            pair<char, int> par1, par2;
            par1.first=li->first; 
            par1.second=li->second; 

            while(!S.empty())
            {
                par2=S.top(); 
                S.pop(); 
                S1.push(par2); 
                if(par1==par2) pom++; 
            }
            if(pom==0)  
            {
                S.push(par1); 
            }
            while(!S1.empty())
            {
                par2=S1.top(); 
                S1.pop(); 
                S.push(par2); 
            }
        }  
        
    }
    return S; 
}

map<pair<char, int>, set<pair<char, int> > > pov (map<pair<char, int>, set<pair<char, int> > > G)
{
    map<pair<char, int>, set<pair<char, int> > > K;
    map<pair<char, int>, set<pair<char, int>>>::iterator mi; 


    for(mi=G.begin(); mi!=G.end(); mi++)  
    {
        pair<char, int> par;
        par=mi->first;
        K[par]=mi->second; 

    }
    for(mi=G.begin(); mi!=G.end(); mi++)
    {
        set<pair<char, int>> S;
        S=mi->second; 
        pair<char, int> par=mi->first; 
        set<pair<char, int>>::iterator si; 
        for(si=S.begin(); si!=S.end(); si++)
        {
            pair<char, int> par1; 
            par1.first=si->first; 
            par1.second=si->second; 
            K[par1].insert(par); 
        }
    }

    return K; 
}


set<char> povezani (map<pair<char, int>, set<pair<char, int> > > G)
{
    map<pair<char, int>, set<pair<char, int>>> K=pov(G); 
    map<pair<char, int>, set<pair<char, int>>>::iterator mi; 
    set<char> S; 
    map<char, int> M;

    for(mi=K.begin(); mi!=K.end(); mi++)  
    {
        pair<char, int> par;
        par=mi->first;
        M[par.first]+=1; 
        

    }
    
    for(mi=K.begin(); mi!=K.end(); mi++)
    {
        pair<char, int> par, par1; 
        int n, pom=0;  
        par=mi->first; 
        list<pair<char, int>> L;
        list<pair<char, int>>::iterator li; 
        L=dostupni(par, G);
        n=M[par.first];


        for(li=L.begin(); li!=L.end(); li++)
        {
            pair<char, int> par1; 
            par1.first=li->first; 
            par1.second=li->second; 
            if(par.first==par1.first)
            {
                pom++; 
            }
            
        }
        if(pom==n)
        {
            S.insert(par.first);
        }

    }
    return S; 
}


