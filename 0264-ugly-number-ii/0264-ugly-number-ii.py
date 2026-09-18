import heapq

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        minheap = [1]
        visited = {1} 
        ugly = 1

        for i in range(n):
            ugly = heapq.heappop(minheap)
            for factor in [2,3,5]:
                next_ugly = ugly * factor
                if next_ugly not in visited:
                    visited.add(next_ugly)
                    heapq.heappush(minheap, next_ugly)
                    
        return ugly