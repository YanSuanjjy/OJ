#include <bits/stdc++.h>
using namespace std;
struct BigInt{
    const static int mod=10000;
    const static int DLEN=4;
    int a[600],len;
    BigInt(){memset(a,0,sizeof(a));len=1;}
    BigInt(int v){
        memset(a,0,sizeof(a));
        len=0;
        do{
            a[len++]=v%10;
            v/=10;
        }while(v);
    }
    BigInt(const char s[]){
        memset(a,0,sizeof(a));
        int L=strlen(s);
        len=L/DLEN;
        if(L%DLEN)len++;int index=0;
        for(int i=L-1;i>=0;i-=DLEN){
            int t=0;
            int k=i-DLEN+1;if(k<0)k=0;
            for(int j=k;j<=i;j++){
                t=t*10+s[j]-'0';
                a[index++]=t;
            }
        }
    }
    BigInt operator+(const BigInt &b)const{
        BigInt res;res.len=max(len,b.len);
        for(int i=0;i<=res.len;i++)res.a[i]=0;
        for(int i=0;i<res.len;i++){
            res.a[i]+=((i<len)?a[i]:0)+((i<b.len)?b.a[i]:0);
            res.a[i+1]+=res.a[i]/mod;res.a[i]%=mod;
        }
        if(res.a[res.len]>0)res.len++;return res;
    }
    BigInt operator*(const BigInt &b)const{
        BigInt res;
        for(int i=0;i<len;i++){
            int up=0;
            for(int j=0;j<b.len;j++){
                int tmp=a[i]*b.a[j]+res.a[i+j]+up;
                res.a[i+j]=tmp%mod;
                up=tmp/mod;
            }
            if(up)res.a[i+b.len]=up;
        }
        res.len=len+b.len;while(res.a[res.len-1]==0&&res.len>1)res.len--;return res;
    }
    void output(){
        printf("%d",a[len-1]);
        for(int i=len-2;i>=0;i--)printf("%04d",a[i]);
    }
};

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
/*
* ��ȫ����ģ��
* ���cin>>a
* ���a.print();
* ע��������벻���Զ�ȥ��ǰ��0�ģ������ȶ��뵽char���飬ȥ��ǰ��0�����ù��캯����
*/
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigNum
{
private:
    int a[500]; //���Կ��ƴ�����λ��
    int len;
public:
    BigNum(){len=1;memset(a,0,sizeof(a));} //���캯��
    BigNum(const int); //��һ��int���͵ı���ת���ɴ���
    BigNum(const char*); //��һ���ַ������͵ı���ת��Ϊ����
    BigNum(const BigNum &); //�������캯��
    BigNum &operator=(const BigNum &); //���ظ�ֵ�����������֮����и�ֵ����
    friend istream& operator>>(istream&,BigNum&); //�������������
    friend ostream& operator<<(ostream&,BigNum&); //������������
    BigNum operator+(const BigNum &)const; //���ؼӷ����������������֮����������
    BigNum operator-(const BigNum &)const; //���ؼ������������������֮����������
    BigNum operator*(const BigNum &)const; //���س˷����������������֮����������
    BigNum operator/(const int &)const; //���س����������������һ�������������
    BigNum operator^(const int &)const; //������n�η�����
    int operator%(const int &)const; //������һ��int���͵ı�������ȡģ����
    bool operator>(const BigNum &T)const; //��������һ�������Ĵ�С�Ƚ�
    bool operator>(const int &t)const; //������һ��int���͵ı����Ĵ�С�Ƚ�
    void print(); //�������
};
BigNum::BigNum(const int b) //��һ��int���͵ı���ת��Ϊ����
{
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>MAXN)
    {
    c=d-(d/(MAXN+1))*(MAXN+1);
    d=d/(MAXN+1);
    a[len++]=c;
    }
    a[len++]=d;
}
BigNum::BigNum(const char *s){//��һ���ַ������͵ı���ת��Ϊ����
    int t,k,index,L,i;
    memset(a,0,sizeof(a));
    L=strlen(s);
    len=L/DLEN;
    if(L%DLEN)len++;
    index=0;
    for(i=L-1;i>=0;i-=DLEN){
    t=0;
    k=i-DLEN+1;
    if(k<0)k=0;
    for(int j=k;j<=i;j++)
    t=t*10+s[j]-'0';
    a[index++]=t;
    }
}
BigNum::BigNum(const BigNum &T):len(T.len){ //�������캯��
    int i;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
    a[i]=T.a[i];
}
BigNum & BigNum::operator=(const BigNum &n){ //���ظ�ֵ�����������֮�丳ֵ����
    int i;
    len=n.len;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
    a[i]=n.a[i];
    return *this;
}
istream& operator>>(istream &in,BigNum &b){
    char ch[MAXSIZE*4];
    int i=-1;
    in>>ch;
    int L=strlen(ch);
    int count=0,sum=0;
    for(i=L-1;i>=0;){
        sum=0;int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10){sum+=(ch[i]-'0')*t;}
    b.a[count]=sum;count++;
    }
    b.len=count++;
    return in;
}
ostream& operator<<(ostream& out,BigNum& b){ //������������
    int i;
    cout<<b.a[b.len-1];
    for(i=b.len-2;i>=0;i--){printf("%04d",b.a[i]);}
    return out;
}
BigNum BigNum::operator+(const BigNum &T)const //��������֮����������
{
    BigNum t(*this);
    int i,big;
    big=T.len>len?T.len:len;
    for(i=0;i<big;i++)
    {
    t.a[i]+=T.a[i];
    if(t.a[i]>MAXN)
    {
    t.a[i+1]++;
    t.a[i]-=MAXN+1;
    }
    }
    if(t.a[big]!=0)
    t.len=big+1;
    else t.len=big;
    return t;
}
BigNum BigNum::operator-(const BigNum &T)const //��������֮����������
{
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T)
    {
    t1=*this;
    t2=T;
    flag=0;
    }
    else
    {
    t1=T;
    t2=*this;
    flag=1;
    }
    big=t1.len;
    for(i=0;i<big;i++)
    {
    if(t1.a[i]<t2.a[i])
    {
    j=i+1;
    while(t1.a[j]==0)
    j++;
    t1.a[j--]--;
    while(j>i)
    t1.a[j--]+=MAXN;
    t1.a[i]+=MAXN+1-t2.a[i];
    }
    else t1.a[i]-=t2.a[i];
    }
    t1.len=big;
    while(t1.a[len-1]==0 && t1.len>1)
    {
    t1.len--;
    big--;
    }
    if(flag)t1.a[big-1]=0-t1.a[big-1];
    return t1;
}
BigNum BigNum::operator*(const BigNum &T)const //��������֮������
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i=0;i<len;i++)
    {
    up=0;
    for(j=0;j<T.len;j++)
    {
    temp=a[i]*T.a[j]+ret.a[i+j]+up;
    if(temp>MAXN)
    {
    temp1=temp-temp/(MAXN+1)*(MAXN+1);
    up=temp/(MAXN+1);
    ret.a[i+j]=temp1;
    }
    else
    {
    up=0;
    ret.a[i+j]=temp;
    }
    }
    if(up!=0)
    ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(ret.a[ret.len-1]==0 && ret.len>1)ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int &b)const //������һ�����������������
{
    BigNum ret;
    int i,down=0;
    for(i=len-1;i>=0;i--)
    {
    ret.a[i]=(a[i]+down*(MAXN+1))/b;
    down=a[i]+down*(MAXN+1)-ret.a[i]*b;
    }
    ret.len=len;
    while(ret.a[ret.len-1]==0 && ret.len>1)
    ret.len--;
    return ret;
}
int BigNum::operator%(const int &b)const //������һ�� int���͵ı�������ȡģ
{
    int i,d=0;
    for(i=len-1;i>=0;i--)
    d=((d*(MAXN+1))%b+a[i])%b;
    return d;
}
BigNum BigNum::operator^(const int &n)const //������n�η�����
{
    BigNum t,ret(1);
    int i;
    if(n<0)exit(-1);
    if(n==0)return 1;
    if(n==1)return *this;
    int m=n;
    while(m>1)
    {
    t=*this;
    for(i=1;(i<<1)<=m;i<<=1)
    t=t*t;
    m-=i;
    ret=ret*t;
    if(m==1)ret=ret*(*this);
    }
    return ret;
}
bool BigNum::operator>(const BigNum &T)const //��������һ�������Ĵ�С�Ƚ�
{
    int ln;
    if(len>T.len)return true;
    else if(len==T.len)
    {
    ln=len-1;
    while(a[ln]==T.a[ln]&&ln>=0)
    ln--;
    if(ln>=0 && a[ln]>T.a[ln])
    return true;
    else
    return false;
    }
    else
    return false;
}
bool BigNum::operator>(const int &t)const //������һ��int���͵ı����Ĵ�С�Ƚ�
{
    BigNum b(t);
    return *this>b;
}
void BigNum::print() //�������
{
    int i;
    printf("%d",a[len-1]);
    for(i=len-2;i>=0;i--)
    printf("%04d",a[i]);
    printf("\n");
}