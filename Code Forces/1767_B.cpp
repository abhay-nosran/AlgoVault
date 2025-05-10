#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ; 
    priority_queue<int,vector<int>,greater<int>> pq ;
    int val ; cin >> val ;

    for (int i = 0; i < n-1; i++)
    {
        int element ; cin >> element ;
        if(element > val) pq.push(element) ;
    }

    while (!pq.empty())
    {
        
        int node = pq.top() ; pq.pop() ;
        if(node <= val) continue; 

        int change = (node - val + 1)/2;
        val += change ;
    }
    
    cout << val << '\n' ;
    

}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}