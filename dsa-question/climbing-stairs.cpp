#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n) {
    if(n==1)return 1;
    if(n==2)return 2;
    
    int p1=1,p2=2,curr=3;
    
    for(int i=3 ; i<=n ; i++){
        curr = p1+p2;
        p1 = p2;
        p2 = curr;
    }
    return curr;
}

int main(){
    
}