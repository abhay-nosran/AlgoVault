#include <bits/stdc++.h>
#define int long long 
using namespace std ;

int binPow(int a , int b){
    if(b==0) return 1 ;

    if(b%2 == 0){
        return binPow(a*a,b/2);
    }else{
        return a*binPow(a,b-1);
    }
}
bool check(int num){
    while (num)
    {
        int dig = num%10 ;
        if(dig == 7) return 1 ;
        num = num/10;
    }
    return 0 ;
}

int calcSteps(int n){
    int numDigits = to_string(n).size();
    int divisor = binPow(10,numDigits)-1;
    
    int cnt = 0 ;
    while (n)
    {
        int next = n%divisor ;
        cnt += (n/divisor);
        divisor /=10;
        n =  next;
    }
    
    return cnt ;
}

void solve(){
    int n ; 
    cin >> n ;
    int temp = n ;
    int ans = 0 ;
    while (temp)
    {   
        cout << temp << '\n' ;
        if(((temp-n)%9 == 0) && check(temp)){
            ans = calcSteps(temp-n) ;
            break ;
        }
        temp++ ;
    }

    cout << ans << '\n' ;
    
}

signed main(){
    int t ; cin >> t ;
    while (t--) 
    {
        solve() ;
    }
    
}