class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def get_dist(start):
            n = len(edges)
            dist = [-1] * n
            d = 0
            while start != -1 and dist[start] == -1:
                dist[start] = d
                start = edges[start]
                d += 1
            return dist

        dist1 = get_dist(node1)
        dist2 = get_dist(node2)
        ans = -1
        min_dist = float('inf')
        for i in range(len(edges)):
            if dist1[i] != -1 and dist2[i] != -1:
                if max(dist1[i], dist2[i]) < min_dist:
                    min_dist = max(dist1[i], dist2[i])
                    ans = i
        return ans