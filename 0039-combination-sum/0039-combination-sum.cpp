class Solution {
public:
    void find(vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp, int sum, int target, int index) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size()) {
            return;
        }
        if(sum > target) {
            return;
        }
        find(candidates, ans, temp, sum, target, index + 1);
        sum += candidates[index];
        temp.push_back(candidates[index]);
        find(candidates, ans, temp, sum, target, index);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;

        find(candidates, ans, temp, sum, target, 0);
        return ans;

    }
};