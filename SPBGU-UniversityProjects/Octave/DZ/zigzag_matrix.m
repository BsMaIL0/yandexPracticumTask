function zigzag_matrix = zigzag_matrix(n)
    zigzag_matrix = zeros(n);
    i = 1; j = 1;
    for num = 1:n*n
        zigzag_matrix(i, j) = num;
        if (i + j)
            if mod(i + j, 2) == 0
                if j < n && i > 1
                    i = i - 1;
                    j = j + 1;
                elseif j < n
                    j = j + 1;
                else
                    i = i + 1;
                end
            else
                if i < n && j > 1
                    i = i + 1;
                    j = j - 1;
                elseif i < n
                    i = i + 1;
                else
                    j = j + 1;
                end
            end
        end
    end
end
