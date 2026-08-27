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
        int low = 1;
        int high = n;
        int answer = -1;
        int current_guess;

        while(answer != 0){
            current_guess = low + (high - low) / 2;
            answer = guess(current_guess);

            if(answer == -1){
                --high;
            }

            else if(answer == 1){
                ++low;
            }
        }

        return current_guess;
    }
};