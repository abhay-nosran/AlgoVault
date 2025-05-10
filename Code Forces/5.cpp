#include <bits/stdc++.h>
using namespace std ;
bool comp(int a , int b){
    if(a > b) return true ;
    return false ;
}
void solve(){
    int n , m , k ; cin >> n >> m >> k ;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> nums(31,-1);
    long long sum = 0LL ;

    // for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    priority_queue<int> pq;
    int element ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> element ;
        sum += element ;
        pq.push(element);
        
    }

    for(int i = 0 ; i < m ; i++) cin >> b[i] ;

    

    
    for (int i = 0 ; i < 31 ; i++) // ith bit
    {
        for(int j = 0 ; j < m ; j++){ // jth b 
            if(b[j] & (1<<i)) ;
            else {
                if(nums[i] == -1 || b[j] < nums[i])
                {
                    nums[i] = b[j] ;
                }
                
            }
        }
        
    }

    while (k--)
    {
        int num = pq.top() ;
        pq.pop();
        sum -= num ;
        int flag = 0 ;

        for(int i = 30 ; i >= 0 ; i--){//ith
            if(num & (1<<i)){

                int temp = (num & nums[i]) ;
                // if some number with ith bit as 0 
                if(nums[i] != -1 && num > temp){
                    
                    num = temp;
                    
                    pq.push(num) ;
                    sum += num ;
                    flag = 1 ;
                    break ;
                }
            }
        }

        if(flag == 0){
            k++;
            sum += num ;
            break;
        }
        
    }
    
    cout << sum << '\n' ;
    


}

signed main(){
    
    int t ; cin >> t ;
    while(t--){
        solve() ;
    }
    
}