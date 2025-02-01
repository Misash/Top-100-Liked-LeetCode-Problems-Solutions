#include <iostream>
#include <vector>
#include <map>
#include <string> 

using namespace std;

string simbol = "()";
int value[] = {1,-1};


void backtracking(string &combination, int index, int n, vector<string> &res) {
    if (index == n * 2) {
        if(){

        }
        res.push_back(combination);
        cout<<"\n\n"<<(combination);
        return;
    }

    for (char letter : simbol) {
        combination.push_back(letter);
        backtracking(combination, index + 1, n, res); 
        combination.pop_back();           
    }
}


// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
        
//     }
// };

int main(){

    string c = "";
    int index = 0;
    int n = 1;
    vector<string> res;

    backtracking(c,index,n,res);

    cout<<"otro valor\n";

    for (const string &comb : res) {
        cout << comb << " ";
    }

}


