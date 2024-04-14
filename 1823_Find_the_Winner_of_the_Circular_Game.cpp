class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);
        for(int i=0; i<n; i++){
            friends[i]=i+1;
        }
        int i=0, size = friends.size();
        while(size != 1){
            i = ((k+i)%size) ? ((k+i)%size - 1) : (size - 1);
            friends.erase(friends.begin()+i);
            size--;
        }
        return friends[0];
    }
};