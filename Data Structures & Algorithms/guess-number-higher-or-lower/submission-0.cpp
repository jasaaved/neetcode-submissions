/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int g = n / 2;
        int answer = -1;

        while(answer != 0){
            answer = guess(g);

            if(answer == -1){
                --g;
            }
            else if(answer == 1){
                ++g;
            }
        }

        return g;
    }
};