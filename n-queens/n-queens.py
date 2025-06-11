from collections import defaultdict
def solveNQueens(n):
    tree = [defaultdict(int) for _ in range(n)]
    leaves = 0 # How many leaf leaves were visited in the imaginary search tree
    solutions = []
    # Recursive function to explore solutions
    # It goes from top row to bottom row and keeps track of free columns and diagonals
    # rdias go from top-left to bottom-right
    # ldias go from top-right to bottom-left
    def nqueens(brd, curr_row, free_cols, free_rdias, free_ldias):
        nonlocal leaves
        if curr_row == n:
            leaves += 1
            solutions.append([''.join('.' if elm == 0 else 'Q' for elm in row) for row in brd])
            return
        free_places = 0
        for col in free_cols:
            rdia = curr_row + col
            ldia = curr_row + n-1-col
            if rdia not in free_rdias or ldia not in free_ldias:
                continue
            free_places += 1
            # tree[0]
            new_brd = [row[:] for row in brd]
            new_brd[curr_row][col] = 1
            nqueens(new_brd, curr_row + 1, free_cols - {col}, free_rdias - {rdia}, free_ldias - {ldia})
        if free_places == 0: # dead end
            leaves +=1

    nqueens([[0]*n]*n, 0, set(range(n)),set(range(2*n-1)),set(range(2*n-1)))
    print(f"N-Queens n={n}: Explored {leaves} possibilit{'ies' if leaves!=1 else 'y'} out of which {len(solutions)} were solutions.", end=' ')
    if input("Show tree? (y/n): ").lower() == 'y':
        pass
    return solutions

total_solutions = [solveNQueens(i) for i in range(1, int(input("Enter the maximum n for N-Queens (default 9): ") or 9)+1)]

if input("Press Enter to see the solutions (q to quit)... ") == 'q':
    exit()

for n, solutions in enumerate(total_solutions):
    print(f"Solutions for n={n+1}: {len(solutions)}")
    sols_per_row = 80 // (2*n+1)
    for i in range(0, len(solutions), sols_per_row):
        for rows in zip(*solutions[i:i+sols_per_row]):
            print(' '.join('|'.join(rows)))
        print('-' * 80)

