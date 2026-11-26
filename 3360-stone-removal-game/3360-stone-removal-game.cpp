class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10 ) return false;
        
        int prevRemove = 10;
        bool flag = true;

        while(prevRemove <= n) {
            n -= prevRemove;
            prevRemove--;

            flag = !flag;
        }

        return !flag;
    }
};