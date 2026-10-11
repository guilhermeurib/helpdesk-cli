#include <raylib.h>
#include <stdio.h>

int main (void) {
    Rectangle botaoAbrir = {20, 120, 220, 40}; // Coordenada do botão


    InitWindow (800, 450, "Service Desk");

    int tela = 0;

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        Color corbotao = LIGHTGRAY;

        if (CheckCollisionPointRec(mouse, botaoAbrir)) {
            corbotao = GRAY;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                tela = 1;
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);


        if (tela == 0) {
            DrawText ("SERVICE DESK", 300, 30, 30, GRAY);

            DrawRectangle (20, 120, 220, 40, corbotao);

            DrawText("ABRIR CHAMADO", 35, 130, 20, BLACK);

        }

        if (tela == 1) {
            DrawText("ABRIR CHAMADO", 30, 30, 30, DARKGRAY);
        }


        EndDrawing();

    }
    CloseWindow();

    return 0;
}