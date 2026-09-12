class Solution {
    struct Interval {
        int l, r, w, id;
    };

    struct State {
        long long weight = 0;
        int count = 0;
        int ids[4] = {0};

        bool operator<(const State& other) const {
            if (weight != other.weight) {
                return weight < other.weight;
            }
            for (int i = 0; i < count && i < other.count; ++i) {
                if (ids[i] != other.ids[i]) {
                    return ids[i] > other.ids[i];
                }
            }
            return count > other.count;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals_in) {
        int n = intervals_in.size();
        vector<Interval> intervals(n);
        
        for (int i = 0; i < n; ++i) {
            intervals[i] = {intervals_in[i][0], intervals_in[i][1], intervals_in[i][2], i};
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.id < b.id;
        });
        
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i].l;
        }
        
        vector<vector<State>> dp(n + 1, vector<State>(5));
        
        for (int i = n - 1; i >= 0; --i) {
            int next_idx = upper_bound(starts.begin(), starts.end(), intervals[i].r) - starts.begin();
            
            for (int k = 1; k <= 4; ++k) {
                State skip = dp[i + 1][k];
                State take = dp[next_idx][k - 1];
                
                take.weight += intervals[i].w;
                take.ids[take.count++] = intervals[i].id;
                
                for (int j = take.count - 1; j > 0; --j) {
                    if (take.ids[j] < take.ids[j - 1]) {
                        swap(take.ids[j], take.ids[j - 1]);
                    } else {
                        break;
                    }
                }
                
                dp[i][k] = (skip < take) ? take : skip;
            }
        }
        
        State best = dp[0][4];
        return vector<int>(best.ids, best.ids + best.count);
    }
};