def SelectionSort(arr: list)->list:
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

if __name__ == '__main__':
    a = list(map(int,  input("Enter the elements of array separated by space : ").split()))
    print("The sorted array is ",SelectionSort(a))