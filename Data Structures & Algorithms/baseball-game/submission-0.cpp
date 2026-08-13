#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int total_score = 0;
        stack<string> scores;

        for(string& s : operations){
            if(s == "C"){
                total_score -= stoi(scores.top());
                scores.pop();
            }

            else if(s == "+"){
                int second = stoi(scores.top());
                scores.pop();
                int first = stoi(scores.top());
                scores.pop();
                int third = first + second;
                total_score += third;

                scores.push(to_string(first));
                scores.push(to_string(second));
                scores.push(to_string(third));
            }

            else if(s == "D"){
                int new_score = stoi(scores.top()) * 2;
                total_score += new_score;
                scores.push(to_string(new_score)); 
            }

            else{
                total_score += stoi(s);
                scores.push(s);
            }

        }

        return total_score;
    }
};