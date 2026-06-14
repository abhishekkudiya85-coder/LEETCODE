class Solution {
public:
    bool isPossible(vector<int>& target) {

        long long totalSum = 0;
        priority_queue<int> maxHeap;

        for (int num : target) {
            totalSum += num;
            maxHeap.push(num);
        }

        while (true) {

            int largest = maxHeap.top();
            maxHeap.pop();

            long long restSum = totalSum - largest;

            if (largest == 1 || restSum == 1)
                return true;

            if (restSum == 0 || largest < restSum)
                return false;

            int previous = largest % restSum;

            if (previous == 0)
                return false;

            totalSum = restSum + previous;
            maxHeap.push(previous);
        }
    }
};
