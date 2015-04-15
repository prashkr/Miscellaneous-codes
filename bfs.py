import Queue

visited = []
nodes = []


def bfs(g, start):
    visited.append(start)
    Q = Queue.Queue()
    Q.put(start)
    print start
    while not Q.empty():
        start = Q.get()
        for neighbour in g[start]:
            if neighbour not in visited:
                print neighbour
                visited.append(neighbour)
                Q.put(neighbour)
    

if __name__=="__main__":
    g = {}
    edges = input("Enter number of edges: ")
    for i in xrange(0, edges):
        temp = raw_input()
        temp = temp.split(' ')
        n1 = temp[0]
        n2 = temp[1]
        if n1 not in nodes:
            g[n1] = []
            nodes.append(n1)
        if n2 not in nodes:
            g[n2] = []
            nodes.append(n2)

        g[n1].append(n2)
        g[n2].append(n1)
    print g
    start = nodes[0]
    bfs(g, start)
        
    
    
