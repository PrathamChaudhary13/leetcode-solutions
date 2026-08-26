class Solution {
public:
    bool isPalindrome(string s) {
         transform(s.begin(), s.end(), s.begin(), ::tolower);
         int l=0;
         int r = s.length()-1;
         if(s == " ")
         return true;
         while(l<=r){
             while (l<r && !isalnum(s[l]))
                l++;
            
            while (l<r && !isalnum(s[r]))
                r--;
        
            if(s[l] != s[r])
            return false;
            l++;
            r--;
         }
         return true;
    }
};