class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
       int open = 0;
       vector<int> ans;
       for(auto it : seq){
            if(it == '('){
                ans.push_back(open%2);
                open++;
            }else{
                if(open != 0){
                    open--;
                }
                ans.push_back(open%2);
            }
       }
       return ans;
    }
};