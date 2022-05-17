#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string ans;
    
    for(int i=s.length()-1 ; i>=0 ; i--){
        if(s[i]==' ')continue;
        string temp;
        while(i>=0 && s[i]!=' '){
            temp.push_back(s[i]);
            i--;
        }
        reverse(temp.begin(),temp.end());
        ans.append(" "+temp);
    }
    if(ans.length())return ans.substr(1);
    return ans;
}

int main(){

}