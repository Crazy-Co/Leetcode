class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
            string s = "";
            string temp="";
            
        while(n){
            if(n%26) temp += char(n%26 + 64); // A = 65
            else if(n%26 == 0 || n==26){
                temp+= char(90); // Z = 90
            }
            s.insert(0,temp);
            n = n - (n%26 ? n%26 : 26);
            n/=26;
            temp="";
        }

        // CA = 3*26+1 = 79
        // 78/26 = 3
        // 52 = 26*1 + 26 // AZ 
        // 701 = 26*26 + 25 // Y
        return s;
    }
};