vector<int> prefixT(string str) {
  int m = str.size();
  vector<int> vec(m);
  for (int i = 1, k = 0; i < m; ++i) {
    while(k > 0 && str[i] != str[k])
      k = vec[k-1];
    if(str[i] == str[k]) ++k;
    vec[i] = k;
  }
  return vec;
}

void kmp(string text, string pat) {
  int n = text.size(), m = pat.size();
  vector<int> preTable = prefix(pat);
  for (int i = 0, k = 0; i < n; ++i) {
    while(k > 0 && pat[k] != text[i])
      k = preTable[k-1];
    if(text[i] == pat[k])
      ++k;
    if(k == m){
      k = preTable[k-1];
    }
  }
}
