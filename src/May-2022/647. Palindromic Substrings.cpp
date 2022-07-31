class Solution {
 public:
  auto countSubstrings(const string &s) -> int {
    N = static_cast<int>(s.length());
    for (int i = 0; i < N; ++i) {
      middleOut(s, i, i);
      middleOut(s, i, i + 1);
    }
    return ans;
  }

 private:
  int ans{0};
  int N{0};
  void middleOut(const string &s, int i, int j) {
    if (i < 0 || j > N - 1) return;

    int step{0};
    while (i - step >= 0 && j + step <= N - 1 && s[i - step] == s[j + step]) {
      ++ans;
      ++step;
    }
  }
};
