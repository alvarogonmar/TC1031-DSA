
def containerWithMostWater(array, out): # def containerWithMostWater para encontrar el contenedor con más agua
    l = 0
    r = array.length() - 1

    area = min(array[r], array[l])*(r - l)
    while l < r:
        if array[l] < array[r]:
            l += 1
        elif array[l] > array[r]:
            r += 1        



