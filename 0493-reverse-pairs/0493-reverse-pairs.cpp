class Solution {
    private:
   
        int mergeSort(vector<int>& nums, int l , int r){
            if (l >= r) return 0;
            int mid = l + (r - l)/2;

            int count = mergeSort(nums, l, mid);
            count += mergeSort(nums, mid + 1, r);

            int j = mid + 1;
            for (int i = l; i <= mid; i++) {
                while (j <= r &&
                    (long long)nums[i] > 2LL * nums[j]) {
                    j++;
                }
                count += j - (mid + 1);
            }

            // merge arrays
            vector<int> temp;
            int i = l;
            j = mid + 1;

            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    temp.push_back(nums[i++]);
                } else {
                    temp.push_back(nums[j++]);
                }
            }

            while (i <= mid) 
                temp.push_back(nums[i++]);
            while (j <= r) 
                temp.push_back(nums[j++]);

            for (int k = l; k <= r; k++) {
                nums[k] = temp[k - l];
            }

            return count;
        }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};