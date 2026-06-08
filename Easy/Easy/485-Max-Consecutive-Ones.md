# 485. Max Consecutive Ones

## Approach
- count = current consecutive 1's
- maxCount = maximum consecutive 1's found so far
- If element is 1 → increment count
- If element is 0 → reset count = 0
- Update maxCount = max(maxCount, count)

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Follow-up
If one 0 can be flipped to 1, solve using Sliding Window.
