#include <iostream>
#include<vector>
#include<string>
using namespace std;
#define V 9

int chartoint(char c){
    return c-'A';
}

char inttochar(int i){
    return static_cast<char>('A'+(i%26));
}

void convert(string key , vector<vector<int>>&keymat,vector<int>&intct,string pt)
{
    int k=0;
    for (int i=0;i<3;i++)
    {
        vector<int>v;
        for(int j=0;j<3;j++)
        {
          v.push_back(chartoint(key[k++])); 
        }
        keymat.push_back(v);
    }

    for(int i=0;i<pt.size();i++)
    {
        intct.push_back(chartoint(pt[i]));
    }
}

void matmul(vector<vector<int>>&keymat,vector<int>&intct,vector<int>&resmat)
{
    
    for(int i=0;i<3;i++){
        int s=0;
        vector<int>v;
        for(int j=0;j<3;j++){
           int mul = keymat[i][j]*intct[j];
           s=s+mul; 
        }
        resmat.push_back(s);
    }
}

void print(vector<int>&resmat){
    for(int no:resmat){
        cout<<inttochar(no);
    }
}

int main()
{
    string key = "";
    string pt;
    vector<vector<int>>keymat;
    vector<int>resmat;
    vector<int>intct;
    cout<<"enter key";
    cin>>key;
    cout<<"enter plain text";
    cin>>pt;
    convert(key,keymat,intct,pt);
    matmul(keymat,intct,resmat); 
    print(resmat);

}