#include<iostream>
#include<vector>
using namespace std;

string s;
vector<string>ans;

void fun(int n,int i,int open){
    if(i>n){
        ans.push_back(s);
        return;
    }
    if(open-(i-open)!=n-i){
        s.push_back('(');
        fun(n,i+1,open+1);
        s.pop_back();
    }
    if(open-(i-open-1)){
        s.push_back(')');
        fun(n,i+1,open);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    s.clear();
    ans.clear();
    fun(2*n,1,0);
    return ans;
}

int main(){
    
}