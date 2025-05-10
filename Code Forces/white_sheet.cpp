#include <iostream>
using namespace std;
#define int long long

signed main(){
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 ;

     int white_area = (y2-y1) * (x2 - x1) ;

     int b1_w_area = max(min(x4,x2) - max(x1,x3),0LL)*max(min(y4,y2) - max(y1,y3),0LL);
     int  b2_w_area = max(min(x6,x2) - max(x1,x5),0LL) * max(min(y6,y2) - max(y1,y5),0LL) ;
     int b1_b2_w_area = max(min(x2,min(x4,x6)) - max(x1,max(x3,x5)),0LL) *  max(min(y2,min(y4,y6)) - max(y1,max(y3,y5)),0LL) ;

    white_area = white_area - b1_w_area - b2_w_area + b1_b2_w_area;
    // cout << white_area << endl ;
    if(white_area > 0) cout << "YES" << endl ;
    else cout << "NO" << endl ;
    return 0;
}