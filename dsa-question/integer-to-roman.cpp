#include<iostream>
using namespace std;

string intToRoman(int num) {
    string ans;
    
    int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    
    int i=0;
    
    while(num){
        while(num>=val[i]){
            num -= val[i];
            ans += roman[i];
        }
        i++;
    }
    
    return ans;
}

int main(){
    
}