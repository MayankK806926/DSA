#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralOrderRings(int** matrix, int rows, int cols) {
    vector<vector<int>> rings;
    if (rows == 0 || cols == 0) return rings;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        vector<int> currentRing;

        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            currentRing.push_back(matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            currentRing.push_back(matrix[i][right]);
        }
        right--;

        // Traverse from right to left (if needed)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                currentRing.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top (if needed)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                currentRing.push_back(matrix[i][left]);
            }
            left++;
        }

        rings.push_back(currentRing);
    }

    return rings;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int rows, cols;
        cin >> rows >> cols;

        vector<string> v(rows);
        for (int i = 0; i < rows; ++i) {
            cin >> v[i];
        }

        int** matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = v[i][j] - '0';
            }
        }

        vector<vector<int>> rings = spiralOrderRings(matrix, rows, cols);
          for(int j=0;j<rings.size();++j){
               for (int i = 0; i < 3; ++i) {
                    rings[j].push_back(rings[j][i]);
               }
          }
          // for (size_t i = 0; i < rings.size(); ++i) {
          //      cout << "Ring " << i + 1 << ": ";
          //      for (int val : rings[i]) {
          //           cout << val << " ";
          //      }
          //      cout << endl;
          // }
          int cnt = 0;
          for(int j=0;j<rings.size();++j){
               for (int i = 0; i <= rings[j].size() - 4; ++i) {
                    if (rings[j][i] == 1 && rings[j][i + 1] == 5 && rings[j][i + 2] == 4 && rings[j][i + 3] == 3) {
                         cnt++;
                    }
               }
          }
          cout << cnt << endl;

    }
}




//NO IDEA WHY BELOW SOLUTION IS NOT CORRECT
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralOrderRings(vector<string> &v, int rows, int cols) {
     vector<vector<int>> rings;
     if (rows == 0 || cols == 0) return rings;
     int top = 0, bottom = rows - 1;
     int left = 0, right = cols - 1;
     while (top <= bottom && left <= right) {
          vector<int> currentRing;
          for (int i = left; i <= right; i++) {
               currentRing.push_back(v[top][i]-'0');
          }
          top++;
          for (int i = top; i <= bottom; i++) {
               currentRing.push_back(v[i][right]-'0');
          }
          right--;
          if (top <= bottom) {
               for (int i = right; i >= left; i--) {
                    currentRing.push_back(v[bottom][i]-'0');
               }
               bottom--;
          }
          if (left <= right) {
               for (int i = bottom; i >= top; i--) {
                    currentRing.push_back(v[i][left]-'0');
               }
               left++;
          }
          rings.push_back(currentRing);
     }
     return rings;
}

void shift1right(vector<int>& v) {
     reverse(v.begin(),v.begin()+v.size()-1);
     reverse(v.begin()+v.size()-1,v.end());
     reverse(v.begin(),v.end());
}

void shift2right(vector<int>& v) {
     reverse(v.begin(),v.begin()+v.size()-2);
     reverse(v.begin()+v.size()-2,v.end());
     reverse(v.begin(),v.end());
}

void shift3right(vector<int>& v) {
     reverse(v.begin(),v.begin()+v.size()-3);
     reverse(v.begin()+v.size()-3,v.end());
     reverse(v.begin(),v.end());
}

int main() {
     int t;
     cin >> t;
     while (t--) {
          int rows, cols;
          cin >> rows >> cols;
          vector<string> v(rows);
          for (int i = 0; i < rows; ++i) {
               cin >> v[i];
          }
          vector<vector<int>> rings = spiralOrderRings(v, rows, cols);
          // for (size_t i = 0; i < rings.size(); ++i) {
          //      cout << "Ring " << i + 1 << ": ";
          //      for (int val : rings[i]) {
          //           cout << val << " ";
          //      }
          //      cout << endl;
          // }
          int cnt = 0;
          for(int j=0;j<rings.size();++j){
               for (int i = 0; i <= rings[j].size() - 4; ++i) {
                    if (rings[j][i] == 1 && rings[j][i + 1] == 5 && rings[j][i + 2] == 4 && rings[j][i + 3] == 3) {
                         cnt++;
                    }
               }
               if (rings[j][0] == 5){
                    shift1right(rings[j]);
                    if (rings[j][0] == 1 && rings[j][1] == 5 && rings[j][2] == 4 && rings[j][3] == 3) cnt++;
               }
               if (rings[j][0] == 4){
                    shift2right(rings[j]);
                    if (rings[j][0] == 1 && rings[j][1] == 5 && rings[j][2] == 4 && rings[j][3] == 3) cnt++;
               }
               if (rings[j][0] == 3){
                    shift3right(rings[j]);
                    if (rings[j][0] == 1 && rings[j][1] == 5 && rings[j][2] == 4 && rings[j][3] == 3) cnt++;
               }
          }
          // for (size_t i = 0; i < rings.size(); ++i) {
          //      cout << "Ring " << i + 1 << ": ";
          //      for (int val : rings[i]) {
          //           cout << val << " ";
          //      }
          //      cout << endl;
          // }
          cout << cnt << endl;

    }
}
*/
