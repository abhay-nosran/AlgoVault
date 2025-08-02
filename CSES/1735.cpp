#include <bits/stdc++.h>
using namespace std ;
#define  MAXN  2*200100 
#define int long long 
int arr[MAXN] ;
struct Node {
    int sum ; 
    int lazy1 ; // +x
    int lazy2 ; // set x

    Node(){
        sum = 0 ; lazy1 = 0 ; lazy2 = 0 ;
    }
    
};
Node t[4*MAXN] ;

Node merge(Node a , Node b){
    Node temp ;
    temp.sum = a.sum + b.sum ;
    return temp ;
}

void push_down(int cur , int child){


    if(t[cur].lazy2 != 0){

        t[child].lazy2 = t[cur].lazy2 ;
        t[child].lazy1 = 0 ;

    }else{

        if(t[child].lazy2 != 0){
            t[child].lazy2 = t[child].lazy2 + t[cur].lazy1 ;
            t[child].lazy1 = 0 ;
        }else{
            t[child].lazy1 = t[child].lazy1 + t[cur].lazy1 ;
            t[child].lazy2 = 0 ;
        }
    }
}

void push(int index , int l , int r){

    if(t[index].lazy1 == 0 && t[index].lazy2 == 0) return ;

    if(l!=r){
        push_down(index,2*index) ;
        push_down(index,2*index+1) ;
    }
    
    if(t[index].lazy1){
        t[index].sum += (r-l+1)*(t[index].lazy1);
        t[index].lazy1 = 0 ;
    }
    else if(t[index].lazy2){
        t[index].sum = (r-l+1)*(t[index].lazy2);
        t[index].lazy2 = 0 ;
    }
}
void build(int index , int l , int r){

    if(l > r) return ;

    if(l == r){
        Node temp ; temp.sum = arr[l] ;
        t[index] = temp ;
        return ;
    }

    int mid = (l+r)/2 ;
    build(2*index,l,mid) ;
    build(2*index+1,mid+1,r) ;
    t[index] = merge(t[2*index],t[2*index+1]) ;
}

void update(int index , int l , int r , int lq , int rq , int val , int type){

    if(l > r) return ;
    push(index,l,r) ;
    if(l > rq || r < lq){
        return ;
    }

    if(lq <= l && r <= rq){
        
        if(type == 1){
            t[index].lazy1 += val ;
        }else{
            t[index].lazy2 = val ;
        }
        push(index,l,r);
        return ;
    }

    int mid = (l+r)/2 ;
    update(2*index,l,mid,lq,rq,val,type) ;
    update(2*index+1,mid+1,r,lq,rq,val,type) ;

    t[index] = merge(t[2*index],t[2*index+1]) ;
}

int query(int index , int l , int r , int lq , int rq ){

    push(index,l,r) ;
    if(l>rq || r < lq) return 0 ;

    if(lq <= l && r <= rq){
        return t[index].sum ;
    }

    int mid = (l+r)/2 ;

    return query(2*index,l,mid,lq,rq) + query(2*index+1,mid+1,r,lq,rq);

}

signed main(){

    int n , q; cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
    }

    build(1,1,n) ;
    while(q--){
        int ch ; cin >> ch ;

        if(ch ==1 ){
            int a,b,x ; cin>>a>>b>>x ;
            update(1,1,n,a,b,x,1);
        }else if(ch == 2){
            int a,b,x ; cin>>a>>b>>x ;
            update(1,1,n,a,b,x,2);
        }else{
            int a , b ; cin >> a >> b ;
            cout << query(1,1,n,a,b) << '\n'; 
        }
    }
}