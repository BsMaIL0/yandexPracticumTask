function result = logic_matrix(rows, cols)
  result = repmat(mod(1:cols, 2), rows, 1);
endfunction

