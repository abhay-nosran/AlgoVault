#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    int arr[n+1] ; 
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i] ;
    }

    sort(arr+1,arr+n+1) ;

    int medianIndex = (n+1)/2 ;
    int cnt = 1 ;

    for (int i = medianIndex; i <= n; i++)
    {
        if(i+1 <= n && arr[i] == arr[i+1]){
            cnt++ ;
        }else{
            break ;
        }
    }

    cout <<  cnt << '\n' ;
    
    
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}