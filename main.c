#include <raylib.h>
#include <stdio.h>
#include <stdbool.h>

void desenhar_menu (Rectangle botao, Color corbotao) {
    DrawText ("SERVICE DESK", 300, 30, 30, GRAY);

    DrawRectangleRec (botao, corbotao);

    DrawText("ABRIR CHAMADO", 35, 130, 20, BLACK);
}

void desenhar_abrir_chamado (Rectangle botao, Rectangle CampoUsuario, Color corbotao, Color Cor_campo) {
    
    DrawText("ABRIR CHAMADO", 30, 30, 30, DARKGRAY);

    DrawText("Usuário: ", 30, 130, 20, BLACK);
    DrawRectangleRec(CampoUsuario, Cor_campo);
    DrawText("[________________________]", 30, 150, 20, BLACK);

    DrawRectangleRec(botao, corbotao);

    DrawText ("VOLTAR", 695, 410, 20, BLACK);

}

bool botao_clicado (Rectangle botao, Vector2 mouse) {
    if (CheckCollisionPointRec(mouse, botao) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return true;
    } else {
        return false;
    }
}

Color cor_do_botao (Rectangle botao, Vector2 mouse) {
    if (CheckCollisionPointRec(mouse, botao)) {
        return GRAY;
    } else {
        return LIGHTGRAY;
    }
}



int main (void) {
    // CAMPOS OU 'BOTÕES' 
    Rectangle botao = {20, 120, 220, 40}; // Coordenada do botão

    Rectangle CampoUsuario = {30, 150, 300, 20};
    Color Cor_campo = LIGHTGRAY;


    InitWindow (800, 450, "Service Desk"); // ABRE JANELA

    int tela = 0; // 'TELA/JANELA' inicial


    bool CampoUsuario_clicado = false;//

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();


        BeginDrawing();

        ClearBackground(RAYWHITE);


        if (tela == 0) {
            Color corbotao = cor_do_botao(botao, mouse);
            if (botao_clicado(botao, mouse)) {
                tela = 1;
            }
        desenhar_menu(botao, corbotao);

        } else if (tela == 1) {
            Rectangle botao = {680, 400, 115, 40};
            Color corbotao = cor_do_botao(botao, mouse);

            if (botao_clicado(botao, mouse)) {
                tela = 0;
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(mouse, CampoUsuario)){
                    CampoUsuario_clicado = true;
                } else {
                CampoUsuario_clicado = false;
                }
            }

            if (CampoUsuario_clicado) {
                Cor_campo = GRAY;
            } else {
                Cor_campo = LIGHTGRAY;
            }
            
            desenhar_abrir_chamado(botao, CampoUsuario, corbotao, Cor_campo);
        }


        EndDrawing();

    }
    CloseWindow();

    return 0;
}