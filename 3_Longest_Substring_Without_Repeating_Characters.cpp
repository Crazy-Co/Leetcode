#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char, int> map;
    int ans = 0, i = 0, j = 0;

    if(n == 0) return 0;
    while (j < n){
        for (int k = i; k <= j; k++)
        {
            if (map[s[k]] == 0){
                ans = max(k-i+1, ans);
                map[s[k]]++;
            }else{
                i++;
                break;
            }

            if (k == j){
                j++;
                break;
            }
        }
        map.clear();
    }

    return ans;
}

int main()
{
    string s = "pwwkew";
    int x = lengthOfLongestSubstring(s);
    cout<< x << endl;
    return 0;
}