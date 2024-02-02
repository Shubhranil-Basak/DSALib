def BubbleSort(arr: list) -> list:
    length = len(arr)
    for i in range(length):
        for j in range(length - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return  arr

if __name__ == '__main__':
    a = list(map(int,  input("Enter the elements of array separated by space : ").split()))
    print("The sorted array is ",BubbleSort(a))