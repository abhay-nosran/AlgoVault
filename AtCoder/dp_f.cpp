#include <bits/stdc++.h>
using namespace std ;
int n , m ; 
string s , t ;
int dp[3003][3003];
int back[3003][3003];
int lcs(int l1 , int l2){

    if(l1 >= n || l2 >= m) return 0 ;

    if(dp[l1][l2] != -1) return dp[l1][l2] ;
    int ans = 0 ;

    if(s[l1] == t[l2] && ans < lcs(l1+1,l2+1) + 1){
        ans = lcs(l1+1,l2+1) + 1 ;
        back[l1][l2] = 2 ;
    }

    if(ans < lcs(l1+1,l2)){
        ans = lcs(l1+1,l2) ;
        back[l1][l2] = 0 ;
    }
    if(ans < lcs(l1,l2+1)){
        ans = lcs(l1,l2+1) ;
        back[l1][l2] = 1 ;
    }
    

    return dp[l1][l2] = ans ;

}

void generate(int l1,int l2){
    
    if(l1 >= n || l2 >= m) return  ;

    int ch = back[l1][l2] ;
    if(ch == 0){
        generate(l1+1,l2) ;
    }else if(ch ==1){
        generate(l1,l2+1) ;
    }else{
        cout << s[l1] ;
        generate(l1+1,l2+1) ;
    }
    
    return ;
}
void solve(){
    cin >> s >> t ;
    n = s.size() ; m = t.size() ;
    memset(dp,-1,sizeof(dp)) ;
    lcs(0,0) ;
    // cout << lcs(0,0) << '\n' ;
    generate(0,0) ;
}

int main(){
    solve() ;
}