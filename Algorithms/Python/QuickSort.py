def QuickSort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return QuickSort(left) + middle + QuickSort(right)

if __name__ == '__main__':
    a = list(map(int,  input("Enter the elements of array separated by space : ").split()))
    print("The sorted array is ",QuickSort(a))
