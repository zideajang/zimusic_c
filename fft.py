import math
import numpy as np

import matplotlib.pyplot as plt


t = np.linspace(0, 7, 8)
x = [i/8.0 for i in t]
y = [np.sin( 1.0 * 2.0 * math.pi * t) + np.sin(3.0 * 2.0 *math.pi* t) for t in x]

fft_result = np.fft.fft(y)
print(fft_result)
print(f"x {x}, y:{y}")
# 
exit(0)

freq = np.fft.fftfreq(len(y), d=x[1]-x[0])
# plt.plot(x,y)
plt.plot(freq, np.abs(fft_result))
plt.xlabel('Frequency')
plt.ylabel('Magnitude')
plt.show()
