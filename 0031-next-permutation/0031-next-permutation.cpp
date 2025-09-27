class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = nums.size() - 1;

        // Find the first index from the end where nums[p-1] < nums[p]
        while (p > 0 && nums[p] <= nums[p - 1]) p--;

        if (p == 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        p--; // This is the breakpoint

        // Find the smallest number greater than nums[p] to the right
        int idx_smallest = p + 1;
        for (int i = p + 1; i < nums.size(); i++) {
            if (nums[i] > nums[p] && nums[i] <= nums[idx_smallest]) {
                idx_smallest = i;
            }
        }

        swap(nums[p], nums[idx_smallest]);
        reverse(nums.begin() + p + 1, nums.end());
    }
};
