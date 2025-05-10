#include <bits/stdc++.h>
#define F first 
#define S second 
using namespace std ; 
using node = pair<int,int> ;
struct comp {
    bool operator()(const node& a, const node& b) {
        if (a.second < b.second) return true;
        if (a.second == b.second && a.first < b.first) return true;
        return false;
    }
};
struct comp2{
    bool operator()(const node& a, const node& b) {
        if (a.first < b.first) return true;
        if (a.first == b.first && a.second < b.second) return true;
        return false;
    }
};

void solve(){
    int n ; cin  >> n ;
    vector<node> nodes(n) ;
    priority_queue<node,vector<node>,comp> pq;
    priority_queue<node,vector<node>,comp2> pq2;

    for (int i = 0; i < n; i++)
    {
        int a , b ; cin >> a >> b ;
        nodes[i]= {a,b} ;
    }
    
    node n1 = nodes[0];
    int n1Index = 0 ,n2Index = 1;
    node n2 = nodes[1] ;

    // cout << n1.F << ' ' << n2.S ;
    int mini = max(n1.F + n2.S , n1.S + n2.F) ;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(nodes[i].F + nodes[j].S < mini && nodes[i].S + nodes[j].F < mini){
                mini = max(nodes[i].F + nodes[j].S , nodes[i].S + nodes[j].F) ;
                n1Index = i ; n2Index = j ;
            }
        }
        
    }
    // cout << mini ;
    // n1 n2 are two min nodes 
    for (int i = 0; i < n; i++)
    {
        if(i == n1Index || i == n2Index) continue; 
        pq.push(nodes[i]) ;
    }
    
    pq2.push(n1);
    pq2.push(n2);

    cout << mini << ' ' ;
    int sum = mini ;
    for (int k = 3; k <= n ; k++)
    {   
        node top1 = pq.top() ;
        node top2 = pq2.top() ;
        sum += max(top1.F + top2.S , top1.S + top2.F) ;
        cout << sum  << ' ';
        
        pq.pop();
        pq2.push(top1);
    }
    
    cout << '\n' ;

}

int main(){

    int t ; cin >> t ;
    while (t--) 
    {
        solve() ;
    }
    
}