class Solution {
 public:
  // insert , delete , replace
  int cache[501][501];

  int func(string w1, string w2, int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (cache[i][j] != -1) return cache[i][j];
    
    
    if (w1[i - 1] == w2[j - 1]) return func(w1, w2, i - 1, j - 1);

    return cache[i][j] = 1 + min({func(w1, w2, i, j - 1) , func(w1, w2, i - 1, j) ,
                         func(w1, w2, i - 1, j - 1)});
  }
  int minDistance(string word1, string word2) {
    memset(cache, -1, sizeof(cache));

    return func(word1, word2, word1.length(), word2.length());
  }
};