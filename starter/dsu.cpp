#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    if (parent[v] != v) {
        int x = findSet(parent[v]);
        parent[v] = x;
        return x;
    }
    return v;
}


void unionSet(int a, int b) {

    int pa = findSet(a);
    int pb = findSet(b);

    if (pa != pb) {
        if (sz[pa] > sz[pb]) {
            parent[pb] = pa;
            sz[pa] += sz[pb];
        } else {
            parent[pa] = pb;
            sz[pb] += sz[pa];
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
