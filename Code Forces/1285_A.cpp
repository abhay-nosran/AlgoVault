#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    int maxLeft = 0 ;
    int maxRight = 0 ;
    for (int i = 0; i < n; i++)
    {
        char element ; cin >> element ;

        if(element == 'L'){
            maxLeft++;
        }else{
            maxRight++;
        }
    }

    cout << (maxRight + maxLeft + 1) << '\n' ;
    
}

int main(){
    // int t ; cin >> t; while(t--)
    solve();
}