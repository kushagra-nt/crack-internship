#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minDifference(vector<int>&choco,int m){
    int n = choco.size();
    sort(choco.begin(),choco.end());

    int ans= choco[m-1]-choco[0];

    for(int i=m ; i<n ; i++) ans = min(ans,choco[i]-choco[i-m+1]);

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>choco(n);

    for(int i=0 ; i<n ; i++)cin>>choco[i];

    cout<<minDifference(choco,m);

    return 0;
}