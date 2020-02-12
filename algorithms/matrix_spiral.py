# Program by Sundar Saravanan (31.12.2019:00.17.30)
def spiral(mat, strt, rows, cols):  #1, 2, 3
    if strt>=cols or strt>=rows:
        return
    for i in range(strt, cols):          # 1,3 => 1,2
        print(mat[strt][i], end=' ')
    if strt==rows-1:    # only one row
        return
    for i in range(strt+1, rows):        # 2, 2 => null
        print(mat[i][cols-1], end=' ')
    for i in range(cols-2, strt-1, -1):  # 1, 0, -1 => 1
        print(mat[rows-1][i], end=' ')
    for i in range(rows-2, strt, -1):    # 0, 1, -1 => null
        print(mat[i][strt], end=' ')
    print()
    spiral(mat, strt+1, rows-1, cols-1)
mat = [ [1,2,3,4],
        [5,6,7,8],
        [9,10,11,12] ]
spiral(mat, 0, 3, 4)