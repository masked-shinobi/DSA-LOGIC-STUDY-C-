#include <bits/stdc++.h>

using namespace std;

int main(){

    string str = "Sanjayisthestudentwithaura.";
    string s = "th";

    while(str.find(s) != str.npos){
        str.erase(s.find(s), s.length());
    }

    cout << str;

    return 0;
}