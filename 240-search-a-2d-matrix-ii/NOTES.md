# Staircase Search
​
*We start from the position of first row,last column and make use of these properties in the matrix*-
1. Since every row is sorted and every column is sorted,then if the target is greater than the current  position it will certainly be in the next row because elements to the left of it are all smaller.
2. Similarly if the target is smaller than the current one,then certainly it would be in the next column because all elements to the bottom of it are always greater than it.