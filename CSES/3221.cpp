#include <bits/stdc++.h>
using namespace std ;
#define int long long 
deque<int> dq ; 
void insert(int x){
    while(!dq.empty() && dq.back() > x){
        dq.pop_back();
    }
    dq.push_back(x) ;
    return ;
}

int getMin(){
    return dq.front() ;
}

void remove(int x){
    if(dq.front() == x) dq.pop_front() ;
}
signed main(){
    int n , k , x ,a , b , c; 
    cin >> n >> k >> x >> a >> b >> c ;

    vector<int> v(n+1,0) ;
    v[1] = x ;

    int ans  = 0 ;
   
    for(int i = 1 ; i <= n ; i++){

        if(i>1) v[i] = (a*v[i-1]+b) % c; 
        // minima.insert(v[i]) ;
        insert(v[i]) ;
        if(i-k >= 1){  
            // remove from set
            // minima.erase(minima.find(v[i-k])) ; 
            remove(v[i-k]) ;
        }
        if(i-k >= 0){
            // get minima
            // ans ^= *minima.begin() ;
            ans ^= getMin() ;
        }
    }
    cout << ans ;
}