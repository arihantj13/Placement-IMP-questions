// 17. Letter Combinations of a Phone Number
#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans, string& output, string* mapping, string digits, int index){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(ans, output, mapping, digits, index+1);
        output.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if(digits.length() == 0)
        return ans;

    solve(ans, output, mapping, digits, index);
    return ans;
}

int main(){
    string str = "23";
    vector<string> ans = letterCombinations(str);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout<< endl;
    return 0;
}