Same as unique paths solution:  

f(i,j){
    if (i < 0 || j < 0 || matrix[i][j] == 1) return 0;

    if (i == 0 && j == 0)  return 1; //Base case
    if (i < 0 || j < 0)  return 0; // out of bounds

    up = f(i-1, j)
    left = f(i, j-1)
    return up+left
}
