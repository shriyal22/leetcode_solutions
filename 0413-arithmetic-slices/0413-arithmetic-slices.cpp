class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
    
        int diff = nums[1] - nums[0];
        int ans = 0, temp=0;
        for(int i=2;i<n;i++){
            int d = nums[i]-nums[i-1];
            if(d==diff) temp++;
            else{
                diff=d;
                temp=0;
            }
            ans += temp;
        }
        return ans;
    }
};