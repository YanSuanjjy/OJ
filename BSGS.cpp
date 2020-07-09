#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxb=510;
const int mod=100000007;
ll mul_mod(ll a,ll b){
    return (ll)a*b%mod;
}
ll qpow(ll a,ll p){
    if(p==0)return 1;
    ll ans=qpow(a,p>>1);
    ans=ans*ans%mod;
    if(p&1)ans=ans*a%mod;
    return ans;
}
void gcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){d=a;x=1;y=0;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
//模mod 下a的逆，不存在返回-1
ll inv(ll a,ll mod){
    ll d,x,y;
    gcd(a,mod,d,x,y);
    return d==1?(x+mod)%mod:-1;
}
int Count(){
    int c=0;
    for(int i=0;i<b;i++){
        if(x[i]!=m&&!bset.count(make_pair(x[i]+1,y[i])))c++;
    }
    c+=n;
    for(int i=0;i<b;i++)if(x[i]==1)c--;
    //ans=k^c*(k-1)^(mn-b-c)
    return mul_mod(qpow(k, c), qpow(k-1, (ll)m*n-b-c));
}

#define MOD 76543
int hs[MOD],head[MOD],next1[MOD],id[MOD],top;
void insert1(int x,int y){
    int k = x%MOD;
    hs[top] = x, id[top] = y, next1[top] = head[k], head[k] = top++;
}
int find1(int x){
    int k = x%MOD;
    for(int i = head[k]; i != -1; i = next1[i])
    if(hs[i] == x)
    return id[i];
    return -1;
}
int BSGS(int a,int b,int n){
    memset(head,-1,sizeof(head));
    top = 1;
    if(b == 1)return 0;
    int m = sqrt(n*1.0), j;
    long long x = 1, p = 1;
    for(int i = 0; i < m; ++i, p = p*a%n)insert1(p*b%n,i);
    for(long long i = m; ;i += m){
        if( (j = find1(x = x*p%n)) != -1 )return i-j;
        if(i > n)break;
    }
    return -1;
}



int log_mod (ll a, ll b) {
    ll m = (ll)sqrt(mod+0.5), v, e = 1;
    v = inv(qpow(a, m),mod);
    map<ll, ll> g;
    g[1] = 0;
    for (ll i = 1; i < m; i++) {
        e = mul_mod(e, a);
        if (!g.count(e))
            g[e] = i;
    }
    for (ll i = 0; i < m; i++) {
        if (g.count(b))
            return i*m+g[b];
        b = mul_mod(b, v);
    }
    return -1;
}
