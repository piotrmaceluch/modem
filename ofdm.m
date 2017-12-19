%============== PARAMETERS =========================
M = 8;
N = 1024;
%15 = m*fs / N
%
fs = 960; % 8*fmax
ts = 1/fs;
time  = 0 : ts : (N-1)*ts;

%===============================================================================
%===============================================================================
%================== MODULATOR ==================================================
%===============================================================================
%===============================================================================

%=================== BITS ==========================
modBits1 = [0,0,0,0];
modBits2 = [1,1,1,1];
modBits3 = [0,1,1,0];
modBits4 = [1,0,0,1];
modBits5 = [1,0,0,0];
modBits6 = [0,1,0,0];
modBits7 = [0,0,1,0];
modBits8 = [0,0,0,1];
%=================== SET Z =========================
z = [1:M];

z(1) = setInputZ(modBits1);
z(2) = setInputZ(modBits2);
z(3) = setInputZ(modBits3);
z(4) = setInputZ(modBits4);
z(5) = setInputZ(modBits5);
z(6) = setInputZ(modBits6);
z(7) = setInputZ(modBits7);
z(8) = setInputZ(modBits8);


%================ FREQUENCIES ======================
modFrequencies = [1:M];
for n = 1:M;
  modFrequencies(n) = n*15;
endfor
%=========== ANGULAR VELOCITIES ====================
angularVelocities = [1:M];
for x = 1:M;
  angularVelocity(x) = 2*pi*modFrequencies(x);
endfor
%==================== Z ============================

%============== SET AMPLITUDES =====================
modAmplitudes = [1:M];

for n = 1:M
  modAmplitudes(n) = abs(z(n));
endfor
%================ SET PHASES =======================
modPhases = [1:M];

for n = 1:M
  modPhases(n) = arg(z(n));
endfor
%============== SUBCARRIERS ========================
modulatorSc1 = [1:N];
modulatorSc2 = [1:N];
modulatorSc3 = [1:N];
modulatorSc4 = [1:N];
modulatorSc5 = [1:N];
modulatorSc6 = [1:N];
modulatorSc7 = [1:N];
modulatorSc8 = [1:N];
%=============== GENERATOR =========================

for x = 1:N
    modulatorSc1(x) = z(1) * e^(angularVelocity(1) * time(x)*i);
    modulatorSc2(x) = z(2) * e^(angularVelocity(2) * time(x)*i);
    modulatorSc3(x) = z(3) * e^(angularVelocity(3) * time(x)*i);
    modulatorSc4(x) = z(4) * e^(angularVelocity(4) * time(x)*i);
    modulatorSc5(x) = z(5) * e^(angularVelocity(5) * time(x)*i);
    modulatorSc6(x) = z(6) * e^(angularVelocity(6) * time(x)*i);
    modulatorSc7(x) = z(7) * e^(angularVelocity(7) * time(x)*i);
    modulatorSc8(x) = z(8) * e^(angularVelocity(8) * time(x)*i);
endfor
%============ PLOT SUBCARRIERS =====================
figure
ax1 = subplot(9,1,1);
plot(ax1, time, modulatorSc1);
title('15kHz');
hold on;

ax2 = subplot(9,1,2);
plot(ax2, time, modulatorSc2);
title('30kHz');
hold on;

ax3 = subplot(9,1,3);
plot(ax3, time, modulatorSc3);
title('45kHz');
hold on;

ax4 = subplot(9,1,4);
plot(ax4, time, modulatorSc4);
title('60kHz');
hold on;

ax5 = subplot(9,1,5);
plot(ax5, time, modulatorSc5);
title('75kHz');
hold on;

ax6 = subplot(9,1,6);
plot(ax6, time, modulatorSc6);
title('90kHz');
hold on;

ax7 = subplot(9,1,7);
plot(ax7, time, modulatorSc7);
title('105kHz');
hold on;

ax8 = subplot(9,1,8);
plot(ax8, time, modulatorSc8);
title('120kHz');
hold on;
%==================== IDFT =========================
IDFT = [1:N];
IDFT = (modulatorSc1+modulatorSc2+modulatorSc3+modulatorSc4+modulatorSc5+modulatorSc6+modulatorSc7+modulatorSc8);
ax9 = subplot(9,1,9);
plot(ax9, time, IDFT, 'r')
title('sum of subcarriers');
hold on;
%============ EXTRACT REAL PART ====================
for n = 1:N
  realPart(n) = real(IDFT(n));
endfor



%===============================================================================
%===============================================================================
%================= DEMODULATOR =================================================
%===============================================================================
%===============================================================================


demodulatorInput = realPart;
%================ fAnalysis ========================
for m = 1:N
  fAnalysis(m) = (m-1)*fs/N;
endfor
%=================== DFT ===========================
figure
DFT = fft(demodulatorInput);
plot(fAnalysis, abs(DFT));
title('DFT');
hold on;
%=========== CREATE SUBCARRIERS ====================         
demFrequencies = [1:M];
demAmplitudes = [1:M];
demPhases = [1:M];

counter = 1;
for k= 1 : N/2
  if (abs(DFT(k)) > 1) && counter < 9
    demFrequencies(counter) = fAnalysis(k);
    demAmplitudes(counter) = abs(DFT(k));
    demPhases(counter) = angle(DFT(k));
    counter++;
  end
endfor
%=========== AMPLITUDES SCALING ====================
for m = 1:M
  demAmplitudes(m) = demAmplitudes(m) * 2.0/N;
endfor

%============== SET OUTPUT BITS ====================

demBits1 = setOutputBits(demAmplitudes(1), demPhases(1));
demBits2 = setOutputBits(demAmplitudes(2), demPhases(2));
demBits3 = setOutputBits(demAmplitudes(3), demPhases(3));
demBits4 = setOutputBits(demAmplitudes(4), demPhases(4));
demBits5 = setOutputBits(demAmplitudes(5), demPhases(5));
demBits6 = setOutputBits(demAmplitudes(6), demPhases(6));
demBits7 = setOutputBits(demAmplitudes(7), demPhases(7));
demBits8 = setOutputBits(demAmplitudes(8), demPhases(8));

%=========== SHOW AMPLITUDES & PHASES ==============
figure
scArray = 1 : 1 : M;
ax20 = subplot(4,1,1);
plot(ax20, scArray, demAmplitudes,'.-r', 'MarkerSize',10);
title('modulator Amplitudes');

ax21 = subplot(4,1,2);
plot(ax21, scArray, demAmplitudes,'.-r', 'MarkerSize',10);
title('demodulator Amplitudes');

ax30 = subplot(4,1,3);
plot(ax30, scArray, modPhases,'.-r', 'MarkerSize',10);
title('modulator Phases[Rad]');


ax31 = subplot(4,1,4);
plot(ax31, scArray, demPhases,'.-r', 'MarkerSize',10);
title('demodulator Phases[Rad]');

%=========== SHOW INPUT AND OUTPUT BITS ============
bitsVector = [1:1:4];
figure
ax41 = subplot(8,1,1);
plot(ax41, bitsVector, demBits1,'.-r', 'MarkerSize',10);
title('input Bits');
ax42 = subplot(8,1,2);
plot(ax42, bitsVector, demBits2,'.-r', 'MarkerSize',10);
ax43 = subplot(8,1,3);
plot(ax43, bitsVector, demBits3,'.-r', 'MarkerSize',10);
ax44 = subplot(8,1,4);
plot(ax44, bitsVector, demBits4,'.-r', 'MarkerSize',10);
ax45 = subplot(8,1,5);
plot(ax45, bitsVector, demBits5,'.-r', 'MarkerSize',10);
ax46 = subplot(8,1,6);
plot(ax46, bitsVector, demBits6,'.-r', 'MarkerSize',10);
ax47 = subplot(8,1,7);
plot(ax47, bitsVector, demBits7,'.-r', 'MarkerSize',10);
ax48 = subplot(8,1,8);
plot(ax48, bitsVector, demBits8,'.-r', 'MarkerSize',10);
%---------------------------------------------------
figure
ax51 = subplot(8,1,1);
plot(ax51, bitsVector, modBits1,'.-r', 'MarkerSize',10);
title('output Bits');
ax52 = subplot(8,1,2);
plot(ax52, bitsVector, modBits2,'.-r', 'MarkerSize',10);
ax53 = subplot(8,1,3);
plot(ax53, bitsVector, modBits3,'.-r', 'MarkerSize',10);
ax54 = subplot(8,1,4);
plot(ax54, bitsVector, modBits4,'.-r', 'MarkerSize',10);
ax55 = subplot(8,1,5);
plot(ax55, bitsVector, modBits5,'.-r', 'MarkerSize',10);
ax56 = subplot(8,1,6);
plot(ax56, bitsVector, modBits6,'.-r', 'MarkerSize',10);
ax57 = subplot(8,1,7);
plot(ax57, bitsVector, modBits7,'.-r', 'MarkerSize',10);
ax58 = subplot(8,1,8);
plot(ax58, bitsVector, modBits8,'.-r', 'MarkerSize',10);