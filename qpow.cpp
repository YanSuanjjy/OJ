#include <bits/stdc++.h>
using namespace std;

//a^p%mod
ll qpow(ll a,ll p,ll mod){
    if(p==0)return 1;
    ll ans=qpow(a,p>>1,mod);
    ans=ans*ans%mod;
    if(p&1)ans=ans*a%mod;
    return ans;
}

//gcd
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

//��չŷ�����
//������x��yʹ��ax+by=d,��|x|+|y|��С������d=gcd(a,b)
void gcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){d=a;x=1;y=0;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

//ģmod ��a���棬�����ڷ���-1
ll inv(ll a,ll mod){
    ll d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+mod)%mod:-1;
}

//���a^x=b(mod n) nΪ�������޽ⷵ��-1

