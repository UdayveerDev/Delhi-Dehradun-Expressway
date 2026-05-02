#include "../include/DSU.h"
#include <numeric>
#include <algorithm>

DSU::DSU(int n) : p(n), r(n,0) {
    iota(p.begin(), p.end(), 0);
}

int DSU::find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

bool DSU::unite(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;
    if(r[a] < r[b]) swap(a,b);
    p[b] = a;
    if(r[a] == r[b]) r[a]++;
    return true;
}