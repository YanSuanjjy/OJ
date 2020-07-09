#include <bits/stdc++.h>
using namespace std;
void gcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){d=a;x=1;y=0;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
//n¸ö·½³Ì£ºx=a[i](mod m[i]) 0<=i<n
ll china(int n,int *a,int *m){
    ll M=1,d,y,x=0;
    for(int i=0;i<n;i++)M*=m[i];
    for(int i=0;i<n;i++){
        ll w=M/m[i];
        gcd(m[i],w,d,d,y);
        x=(x+y*w*a[i])%M;
    }
    return (x+M)%M;
}
