#include <bits/stdc++.h>
using namespace std ;

void solve(){
   int n ; cin >> n ;
   vector<int> arr(n+1) ; 
   map<int,int> freq ;
   for(int i = 1 ; i <= n ; i++){
    cin >> arr[i] ;
   }

   for(int i = 1 ; i <= n ; i++){
        freq[arr[i]]++ ;
   }

    int curLen = 0 ; 
    int start , end ;
    int x , y ;
    int maxLen = 0 ;
   for (int i = 1 ; i <= n; i++)
   {
        if(freq[arr[i]] == 1){
            curLen++ ;
            if(curLen == 1) start = i ;
            end = i;
            if(curLen > maxLen){
                maxLen = curLen ;
                x = start ;
                y = end ;
            }
        }else{
            curLen = 0 ;
        }
   }
   

   if(maxLen == 0){
    cout << 0 << '\n' ;
   }else{
    cout << x << ' ' << y << '\n'; 
   }

}

signed main(){
    int t ; cin >> t ;
    while (t--) 
    {
        solve() ;
    }
    
}