class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> result;

        priority_queue<
            pair<long long, pair<int, int>>,
            vector<pair<long long, pair<int, int>>>,
            greater<pair<long long, pair<int, int>>>
        > pq;

        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({(long long)nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- && !pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                pq.push({
                    (long long)nums1[i] + nums2[j + 1],
                    {i, j + 1}
                });
            }
        }

        return result;
    }
};
