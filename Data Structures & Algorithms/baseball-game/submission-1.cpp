#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int total_score = 0;
        stack<int> scores;

        for(string& s : operations){
            if(s == "C"){
                total_score -= scores.top();
                scores.pop();
            }

            else if(s == "+"){
                int first = scores.top();
                scores.pop();

                int second = scores.top();
                
                scores.push(first);

                int third = first + second;
                total_score += third;
                scores.push(third);
            }

            else if(s == "D"){
                int new_score = scores.top() * 2;
                total_score += new_score;

                scores.push(new_score); 
            }

            else{
                int score = stoi(s);
                total_score += score;
                scores.push(score);
            }

        }

        return total_score;
    }
};