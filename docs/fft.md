
# FFT(快速傅里叶变换)

## 背景
将时间域或空间域问题转换频率域上的问题
DFT(离散傅里叶变换)
FFT(快速傅里叶变换)

- 高效的计算DFT(理算傅里叶变化)的方法


$$
X[k] = \sum_{i=0}^{N-1} x_n  e^{-\frac{i 2\pi}{N} k_n}
$$

$$
e^{in} = \cos(n) + i\sin(n)
$$

$$
t_i = \frac{x_i}{N}, x_{i \in \{0...N\}}
$$

$$
y_i = \sin(2 \pi t_i \times (freq_1)) + \sin(2\pi t_i  \times (freq_2) )
$$

$$
freq_{out} = \sum_{i=0}^N y_i \sin(2\pi t_i \times freq)
$$


```c
for (size_t i = 0; i < SMAPLE_N; i++)
{
    float t = (float)i/SMAPLE_N;
    // in[i] = sinf(2*pi*t*1) + sinf(2*pi*t*2);
    in[i] = cosf(2*pi*t*1) + cosf(2*pi*t*2);
}

for (size_t f = 0; f <SMAPLE_N; f++)
{
    printf("%f\n",in[f]);
    out_sin[f] = 0;
    out_cos[f] = 0;
    for (size_t i = 0; i < SMAPLE_N; i++)
    {
        float t = (float)i/SMAPLE_N;
        out_sin[f] += in[i]*sinf(2*pi*f*t);
        out_cos[f] += in[i]*cosf(2*pi*f*t);
    }
}

for (size_t f = 0; f < SMAPLE_N; f++)
{
    printf("%02zu: sin: %.2f, cos:%.2f\n",f,out_sin[f],out_cos[f]);
}
```

## 复数
$$
e^{ix} = \cos x + i \sin x
$$