#include<iostream>
#include<vector>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z){
    vector<int>v(n+1,0);
    v[0] =0;
    
    for(int i=1 ; i<=n ; i++){
        if(x<i && v[i-x])v[i] = max(v[i],v[i-x]+1);
        if(y<i && v[i-y])v[i] = max(v[i],v[i-y]+1);
        if(z<i && v[i-z])v[i] = max(v[i],v[i-z]+1);
        if(!v[i]){
            if(i==x)v[i]=1;
            if(i==y)v[i]=1;
            if(i==z)v[i]=1;
        }
    }
    return v[n];
}

int main(){
    
}