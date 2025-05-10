#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

long long goodSub(vector<int> & arr){
    int n = arr.size() ;
    unordered_map<int,long long> mpp ;
    int sum = 0 ;
    long long count = 0 ;
    mpp[0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i] ;
       if(mpp.find(sum) != mpp.end()) count += mpp[sum] ;
        mpp[sum]++ ;
    }
    return count ;
   
}
int main(){
    int t ; cin >> t ;

    for (int i = 0; i < t; i++)
    {
        int n ; cin >> n ; 
        string s ; cin >> s ;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            arr[j] = s[j] - '0' - 1; // to make sum of array 0
        }
        cout << goodSub(arr) <<endl ;
    }
    
}