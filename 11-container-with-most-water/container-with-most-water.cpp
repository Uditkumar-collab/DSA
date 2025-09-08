class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0; //ans
        int lp =0;
        int rp = height.size()-1;
        while(lp<rp){
            int w = rp-lp;
            int ht = min(height[lp] , height[rp]);

            int currwater = w*ht;
            maxwater = max(maxwater ,currwater);

            if(height[lp]<height[rp])
            lp++;
            else
            rp--;
        }
        return maxwater;
    }
};