%% Discrete Convolution Integral
close all; % Close every figure before

% Define the input signals
x = [1, 1];
h = [1, 1, 1,1,1,1,1,1];

% Compute the convolution
y = conv(x, h);

% --- PLOT ---
figure;

% Subplot 1: Plot x[n]
subplot(3, 1, 1);
stem(x, 'LineWidth', 1.5, 'MarkerFaceColor', 'blue'); 
title('Input Signal x[n]');
ylabel('Amplitude');
grid on;
ax = gca;
ax.XAxis.Limits = [0, numel(x) + 1];
ax.YAxis.Limits = [min(x)-0.5, max(x)+0.5];

% Subplot 2: Plot h[n]
subplot(3, 1, 2);
stem(h, 'LineWidth', 1.5, 'MarkerFaceColor', 'red');
title('Impulse Response h[n]');
ylabel('Amplitude');
grid on;
ax = gca;
ax.XAxis.Limits = [0, numel(h) + 1];
ax.YAxis.Limits = [min(h)-0.5, max(h)+0.5];

% Subplot 3: Plot Output Signal y[n]
subplot(3, 1, 3);
stem(y, 'LineWidth', 1.5, 'MarkerFaceColor', 'green');
title('Output Signal y[n] = x[n]*h[n]');
xlabel('n (samples)');
ylabel('Amplitude');
grid on;
ax = gca;
ax.XAxis.Limits = [0, numel(y) + 1];
ax.YAxis.Limits = [min(y)-0.5, max(y)+0.5];

