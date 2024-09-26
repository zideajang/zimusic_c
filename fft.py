import math
import numpy as np

import matplotlib.pyplot as plt


t = np.linspace(0, 7, 8)
x = [i/8.0 for i in t]
y = [1 for i in range(8)]
f_1 = 1.0
f_2 = 3.0
y = [np.cos( f_1 * 2.0 * math.pi * t) + np.cos(f_2 * 2.0 *math.pi* t) for t in x]

out_sin = []
out_cos = []
for f in range(8):
    temp_sin = 0
    temp_cos = 0
    for i in range(8):
        temp_sin += y[i]*math.sin(2*math.pi * x[i]* f) 
        temp_cos += y[i]*math.cos(2*math.pi * x[i]* f) 
    out_sin.append(temp_sin)
    out_cos.append(temp_cos)
print(out_sin)
print(out_cos)
# plt.scatter(x,y)
# plt.show()




exit(0)

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
