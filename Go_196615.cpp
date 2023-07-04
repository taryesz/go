#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"conio2.h"
#include<string.h>
#include<stdlib.h>
#include <string>
using namespace std;

#define MENU_X 6
#define MENU_Y 6

#define MAP_X 80
#define MAP_Y 5

#define WINDOW_BORDER_X 120
#define WINDOW_BORDER_Y 30

void put_i_checker(int& player, int& wsp, int& wspY, char** map, int& size) {
    if (player % 2 == 0) {

        if (wsp == 0 && wspY == 1 && map[wsp + 1][wspY - 1] == '*' && map[wsp][wspY] == '*') {
            // nic
        }
        else if (wsp == (size - 1) && wspY == 1 && map[wsp - 1][wspY - 1] == '*' && map[wsp][wspY] == '*') {
            // nic
        }
        else if (wsp == 0 && wspY == size && map[wsp + 1][wspY - 1] == '*' && map[wsp][wspY - 2] == '*') {
            // nic
        }
        else if (wsp == (size - 1) && wspY == size && map[wsp - 1][wspY - 1] == '*' && map[wsp][wspY - 2] == '*') {
            // nic
        }
        else if (map[wsp][wspY - 1] != 'o') {
            map[wsp][wspY - 1] = '*';
        }

    }
    else if (player % 2 != 0) {

        if (wsp == 0 && wspY == 1 && map[wsp + 1][wspY - 1] == 'o' && map[wsp][wspY] == 'o') {
            // nic
        }
        else if (wsp == (size - 1) && wspY == 1 && map[wsp - 1][wspY - 1] == 'o' && map[wsp][wspY] == 'o') {
            // nic
        }
        else if (wsp == 0 && wspY == size && map[wsp + 1][wspY - 1] == 'o' && map[wsp][wspY - 2] == 'o') {
            // nic
        }
        else if (wsp == (size - 1) && wspY == size && map[wsp - 1][wspY - 1] == 'o' && map[wsp][wspY - 2] == 'o') {
            // nic
        }
        else if (map[wsp][wspY - 1] != '*') {
            map[wsp][wspY - 1] = 'o';
        }

    }
}

void kill_white(char** map, int& size, int& i, int& k, int& j, int& black_players_count, string message_white_player) {
    map[i][k] = '+';
    textcolor(1);
    putch(map[i][k]);
    if (i != size - 1) {
        putch(' ');
    }
    black_players_count += 1;
    gotoxy(MENU_X, MENU_Y + 12);
    char buffer[1000];
    strcpy(buffer, message_white_player.c_str());
    sprintf(buffer, "The Black Player killed the White player %d times", black_players_count);
    cputs(buffer);
    gotoxy(MAP_X, j + 4);
}

void white_move(int& i, int& j, int& k, char** map, int& size, int& black_players_count, string message_white_player) {
    // sprawdzenie czy gracz Bialy znajduje sie w rogu planszy i jest otoczony prze gracza Czarnego

    // lewy gorny rog..
    if (i == 0 && k == 0 && map[i + 1][k] == '*' && map[i][k + 1] == '*') {
        kill_white(map, size, i, k, j, black_players_count, message_white_player);
    }
    // prawy gorny rog..
    if (i == (size - 1) && k == 0 && map[i - 1][k] == '*' && map[i][k + 1] == '*') {
        kill_white(map, size, i, k, j, black_players_count, message_white_player);
    }
    // lewy dolny rog..
    if (i == 0 && k == (size - 1) && map[i + 1][k] == '*' && map[i][k - 1] == '*') {
        kill_white(map, size, i, k, j, black_players_count, message_white_player);
    }
    // prawy dolny rog..
    if (i == (size - 1) && k == (size - 1) && map[i - 1][k] == '*' && map[i][k - 1] == '*') {
        kill_white(map, size, i, k, j, black_players_count, message_white_player);
    }

    // sprawdzenie czy gracz Bialy jest w otoczeniu gracza Czarnego ze wszystkich stron

    if (map[i][k - 1] == '*' && map[i][k + 1] == '*' && map[i - 1][k] == '*' && map[i + 1][k] == '*') {
        map[i][k] = '.';
        textcolor(1);
        putch(map[i][k]);
        if (i != size - 1) {
            putch(' ');
        }
        black_players_count += 1;
        gotoxy(MENU_X, MENU_Y + 12);
        char buffer[1000];
        strcpy(buffer, message_white_player.c_str());
        sprintf(buffer, "The Black Player killed the White player %d times", black_players_count);
        cputs(buffer);
        gotoxy(MAP_X, j);
    }
    else {
        textcolor(15);
        putch(map[i][k]);
        if (i != size - 1) {
            putch(' ');
        }
        textcolor(1);
    }
}

void kill_black(char** map, int& size, int& i, int& k, int& j, int& white_players_count, string message_black_player) {
    map[i][k] = '+';
    textcolor(1);
    putch(map[i][k]);
    if (i != size - 1) {
        putch(' ');
    }
    white_players_count += 1;
    gotoxy(MENU_X, MENU_Y + 13);
    char buffer[1000];
    strcpy(buffer, message_black_player.c_str());
    sprintf(buffer, "The White Player killed the Black player %d times", white_players_count);
    cputs(buffer);
    gotoxy(MAP_X, j + 4);
}

void black_move(int& i, int& j, int& k, char** map, int& size, int& white_players_count, string message_black_player) {

    // sprawdzenie czy gracz Bialy znajduje sie w rogu planszy i jest otoczony prze gracza Czarnego

    // lewy gorny rog..
    if (i == 0 && k == 0 && map[i + 1][k] == 'o' && map[i][k + 1] == 'o') {
        kill_black(map, size, i, k, j, white_players_count, message_black_player);
    }
    // prawy gorny rog..
    if (i == (size - 1) && k == 0 && map[i - 1][k] == 'o' && map[i][k + 1] == 'o') {
        kill_black(map, size, i, k, j, white_players_count, message_black_player);
    }
    // lewy dolny rog..
    if (i == 0 && k == (size - 1) && map[i + 1][k] == 'o' && map[i][k - 1] == 'o') {
        kill_black(map, size, i, k, j, white_players_count, message_black_player);
    }
    // prawy dolny rog..
    if (i == (size - 1) && k == (size - 1) && map[i - 1][k] == 'o' && map[i][k - 1] == 'o') {
        kill_black(map, size, i, k, j, white_players_count, message_black_player);
    }

    // sprawdzenie czy gracz Czarny jest w otoczeniu gracza Bialego ze wszystkich stron

    if (map[i][k - 1] == 'o' && map[i][k + 1] == 'o' && map[i - 1][k] == 'o' && map[i + 1][k] == 'o') {
        map[i][k] = '.';
        textcolor(1);
        putch(map[i][k]);
        if (i != size - 1) {
            putch(' ');
        }
        white_players_count += 1;
        gotoxy(MENU_X, MENU_Y + 13);
        char buffer[1000];
        strcpy(buffer, message_black_player.c_str());
        sprintf(buffer, "The White Player killed the Black player %d times", white_players_count);
        cputs(buffer);
        gotoxy(MAP_X, j);

    }
    else {
        textcolor(0);
        putch(map[i][k]);
        if (i != size - 1) {
            putch(' ');
        }
        textcolor(1);
    }
}

void initialize_board(int x, int y, int attr, int& player, char** map, int& size, int& black_players_count, int& white_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player, bool putI = false) {

    for (int i = MAP_Y, j = 0; i <= (MAP_Y + size); i++, j++) {
        convert_y[i] = j;
    }
    int wspY = convert_y[y];

    for (int i = MAP_X, j = 0; i <= (size * 2) - 2 + MAP_X; i = i + 2, j++) {
        convert_x[i] = j;
    }
    int wsp = convert_x[x];

    if (putI == true) {
        put_i_checker(player, wsp, wspY, map, size);
    }

    for (int j = MAP_Y, k = 0; j < (MAP_Y + size); j++, k++) {

        gotoxy(MAP_X, j + 1);

        for (int i = 0; i < size; i++) {

            // jezeli aktualnie jestesmy graczem Bialym...
            if (map[i][k] == 'o') {
                white_move(i, j, k, map, size, black_players_count, message_white_player);
            }
            // jezeli aktualnie jestesmy graczem Czarnym...
            else if (map[i][k] == '*') {
                black_move(i, j, k, map, size, white_players_count, message_black_player);
            }
            else {
                putch(map[i][k]);
                if (i != size - 1) {
                    putch(' ');
                }
            }
        }
    }
}

void draw_side_menu() {

    gotoxy(MENU_X, MENU_Y);
    cputs("arrows: move around");

    gotoxy(MENU_X, MENU_Y + 1);
    cputs("q: quit game");

    gotoxy(MENU_X, MENU_Y + 2);
    cputs("n: new game");

    gotoxy(MENU_X, MENU_Y + 3);
    cputs("i: place a stone");

    gotoxy(MENU_X, MENU_Y + 15);
    cputs("Copyright Taras Shuliakevych");

}

void show_coords(int zero, int wsp, int wspY, char txt[32]) {

    if (zero) sprintf(txt, "coords: %d %d   ", wsp + 1, wspY);
    else sprintf(txt, "coords: %d %d   ", wsp + 1, wspY);
    gotoxy(MENU_X, MENU_Y + 10);
    cputs(txt);

}

int main();

void new_game(int& player, int& white_players_count, int& black_players_count) {

    player = 1;
    white_players_count = 0;
    black_players_count = 0;
    main();

}

void black_player_logic(char** map, int& wsp, int& wspY, int& player, int& size, int x, int y, int attr, int& black_players_count, int& white_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player) {

    if (map[wsp][wspY - 1] == 'o' || map[wsp][wspY - 1] == '*') {
        player -= 1;
        //nic sie nie dzieje bo w tym miejscu jest juz kamien
    }

    // lewy gorny rog..
    if (wsp == 0 && wspY == 1 && map[wsp + 1][wspY - 1] == 'o' && map[wsp][wspY] == 'o') {
        player -= 1;
    }

    // prawy gorny rog..
    if (wsp == size - 1 && wspY == 1 && map[wsp - 1][wspY - 1] == 'o' && map[wsp][wspY] == 'o') {
        player -= 1;
    }

    // lewy dolny rog..
    if (wsp == 0 && wspY == size && map[wsp + 1][wspY - 1] == 'o' && map[wsp][wspY - 2] == 'o') {
        player -= 1;
    }

    // prawy dolny rog..
    if (wsp == size - 1 && wspY == size && map[wsp - 1][wspY - 1] == 'o' && map[wsp][wspY - 2] == 'o') {
        player -= 1;
    }

    if (map[wsp][wspY - 2] == 'o') {
        if (map[wsp][wspY] == 'o') {
            if (map[wsp - 1][wspY - 1] == 'o') {
                if (map[wsp + 1][wspY - 1] == 'o') {
                    player -= 1;
                }
                else {
                    initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player,true);
                }
            }
            else {
                initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
            }
        }
        else {
            initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
        }
    }
    else {
        initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
    }

}

void white_player_logic(char** map, int& wsp, int& wspY, int& player, int& size, int x, int y, int attr, int& black_players_count, int& white_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player) {

    if (map[wsp][wspY - 1] == '*' || map[wsp][wspY - 1] == 'o') {
        player -= 1;
        //nic sie nie dzieje bo w tym miejscu jest juz kamien
    }

    // lewy gorny rog..
    if (wsp == 0 && wspY == 1 && map[wsp + 1][wspY - 1] == '*' && map[wsp][wspY] == '*') {
        player -= 1;
    }

    // prawy gorny rog..
    if (wsp == size - 1 && wspY == 1 && map[wsp - 1][wspY - 1] == '*' && map[wsp][wspY] == '*') {
        player -= 1;
    }

    // lewy dolny rog..
    if (wsp == 0 && wspY == size && map[wsp + 1][wspY - 1] == '*' && map[wsp][wspY - 2] == '*') {
        player -= 1;
    }

    // prawy dolny rog..
    if (wsp == size - 1 && wspY == size && map[wsp - 1][wspY - 1] == '*' && map[wsp][wspY - 2] == '*') {
        player -= 1;
    }

    // sprawdzenie czy gracz Czarny jest otoczony przez gracza Bialego
    if (map[wsp][wspY - 2] == '*') {
        if (map[wsp][wspY] == '*') {
            if (map[wsp - 1][wspY - 1] == '*') {
                if (map[wsp + 1][wspY - 1] == '*') {
                    player -= 1;
                }
                else {
                    initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
                }
            }
            else {
                initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
            }
        }
        else {
            initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
        }
    }
    else {
        initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player, true);
    }

}

void place_stone(char** map, int& player, int& wsp, int& wspY, int& size, int x, int y, int attr, int& black_players_count, int& white_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player) {

    player += 1;

    // jezeli gracz jest czarny..
    if (player % 2 == 0) {
        black_player_logic(map, wsp, wspY, player, size, x, y, attr, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player);
    }
    // jezeli gracz jest bialy
    else if (player % 2 != 0) {
        white_player_logic(map, wsp, wspY, player, size, x, y, attr, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player);
    }
}

void program(int x, int y, int zn, int attr, int back, int zero, char txt[32], int& size, int& player, int& white_players_count, int& black_players_count, int& left_border, int& right_border, int& top_border, int& bottom_border, char** map, int* convert_x, int* convert_y, string message_white_player, string message_black_player) {

    _setcursortype(_NOCURSOR);
    do {

        textbackground(3);
        textcolor(1);

        draw_side_menu();

        for (int i = MAP_Y, j = 0; i < (MAP_Y + size); i++, j++) {
            convert_y[i] = j;
        }
        int wspY = convert_y[y];

        for (int i = MAP_X, j = 0; i <= (size * 2) - 2 + MAP_X; i = i + 2, j++) {
            convert_x[i] = j;
        }
        int wsp = convert_x[x];

        show_coords(zero, wsp, wspY, txt);

        if (zn == 'n') {
            new_game(player, white_players_count, black_players_count);
        }
        if (zn == 'i') {
            place_stone(map, player, wsp, wspY, size, x, y, attr, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player);
        }

        initialize_board(x, y, attr, player, map, size, black_players_count, white_players_count, convert_x, convert_y, message_white_player, message_black_player);

        gotoxy(x, y);
        textcolor(attr);
        textbackground(back);

        // jezeli gracz jest czarny
        if (player % 2 == 0) {
            textbackground(15);
            putch(' ');
        }
        // jezeli gracz jest bialy
        else if (player % 2 != 0) {
            textbackground(0);
            putch(' ');
        }

        zero = 0;
        zn = getch();

        if (zn == 0) {
            zero = 1;
            zn = getch();

            // przesuwanie kamieni
            if (zn == 0x48) {
                if (y != top_border) y = y - 1;
            }
            else if (zn == 0x50) {
                if (y != bottom_border) y = y + 1;
            }
            else if (zn == 0x4b) {
                if (x != left_border) x = x - 2;
            }
            else if (zn == 0x4d) {
                if (x != right_border) x = x + 2;
            }
        }

    } while (zn != 'q');
    textcolor(WHITE);
    textbackground(BLACK);

}

void provide_size(int zn, string& input_size, int& size) {

    while (zn != 0x0D) {

        zn = getch();


        if (zn == 0x30) {
            int zero = 0;
            input_size += to_string(zero);
            size = stoi(input_size);

        }
        else if (zn == 0x31) {
            input_size += 1;
            size = stoi(input_size);
        }
        else if (zn == 0x32) {
            input_size += 2;
            size = stoi(input_size);

        }
        else if (zn == 0x33) {
            input_size += 3;
            size = stoi(input_size);

        }
        else if (zn == 0x34) {
            input_size += 4;
            size = stoi(input_size);

        }
        else if (zn == 0x35) {
            input_size += 5;
            size = stoi(input_size);

        }
        else if (zn == 0x36) {
            input_size += 6;
            size = stoi(input_size);

        }
        else if (zn == 0x37) {
            input_size += 7;
            size = stoi(input_size);
        }
        else if (zn == 0x38) {
            input_size += 8;
            size = stoi(input_size);

        }
        else if (zn == 0x39) {
            input_size += 9;
            size = stoi(input_size);

        }
    }
}

void create_board(char** map, int& size) {

    for (int h = 0; h <= (size - 1); h++) {
        for (int j = 1; j < (size - 1); j++) {
            map[0][j] = '+';
            map[h][0] = '+';
            map[h][j] = '.';
            map[size - 1][j] = '+';
            map[h][size - 1] = '+';
        }
    }

}

void apply_limitations(char** map, int& size, int& left_border, int& right_border, int& top_border, int& bottom_border) {

    map[size][size];

    left_border = MAP_X;
    top_border = MAP_Y + 1;
    right_border = (size * 2) - 2 + MAP_X;
    bottom_border = MAP_Y + size;

}

void choose_size(int x, int y, int zn, int attr, int back, int zero, char txt[32], string& input_size, int& size, char** map, int& left_border, int& right_border, int& top_border, int& bottom_border, int& player, int& white_players_count, int& black_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player);

void check_size(int x, int y, int zn, int attr, int back, int zero, char txt[32], string& input_size, int& size, char** map, int& left_border, int& right_border, int& top_border, int& bottom_border, int& player, int& white_players_count, int& black_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player) {

    int allowed_size_x = WINDOW_BORDER_X - MAP_X;
    int allowed_size_y = WINDOW_BORDER_Y - MAP_Y;

    input_size = "";

    int actual_size = (size * 2) - 1;

    if (actual_size > allowed_size_x || size > allowed_size_y) {
        size = 0;

        input_size = "";

        choose_size(x, y, zn, attr, back, zero, txt, input_size, size, map, left_border, right_border, top_border, bottom_border, player, white_players_count, black_players_count, convert_x, convert_y, message_white_player, message_black_player);
    }
    else {
        apply_limitations(map, size, left_border, right_border, top_border, bottom_border);
        create_board(map, size);
        clrscr();
        program(x, y, zn, attr, back, zero, txt, size, player, white_players_count, black_players_count, left_border, right_border, top_border, bottom_border, map, convert_x, convert_y, message_white_player, message_black_player);
        clrscr();
        textcolor(WHITE);
        textbackground(BLACK);
        exit(0);
    }

}

void choose_size(int x, int y, int zn, int attr, int back, int zero, char txt[32], string& input_size, int& size, char** map, int& left_border, int& right_border, int& top_border, int& bottom_border, int& player, int& white_players_count, int& black_players_count, int* convert_x, int* convert_y, string message_white_player, string message_black_player) {

    int option;

    while (true) {

        clrscr();

        _setcursortype(_NOCURSOR);

        gotoxy(6, 12);
        cputs("Choose the board size (press the corresponding key on you keyboard)");

        gotoxy(6, 14);
        cputs("a) 9x9");

        gotoxy(6, 16);
        cputs("b) 13x13");

        gotoxy(6, 18);
        cputs("c) 19x19");

        gotoxy(6, 20);
        cputs("d) custom size");

        textcolor(RED);
        gotoxy(6, 22);
        cputs("q) QUIT GAME");
        textcolor(WHITE);

        option = getch();

        if (option == 'a') {

            size = 9;

            check_size(x, y, zn, attr, back, zero, txt, input_size, size, map, left_border, right_border, top_border, bottom_border, player, white_players_count, black_players_count, convert_x, convert_y, message_white_player, message_black_player);

        }
        else if (option == 'b') {

            size = 13;

            check_size(x, y, zn, attr, back, zero, txt, input_size, size, map, left_border, right_border, top_border, bottom_border, player, white_players_count, black_players_count, convert_x, convert_y, message_white_player, message_black_player);

        }
        else if (option == 'c') {

            size = 19;

            check_size(x, y, zn, attr, back, zero, txt, input_size, size, map, left_border, right_border, top_border, bottom_border, player, white_players_count, black_players_count, convert_x, convert_y, message_white_player, message_black_player);

        }
        else if (option == 'd') {

            clrscr();

            gotoxy(6, 10);
            cputs("Wprowadz wlasny rozmiar..");

            provide_size(zn, input_size, size);

            check_size(x, y, zn, attr, back, zero, txt, input_size, size, map, left_border, right_border, top_border, bottom_border, player, white_players_count, black_players_count, convert_x, convert_y, message_white_player, message_black_player);

        }
        else if (option == 'q') {
            clrscr();
            exit(0);
        }
    }

}

int main() {

    textcolor(WHITE);
    textbackground(BLACK);

    settitle("Go by Taras Shuliakevych, 196615");

    int left_border = 0;
    int top_border = 0;
    int bottom_border = 0;
    int right_border = 0;

    int player = 1;
    int white_players_count = 0;
    int black_players_count = 0;

    string message_black_player;
    string message_white_player;

    const int max_storage_convert = 100;

    int convert_y[max_storage_convert];
    int convert_x[max_storage_convert];

    int zn = 0, x = MAP_X, y = MAP_Y + 1, attr = 0, back = 3, zero = 0;
    int size = 0;
    string input_size;
    char txt[32];
  
    const int max_storage_map = 200;

    char** map = new char* [max_storage_map];
    for (int i = 0; i < max_storage_map; i++) {
        map[i] = new char[max_storage_map];
    }

    choose_size(x, y, zn, attr, back, zero, txt, input_size, size, map, left_border, right_border, top_border, bottom_border, player, white_players_count, black_players_count, convert_x, convert_y, message_white_player, message_black_player);

    return 0;
}
