// method 1 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for( int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int sum = 0;
                for(int k = i;k<=j;k++){
                    sum+=nums[k];
                }
                if(sum == k){
                    cnt++;
                }    
            }
        }
        return cnt;
        
    }
};

// method 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for( int i = 0; i<nums.size();i++){
            int sum = 0;
            for( int j = i ;j<nums.size();j++){
                sum += nums[j];
                if(sum == k) cnt++;
            }
            
        }
        return cnt;
    }
};