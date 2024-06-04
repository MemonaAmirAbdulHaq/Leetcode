class Solution {
public:
 bool isVowels(char c){
     return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
 }
    string reverseVowels(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            while(left<right && !isVowels(s[left])) left++;
            while(left<right && !isVowels(s[right])) right--;
            swap(s[left],s[right]);
            left++ ,right--;
        }
        return s;
        
    }
};