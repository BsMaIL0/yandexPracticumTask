##t = 0:0.1:9*pi;
##x = 2*sin(t);
##y = 3*cos(t);
##plot3(x,y,t,'LineWidth',3,'Color','r')
##xlabel('x')
##ylabel('y')
##zlabel('z')
##grid on
##comet3(x,y,t,0.01) % отрисовывает

##x= -10:0.5:10;
##y = -10:0.5:10;
##[X,Y] = meshgrid(x,y);
##Z = sin(sqrt(X.^2+Y.^2))./sqrt(X.^2+Y.^2);
##mesh(X,Y,Z) % самая простая функция отрисовки
##hidden off % сделать прозрачной

##surf(X,Y,Z) % поверхность с заливкой
##shading flat % убирает сетку с поверхностиg
##shading interp % сглаживает переходы

##surfc(X,Y,Z) % поверхность с линиями уровня

##contour(X,Y,Z) % только линии уровня

##surf(X,Y,Z)
##colorbar % выдаёт градацию изменения
##colormap('ocean') % цветовая политра

##clear
##clearvars

##a = linspace(0,1,64)';
##b = linspace(0,1,64)';
##c = linspace(0,1,64)';
##mymap = [a b c]
##surf(X,Y,)
##colormap(mymap)

##x = -pi:0.1:pi;
##y = -pi:0.1:pi;
##[X,Y] = meshgrid(x,y);
##Z = 20 - X.^2 - Y.^2
##surf(X,Y,Z)
##axis equal


##u = linspace(0,2*pi,64);
##v = linspace(0,2*pi,64);
##[X,Y] = meshgrid(u,v);
##R = 10;
##r = 5;
##x = (R+r.*cos(X)).*cos(Y);
##y = (R+r.*cos(X)).*sin(Y);
##z = r.*sin(X);
##surf(x,y,z)

##u = linspace(0,10*pi,64);
##v = linspace(0,10*pi,64);
##a = 1;
##[U,V] = meshgrid(u,v);
##x = U.*cos(V);
##y = U.*sin(V);
##z = a.*V;
##surf(x,y,z)

##figure
##u = linspace(0,2*pi,64);
##v = linspace(-1,1,64);
##[U,V] = meshgrid(u,v);
##x = (1 + V./2 .* cos(U./2)).*cos(U);
##y = (1+V./2 .*cos(U./2)).*sin(U);
##z = V./2 .* sin(U./2);
##surf(x,y,z)
