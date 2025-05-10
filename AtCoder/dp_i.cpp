#include <bits/stdc++.h>
using namespace std;
double ph[3000] ;
int n ;
vector<vector<double>> dp(3000,vector<double>(3000,-1)) ;   
double rec(int index , int numHeads){
    int boxes = n - index ;
    int numTails = boxes - numHeads  ;

    if(boxes < numHeads) return 0.0 ;

    if(index  ==  n){
        return numHeads == 0 ? 1.0 : 0.0; ;
    }

    if(dp[index][numHeads] != -1.0) return dp[index][numHeads] ;
    double ans = 0 ;
    //head comes
    if(numHeads > 0){
        ans += rec(index+1,numHeads-1)*ph[index] ;
    }
    if(numTails > 0){
        ans += rec(index+1,numHeads)*(1-ph[index]) ;
    }

    return dp[index][numHeads] = ans ;

}
void solve(){
     cin >> n ;
    dp.resize(n+1,vector<double>(n+1,-1.0)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> ph[i] ;
    }

    double ans = 0 ;

    for(int i = n ; i > n/2 ; i--){
        ans += rec(0,i) ;
    }

    cout <<  ans << '\n' ;

    
}

int main(){
    
    solve();
}