#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int>left(n),right(n);
    
    {stack<int>s;
    s.push(0);
    left[0]=-1;
    for(int i=1 ; i<n ; i++){
        while(!s.empty()){
            if(heights[s.top()]<heights[i])break;
            s.pop();
        }
        if(s.empty()){
            left[i] = -1;
            s.push(i);
        }
        else{
            left[i] = s.top();
            s.push(i);
        }
    }}
    {
        stack<int>s;
    s.push(n-1);
    right[n-1] =n;
    for(int i=n-2 ; i>=0 ; i--){
        while(!s.empty()){
            if(heights[s.top()]<heights[i])break;
            s.pop();
        }
        if(s.empty()){
            right[i] = n;
            s.push(i);
        }
        else{
            right[i] = s.top();
            s.push(i);
        }
    }}
    int ans=0;
    
    for(int i=0 ; i<n ; i++){
        int width = 1+(i-left[i]-1)+(right[i]-i-1);
        ans = max(ans,heights[i]*width);
    }
    return ans;
}

int main(){
    
}