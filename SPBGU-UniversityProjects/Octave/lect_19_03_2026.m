##x1 = 0:0.1:2;
##y1 = x.*(1-x) + 0.1;

##x2 = -0.5:0.1:1.5;
##y2 = (x2+0.5)/2;

##Fig = figure('Name','Название окна','NumberTitle','off')
##plot(x1,y1,'LineWidth',3,'Color',[0.5 0.8 0.1])
##xlabel('x') % Ось X
##ylabel('f(x)') % Ось y
##title('My graph')
##grid on

##figure %Позволяет заново открывать окно фигуры => 2 графика
##hold on %Удеарживает оси
##plot(x2,y2,'LineWidth',3,'Color',[0.1 0.5 0.2])%Каждый новый plot очищает оси
##hold off %Отключает удержание

##Fig = figure('Name','Название окна','NumberTitle','off');
##x = linspace(0, 2*pi, 500);
##y1 = exp(-0.5*x).*sin(4*pi*x);
##plot(x,y1,'LineWidth',3,'LineStyle','--','Marker','d')
##
##xlabel('x') % Ось X
##ylabel('f(x)') % Ось y
##title('My graph')

##subplot(3,2,[1,4])
##plot(x,sin(x),'LineWidth',3,'color','m')
##grid on
##
##subplot(3,2,5)
##plot(x,sin(2*x))
##
##subplot(3,2,6)
##plot(x,sin(3*x))

##fplot(fun,[x_min,x_max])

##ezplot(fun,[x_min x_max y_min y_max])

f = @(x,y)x.*(x+y.^3)-1;
##C = ezplot(f,[-1 2 -4 4])
##set(C,'LineWidth',3,'Color',[0,0.5 1])

##C.LineWidth = 3 Можно в MathLab, но не работает тут

##fimplicit(f,[-1 2 -4 4]) Есть в MathLab, Обновление ezplot

##x = 0:0.01:20;
##y1 = 200*exp(-0.5*x).*sin(x);
##y2 = 0.8*exp(-0.5*x).*sin(10*x);

##legend %Выводит легенду графика

##[hAx, Line1, Line2] = plotyy(x,y1,x,y2) %Создание графика с несколькими осями
##legend



