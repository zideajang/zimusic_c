#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>


#include <stdint.h>
#include <unistd.h>

#include <raylib.h>
#include <raymath.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

const int screenWidth = 800;
const int screenHeight = 600;

#define FRAMES_CAPACITY 4080
int32_t global_frames[FRAMES_CAPACITY] = {0};
size_t global_frame_count = 0;

// size_t capacity = 0;

void callback(void *bufferData, unsigned int frames)
{
    // 2 channle
    // size_t s = sizeof((int32_t*)bufferData)/sizeof(int32_t);
    // printf( "%zu\n",s);

    if(frames > ARRAY_LEN(global_frames)){
        frames = ARRAY_LEN(global_frames);
    }
    memcpy(global_frames,bufferData,frames*sizeof(uint32_t));
    // 2 channel 16bit 32bit
    global_frame_count = frames;

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
            int16_t sample = *(int16_t*)&global_frames[i];
            
            if(sample > 0){
                float t = (float)sample/INT16_MAX;
                DrawRectangle(i*cell_width,h/2 - h/2*t,cell_width,h/2*t,RED);
            }else{
                float t = (float)sample/INT16_MIN;
                
                DrawRectangle(i*cell_width,h/2,cell_width,h/2*t,RED);
            }
            // printf("%d ",sample);
        }
        EndDrawing();
    
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}