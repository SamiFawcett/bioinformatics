import sys


def createAdjcencyList(filename):
    # first line has number of nodes, n and number of edges, m
    with open(filename) as f:
        parameters = f.readline().split(' ')
        n = int(parameters[0])
        m = int(parameters[1])

        adjcencyList = n * [0]

        for line in f.readlines():
            tokens = line.split(' ')
            n1 = int(tokens[0]) - 1
            n2 = int(tokens[1]) - 1
            print(n1, n2)
            adjcencyList[n1] += 1
            adjcencyList[n2] += 1

        return adjcencyList


if __name__ == "__main__":

    adjList = createAdjcencyList(sys.argv[1])
    for val in adjList:
        print(val, end=' ')
