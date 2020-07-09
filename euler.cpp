#include <bits/stdc++.h>
using namespace std;
using ll=long long;

//±í
ll euler[maxn];
void getEuler(int n){
    memset(euler,0,sizeof(euler));
    euler[1] = 1;
    for(int i = 2;i <= n;i++)
    if(!euler[i])
    for(int j = i;j <= n; j += i){
        if(!euler[j])euler[j] = j;
        euler[j] = euler[j]/i*(i-1);
    }
}

ll eular(ll n){
    ll ans = n;
    for(int i = 2;i*i <= n;i++){
        if(n % i == 0){
            ans -= ans/i;
            while(n % i == 0)n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}
