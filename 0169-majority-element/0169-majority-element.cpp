class Solution {
public:
    int findMajority(vector<int>& nums, int left, int right) {
        if (left == right) 
            return nums[left];
        
        int mid = left + (right - left) / 2;
        int lM = findMajority(nums, left, mid);
        int rM = findMajority(nums, mid + 1, right);

        if (lM == rM) 
            return lM;
        
        int lc = 0, rc = 0;

        for (int i = left; i <= right; i++) {
            if (nums[i] == lM) {
                lc++;
            }
            if (nums[i] == rM) {
                rc++;
            }
        }

        return (lc > rc) ? lM : rM;
    }

    int majorityElement(vector<int>& nums) {
        return findMajority(nums, 0, nums.size() - 1);
    }
};
