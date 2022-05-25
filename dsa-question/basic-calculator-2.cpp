#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int calculate(string s) {
    stack<int>st;
    
    int curr=0;
    bool prem=false,pred=false,neg=false;
    
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]>='0' && s[i]<='9'){
            curr = curr*10+(s[i]-'0');
        }
        else if(s[i]==' ')continue;
        else{
            if(prem){
                int x = st.top();
                st.pop();
                st.push(x*curr);
                prem = false;
            }
            else if(pred){
                int x = st.top();
                st.pop();
                if(curr==0)st.push(0);
                else
                st.push(x/curr);
                pred = false;
            }
            else{
                if(neg){
                    st.push(-curr);
                    neg = false;
                }
                else
                st.push(curr); 
            }
            curr=0;
            
            if(s[i]=='-')neg = true;
            else if(s[i]=='*')prem=true;
            else if(s[i]=='/') pred=true;
        }
    }
    int ans;
    if(prem){
        int x = st.top();
        st.pop();
        ans = x*curr;
    }
    else if(pred){
        int x = st.top();
        st.pop();
        if(curr==0)
            ans = 0;
        else
        ans = x/curr;
    }
    else{
        if(neg)ans = -curr;
        else
            ans = curr;
    }
    
    while(!st.empty()){
        int x = st.top();
        st.pop();
        
        ans += x;
    }
    return ans;
}

int main(){
    
}