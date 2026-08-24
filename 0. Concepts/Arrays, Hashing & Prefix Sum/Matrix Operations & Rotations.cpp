/*
 * ============================================================================
 * Concept: Matrix Operations & Rotations
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Grid/Matrix manipulation involves 2D array traversals, 90-degree clockwise/counter-clockwise in-place rotations, spiral traversals, and zero-setting.
Rotate 90 deg clockwise: Transpose matrix (`matrix[i][j] = matrix[j][i]`), then reverse each row.
Spiral Traversal: Maintain `top`, `bottom`, `left`, `right` boundary pointers.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * M) - visits each cell constant number of times.
 * - Space Complexity: O(1) auxiliary space for in-place algorithms.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Image transformation / 2D rotation.
- Spiral / snake matrix traversal.
- Setting matrix zeroes based on row/col markers.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Rotate Image 90 deg Clockwise (LC 48).
2. Spiral Matrix (LC 54).
3. Set Matrix Zeroes (LC 73 - O(1) space using first row/col as markers).
4. Game of Life (LC 289 - In-place state encoding using bit manipulation).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Rotate Matrix 90 degrees clockwise in-place
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 1. Transpose
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 2. Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Spiral Matrix Traversal
vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; ++c) result.push_back(matrix[top][c]);
        top++;
        for (int r = top; r <= bottom; ++r) result.push_back(matrix[r][right]);
        right--;
        if (top <= bottom) {
            for (int c = right; c >= left; --c) result.push_back(matrix[bottom][c]);
            bottom--;
        }
        if (left <= right) {
            for (int r = bottom; r >= top; --r) result.push_back(matrix[r][left]);
            left++;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(mat);
    cout << "Rotated Matrix Top-Left: " << mat[0][0] << "\n";
    return 0;
}
