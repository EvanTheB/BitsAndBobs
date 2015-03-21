import numpy
from scipy import signal
import matplotlib.pyplot as plt

DOWN = 3
UP = 3

N = (1024/DOWN) * DOWN
fs = 10. ** 3
T = 1 / fs


f1 = 0.1 * fs
f2 = 0.2 * fs
f3 = 0.4 * fs

plt.grid()

t = numpy.linspace(0, N * T, N)
sig = (0.8 * numpy.sin(2 * numpy.pi * t * f1) +
       1.0 * numpy.sin(2 * numpy.pi * t * f2) +
       0.6 * numpy.sin(2 * numpy.pi * t * f3) +
       numpy.random.randn(N))

plt.magnitude_spectrum(sig, fs)
plt.show()

# sig_f = numpy.fft.fft(sig)
# x_f = numpy.fft.fftfreq(N,T)


filt = signal.firwin(DOWN*10, 1./UP)


w, h = signal.freqz(filt)
plt.plot(0.5*fs*w/numpy.pi, numpy.abs(h), 'b')
plt.show()

downsample = sig.reshape([-1, DOWN]).T
filt_down = filt.reshape([DOWN, -1])


out = []
for i in range(downsample.shape[0]):
    out.append(signal.lfilter(filt_down[i], 1, downsample[i]))

outarr = numpy.array(out)
final = outarr.reshape(-1)

# print out

plt.magnitude_spectrum(final, fs)
plt.show()
# plt.plot(t, sig_filt)
# plt.show()
# plt.plot(t, sig)
# plt.show()


# plt.plot(x_f[:N/2], numpy.abs(sig_f[:N/2]))
# plt.show()
