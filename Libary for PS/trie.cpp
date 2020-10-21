int addTrie() {
  trie.push_back(vector<int>(28, -1));
  isEnd.push_back(0);
  return isEnd.size() - 1;
}

void insert(string str) {
  int cur = 0;
  for (int i = 0; i < (int) str.size(); ++i) {
    int word = str[i] - 'a';
    int nxt = trie[cur][word];
    if (nxt == -1)
      nxt = addTrie();
    trie[cur][word] = nxt;
    cur = nxt;
  }
  isEnd[cur] = 1;
}

bool search(string str) {
  int cur = 0;
  for (int i = 0; i < (int) str.size(); ++i) {
    int word = str[i] - 'a';
    int nxt = trie[cur][word];
    if (nxt == -1)
      return 0;
    trie[cur][word] = nxt;
    cur = nxt;
  }
  return isEnd[cur];
}

// Dont forget to add dummy node
addTrie();
