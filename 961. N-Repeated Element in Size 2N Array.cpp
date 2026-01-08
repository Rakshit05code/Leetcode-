class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                if(nums[i] == nums[j]) {
                    return nums[i];   
                }
            }
        }
        return -1; 
    }
};
