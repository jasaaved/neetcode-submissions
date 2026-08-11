class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int bill : bills){
            if(bill == 5){
                ++five;
            }

            else if(bill == 10){
                ++ten;
                --five;
            }
            
            else{
                int change = 15;
                if(ten > 0){
                    --ten;
                    change -= 10;
                }

                while(change > 0){
                    --five;
                    change -= 5;
                }
            }

            if(five < 0){
                return false;
            }
        }
        
        return true;
    }
};