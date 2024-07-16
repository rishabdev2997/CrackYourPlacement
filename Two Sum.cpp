class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> result;
        int n = arr.size();
        for( int i = 0;i<n;i++){
            for( int j = i+1;j<n;j++){
                if(arr[i]+arr[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;

    }
};