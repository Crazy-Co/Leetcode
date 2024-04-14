class Solution {
public:
    bool isVowel(char v){
        v = tolower(v);
        return (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u');
    }

    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            } 
            while(!isVowel(s[i]) && i<j) i++;
            while(!isVowel(s[j]) && i<j) j--;   
        }
        return s;
    }
};