class Solution {
public:
vector<int> twoSumClosest(vector<int> nums, int start,int target) {
    
    // sort(nums.begin(),nums.end());
    int low = start, high = nums.size() - 1;
    int p1,p2;
    int ResDiff = 1e9;
    
    while (low < high) {
        int sum = nums[low] + nums[high];
        // cout << low << " "<< high << endl;
        // cout << " _ " << sum << endl;
        // p1 = low,p2 = high;
        if (abs(sum-target)<ResDiff){
            ResDiff = abs(sum-target);
            p1 = low,p2 = high;
        }

        if (sum < target) {
            low++;
            while (low < high && nums[low] == nums[low - 1]) low++;

        } else if (sum > target) {
            high--;
            while (low < high && nums[high] == nums[high + 1]) high--;

        } else {
            return {nums[low],nums[high]};
        }
    }
    // cout << p1 << p2;
    // cout << low << " "<<high<<endl;
    return {nums[p1],nums[p2]};
}

int threeSumClosest(vector<int>& nums,int target){
    int ResSum;
    int ResDiff = 1e9;
    
    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size()-2;i++){

        // cout << i;
        if (i>0 && nums[i-1] == nums[i]){
            continue;
        }
        // cout << " "<<nums[i];
        vector<int> result = twoSumClosest(nums,i+1,target-nums[i]);
        // cout << result[0]<<result[1]<<endl;
        int sum = nums[i]+result[0]+result[1];
        int diff = abs(sum-target);
        // cout << diff<<endl;
        if (diff<ResDiff){
            // cout << "yes";
            ResDiff = diff;
            ResSum = sum;
        }
        
        // if (sum>target){
        //     break;
        // }
        
        // cout << ResSum << endl;


    
        }

    // cout << ResSum;
    // cout << "i: "<<i<<endl;
    return ResSum;
}
};