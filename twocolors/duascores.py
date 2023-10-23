import networkx as nx
from collections import deque

def is_bicolorable(graph):
    # Dictionary to store colors of nodes
    color = {}

    # We will use BFS for traversal
    queue = deque()

    # Start coloring from the first node
    for node in graph:
        if node not in color:
            color[node] = 0
            queue.append(node)

            while queue:
                current_node = queue.popleft()

                # Color neighbors with opposite color
                for neighbor in graph[current_node]:
                    if neighbor not in color:
                        color[neighbor] = 1 - color[current_node]
                        queue.append(neighbor)
                    elif color[neighbor] == color[current_node]:
                        return False

    return True

while True:
    n = int(input())

    if n == 0:
        break

    l = int(input())
    graph = nx.Graph()

    for _ in range(l):
        edge1, edge2 = map(int, input().split())
        graph.add_edge(edge1, edge2)

    if is_bicolorable(graph):
        print("BICOLORABLE.")
    else:
        print("NOT BICOLORABLE.")
