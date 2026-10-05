#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    getline(cin, s); // cin >> s for 1 word

    // comma as delimiter -- after getting the full word
    stringstream ss(s);
    string capture;
    vector<string> values;
    // on delimiter
    while(getline(ss, capture, ',')){
        values.push_back(capture);
    }
    ss.clear(); // if needed to reuse
    // just go through 
    while(ss>>capture){
        values.push_back(capture);
    }

    // timings : 12:30AM
    // declare everything with its own types to capture separately regardless of the commmas

    string str;
    cin >> str;

    cout << "hours :" << stoi(str.substr(0, 2))<< endl;
    cout << "minutes :" << stoi(str.substr(3, 5)) << endl;
    cout << "AM/PM :" << str.substr(5, 7) << endl;

    return 0;

    // string to word
    vector<string> words;
    string word;
    for (int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            word = word + s[i];
        }
        if(s[i] == ' '){
            words.push_back(word);
            word.clear();
        }
    }
    if(!word.empty()){
        words.push_back(word);
    }

    
    return 0;
}