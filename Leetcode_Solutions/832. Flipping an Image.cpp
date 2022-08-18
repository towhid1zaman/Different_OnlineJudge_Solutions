class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& images) {
        vector< vector<int> >ans;
        for(auto &image:images){
            reverse(image.begin(), image.end());
            for(auto &imageDetail:image){
                imageDetail ^= 1; // toggle
            }
            ans.push_back(image);
        }
        return ans;
    }
};
