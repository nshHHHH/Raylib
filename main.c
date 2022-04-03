#include "raylib.h"
 int btnState = 0;
 bool btnAction = false;
 Vector2 mousePoint = { 0.0f, 0.0f };
int main()
{ //mingw32-make
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Music Player");
    //кнопка 
    Texture2D button = LoadTexture("resources/play.png"); // Load button texture
    float frameHeight = (float)button.height;
    Rectangle sourceRecPlay = { 0, 0, (float)button.width, frameHeight };
    Rectangle btnBoundsPlay = { screenWidth / 2.2f - button.width / 2.5f, screenHeight / 1.8f - button.height / 3.0f, (float)button.width, frameHeight };
    //кнопка 
    Texture2D button2 = LoadTexture("resources/pause.png"); // Load button texture
    float frameHeight2 = (float)button2.height;
    Rectangle sourceRecStop = { 0, 0, (float)button2.width, frameHeight2 };
    Rectangle btnBoundsStop = { screenWidth / 2.0f - button2.width / 2.5f, screenHeight / 1.8f - button2.height / 3.0f, (float)button2.width, frameHeight2 };
    //кнопка  - 3
    Texture2D button3 = LoadTexture("resources/volumemunis.png"); // Load button texture
    float frameHeight3 = (float)button3.height;
    Rectangle sourceRecVolume = { 0, 0, (float)button3.width, frameHeight3 };
    Rectangle btnBoundsVolume = { screenWidth / 2.5f - button3.width / 2.5f, screenHeight / 1.8f - button3.height / 3.0f, (float)button3.width, frameHeight3 };
    //кнопка - 4
    Texture2D button4 = LoadTexture("resources/volume.png"); // Load button texture
    float frameHeight4 = (float)button4.height;
    Rectangle sourceRecVolum = { 0, 0, (float)button4.width, frameHeight4 };
    Rectangle btnBoundsVolum = { screenWidth / 1.8f - button4.width / 2.5f, screenHeight / 1.8f - button4.height / 3.0f, (float)button4.width, frameHeight4 };
    //кнопка - 5
    Texture2D button5 = LoadTexture("resources/left.png"); // Load button texture
    float frameHeight5 = (float)button5.height;
    Rectangle sourceRecPitch = { 0, 0, (float)button5.width, frameHeight5 };
    Rectangle btnBoundsPitch = { screenWidth / 2.2f - button5.width / 2.5f, screenHeight / 1.4f - button5.height / 3.0f, (float)button5.width, frameHeight5 };
    //кнопка - 6
    Texture2D button6 = LoadTexture("resources/next.png"); // Load button texture
    float frameHeight6 = (float)button6.height;
    Rectangle sourceRecPitchplus = { 0, 0, (float)button6.width, frameHeight6 };
    Rectangle btnBoundsPitchplus = { screenWidth / 2.0f - button6.width / 2.5f, screenHeight / 1.4f - button6.height / 3.0f, (float)button6.width, frameHeight6 };
    //кнопка - 7
    Texture2D button7 = LoadTexture("resources/repeat.png"); // Load button texture
    float frameHeight7 = (float)button7.height;
    Rectangle sourceRecrewind = { 0, 0, (float)button7.width, frameHeight7 };
    Rectangle btnBoundsrewind = { screenWidth / 2.1f - button7.width / 2.5f, screenHeight / 1.6f - button7.height / 3.0f, (float)button7.width, frameHeight7};
    //кнопка - 8
    Texture2D button8 = LoadTexture("resources/fast.png"); // Load button texture
    float frameHeight8 = (float)button8.height;
    Rectangle sourceRecPosition = { 0, 0, (float)button8.width, frameHeight8 };
    Rectangle btnBoundsPosition = { screenWidth / 1.93f - button8.width / 2.5f, screenHeight / 1.6f - button8.height / 3.0f, (float)button8.width, frameHeight8 };
    //кнопка - 9
    Texture2D button9 = LoadTexture("resources/previous.png"); // Load button texture
    float frameHeight9 = (float)button9.height;
    Rectangle sourceRecPrevious = { 0, 0, (float)button9.width, frameHeight9 };
    Rectangle btnBoundsPrevious = { screenWidth / 2.3f - button9.width / 2.5f, screenHeight / 1.6f - button9.height / 3.0f, (float)button9.width, frameHeight9 };
    InitAudioDevice();              // Initialize audio device
    float pitch = 1.0f;
    float volume = 1.0f;
    float position = 0.3f;
    Music music = LoadMusicStream("resources/2.mp3");
    PlayMusicStream(music);
    float timePlayed = 0.0f;
    float timePlayed_2 = 0.0f;
    float timePlayed_3 = 0.0f;
    bool pause = false;
    SetTargetFPS(60);              
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        mousePoint = GetMousePosition();
        btnAction = false;
        UpdateMusicStream(music);   // Update music buffer with new stream data
        if (CheckCollisionPointRec(mousePoint, btnBoundsPlay))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction)
        {
            ResumeMusicStream(music);
            btnAction = false;
            btnState = 0;
        }
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsStop))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState= 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState= 0;
        if (btnAction)
        {
            pause = !pause;
            if (pause) PauseMusicStream(music);
            btnAction = false;
            btnState = 0;
        }
        
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsVolume))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction)
        {
            
            volume--;
            SetMusicVolume(music, volume);

            btnAction = false;
            btnState = 0;
        }
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsVolum))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction)
        {
            
            volume++;
            SetMusicVolume(music, volume);

            btnAction = false;
            btnState = 0;
        }
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsPitch))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction)
        {
            pitch -= 0.01f;
            SetMusicPitch(music, pitch);

            btnAction = false;
            btnState = 0;
        }

        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsPitchplus))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction)
        {

           
            pitch += 0.01f;
            SetMusicPitch(music, pitch);

            btnAction = false;
            btnState = 0;
        }
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsrewind))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if ((btnAction) || (IsKeyPressed(KEY_SPACE)))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
            
            btnAction = false;
            btnState = 0;
        }
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsPosition))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if ((btnAction))
        {
            position++;
            SeekMusicStream(music, position);

            btnAction = false;
            btnState = 0;
        }
        //mingw32-make
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBoundsPrevious))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if ((btnAction))
        {

            if(position < 0.05f)  StopMusicStream(music);
                position--;
            SeekMusicStream(music, position);

            btnAction = false;
            btnState = 0;
        }
        timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music) * 400;
        if (timePlayed > 400) StopMusicStream(music);
        if (timePlayed < 0.f)             ResumeMusicStream(music);
        timePlayed_2 = GetMusicTimePlayed(music)/60;
        timePlayed_3 =  (GetMusicTimeLength(music) - GetMusicTimePlayed(music))/60;
        sourceRecPlay.y = btnState * frameHeight;
        sourceRecStop.y = btnState * frameHeight2;
        sourceRecVolume.y = btnState * frameHeight3;
        sourceRecVolum.y = btnState * frameHeight4;
        sourceRecPitch.y = btnState * frameHeight5;
        sourceRecPitchplus.y = btnState * frameHeight6;
        sourceRecrewind.y = btnState * frameHeight7;
        sourceRecPosition.y = btnState * frameHeight8;
        sourceRecPrevious.y = btnState * frameHeight9;
        GetMusicTimeLength(music);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("This is my music player!", 270, 150, 20, LIGHTGRAY);
        DrawText(TextFormat("%.2f", (float)timePlayed_2), 545, 220, 30, BLACK);
        DrawText(TextFormat("%.2f", (float)timePlayed_3), 200, 220, 30, BLACK);
        DrawRectangle(200, 200, 400, 12, LIGHTGRAY);
        DrawRectangle(200, 200, (int)timePlayed, 12, MAROON);
        DrawRectangleLines(200, 200, 400, 12, GRAY);
         //mingw32-make
        DrawTextureRec(button, sourceRecPlay, (Vector2) { btnBoundsPlay.x, btnBoundsPlay.y }, WHITE);
        DrawTextureRec(button2, sourceRecStop, (Vector2) { btnBoundsStop.x, btnBoundsStop.y }, WHITE);
        DrawTextureRec(button3, sourceRecVolume, (Vector2) { btnBoundsVolume.x, btnBoundsVolume.y }, WHITE);
        DrawTextureRec(button4, sourceRecVolum, (Vector2) { btnBoundsVolum.x, btnBoundsVolum.y }, WHITE);
        DrawTextureRec(button5, sourceRecPitch, (Vector2) { btnBoundsPitch.x, btnBoundsPitch.y }, WHITE);
        DrawTextureRec(button6, sourceRecPitchplus, (Vector2) { btnBoundsPitchplus.x, btnBoundsPitchplus.y }, WHITE);
        DrawTextureRec(button7, sourceRecrewind, (Vector2) { btnBoundsrewind.x, btnBoundsrewind.y }, WHITE);
        DrawTextureRec(button8, sourceRecPosition, (Vector2) { btnBoundsPosition.x, btnBoundsPosition.y }, WHITE);
        DrawTextureRec(button9, sourceRecPrevious, (Vector2) { btnBoundsPrevious.x, btnBoundsPrevious.y }, WHITE);
        EndDrawing();
    }
       ClearBackground(RAYWHITE);
        UnloadMusicStream(music);
        for (int i = 0; i <= 9; i++) {
            UnloadTexture(button);
        }
        CloseAudioDevice();        
        CloseWindow();             
    return 0;
}