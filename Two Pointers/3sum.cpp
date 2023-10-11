class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        vector<vector<int>>ans;

        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]= i;
        }
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int required = -1*(nums[i]+nums[j]);
                if(mp.count(required) && mp.find(required)->second > j){
                    ans.push_back({nums[i],nums[j],required});
                }
                j = mp.find(nums[j])->second;
            }
            i = mp.find(nums[i])->second;
        }
        return ans;


    }
};




// optimal approach using two pointers instead of map, since we have already sorted it, we can use two pointers and here we don't need duplicate answer so we are skipping duplicate elements

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorted the function so that we don't have to check both condition mp.find(nums[i]-val) and mp.find(val-nums[i])
        sort(nums.begin(),nums.end());

        if(nums.size() < 3){
            return {};
        }
        if(nums[0] > 0)return {};
        vector<vector<int>>ans;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > 0)break;
            if(i > 0 && nums[i] == nums[i-1])continue;
            int low = i+1,high = n-1;
            int sum = 0;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];

                if(sum > 0){
                    high--;
                }else if(sum < 0){
                    low++;
                }else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int last_low_occurence = nums[low],last_high_occurence = nums[high];
                    while(low < high && nums[low] == last_low_occurence){
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return ans;


    }
};
