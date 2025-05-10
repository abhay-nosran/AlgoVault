#include <bits/stdc++.h>
using namespace std;

int binPow(int a , int b){

    if(b == 0 ) return 1 ; 

    if(b%2 == 1){
        return a*binPow(a,b-1);
        
    }else{
        int ans = binPow(a,b/2);
        return ans * ans ;
    }

}
void solve(){
    int n ; cin >> n ;
    int k = log10(n) ;

    cout << n - binPow(10,k) << '\n'; 
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}