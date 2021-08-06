#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param matrix int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> SpiralMatrix(vector<vector<int> >& matrix) {
        // write code here
      int rs = 0, cs = 0, re = matrix.size() - 1, ce = matrix[0].size() - 1;
      vector<int> res;
      while (cs <= ce && rs <= re) {
        for (int i = cs; i <= ce; i++){
          res.push_back(matrix[rs][i]);
        } 
        rs++;
        for (int i = rs; i <= re; i++) {
          res.push_back(matrix[i][ce]);
        }
        ce--;
        for (int i = ce; i >= cs; i--){
          res.push_back(matrix[re][i]);
        }
        re--;
        for (int i = re; i >= rs; i--) {
          res.push_back(matrix[i][cs]);
        }
        cs++;
      }
      return res;
    }
};