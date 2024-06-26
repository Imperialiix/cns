#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

long long modexp(int base , int exp ,int mod){
    long long res = 1;
    base = base%mod;
    if(base == 0){
        return 0;
    }
    while(exp>0){
        if(exp%2==1){
            res = (res*base)%mod;
        }
        exp = exp/2;
        base = (base*base)%mod;
    }
    return res;
}

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

 vector<long long> encrypt(string &message,int e,int n){
        vector<long long>v;
        for (char c:message){
            long long m = static_cast<long long>(c);
            v.push_back(modexp(m,e,n));
        }
        return v;
    }

    string decrypt(vector<long long> encryptedmsg,int e ,int n){
        string res="";
        for(long long num : encryptedmsg){
            long long temp = modexp(num,e,n);
            char ch = static_cast<char>(temp);
            res.push_back(ch);
        }
        return res;
    }

    void deffie(){
        int q =7 , alpha =5, xa = 3, xb=4;
        long long ya = modexp(alpha,xa,q);
        long long yb=modexp(alpha,xb,q);
        long long ka = modexp(yb,xa,q);
        long long kb = modexp(ya,xb,q);
        cout<<ya<<endl;
        cout<<yb<<endl;
        cout<<"key of a "<<ka<<endl;
        cout<<"key of b "<<kb<<endl;

    }

int main(){
    int p = 13;
    int q=17;
    int e=34;
    int n=p*q;
    int phi = (p-1)*(q-1);
    while(gcd(e,phi)!=1){
        e++;
    }
    int k=0,d;
    while (true)
    {
       if((1+k*phi)%e == 0){
        d=(1+k*phi)/e;
        break;
       }
       k++; 
    }
    string message = "helloworld";
    vector<long long> encryptedmsg = encrypt(message,e,n);
    string decryptedmessage=decrypt(encryptedmsg,d,n);
    cout<<"public key  "<<e<<endl;
    cout<<"private key  "<<d<<endl;
    cout<<"message  "<<message<<endl;
    cout<<"encrypted message  ";
    for(long long num : encryptedmsg){
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<"decryptedmessage  "<<decryptedmessage<<endl;

    deffie();
    
}