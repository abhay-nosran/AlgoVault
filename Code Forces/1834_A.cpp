#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n ;
    int arr[n] ;

    int negativeCnt = 0 ;
    int positiveCnt = 0 ;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]  ;
        if(arr[i] == 1){
            positiveCnt++ ;
        }else{
            negativeCnt++ ;
        }
    }
    
    int sum = -1*negativeCnt + positiveCnt ;
    int ans = 0 ;
    if(sum >= 0){
        if(negativeCnt%2 == 1){
            //odd -ve
            ans++;
        }
    }else{
        int operationsToMakePositive = ((-1*sum)+2-1)/2 ;
        ans += operationsToMakePositive ;
        negativeCnt = negativeCnt - operationsToMakePositive ;
        positiveCnt += operationsToMakePositive ;
        if(negativeCnt%2 == 1){
            //odd -ve
            ans++;
        }
        
    }
    
    cout << ans << '\n' ;
}

int main(){
    int t ; cin >>t  ;
    while(t--) solve() ;
}