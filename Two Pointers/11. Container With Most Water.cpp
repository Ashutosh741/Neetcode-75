class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int mini = 0;
        int area = 0;
        
        while(left < right){
            mini = min(height[left],height[right])*(right-left);
            area = max(area,mini);
            
            if(height[left] > height[right]){
                right--;
            }else if(height[left] < height[right]){
                left++;
            }else{
                left++,right--;
            }
        }
        return area;
    }
};

// i was multiplying it before, so complexity reduces
