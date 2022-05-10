#include<iostream>
#include<vector>
using namespace std;

/*
***************************************Method 1*******************
complexity - O(nlogn)

*/
int leftBinarySearch(vector<int>&height,vector<int>&left,int x){
    int low=0,high=left.size()-1,mid,ans=high;
    
    while(low<=high){
        mid = (low+high)/2;
        if(height[left[mid]]>=x){
            ans = left[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int rightBinarySearch(vector<int>&height,vector<int>&right,int x){
    int low=0,high=right.size()-1,mid,ans=high;
    
    while(low<=high){
        mid = (low+high)/2;
        if(height[right[mid]]>=x){
            ans = right[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int maxArea(vector<int>& height) {
    int ans=0,n=height.size(),i;
    vector<int>leftGreater(n),rightGreater(n);
    vector<int>left,right;
    
    leftGreater[0] = -1,rightGreater[n-1]=-1;
    left.push_back(0);
    right.push_back(n-1);
    
    for(i=1 ; i<n ; i++){
        if(height[left[left.size()-1]]<height[i]){
            leftGreater[i] = -1;
            left.push_back(i);
        }
        else{
            leftGreater[i] = leftBinarySearch(height,left,height[i]);
        }
    }
    
    for(i=n-2 ; i>=0 ; i--){
        if(height[right[right.size()-1]]<height[i]){
            rightGreater[i] = -1;
            right.push_back(i);
        }
        else{
            rightGreater[i] = rightBinarySearch(height,right,height[i]);
        }
    }
    
    for(i=0 ; i<n ; i++){
        if(leftGreater[i]!=-1){
            ans = max(ans,height[i]*(i-leftGreater[i]));
        }
        if(rightGreater[i]!=-1){
            ans = max(ans,height[i]*(rightGreater[i]-i));
        }
    }
    
    return ans;
}

/*
**********************************Method 2*************************
conmplexity => O(n)
(2 Pointer Approach)
description => lets start with i=0,j=n-1 , our ans is min(height[i],height[j])*(j-i)
               now try to maximize it, if we were to move our any one pointer by 1 
               then which one would it be?

*/

int maxArea(vector<int>& height) {
    int n=height.size(),ans=0;
    
    int i=0,j=n-1;
    
    while(i<j)
    {
        int curr=min(height[i],height[j])*(j-i);
        ans=max(ans,curr);
        
        if(height[i]<height[j])
            i++;
        else if(height[i]>height[j])
            j--;
        else{
            if(height[i+1]<height[j-1])
                j--;
            else
                i++;
        }
    }
    
    return ans;
}