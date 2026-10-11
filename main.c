#include <raylib.h>

int main (void) {
    Rectangle botaoAbrir = {20, 120, 220, 40}; // Coordenada do botão


    InitWindow (800, 450, "Service Desk");

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        Color corbotao = LIGHTGRAY;

        if (CheckCollisionPointRec(mouse, botaoAbrir)) {
            corbotao = GRAY;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText ("SERVICE DESK", 300, 30, 30, GRAY);

        DrawRectangle (20, 120, 220, 40, corbotao);

        DrawText("ABRIR CHAMADO", 35, 130, 20, BLACK);


        EndDrawing();

    }
    CloseWindow();

    return 0;
}