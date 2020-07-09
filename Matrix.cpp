#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
typedef long long ll;
ll n,m;int d;
struct Mat{
    ll mat[maxn][maxn];
};
//矩阵乘法mod m下的
Mat mul_mod(Mat a,Mat b){
    Mat temp;
    memset(temp.mat,0,sizeof(temp.mat));
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            for(int k=1;k<=d;k++){
                temp.mat[i][j]=(temp.mat[i][j]+a.mat[i][k]*b.mat[k][j]%m)%m;
            }
        }
    }
    return temp;
}
//矩阵mod m下的矩阵快速幂
Mat qpow(Mat a,ll k){
    Mat tmp;
    memset(tmp.mat,0,sizeof(tmp.mat));
    for(int i=1;i<=d;i++)tmp.mat[i][i]=1;
    while(k){
        if(k&1)tmp=mul_mod(tmp,a);
        k>>=1;
        a=mul_mod(a,a);
    }
    return tmp;
}

//循环矩阵的快速幂及其乘法
struct mat {
	long long v[N];
	mat() {memset(v, 0, sizeof(v));}
	mat operator * (mat c) {
		mat ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans.v[i] = ((ans.v[i] + v[j] * c.v[(j - i + n) % n]) % m + m) % m;
   			}
  		}
  		return ans;
 	}
};

mat pow_mod(mat x, long long k) {
	if (k == 1) return x;
	mat sb = x * x;
	mat ans = pow_mod(sb, k>>1);
	if (k&1) ans = ans * x;
	return ans;
}

