#include<iostream>
#include<vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    vector<int>sum(n);
    sum[0] = cardPoints[0];
    int ans=0;
    
    for(int i=1 ; i<n ; i++)sum[i] = sum[i-1]+cardPoints[i];
    
    for(int i=0 ; i<=k ; i++){
        int curr=0;
        
        //from front
        if(i>0)
            curr = sum[i-1];
        
        //from back
        curr += sum[n-1]-((n==k && i==0)?0:sum[n-1-(k-i)]);
        
        ans = max(ans,curr);
    }
    return ans;
}

int main(){

    

}