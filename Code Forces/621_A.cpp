#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n ; cin >> n ;
    int oddSum = 0 ;
    int evenSum = 0 ;
    int smallestOdd = 1e9+7;
    for (int i = 0; i < n; i++)
    {
        int element ; cin  >> element ;

        if(element % 2){//odd
            oddSum+= element ;
            smallestOdd = min(element,smallestOdd);
        }else{
            evenSum+=element ;
        }
    }

    if(oddSum%2){
        oddSum -= smallestOdd ;
    }

    cout << evenSum+oddSum ;
    
}

signed main(){
    // int t ; cin >> t; while(t--)
    solve();
}