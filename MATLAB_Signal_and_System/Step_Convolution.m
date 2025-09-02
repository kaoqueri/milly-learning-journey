%% The Convolution Integral
close all; % Close every figure before

% Define time vector and step for continuous-time approximation
dt = 0.01;
tau = -2:dt:5; % Time vector for the input functions

% Define the input signals as functions of tau
% x(tau) = u(tau), the unit step function
x = (tau >= 0);
% h(tau) = u(2-tau), a time-reversed and shifted unit step function
h = (tau <= 2);

% Calculate the product of x(tau) and h(tau)
% The result is 1 only where both functions are 1 (i.e., 0 <= tau <= 2)
% This creates a rectangular pulse: u(t) - u(t-2)
y_product = x & h; % Logical AND gives the product for 0/1 signals

% --- PLOT ---

% Create a single figure window
figure;

% Subplot 1: Plot x(tau)
subplot(3, 1, 1); % (rows, columns, index)
plot(tau, x, 'LineWidth', 1.5, 'Color', 'blue'); 
title('x(\tau) = u(\tau)');
ylabel('Amplitude');
grid on;
ax = gca;
ax.YAxis.Limits = [-0.2, 1.2];
ax.XAxis.Limits = [tau(1), tau(end)];

% Subplot 2: Plot h(2-tau)
subplot(3, 1, 2);
plot(tau, h, 'LineWidth', 1.5, 'Color', 'red');
title('h(2-\tau) = u(2-\tau)');
ylabel('Amplitude');
grid on;
ax = gca;
ax.YAxis.Limits = [-0.2, 1.2];
ax.XAxis.Limits = [tau(1), tau(end)];

% Subplot 3: Plot Product Signal y(t)
subplot(3, 1, 3);
plot(tau, y_product, 'LineWidth', 1.5, 'Color', 'green');
title('Result y(\tau) = x(\tau)h(\tau) = u(\tau) - u(\tau-2)');
xlabel('\tau (time)');
ylabel('Amplitude');
grid on;
ax = gca;
ax.XAxis.Limits = [tau(1), tau(end)];
ax.YAxis.Limits = [-0.2, 1.2];

