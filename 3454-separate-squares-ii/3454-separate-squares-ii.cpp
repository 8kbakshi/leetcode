class Solution {
public:
    struct Event {
        long long y;
        int x1, x2;
        int type;
    };

    struct SegTree {
        int n;
        vector<long long> cover, len, xs;

        SegTree(const vector<long long>& coord) {
            xs = coord;
            n = xs.size() - 1;
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int idx, int l, int r) {
            if (cover[idx] > 0) {
                len[idx] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                len[idx] = 0;
            } else {
                len[idx] = len[idx * 2] + len[idx * 2 + 1];
            }
        }

        void update(int idx, int l, int r, int ql, int qr, int v) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cover[idx] += v;
                pull(idx, l, r);
                return;
            }
            int m = (l + r) / 2;
            update(idx * 2, l, m, ql, qr, v);
            update(idx * 2 + 1, m, r, ql, qr, v);
            pull(idx, l, r);
        }

        long long query() {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<long long> xs;

        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
            events.push_back({y, (int)x, (int)(x + l), 1});
            events.push_back({y + l, (int)x, (int)(x + l), -1});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        sort(events.begin(), events.end(),
             [](auto &a, auto &b) { return a.y < b.y; });

        SegTree st(xs);

        long double total = 0;
        long long prevY = events[0].y;

        for (auto &e : events) {
            long long dy = e.y - prevY;
            total += (long double)st.query() * dy;
            st.update(1, 0, st.n, getX(e.x1), getX(e.x2), e.type);
            prevY = e.y;
        }

        long double half = total / 2.0;
        st = SegTree(xs);

        long double cur = 0;
        prevY = events[0].y;

        for (auto &e : events) {
            long long dy = e.y - prevY;
            long double area = (long double)st.query() * dy;

            if (cur + area >= half) {
                return (double)(prevY + (half - cur) / st.query());
            }

            cur += area;
            st.update(1, 0, st.n, getX(e.x1), getX(e.x2), e.type);
            prevY = e.y;
        }

        return (double)prevY;
    }
};
