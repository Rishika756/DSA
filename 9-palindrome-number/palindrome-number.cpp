class Solution {
public:
    bool isPalindrome(int x) {
        int ori = x;
        long rev = 0;
        int rem;
        while(x>0){
            rem = x%10;
            if(ori>0){
                rev = (rev*10) + rem;
            }
            x = x/10;
        }
        if(rev == ori){
            return true;
        }
        else{
            return false;
        }
    }
};