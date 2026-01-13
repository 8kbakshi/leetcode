class Solution {
public:
    bool check(long double mid,
               vector<vector<int>>& squares,
               long double halfArea) {

        long double areaBelow = 0;

        for (auto &sq : squares) {
            long double y = sq[1];
            long double l = sq[2];

            if (mid <= y) {
                continue;
            } else if (mid >= y + l) {
                areaBelow += l * l;
            } else {
                areaBelow += (mid - y) * l;
            }
        }

        return areaBelow >= halfArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double low = 0, high = 0;
        long double totalArea = 0;

        for (auto &sq : squares) {
            long double y = sq[1];
            long double l = sq[2];
            high = max(high, y + l);
            totalArea += l * l;
        }

        long double halfArea = totalArea / 2.0;

        for (int i = 0; i < 60; i++) {
            long double mid = (low + high) / 2;

            if (check(mid, squares, halfArea))
                high = mid;
            else
                low = mid;
        }

        return (double)high;
    }
};
