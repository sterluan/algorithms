class WQuickUnion {
Public:
    WQuickUnion(int size);
    int find(int p);
    bool connected(int p, int q);
    int count();
    void unite(int p, int q);
    
private:
    int cnt; // number of different groups
    vector<int> id, sz;
};

WQuickUnion::WQuickUnion(int x) : cnt(x), id(x, 0), sz(x, 1) {
    for (int i = 0; i < x; ++i) id[i] = i;
}

int WQuickUnion::find(int p) {
    while (p != id[p]) { p = id[p]; }
    return p;
}

bool WQuickUnion::connected(int p, int q) { return find(p) == find(q); }

int WQuickUnion::count() { return cnt; }

void WQuickUnion::unite(int p, int q) {
    int pId = find(p), qId = find(q);
    if (pId == qId) return;
    --cnt;
    if (sz(pId) < sz(qId)) {
        id(pId) = qId;
        sz(qId) += sz(pId);
    }
    else {
        id(qId) = pId;
        sz(pId) += sz(qId);
    }
}