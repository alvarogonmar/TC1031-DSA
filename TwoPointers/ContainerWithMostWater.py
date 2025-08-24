
def containerWithMostWater(array, out, height): # def containerWithMostWater para encontrar el contenedor con más agua
        l = 0 # puntero izquierdo
        r = len(height) - 1
        maxArea = 0

        while l < r:
            area = min(height[r], height[l])*(r - l)
            maxArea = max(area, maxArea)
            if height[l] < height[r]:
                l += 1
            elif height[l] > height[r]:
                r -= 1
            else:
                r -= 1
        return maxArea


