#include <iostream> 
#include <vector> 
#include <stack>
#include <algorithm> 

#define UNVISITED -1 
using namespace std ;

// given a graph as an input
vector<vector<int>> graph ; // directed graph 1 based indexing


vector<int> ids ;
vector<int> lowLink ;
vector<bool> onStack ;
stack<int> st ; 
int id = 0 ;

void dfs(int node){
    ids[node] = ++id ;
    lowLink[node] = id ;
    onStack[node] = 1 ;
    st.push(node) ;

    for(auto neigh : graph[node]){

        if(ids[neigh] == UNVISITED) dfs(neigh) ;
        if(onStack[neigh]) lowLink[node] = min(lowLink[node],lowLink[neigh]) ;
    }

    if(ids[node] == lowLink[node]){
            // scc start detected 

            while(true){
                int temp = st.top() ; st.pop() ;
                onStack[temp] = 0 ;
                if(temp == node) break ;
            }
    }
}


// will return an array lowLink  1 based index 
void tarjan(){

    int n = graph.size() ; // node from [1 ... n-1] 

    ids.resize(n,UNVISITED) ; // idicates that id is not assigned and not visited yet 
    lowLink.resize(n) ;
    onStack.resize(n) ;

    for(int i = 1 ; i <= n ; i++){
        if(ids[i] == UNVISITED) dfs(i) ;
    }

    return ;
}
