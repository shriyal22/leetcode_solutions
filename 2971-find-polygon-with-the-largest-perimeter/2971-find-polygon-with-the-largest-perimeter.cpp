class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int num:nums) sum+=num;
        sort(nums.begin(), nums.end());
        // 1, 1, 2, 3, 5, 12, 50
        int flag = 0;
        for(int i=n-1;i>=2;i--){
            sum -= nums[i];
            if(sum > nums[i]){
                return nums[i]+sum;
            }
        }
        return -1;
    }
};