#include <bits/stdc++.h>
using namespace std ;
using state = pair<int,int> ;
#define F first 
#define S second 


void solve(){
    int n , a , b ; cin >> n >> a >> b ;

    int middleNum = n - a -b ;
    if(n==1){
        cout << "Yes\n" ;
        return ;
    }

    if(middleNum <=1){
        cout << "No\n" ; 
    }else{
        cout << "Yes\n" ;
    }

}

int main(){
    int t ; cin >>t ;
    while (t--)
    {
        solve() ;
    }
    
}