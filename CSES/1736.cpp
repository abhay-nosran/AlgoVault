#include <bits/stdc++.h>
using namespace std ;
#define MAXN 200100 
#define int long long
int arr[MAXN] ;

struct Node{
    int a , d , sum ;
    Node(){
        a = 0 ; d = 0; sum = 0 ;
    }
};

Node t[4*MAXN] ;

Node merge(Node a , Node b){
    Node temp ;
    temp.sum = a.sum + b.sum ;
    return temp ;
}

inline int getSum(int n , int a , int d){
    return n*(2*a+(n-1)*d)/2 ;
}
inline int getNthValue(int a , int d , int n){
    return (a + (n-1)*d );
}
void pushDown(int index , int a , int d){

    t[index].a +=  a;
    t[index].d += d ;

}
void push(int index , int l , int r){
    
    if(t[index].a == 0 && t[index].d == 0)  return ;

    if(l!=r){
        // range[l,r] ;
        int mid = (l+r)/2 ;
        int val = getNthValue(t[index].a,t[index].d,mid-l+2);
        pushDown(2*index,t[index].a,t[index].d) ;
        pushDown(2*index+1,val,t[index].d) ;

    }
    t[index].sum+= getSum(r-l+1,t[index].a,t[index].d) ;
    t[index].a = 0 ;
    t[index].d = 0 ;

}

void update(int index , int l , int r , int lq , int rq , int  a , int d){

    push(index , l , r);
    if(l > rq || r < lq) return ;

    if(lq <= l && r <= rq){

        // t[index].a = a ; error 
        // lq is a l is ? 
        int diff = l - lq ;
        int n = diff + 1 ;
        t[index].a = getNthValue(a,d,n) ;
        t[index].d = d ;

        push(index , l , r);
        return ;
    }

    int mid = (l+r)/2 ;
    update(2*index , l , mid , lq ,rq , a, d) ;
    update(2*index +1, mid+1, r, lq ,rq , a, d) ;

    t[index] = merge(t[2*index],t[2*index+1]) ;

}

int query(int index , int l , int r , int lq , int rq ){

    push(index , l , r) ;
    if(l > rq || r < lq) return 0;

    if(lq <= l && r <= rq){
        return t[index].sum;
    }
    int mid = (l+r)/2 ;
    return query(2*index,l,mid,lq,rq) + query(2*index+1,mid+1,r,lq,rq);
}

void build(int index , int l , int r){

    if(l > r) return ;

    if(l == r){

        Node node ; 
        node.sum = arr[l] ;
        t[index] = node ;
        return ;
    }

    int mid = (l+r)/2 ;

    build(2*index,l,mid);
    build(2*index+1,mid+1,r) ;

    t[index] = merge(t[2*index],t[2*index+1]) ;

}

signed main(){

    int n , q ; 
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
    }

    build(1,1,n) ;
    while (q--)
    {
        int ch ; cin >> ch ; 
        int l , r ; cin >> l >> r  ; 
        if(ch == 1){
            update(1,1,n,l,r,1,1) ;
        }else{
            cout << query(1,1,n,l,r) << '\n' ;
        }
    }
    

}