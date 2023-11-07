def find_cycles(maze):
    def dfs(x, y, length):
        visited[x][y] = True
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            new_x, new_y = x + dx, y + dy
            if 0 <= new_x < h and 0 <= new_y < w and not visited[new_x][new_y]:
                if maze[new_x][new_y] == maze[x][y]:
                    dfs(new_x, new_y, length + 1)
                else:
                    cycles.append(length)

    w, h = len(maze[0]), len(maze)
    visited = [[False] * w for _ in range(h)]
    cycles = []

    for x in range(h):
        for y in range(w):
            if not visited[x][y]:
                dfs(x, y, 1)

    return cycles

def main():
    maze_number = 1
    while True:
        w, h = map(int, input().split())
        if w == 0 and h == 0:
            break

        maze = [input() for _ in range(h)]
        cycles = find_cycles(maze)

        print(f"Maze #{maze_number}:")
        if not cycles:
            print("There are no cycles.")
        else:
            max_length = max(cycles)
            num_cycles = len(cycles)
            print(f"{num_cycles} Cycles; the longest has length {max_length}.")
        print()

        maze_number += 1

if __name__ == "__main__":
    main()
