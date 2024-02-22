class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n==1) return 1;
        vector<int> outdegree(n+1, 0);
        vector<int> indegree(n+1, 0);

        for(auto it: trust){
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};