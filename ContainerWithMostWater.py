
def containerWithMostWater(array, out):
    l = 0
    r = array.lenght() - 1

    area = min(array[r], array[l])*(r - l)
    while l < r:
        if array[l] < array[r]:
            l += 1
        elif array[l] > array[r]:
            r += 1        



