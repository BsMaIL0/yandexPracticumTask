##phi_end = 2*pi;
##phi = linspace(1e-10,phi_end);
##r = sin(phi)./phi;
##x = r.*cos(phi);
##y = r.*sin(phi);
##x_0 = 1 * cos(0);
##y_0 = 1 * sin(0);
##x_end = sin(phi_end)./phi_end * cos(phi_end);
##y_end = sin(phi_end)./phi_end * sin(phi_end);
##hold on
##plot(x,y,'LineWidth',3,'Color','b')
##plot(x_0,y_0,'Color','m','LineWidth',10)
##plot(x_end,y_end,'Color','m','LineWidth',10)
##hold off

##clear
##clearvars

##x = linspace(0,2);
##y = humps(x);
##[m,indx] = max(f);
##max_x = x(indx);
##range = find(y <=40 & y >= 20);
##x_range = x(range);
##y_range = y(range);
##
##hold on;
##plot(x,y,'Color','b');
##plot(max_x,m,'MarkerSize',10,'Color','m');
##plot(x_range,y_range,'LineStyle','None', 'Marker', 'd', 'MarkerSize',6,'Color','r');
##hold off;

clear
clearvars

x = cos(t)-a*cos(m.*t)+b*sin(n.*t);
y = sin(t)+a*sin(m.*t)+b*cos(n.*t);
t = linspace(-5,5);
a = 1/4;
b = 1/16;
m = 8;
n = 8;

