def heapify(arr, size, root):
    largest = root
    left = 2 * root + 1
    right = 2 * root + 2
    if left < size and arr[left] > arr[largest]:
        largest = left
    if right < size and arr[right] > arr[largest]:
        largest = right
    if largest != root:
        arr[root], arr[largest] = arr[largest], arr[root]
        heapify(arr, size, largest)
def heap_sort(arr):
    size = len(arr)

    for index in range(size // 2 - 1, -1, -1):
        heapify(arr, size, index)

    for index in range(size - 1, 0, -1):
        arr[0], arr[index] = arr[index], arr[0]
        heapify(arr, index, 0)


arr = list(map(int, input("Enter integers: ").split()))

heap_sort(arr)

print("Sorted array:", *arr)
