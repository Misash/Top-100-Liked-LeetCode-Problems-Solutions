#include <iostream>
#include <vector>
#include <map>
#include <string> 

using namespace std;

map<char, int> value;
map<char, int> reps;


string simbol = "()";

void backtracking(string &combination, int index, int n, vector<string> &res, int& sum) {
    if (index == n * 2) {
        if( !sum && (reps['('] == reps[')']) ){
            res.push_back(combination);
        }
        return;
    }
    for (char letter : simbol) {
        int prevsum = sum;
        if(value[letter] == 1){
            sum += value[letter];
        }else{
            sum += (sum > 0) ? value[letter]: 0;
        }
        reps[letter]++;
        combination.push_back(letter);
        cout<<"\n\n"<<combination<<"\t"<<sum;
        backtracking(combination, index + 1, n, res, sum); 
        reps[letter]--;
        sum = prevsum;
        combination.pop_back();           
    }
}


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string c = "";
        int index = 0;
        int sum = 0;
        vector<string> res;

        value['('] = 1;
        value[')'] = -1; 
        reps['('] = 0;
        reps[')'] = 0; 

        backtracking(c,index,n,res,sum);

        return res;
    }
};

int main(){

    Solution sol = Solution();
    vector<string> res = sol.generateParenthesis(3);

    for (const string &comb : res) {
        cout << comb << " , ";
    }
}


