#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod;
char p[10000+10];
int xishu[111];
void deal(){
    memset(xishu,0,sizeof(xishu));
    int l=strlen(p);
    for(int i=1;p[i]!=')';){
        int flag=1;//¸ºÊý
        int cur=0;
        while(p[i]!='n'&&p[i]!=')'){
            char ch=p[i];
            if(ch=='+'){}
            else if(ch=='-')flag=0;
            else cur=cur*10+(ch-'0');
            i++;
        }
        if(cur==0)cur=1;
        if(!flag)cur*=(-1);
        i++;
        int zhishu=0;
        if(p[i]=='/'){
            zhishu=0;
            xishu[zhishu]=cur;break;
        }
        else if(p[i]=='^'){
            i++;
            while(isdigit(p[i])){
                zhishu=zhishu*10+(p[i]-'0');i++;
            }
        }
        else{
            zhishu=1;
        }
        xishu[zhishu]=cur;
    }
    mod=0;int i=0;
    for(;p[i]!='/';i++);//p[i]=='/'
    i++;
    for(;i<l;i++)mod=mod*10+(p[i]-'0');
}
ll qpow(ll a,int n){//a^n
    if(n==0)return 1;
    ll ans=qpow(a,n>>1);
    ans=ans*ans%mod;
    if(n&1){
        ans=ans*a%mod;
    }
    return ans;
}

ll cal(ll num){
    if(num==0)return xishu[0];
    ll ans=0;
    for(int i=0;i<=100;i++){
        ans+=xishu[i]*qpow(num,i)%mod;//c*n^e
    }
    return ans;
}
int main(){
    int kase=0;
    while(scanf("%s",p)){
        if(p[0]=='.')break;
        deal();
        bool ok=1;
        for(ll k=0;k<=100;k++){
            ll ans=cal(k);
            if(ans%mod){
                ok=0;break;
            }
        }
        printf("Case %d: ",++kase);
        if(!ok)printf("Not always an integer\n");
        else printf("Always an integer\n");
    }
    return 0;
}

