
frame 每秒钟显示的帧频数
sample 和 frame 的区别
fft 快速傅里叶变换 NlogN


frame vs smaple

**样本**是数字音频中最小的可用量子。**帧**在纯音频术语中没有正式定义，但通常用于与可能伴随音频轨道的视频相关。在这种情况下，帧是视频帧间隔内采集的音频样本的数量。

如果每秒有 30 帧视频和每秒 48000 个音频样本，您可以说每帧有 48000 / 30 = 1600 个样本，或者说一个“音频帧”包含 1600 个样本，但实际上没有音频帧，这只是关于音频相对于视频帧率的谈话约定。

在某些媒体编码方案（如 DPX）中，帧可以包含视频和音频样本数据，因此将包含的音频样本称为音频帧很方便，但这是一种容器的属性，而不是音频本身的属性。

smaple rate
- frameCount Total Number of frames(consider channel)
- sampleRate Frequency 
- sampleSize depth of bit
- channel Number of channel

16 bit
samapleRate/channel


```c
UpdateMusicStream(music);
if (IsKeyPressed(KEY_SPACE)){
    if(IsMusicStreamPlaying(music)){
        PauseMusicStream(music);
    }else{
        ResumeMusicStream(music);
    }
}

```