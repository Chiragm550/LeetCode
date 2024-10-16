class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>Pascal;
        for(int i=0; i<numRows; i++){
            vector<int> row;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i)
                    row.push_back(1);
                else{
                    row.push_back(Pascal[i-1][j] + Pascal[i-1][j-1]);
                }
            }
            Pascal.push_back(row);
        }
        return Pascal;
    }
};

//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1 