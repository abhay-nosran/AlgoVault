#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n , x ; cin >> n >> x ; 

    int arr[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }

    sort(arr,arr+n) ;

    int gondolaCnt = 0 ;
    // for(int i = 0 ; i < n ; i++){

    //     if(arr[i] <= currWeightLeft){
    //         // can fit in previous gondola 
    //         currWeightLeft -= arr[i] ;
    //     }else{
    //         //cant't fit in previous gondola 
    //         gondolaCnt++ ; currWeightLeft = x ; // spawn new gondola 
    //         currWeightLeft -= arr[i] ; // sit in gondola
    //     }
    // }Wrong


    int i = 0 , j = n-1 ;

    while(i <= j){
        gondolaCnt++ ;
        // both (i,j) can sit 
        if(1LL*arr[i] + 1LL*arr[j] <= 1LL*x){
            i++,j--;
        }else{
            // sit jth 
            j--;
        }
    }
    cout << gondolaCnt ;

}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}