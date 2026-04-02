function circle = circle(n, r)
    center = (n + 1) / 2;
    [x, y] = meshgrid(1:n, 1:n);
    distance = sqrt((x - center).^2 + (y - center).^2);
    circle = distance <= r;
end
