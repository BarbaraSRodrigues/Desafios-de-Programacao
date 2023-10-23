import networkx as nx

graph = nx.graph()
bicolored = True

def checkColor()

while True:

    # Different nodes and number of edges
    n = int(input())
    l = int(input())

    if n == 0:
        break

    # Create the graph
    for i in range(n):
        graph.add_nodes(i)


    for i in range(l):
        edge1 = int(input())
        edge2 = int(input())
        
        graph.add_edge(edge1, edge2)
    



    # Reset graph for the next input
    graph.clear()

    