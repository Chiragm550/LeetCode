class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i=0, j=0;
        int total = 0;
        int f_tot = m*n;
        int inside = 0;

        vector<int> v;
        while(total < f_tot){
            if(i<m && j<n){
                int k=i;
                for(; k<m; k++){
                    v.push_back(matrix[j][k]);
                    total++;
                    i++;
                }
            }
            else if(i==m && j<n){
                int k = j+1;
                j++;
                for(; k<n; k++){
                    v.push_back(matrix[k][i-1]);
                    total++;
                    j++;
                }
                // cout << endl << i << ' ' << j << ' ' << m << ' ' << n << endl;
            }
            else if(i==m && j==n){
                int k = i-2;
                i = i - 1;
                // cout << endl << i << ' ' << j << ' ' << k <<  endl;
                for(; k >= inside; k--){
                    // cout << endl << i << ' ' << j << ' ' << k << endl;
                    v.push_back(matrix[j-1][k]);
                    total++;
                    i--;
                }
                // cout << endl << i << ' ' << j << total << endl;
            }
            else if(i==inside && j==n){
                int k = j-2;
                j -= 1;
                // cout << endl << i << ' ' << j << endl;
                for(; k>inside; k--){
                    v.push_back(matrix[k][i]);
                    total++;
                    j--;
                }
                i = j;
                n--;
                m--;
                inside += 1;
            }
        }
        return v;
    }
};