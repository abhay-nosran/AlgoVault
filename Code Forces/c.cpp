#include <bits/stdc++.h>
using namespace std ;   

void solve(){
   int n ; cin >> n ;
   int arr[n] ;
   int length = n ;
   for (int i = 0; i < n; i++)
   {
    cin >> arr[i] ;
   }

   int ans = INT_MIN ;


   int diffSum = 0 ;
   int sum = arr[0] ; 

   if(length == 1){
        cout << sum << '\n' ;
        return ;
   }
   while (length > 1)
   {
        for (int i = 1; i < length; i++)
        {
            diffSum = arr[i] - arr[i-1] ;
            arr[i-1] = diffSum ;
            sum += arr[i] ;
        }

        length-- ;

        if(diffSum < 0){
            reverse(arr , arr + length) ;
            diffSum = -1 * diffSum ;
        }

        ans = max(sum,diffSum) ;
        sum = arr[0] ;
        
   }
   

    cout << ans << '\n' ;
}

int main(){

    int t ; cin >> t ;
    while (t--) 
    {
        solve() ;
    }
    
}