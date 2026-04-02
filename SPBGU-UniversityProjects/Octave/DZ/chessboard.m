function chessboard = chessboard(rows, cols)
  [row_indices, col_indices] = meshgrid(1:rows,1:cols);
  row_indices = row_indices';
  col_indices = col_indices';
  chessboard = mod(row_indices + col_indices,2) == 0;
endfunction

