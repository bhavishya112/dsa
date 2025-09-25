class Solution {
public:
    void sortColors(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        
    }
        void mergesort(vector<int> & array, int start, int end) {
        int mid = (start + end) / 2;

        if (start == end) {
            return;
        }

        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);
        merge(array, start, mid, end);
        }

            void merge(vector<int> & array, int start, int mid, int end) {
        int left[mid - start + 1];
        int right[end - mid];
        
        for (int i = start; i <= mid; i++) {
            left[i - start] = array[i];
        }
        for (int i = mid + 1; i <= end; i++) {
            right[i - mid - 1] = array[i];
        }
        
        int l = 0;
        int r = 0;
        int k = start;
        
        while (l <= mid - start && r <= end - mid - 1) {
            if (left[l] <= right[r]) {
                array[k++] = left[l++];
            } else {
                array[k++] = right[r++];
            }
        }
        
        while (l <= mid - start) {
            array[k++] = left[l++];
        }
        while (r <= end - mid - 1) {
            array[k++] = right[r++];
        }
    }
};