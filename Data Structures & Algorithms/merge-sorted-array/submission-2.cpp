#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int current = m + n - 1;
        --m;
        --n;
        
        while(m >= 0 && n >= 0){

            if(nums1[m] > nums2[n]){
                nums1[current] = nums1[m];
                --m;
            }
            
            else{
                nums1[current] = nums2[n];
                --n;
            }

            current--;
        }

        while(n >= 0){
            nums1[current] = nums2[n];
            --n;
            --current;
        }
        
    }
};