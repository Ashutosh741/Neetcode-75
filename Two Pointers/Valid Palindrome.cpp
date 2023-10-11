class Solution {
public:
    bool palindrome(string s){
        int left = 0, right = s.length()-1;
        while(left < right){
            if(s[left] != s[right])return false;
            else {
                left++,right--;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string check;
        int n = s.length();
        for(int i=0;i<n;i++){
            if((s[i] -'a' >= 0 && s[i]-'a' < 26) || (s[i] -'A' >= 0 && s[i]-'A' < 26) || (s[i]-'0' >= 0 && s[i]-'0' < 10) ){
                check+=tolower(s[i]);
            }
        }
        cout<<check<<endl;
        if(palindrome(check))return true;
        else return false;
    }
};


// optimal approach

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        int n = s.length();
        while(i < j){
            while(i< j && !iswalnum(s[i]))i++;
            while(j>0 && !iswalnum(s[j]))j--;
            if(iswalnum(s[j]) && iswalnum(s[i])){
            if(tolower(s[i]) != tolower(s[j]))return false;
            }
            i++,j--;
        }
        return true;

    }
};
