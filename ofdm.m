
A1 = 4.24265;
fi1= 3.92669;
f1 = 15000;

A2 = 1.41421;
fi2= 0.785398;
f2 = 30000;

A3 = 3.16228;
fi3= 5.96143;
f3 = 45000;

A4 = 4.24264;
fi4= 0.785398;
f4 = 60000;

N = 1024;
fs = 5*f4;
ts = 1/fs;
t  = 0 : ts : (N-1)*ts;

z1 = A1*e^(fi1*i);
z2 = A2*e^(fi2*i);
z3 = A3*e^(fi3*i);
z4 = A4*e^(fi4*i);

gen1 = [0:N-1];
gen2 = [0:N-1];
gen3 = [0:N-1];
gen4 = [0:N-1];

for n = 1:N
  gen1(n) = z1 * A1*e^(2*pi*f1*t(n)*i);
  gen2(n) = z2 * A2*e^(2*pi*f2*t(n)*i);
  gen3(n) = z3 * A3*e^(2*pi*f3*t(n)*i);
  gen4(n) = z4 * A4*e^(2*pi*f4*t(n)*i);
endfor

ax1 = subplot(6,1,1);
plot(ax1,t,gen1,'g');
xlabel('frequency');
ylabel('Amplitude');
legend('15kHz');

ax2 = subplot(6,1,2);
plot(ax2,t,gen2,'b');
xlabel('frequency');
ylabel('Amplitude');
legend('30kHz');

ax3 = subplot(6,1,3);
plot(ax3,t,gen3,'r');
xlabel('frequency');
ylabel('Amplitude');
legend('45kHz');

ax4 = subplot(6,1,4);
plot(ax4,t,gen4,'c');
xlabel('frequency');
ylabel('Amplitude');
legend('60kHz');

sum = gen1+gen2+gen3+gen4;

ax4 = subplot(6,1,5);
plot(ax4,t,sum,'k');
xlabel('frequency');
ylabel('Amplitude');
legend('15kHz + 30kHz + 45kHz + 60kHz');

fAnalysis = [0:N-1];
for n = 1:N
  fAnalysis(n) = n*fs/N;
endfor  

ax6 = subplot(6,1,6);
Y = abs(fft(sum));
plot(ax6,fAnalysis, Y);
xlabel('frequency');
ylabel('Amplitude');
legend('fft(sum of signals)');