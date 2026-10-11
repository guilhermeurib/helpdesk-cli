#include <raylib.h>
#include <stdio.h>

void desenhar_menu (Rectangle botao, Color corbotao) {
    DrawText ("SERVICE DESK", 300, 30, 30, GRAY);

    DrawRectangle (20, 120, 220, 40, corbotao);

    DrawText("ABRIR CHAMADO", 35, 130, 20, BLACK);
}

void desenhar_abrir_chamado (Rectangle botao, Color corbotao) {
    DrawText("ABRIR CHAMADO", 30, 30, 30, DARKGRAY);

    DrawRectangleRec(botao, corbotao);

    DrawText ("VOLTAR", 695, 410, 20, BLACK);

}
int main (void) {
    Rectangle botao = {20, 120, 220, 40}; // Coordenada do botão


    InitWindow (800, 450, "Service Desk");

    int tela = 0;

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        Color corbotao = LIGHTGRAY;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (tela == 0) {
            if (CheckCollisionPointRec(mouse, botao)) {
            corbotao = GRAY;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                tela = 1;
            }
        }

        desenhar_menu(botao, corbotao);

        } else if (tela == 1) {
            Rectangle botao = {680, 400, 115, 40};

            if (CheckCollisionPointRec(mouse, botao)) {
                corbotao = GRAY;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    tela = 0;
                }
            }

            desenhar_abrir_chamado(botao, corbotao);

        }


        EndDrawing();

    }
    CloseWindow();

    return 0;
}