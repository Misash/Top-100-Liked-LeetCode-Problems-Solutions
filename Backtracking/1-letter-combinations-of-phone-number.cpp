#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<char, string> pl;


void func(string &current, int index, string &digits, vector<string> &res) {
    if (index == digits.length()) {
        res.push_back(current);
        return;
    }

    for (char letter : pl[digits[index]]) {
        current.push_back(letter);     
        func(current, index + 1, digits, res); 
        current.pop_back();            
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        
        pl['2'] = "abc";
        pl['3'] = "def";
        pl['4'] = "ghi";
        pl['5'] = "jkl";
        pl['6'] = "mno";
        pl['7'] = "pqrs";
        pl['8'] = "tuv";
        pl['9'] = "wxyz";
        
        vector<string> res;   
        string current = "";  
        
        func(current, 0, digits, res);
        
        return res;
    }
};

int main() {
    string digits = "234";
    Solution sol;

    vector<string> combinations = sol.letterCombinations(digits);


    for (const string &comb : combinations) {
        cout << comb << " ";
    }

    return 0;
}
