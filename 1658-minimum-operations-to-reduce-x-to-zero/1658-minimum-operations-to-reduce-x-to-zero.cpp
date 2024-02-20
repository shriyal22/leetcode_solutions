class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto num: nums){
            sum+=num;
        }
        int target = sum-x, curr=0;
        int i=0, j=0;
        int len = -1;
        while(j<nums.size()){
            curr += nums[j];
            while(i<=j && curr>target){
                curr-=nums[i];
                i++;
            }
            if(curr == target) len = max(len, j-i+1);
            j++;
        }
        if(len==-1) return -1;
        else return nums.size()-len;
    }
};