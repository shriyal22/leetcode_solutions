class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;

        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(auto num: nums) pq.push(num*num);
        // for(int i=0;i<nums.size();i++){
        //     nums[i] = pq.top();
        //     pq.pop();
        // }
        // return nums;
    }
};