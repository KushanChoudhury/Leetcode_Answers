class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=to_string(board[i][j]);
            }
        }
        string target="123450";
        queue<string> q;
        q.push(start);
        unordered_map<int,vector<int>> map;
        map[0]={1,3};
        map[1]={0,2,4};
        map[2]={1,5};
        map[3]={0,4};
        map[4]={1,3,5};
        map[5]={2,4};
        unordered_set<string> visited;
        visited.insert(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                int idx=curr.find('0');
                for(int swapIdx : map[idx]){
                    string newState=curr;
                    swap(newState[idx],newState[swapIdx]);
                    if(visited.find(newState)==visited.end()){
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
                
            }
            level++;
        }
        return -1;
    }
};