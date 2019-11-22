#include<bits/stdc++.h>
using namespace std;

int getBinary(int num) {
    int result = 0;
    int i =0;
    while(num!=0) {
        int tt = num%2;
        num /= 2;
        result += tt*pow(10,i);
        i++;
    }
    return result;
}

int main() {
    string inp;
    cin>>inp;
    map<string,int> val;
    string temp = "";
    int count = 1;
    for(auto i:inp) {
        temp += i;
        if(val.find(temp) == val.end()) {
            val[temp] = count;
            temp = "";
            count++;
        }
    }
    for(auto i: val) {
    string check;
    if(i.first.size() != 1)
    {  
        check = i.first.substr(0,i.first.size()-1);
        string substrval = to_string(getBinary(val[check]));
        string lastchar = to_string(getBinary(val[i.first.substr(i.first.size()-1,1)]));
        cout<<substrval+lastchar<<endl;
    }
    else {
        check = i.first;
         string singlechar = to_string(getBinary(val[check]-1));
         cout<<singlechar<<endl;
    } 
    }
}
