class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        string prefix="";
        for(int i=0;i<strs[0].length();i++       )
{
  char h =strs[0][i];
  for(string s:strs){
  if(h==s[i]){
    continue;
  }
  else{
    return prefix;
  }
  }
  prefix +=h;
}   
return prefix;
 }
};