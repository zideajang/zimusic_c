
import numpy as np
import matplotlib.pyplot as plt

y = np.array([
    0.000000,
    0.707107,
    1.000000,
    0.707107,
    -0.000000,
    -0.707107,
    -1.000000,
    -0.707107,
])

y_2= np.array([
    0.000000,
    1.306563,
    1.414214,
    0.541196,
    0.000000,
    0.541197,
    1.414214,
    1.306563,
    -0.000000,
    -1.306563,
    -1.414213,
    -0.541196,
    0.000000,
    -0.541196,
    -1.414214,
    -1.306563,
])

x = [i for i in range(16)]

fft_result = np.fft.fft(y_2)
freq = np.fft.fftfreq(len(y_2), d=x[1]-x[0])

# plt.plot(x,y_2)
plt.plot(freq, np.abs(fft_result))
plt.xlabel('Frequency')
plt.ylabel('Magnitude')
plt.show()
