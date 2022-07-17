class Solution {
public:
	int d = pow(10, 9) + 7;
	int findP(int m, int n, int maxMove, int startRow, int startColumn) {
		long long ***matrix = new long long**[maxMove + 1];
		for(int i = 0; i < maxMove + 1; i++) {
			matrix[i] = new long long*[m];
			for(int j = 0; j < m; j ++) matrix[i][j] = new long long[n];
		}
		for(int i = 0; i < maxMove + 1; i++) {
			for(int j = 0; j < m; j ++) {
				for(int k = 0; k < n; k++) {
					int left = k + 1, right = n - k, up = j + 1, down = m - j;
					if(left == 0 || right == 0 || up == 0 || down == 0 || i == 0) matrix[i][j][k] = 0;
					else if(i <  left && i < right && i < up && i < down) matrix[i][j][k] = 0;
					else if(i == 1) {
						long long arr[4] = {left, right, up, down};
						long long count = 0;
						for(int l = 0; l < 4; l++) if(arr[l] == 1) count ++;
						matrix[i][j][k] = count;
					} else if(i > 1) {
						if(j == 0 && j == m - 1) {
							if(k == 0 && k == n - 1) matrix[i][j][k] = 0;
							else if(k == 0) matrix[i][j][k] = matrix[i - 1][j][k + 1];
							else if(k == n - 1) matrix[i][j][k] = matrix[i - 1][j][k - 1];
							else matrix[i][j][k] = matrix[i - 1][j][k - 1] + matrix[i - 1][j][k + 1];
						} else if(j == 0) {
							if(k == 0 && k == n - 1) matrix[i][j][k] = matrix[i - 1][j + 1][k];
							else if(k == 0) matrix[i][j][k] = matrix[i - 1][j + 1][k] + matrix[i - 1][j][k + 1];
							else if(k == n - 1) matrix[i][j][k] = matrix[i - 1][j + 1][k] + matrix[i - 1][j][k - 1];
							else matrix[i][j][k] = matrix[i - 1][j + 1][k] + matrix[i - 1][j][k - 1] + matrix[i - 1][j][k + 1];
						} else if(j == m - 1) {
							if(k == 0 && k == n - 1) matrix[i][j][k] = matrix[i - 1][j - 1][k];
							else if(k == 0) matrix[i][j][k] = matrix[i - 1][j - 1][k] + matrix[i - 1][j][k + 1];
							else if(k == n - 1) matrix[i][j][k] = matrix[i - 1][j - 1][k] + matrix[i - 1][j][k - 1];
							else matrix[i][j][k] = matrix[i - 1][j - 1][k] + matrix[i - 1][j][k - 1] + matrix[i - 1][j][k + 1];
						} else {
							if(k == 0 && k == n - 1) matrix[i][j][k] = matrix[i - 1][j - 1][k] + matrix[i - 1][j + 1][k];
							else if(k == 0) matrix[i][j][k] = matrix[i - 1][j - 1][k] + matrix[i - 1][j + 1][k] + matrix[i - 1][j][k + 1];
							else if(k == n - 1) matrix[i][j][k] = matrix[i - 1][j - 1][k] + matrix[i - 1][j + 1][k] + matrix[i - 1][j][k - 1];
							else matrix[i][j][k] = (matrix[i - 1][j - 1][k] + matrix[i - 1][j + 1][k] + matrix[i - 1][j][k - 1] + matrix[i - 1][j][k + 1]) % d;
						}
					}
				}
			}
		}
		return matrix[maxMove][startRow][startColumn] % d;
	}
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		if(maxMove == 0) return 0;
		return (findP(m, n, maxMove, startRow, startColumn) % d + findPaths(m, n, maxMove - 1, startRow, startColumn) % d) % d;
	}
};
