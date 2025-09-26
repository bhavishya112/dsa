class Solution {
public:
    int maxArea(vector<int>& height) {
        int h1 = 0, h2 = height.size()-1;
        int MaxArea = 0;

        while(h1<h2){
            int area = (h2-h1)*min(height[h1],height[h2]);
            if (area>MaxArea){
                MaxArea = area;
            }

            if (height[h1]<height[h2]){
                h1++;
            }
            else{
                h2--;
            }
        }
        return MaxArea;
    }
};