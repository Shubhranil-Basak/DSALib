import random

def IsSorted(lst: list)->bool:
    return all(lst[i] <= lst[i + 1] for i in range(len(lst) - 1))

def BogoSort(lst: list)->list:
    while not IsSorted(lst):
        random.shuffle(lst)
    return lst

if __name__ == '__main__':
    a = list(map(int,  input("Enter the elements of array separated by space : ").split()))
    print("The sorted array is ",BogoSort(a))