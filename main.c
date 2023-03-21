#include <stdio.h>
#include "raylib.h"

#define N 9
#define w  50

typedef struct {

    int cells[9 * 9];
} grid_t;

int screenWidth = w * N;
int screenHeight = w * N;

int idx(int r, int c) { return r * N + c; }

void draw_board(const grid_t *grid) {

    for (int j = 0; j < N; ++j) {

        for (int i = 0; i < N; ++i) {

            Rectangle rec = {
                    i * w, // x
                    j * w, // y
                    w,     // width
                    w      // height
            };

            //   if (grid[idx(j, i)] != 0) {

            //   if (original_grid[idx(j, i)]) {
            DrawRectangleRec(rec, DARKPURPLE);
            //   }

            char str[10];
            sprintf(str, "%d", grid->cells[idx(j, i)]);

            int font_size = 18;
            int str_size = MeasureText(str, font_size);
            //        DrawText("0", i * w + w / 2.0 - str_size / 2.0,
            //               j * w + w / 2 - font_size / 2, font_size, RAYWHITE);

            DrawText("9", i * w + 20, j *w + 20, 20, RAYWHITE);

            DrawRectangleLines(i * w, j *w, w , w, RAYWHITE);
        }
    }
}

int main(void) {


    InitWindow(screenWidth, screenHeight, "Sudoku");

    SetTargetFPS(60);

    grid_t grid;

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            grid.cells[idx(j, i)] = 0;
        }
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        draw_board(&grid);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
