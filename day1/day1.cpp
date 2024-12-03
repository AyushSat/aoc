#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

vector<string> split(string str, char delim){
    vector<string> res;
    size_t pos = str.find(delim);
    while(pos != string::npos){
        if(str.substr(0, pos) != ""){
            res.push_back(str.substr(0, pos));
        }
        str = str.substr(pos + 1);
        pos = str.find(delim);
    }
    if(str != ""){
        res.push_back(str.substr(0, pos));
    }
    return res;
}

int main() {
    string line;
    vector<int> left;
    unordered_map<int, int> right;
    while (getline(cin, line)) {
        vector<string> parts = split(line, ' ');
        left.push_back(stoi(parts.at(0)));
        if(right.find(stoi(parts.at(1))) == right.end()){
            right[stoi(parts.at(1))] = 0;
        }
        right[stoi(parts.at(1))] += 1;
    }

    int res = 0;
    for(int i = 0;i < left.size();i++){
        if(right.find(left.at(i)) != right.end()){
            res += left.at(i) * right.at(left.at(i));
        }
    }

    cout << res << endl;
    
    return 0;
}