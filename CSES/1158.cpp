#include <bits/stdc++.h>
using namespace std;
int price[1001] ;
int pages[1001] ;
int temp[100100] ;
void solve(){
    int n , W ; cin >> n >> W ;

    for(int i = 1 ; i <= n ; i++){
        cin >> price[i] ;
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> pages[i] ;
    }


    for(int k = 1 ; k <= n ; k++){
        for(int x = W ; x >= 1 ; x--){
            temp[x] = temp[x] ;
            if(x >= price[k]) temp[x] = max(temp[x],pages[k]+temp[x-price[k]]);
        }
        // for(int i = 0 ; i <= W ; i++) cout << temp[i] << ' ' ;
        // cout << endl ;
    }

    cout << temp[W] << endl ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}