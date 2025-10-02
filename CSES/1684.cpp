#include <iostream>
#include <vector> 
using namespace std;
vector<pair<int,int>> arr ;
vector<int> toppings ;

int n ;
bool rec(int level){

    // base case 
    if(level == n){
        return 1 ;
    }

    // choice 1 
    int a = arr[level].first ;

    if(toppings[abs(a)] == 0){
        // le hi lenge 
        toppings[abs(a)] = a ;
        if(rec(level+1)) return 1 ;
        toppings[abs(a)] = 0 ;
    }else if(a + toppings[abs(a)] == 0){
        // nhi le skta 
        
    }else{
        if(rec(level+1)) return 1 ;
    }

    int b = arr[level].second ;
     if(toppings[abs(b)] == 0){
        // le hi lenge 
        toppings[abs(b)] = b ;
        if(rec(level+1)) return 1 ;
        toppings[abs(b)] = 0 ;
    }else if(b + toppings[abs(b)] == 0){
        // nhi le skta 
        
    }else{
        if(rec(level+1)) return 1 ;
    }

    return 0 ;
}
void solve(){
    int m ; cin >> n >> m ;

    arr.resize(n) ;
    toppings.resize(m+1,0) ;
    for(int i = 0 ; i < n ; i++){
        char c ; cin >> c ; int a ; cin >> a ;
        a = c == '+' ? a : -a ;
        char d ; cin >> d ; int b ; cin >> b ;
        b = d == '+' ? b : -b ;

        // {a , b }
        arr[i] = {a,b} ;
    }

    if(rec(0) == 0){
        cout << "IMPOSSIBLE" ;
    }else{
        for(int i = 1 ; i <= m ; i++){

            if(toppings[i] > 0) cout << "+ " ; 
            else cout << "- " ;
        }
    }

}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}