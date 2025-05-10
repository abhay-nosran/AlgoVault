#include <bits/stdc++.h>
using namespace std ;

struct unionFind
{
    int numComponents;
    int _size;
    int * rank ;
    int * parent ;

    unionFind(int n){
        _size = n ;
        numComponents = n ;
        rank = new int[_size];
        parent = new int[_size];

        for (int i = 0; i < _size ; i++)
        {
            rank[i] = 1 ;
            parent[i] = i ;
        }
        
    }

    int find(int x){

        if(parent[x] == x) return x ;
        return parent[x] = find(parent[x]) ;

    }

    void insert(int x , int y ){
        x = find(x) ;
        y = find(y) ;

        if(x == y) return ;

        if(rank[x] > rank[y]){
            parent[y] = x ;
            rank[x] += rank[y] ;
        }else{
            parent[x] = y ;
            rank[y] += rank[x] ;
        }
        numComponents-- ;
        return ;
    }

    int getComponents(){
        return numComponents ;
    }

    void print(){

        for(int i = 0 ; i < _size ; i++){
            cout << i << " -> "  << parent[i] << '\n' ;
        }
    }   

    void reset(int n){
        _size = n ;
        numComponents = n ;
        rank = new int[_size];
        parent = new int[_size];

        for (int i = 0; i < _size ; i++)
        {
            rank[i] = 1 ;
            parent[i] = i ;
        }
    }

    ~unionFind() {
        delete[] rank;
        delete[] parent;
    }

};
