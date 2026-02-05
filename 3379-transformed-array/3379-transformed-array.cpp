class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);

        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {        // positive
                res[i] = arr[(i + arr[i]) % n];
            } else if(arr[i] < 0) {     // negative
                int idx = (i + arr[i]) % n;
                if(idx < 0) {
                    idx += n;
                }
                res[i] = arr[idx];
            } else {        // arr[i] == 0
                res[i] = arr[i];
            }
        }

        return res;
    }
};