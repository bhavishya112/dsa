class Solution {
    public:
    void Swap(int &i,int &j){
        int temp = i;
        i = j;
        j = temp;
    }
    void rotate(vector<int> &nums, int k) {
        k = k%nums.size();
        if (k>0){
            // for(int x:nums){
            //     cout << x;
            // }
            // cout << endl << endl;

            reverse(nums,0,nums.size()-1);

            // for(int x:nums){
            //     cout << x;
            // }
            // cout << endl;

            reverse(nums,0,k-1);

            // for(int x:nums){
            //     cout << x;
            // }
            // cout << endl;

            reverse(nums,k,nums.size()-1);

            // for(int x:nums){
            //     cout << x;
            // }
            cout << endl;
        }
    }
    void reverse(vector<int> &arr,int start,int end){
        int p1 = start;
        int p2 = end;

        while (p1<p2){
            Swap(arr[p1++],arr[p2--]);
        }
    }
};