class QuickFind {
Public:
    QuickFind(int size);
    int find(int p);
    bool connected(int p, int q);
    int count();
    void unite(int p, int q);
    
private:
    int cnt; // number of different groups
    vector<int> id;
};

QuickFind::QuickFind(int size) : cnt(size), id(size, 0) {
    for (int i = 0; i < size; ++i) id[i] = i;
}

int QuickFind::find(int p) { return id[p]; }

bool QuickFind::connected(int p, int q) { return find[p] == find[q]; }

int QuickFind::count() { return cnt; }

void QuickFind::unite(int p, int q) {
    int pId = find(p), qId = find(q);
    if (pId == qId) return;
    --cnt;
    for (int i = 0; i < id.size(); ++i) {
        if (id[i] == pId) id[i] = qId;
    }
}