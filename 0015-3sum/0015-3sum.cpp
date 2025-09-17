class Solution {
public:
vector<vector<int>> twoSum(vector<int> nums, int start, int target) {
    vector<vector<int>> Result;
    int low = start, high = nums.size() - 1;

    while (low < high) {
        int sum = nums[low] + nums[high];

        if (sum < target) {
            ++low;
        } else if (sum > target) {
            --high;
        } else {
            Result.push_back({nums[low], nums[high]});
            ++low;
            --high;

            // Skip duplicates AFTER pushing
            while (low < high && nums[low] == nums[low - 1]) ++low;
            while (low < high && nums[high] == nums[high + 1]) --high;
        }
    }

    return Result;
}

vector<vector<int>> threeSum(vector<int> nums){
    vector<vector<int>> Result;

    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size();i++){
        if (i>0 && nums[i-1] == nums[i]){
            continue;
        }
        
        vector<vector<int>> result = twoSum(nums,i+1,0-nums[i]);
        for(vector<int> x:result){
            Result.push_back({nums[i],x[0],x[1]});
        }
    }

    return Result;
}
};