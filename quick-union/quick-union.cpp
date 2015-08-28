class QuickUnion {
Public:
    QuickUnion(int size);
    int find(int p);
    bool connected(int p, int q);
    int count();
    void unite(int p, int q);
    
private:
    int cnt; // number of different groups
    vector<int> id;
};

QuickUnion::QuickUnion(int size) : cnt(size), id(size, 0) {
    for (int i = 0; i < size; ++i) id[i] = i;
}

int QuickUnion::find(int p) {
    while (p != id[p]) p = id[p];
    return p;
}

bool QuickUnion::connected(int p, int q) { return find(p) == find(q); }

int QuickUnion::count() { return cnt; }

void QuickUnion::unite(int p, int q) {
    int pId = find(p), qId = find(q);
    if (pId == qId) return;
    --cnt;
    id[pId] = qId;
}