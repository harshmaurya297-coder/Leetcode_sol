class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int count = 0, n = img1.size();
        vector<pair<int,int>> v1, v2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1)
                    v1.push_back({i, j});
                if(img2[i][j] == 1)
                    v2.push_back({i, j});
            } 
        }
        map<pair<int, int>, int> mp;
        for(auto it : v1){
            for(auto i : v2){
                mp[{it.first - i.first, it.second - i.second}]++;
            }
        }

        for(auto it : mp)
            count = max(it.second, count);
        
    return count;
    }
};