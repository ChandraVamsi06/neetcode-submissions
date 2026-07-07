class Solution {
public:
    int countSplits(vector<int> &nums, int val) {
        int n = nums.size();
        int sum = 0, res = 1;
        for(int i = 0; i < n; i++) {
            if(sum + nums[i] > val) {
                res++;
                sum = 0;
            }
            sum += nums[i];
        }
        // if(res != 0) res++;
        return res;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int res;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int splits = countSplits(nums, mid);
            if(splits > k) low = mid + 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return low;
    }
};