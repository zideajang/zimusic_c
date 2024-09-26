#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>


#include <stdint.h>
#include <unistd.h>

#include <raylib.h>
#include <raymath.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

typedef struct{
    float left;
    float right;
}Frame;

const int screenWidth = 800;
const int screenHeight = 600;

#define FRAMES_CAPACITY 4800
Frame global_frames[FRAMES_CAPACITY*2] = {0};
size_t global_frame_count = 0;

// size_t capacity = 0;

void callback(void *bufferData, unsigned int frames)
{
    // 2 channle
    // size_t s = sizeof((int32_t*)bufferData)/sizeof(int32_t);
    // printf( "%zu\n",s);

    size_t capacity = ARRAY_LEN(global_frames);

    if(frames <= capacity -  global_frame_count ){
        memcpy(global_frames + global_frame_count,bufferData,frames*sizeof(Frame));
        global_frame_count += frames;
    }else if(frames <= capacity){
        // element , bit size
        memmove(global_frames,global_frames + frames,sizeof(Frame)*(capacity - frames));
        memcpy(global_frames + (capacity-frames),bufferData,sizeof(Frame)*frames);
    }else{
        memcpy(global_frames,bufferData,sizeof(Frame)*capacity);
        global_frame_count = capacity;
    }


    // (void)bufferData;
    // int16_t* frame = bufferData;    
    // (void)frames;
    // printf("callback(frame = %u)\n",frames);
}

int main(void)
{
    
    InitWindow(screenWidth, screenHeight, "sound loading and playing");
    InitAudioDevice();
    // Sound  fxOgg = LoadSound("example.ogg");
    // TODO
    Music  music = LoadMusicStream("example.ogg");
    
    // TODO
    assert(music.stream.sampleSize == 16);
    assert(music.stream.channels == 2);
    // zimusic_c
    // printf("music.frameCount = %u\n",music.frameCount);
    // printf("music.stream.sampleRate = %u\n",music.stream.sampleRate);
    // printf("music.stream.sampleSize = %u\n",music.stream.sampleSize);
    // printf("music.stream.channels = %u\n",music.stream.channels);
    
    
    PlayMusicStream(music);
    // 
    SetMusicVolume(music,0.5f);
    AttachAudioStreamProcessor(music.stream,callback);

    SetTargetFPS(60);   

    int w = GetRenderWidth();
    int h = GetRenderHeight();

    while(!WindowShouldClose())
    {
        UpdateMusicStream(music);
        if (IsKeyPressed(KEY_SPACE)){
            if(IsMusicStreamPlaying(music)){
                PauseMusicStream(music);
            }else{
                ResumeMusicStream(music);
            }
        }
        

        BeginDrawing();
        ClearBackground(CLITERAL(Color){0x18, 0x18, 0x18, 0xFF});
        
        float cell_width = (float)w/global_frame_count;

        for (size_t i = 0; i < global_frame_count; i++)
        {
            float t = global_frames[i].left;
            
            if(t > 0){
                DrawRectangle(i*cell_width,h/2 - h/2*t,1,h/2*t,RED);
            }else{
                DrawRectangle(i*cell_width,h/2,1,h/2*t,RED);
            }
            // printf("%d ",sample);
        }
        EndDrawing();
    
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}