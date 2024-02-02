def InsertionSort(arr: list)->list:
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while(j >= 0 and key < arr[j]):
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return  arr

if __name__ == '__main__':
    a = list(map(int,  input("Enter the elements of array separated by space : ").split()))
    print("The sorted array is ",InsertionSort(a))