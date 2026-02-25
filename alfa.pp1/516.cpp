#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event {
    int x;
    int y1, y2;
    int delta; // +1 add, -1 remove
    bool operator<(Event const& o) const {
        return x < o.x;
    }
};

struct SegTree {
    int n;
    vector<int> cnt;      // how many times interval covered
    vector<ll> coverLen;  // total covered length in this segment
    vector<int> ys;       // compressed coords differences stored outside

    SegTree(int m, const vector<int>& ys_coords) {
        n = m;
        cnt.assign(4*n, 0);
        coverLen.assign(4*n, 0);
        ys = ys_coords;
    }

    void pull(int v, int l, int r) {
        if (cnt[v] > 0) {
            // if covered at least once, whole segment is covered
            coverLen[v] = (ll)(ys[r+1] - ys[l]);
        } else {
            if (l == r) coverLen[v] = 0;
            else coverLen[v] = coverLen[v*2] + coverLen[v*2+1];
        }
    }

    void update(int v, int l, int r, int ql, int qr, int delta) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            cnt[v] += delta;
            pull(v, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(v*2, l, mid, ql, qr, delta);
        update(v*2+1, mid+1, r, ql, qr, delta);
        pull(v, l, r);
    }

    // helper to call: update interval [L,R] in terms of compressed indices
    void updateRange(int L, int R, int delta) {
        if (L > R) return;
        update(1, 0, n-1, L, R, delta);
    }

    ll totalCovered() const {
        return coverLen[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int W, H;
    if (!(cin >> W >> H)) return 0;
    int k; cin >> k;
    vector<array<int,4>> rects;
    rects.reserve(k);
    for (int i = 0; i < k; ++i) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // clamp to canvas [0, W) x [0, H)
        int cx1 = max(0, min(W, x1));
        int cx2 = max(0, min(W, x2));
        int cy1 = max(0, min(H, y1));
        int cy2 = max(0, min(H, y2));
        // ensure proper orientation (x1 < x2, y1 < y2)
        if (cx1 < cx2 && cy1 < cy2) {
            rects.push_back({cx1, cy1, cx2, cy2});
        }
    }

    if (rects.empty()) {
        cout << (ll)W * H << "\n"; // no painted area -> whole canvas unpainted
        return 0;
    }

    // collect all Y endpoints for compression
    vector<int> ys;
    ys.reserve(rects.size()*2);
    for (auto &r : rects) {
        ys.push_back(r[1]);
        ys.push_back(r[3]);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    // build events
    vector<Event> events;
    events.reserve(rects.size()*2);
    for (auto &r : rects) {
        int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
        // map y to indices in compressed array
        // we'll use segments between ys[i] and ys[i+1], so indices are 0..m-2
        events.push_back({x1, y1, y2, +1});
        events.push_back({x2, y1, y2, -1});
    }
    sort(events.begin(), events.end());

    // Prepare ys_coords: we need ys array as sorted distinct Y endpoints.
    // For segment tree we need the differences between consecutive ys, so we will use ys vector,
    // and segments indices will range 0..(m-2) where segment i corresponds to [ys[i], ys[i+1])
    // If only one unique y, then no vertical span -> no area; handle that.
    if (ys.size() < 2) {
        // No vertical length, union area zero
        cout << (ll)W * H - 0 << "\n";
        return 0;
    }

    // For segment tree we need ys with an extra element indexing convenience:
    // We'll keep ys as is; when computing cover length for node covering [l..r] we use ys[r+1] - ys[l]
    // So we must ensure we can index ys[r+1] -> therefore pass ys as they are and tree n = ys.size()-1
    int m = (int)ys.size() - 1;
    // build helper vector for segtree that allows ys[r+1] indexing inside pull:
    // we'll create an array ycoords of size m+1 that equals ys (0..m)
    vector<int> ycoords(m+1);
    for (int i = 0; i <= m; ++i) ycoords[i] = ys[i];

    SegTree seg(m, ycoords);

    // helper to map a y value to index of segment start: find i such that ys[i] == y
    auto idx = [&](int y) {
        return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
    };

    ll painted = 0;
    int i = 0;
    while (i < (int)events.size()) {
        int curX = events[i].x;
        // process all events at curX
        while (i < (int)events.size() && events[i].x == curX) {
            int L = idx(events[i].y1);
            int R = idx(events[i].y2) - 1; // segment indices are [L, R] where segment i -> [ys[i], ys[i+1])
            seg.updateRange(L, R, events[i].delta);
            ++i;
        }
        // next event x (if any)
        if (i < (int)events.size()) {
            int nextX = events[i].x;
            ll coveredY = seg.totalCovered();
            painted += coveredY * (ll)(nextX - curX);
        }
    }

    ll total = (ll)W * H;
    ll unpainted = total - painted;
    cout << unpainted << "\n";
    return 0;
}