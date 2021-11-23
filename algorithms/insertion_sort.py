import sys


def insertionSort(a, n):
    arr = a.copy()
    counts = 0
    for i in range(1, n):
        k = i
        while k > 0 and arr[k] < arr[k-1]:
            temp = arr[k]
            arr[k] = arr[k-1]
            arr[k-1] = temp
            counts += 1
            k = k - 1
    return [arr, counts]


def parse(filename):
    file = open(filename, "rt")
    data = file.readlines()
    n = int(data[0])
    arr = data[1].split(' ')
    for i in range(len(arr)):
        arr[i] = int(arr[i])

    return [n, arr]


if __name__ == "__main__":

    n, arr = parse(sys.argv[1])

    sortedArr, counts = insertionSort(arr, n)
    print(sortedArr)
    print(counts)
