#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    int evenCnt = 0 ;
    int oddCnt = 0 ;

    for (int i = 0; i < (2*n); i++)
    {
        int element ;
        cin >> element ;
        if(element%2 == 0) evenCnt++ ;
        else oddCnt++ ;
    }

    if(evenCnt == oddCnt) cout << "Yes\n"  ;
    else cout << "No\n" ;
    
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}