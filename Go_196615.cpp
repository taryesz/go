#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"conio2.h"
#include<string.h>
#include<stdlib.h>


#define LEGENDA_X 6
#define LEGENDA_Y 6

#define PLANSZA_X 80
#define PLANSZA_Y 5

#define GRANICA_OKNA 120
#define GRANICA_OKNA_Y 30

static int rozmiar = 0;

static int granicaL = 0;
static int granicaG = 0;
static int granicaD = 0;
static int granicaP = 0;

static char pl[120][120];
static int gracz = 1;
static int wynikBialego = 0;
static int wynikCzarnego = 0;
static char wynB[10000];
static char wynC[10000];

static int konwertacjaY[100];
static int konwertacjaX[100];

static char str[100] = "";

// ----------------------------------------------

void planszaIni(int x, int y, int attr, bool putI = false) {

    for (int i = PLANSZA_Y, j = 0; i <= (PLANSZA_Y + rozmiar); i++, j++) {
        konwertacjaY[i] = j;
    }
    int wspY = konwertacjaY[y];

    for (int i = PLANSZA_X, j = 0; i <= (rozmiar * 2) - 2 + PLANSZA_X; i = i + 2, j++) {
        konwertacjaX[i] = j;
    }
    int wsp = konwertacjaX[x];

    if (putI == true) {
        if (gracz % 2 == 0) {
            if (wsp == 0 && wspY == 1 && pl[wsp + 1][wspY - 1] == '*' && pl[wsp][wspY] == '*') {
                // nic
            }
            else if (wsp == (rozmiar - 1) && wspY == 1 && pl[wsp - 1][wspY - 1] == '*' && pl[wsp][wspY] == '*') {
                // nic
            }
            else if (wsp == 0 && wspY == rozmiar && pl[wsp + 1][wspY - 1] == '*' && pl[wsp][wspY - 2] == '*') {
                // nic
            }
            else if (wsp == (rozmiar - 1) && wspY == rozmiar && pl[wsp - 1][wspY - 1] == '*' && pl[wsp][wspY - 2] == '*') {
                // nic
            }
            else if (pl[wsp][wspY - 1] != 'o') {
                pl[wsp][wspY - 1] = '*';
            }
        }
        else if (gracz % 2 != 0) {
            if (wsp == 0 && wspY == 1 && pl[wsp + 1][wspY - 1] == 'o' && pl[wsp][wspY] == 'o') {
                // nic
            }
            else if (wsp == (rozmiar - 1) && wspY == 1 && pl[wsp - 1][wspY - 1] == 'o' && pl[wsp][wspY] == 'o') {
                // nic
            }
            else if (wsp == 0 && wspY == rozmiar && pl[wsp + 1][wspY - 1] == 'o' && pl[wsp][wspY - 2] == 'o') {
                // nic
            }
            else if (wsp == (rozmiar - 1) && wspY == rozmiar && pl[wsp - 1][wspY - 1] == 'o' && pl[wsp][wspY - 2] == 'o') {
                // nic
            }
            else if (pl[wsp][wspY - 1] != '*') {
                pl[wsp][wspY - 1] = 'o';
            }
        }
    }
    for (int j = PLANSZA_Y, k = 0; j < (PLANSZA_Y + rozmiar); j++, k++) {

        gotoxy(PLANSZA_X, j + 1);

        for (int i = 0; i < rozmiar; i++) {

            // jezeli aktualnie jestesmy graczem Bialym...

            if (pl[i][k] == 'o') {

                // sprawdzenie czy gracz Bialy znajduje sie w rogu planszy i jest otoczony prze gracza Czarnego

                // lewy gorny rog..
                if (i == 0 && k == 0 && pl[i + 1][k] == '*' && pl[i][k + 1] == '*') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikCzarnego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 12);
                    sprintf(wynC, "Gracz Czarny %d raz(y) zabil gracza Bialego", wynikCzarnego);
                    cputs(wynC);
                    gotoxy(PLANSZA_X, j + 4);
                }
                // prawy gorny rog..
                if (i == (rozmiar - 1) && k == 0 && pl[i - 1][k] == '*' && pl[i][k + 1] == '*') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikCzarnego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 12);
                    sprintf(wynC, "Gracz Czarny %d raz(y) zabil gracza Bialego", wynikCzarnego);
                    cputs(wynC);
                    gotoxy(PLANSZA_X, j + 4);
                }
                // lewy dolny rog..
                if (i == 0 && k == (rozmiar - 1) && pl[i + 1][k] == '*' && pl[i][k - 1] == '*') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikCzarnego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 12);
                    sprintf(wynC, "Gracz Czarny %d raz(y) zabil gracza Bialego", wynikCzarnego);
                    cputs(wynC);
                    gotoxy(PLANSZA_X, j - 1);
                }
                // prawy dolny rog..
                if (i == (rozmiar - 1) && k == (rozmiar - 1) && pl[i - 1][k] == '*' && pl[i][k - 1] == '*') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikCzarnego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 12);
                    sprintf(wynC, "Gracz Czarny %d raz(y) zabil gracza Bialego", wynikCzarnego);
                    cputs(wynC);
                    gotoxy(PLANSZA_X, j - 1);
                }

                // sprawdzenie czy gracz Bialy jest w otoczeniu gracza Czarnego ze wszystkich stron

                if (pl[i][k - 1] == '*' && pl[i][k + 1] == '*' && pl[i - 1][k] == '*' && pl[i + 1][k] == '*') {
                    pl[i][k] = '.';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikCzarnego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 12);
                    sprintf(wynC, "Gracz Czarny %d raz(y) zabil gracza Bialego", wynikCzarnego);
                    cputs(wynC);
                    gotoxy(PLANSZA_X, j);
                }
                else {
                    textcolor(15);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    textcolor(1);
                }
            }

            // jezeli aktualnie jestesmy graczem Czarnym...

            else if (pl[i][k] == '*') {

                // sprawdzenie czy gracz Bialy znajduje sie w rogu planszy i jest otoczony prze gracza Czarnego

                // lewy gorny rog..
                if (i == 0 && k == 0 && pl[i + 1][k] == 'o' && pl[i][k + 1] == 'o') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikBialego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 13);
                    sprintf(wynB, "Gracz Bialy %d raz(y) zabil gracza Czarnego", wynikBialego);
                    cputs(wynB);
                    gotoxy(PLANSZA_X, j + 4);
                }
                // prawy gorny rog..
                if (i == (rozmiar - 1) && k == 0 && pl[i - 1][k] == 'o' && pl[i][k + 1] == 'o') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikBialego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 13);
                    sprintf(wynB, "Gracz Bialy %d raz(y) zabil gracza Czarnego", wynikBialego);
                    cputs(wynB);
                    gotoxy(PLANSZA_X, j + 4);
                }
                // lewy dolny rog..
                if (i == 0 && k == (rozmiar - 1) && pl[i + 1][k] == 'o' && pl[i][k - 1] == 'o') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikBialego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 13);
                    sprintf(wynB, "Gracz Bialy %d raz(y) zabil gracza Czarnego", wynikBialego);
                    cputs(wynB);
                    gotoxy(PLANSZA_X, j - 1);
                }
                // prawy dolny rog..
                if (i == (rozmiar - 1) && k == (rozmiar - 1) && pl[i - 1][k] == 'o' && pl[i][k - 1] == 'o') {
                    pl[i][k] = '+';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikBialego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 13);
                    sprintf(wynB, "Gracz Bialy %d raz(y) zabil gracza Czarnego", wynikBialego);
                    cputs(wynB);
                    gotoxy(PLANSZA_X, j - 1);
                }

                // sprawdzenie czy gracz Czarny jest w otoczeniu gracza Bialego ze wszystkich stron

                if (pl[i][k - 1] == 'o' && pl[i][k + 1] == 'o' && pl[i - 1][k] == 'o' && pl[i + 1][k] == 'o') {
                    pl[i][k] = '.';
                    textcolor(1);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    wynikBialego += 1;
                    gotoxy(LEGENDA_X, LEGENDA_Y + 13);
                    sprintf(wynB, "Gracz Bialy %d raz(y) zabil gracza Czarnego", wynikBialego);
                    cputs(wynB);
                    gotoxy(PLANSZA_X, j);

                }
                else {
                    textcolor(0);
                    putch(pl[i][k]);
                    if (i != rozmiar - 1) {
                        putch(' ');
                    }
                    textcolor(1);
                }
            }
            else {
                putch(pl[i][k]);
                if (i != rozmiar - 1) {
                    putch(' ');
                }
            }
        }
    }
}

void malujLegende() {

    gotoxy(LEGENDA_X, LEGENDA_Y);
    cputs("strzalki: poruszanie kursorem na planszy");

    gotoxy(LEGENDA_X, LEGENDA_Y + 1);
    cputs("q: zakonczenie gry i wlaczenie menu");

    gotoxy(LEGENDA_X, LEGENDA_Y + 2);
    cputs("n: rozpoczecie nowej gry");

    gotoxy(LEGENDA_X, LEGENDA_Y + 3);
    cputs("enter: potwierdzenie wyboru i zakonczenie tury gracza");

    gotoxy(LEGENDA_X, LEGENDA_Y + 4);
    cputs("esc: anulowanie obecnej akcji");

    gotoxy(LEGENDA_X, LEGENDA_Y + 5);
    cputs("i: polozenie kamienia na planszy");

    gotoxy(LEGENDA_X, LEGENDA_Y + 6);
    cputs("s: zapis stanu gry");

    gotoxy(LEGENDA_X, LEGENDA_Y + 7);
    cputs("l: wczytanie stanu gry");

    gotoxy(LEGENDA_X, LEGENDA_Y + 8);
    cputs("f: zakonczenie gry");

    gotoxy(LEGENDA_X, LEGENDA_Y + 15);
    cputs("Projekt stworzony przez Taras'a Shuliakevych'a, 196615");

}

void pokazWspolrzedne(int zero, int wsp, int wspY, char txt[32]) {

    if (zero) sprintf(txt, "wspolrzedne: %d %d   ", wsp + 1, wspY);
    else sprintf(txt, "wspolrzedne: %d %d   ", wsp + 1, wspY);
    gotoxy(LEGENDA_X, LEGENDA_Y + 10);
    cputs(txt);

}


// deklaracja funkcji main po to aby dzialal klawisz 'n'
int main();


void nowaGra() {

    gracz = 1;
    wynikBialego = 0;
    wynikCzarnego = 0;
    main();

}

void program(int x, int y, int zn, int attr, int back, int zero, char txt[32]) {

    _setcursortype(_NOCURSOR);
    do {

        textbackground(3);
        textcolor(1);

        malujLegende();

        for (int i = PLANSZA_Y, j = 0; i < (PLANSZA_Y + rozmiar); i++, j++) {
            konwertacjaY[i] = j;
        }
        int wspY = konwertacjaY[y];

        for (int i = PLANSZA_X, j = 0; i <= (rozmiar * 2) - 2 + PLANSZA_X; i = i + 2, j++) {
            konwertacjaX[i] = j;
        }
        int wsp = konwertacjaX[x];

        pokazWspolrzedne(zero, wsp, wspY, txt);

        if (zn == 'n') nowaGra();

        if (zn == 'i') {

            gracz += 1;

            // jezeli gracz jest czarny..
            if (gracz % 2 == 0) {
                if (pl[wsp][wspY - 1] == 'o' || pl[wsp][wspY - 1] == '*') {
                    gracz -= 1;
                    //nic sie nie dzieje bo w tym miejscu jest juz kamien
                }

                // lewy gorny rog..
                if (wsp == 0 && wspY == 1 && pl[wsp + 1][wspY - 1] == 'o' && pl[wsp][wspY] == 'o') {
                    gracz -= 1;
                }

                // prawy gorny rog..
                if (wsp == rozmiar - 1 && wspY == 1 && pl[wsp - 1][wspY - 1] == 'o' && pl[wsp][wspY] == 'o') {
                    gracz -= 1;
                }

                // lewy dolny rog..
                if (wsp == 0 && wspY == rozmiar && pl[wsp + 1][wspY - 1] == 'o' && pl[wsp][wspY - 2] == 'o') {
                    gracz -= 1;
                }

                // prawy dolny rog..
                if (wsp == rozmiar - 1 && wspY == rozmiar && pl[wsp - 1][wspY - 1] == 'o' && pl[wsp][wspY - 2] == 'o') {
                    gracz -= 1;
                }

                if (pl[wsp][wspY - 2] == 'o') {
                    if (pl[wsp][wspY] == 'o') {
                        if (pl[wsp - 1][wspY - 1] == 'o') {
                            if (pl[wsp + 1][wspY - 1] == 'o') {
                                gracz -= 1;
                            }
                            else {
                                planszaIni(x, y, attr, true);
                            }
                        }
                        else {
                            planszaIni(x, y, attr, true);
                        }
                    }
                    else {
                        planszaIni(x, y, attr, true);
                    }
                }
                else {
                    planszaIni(x, y, attr, true);
                }

            }

            // jezeli gracz jest bialy
            else if (gracz % 2 != 0) {
                if (pl[wsp][wspY - 1] == '*' || pl[wsp][wspY - 1] == 'o') {
                    gracz -= 1;
                    //nic sie nie dzieje bo w tym miejscu jest juz kamien
                }

                // lewy gorny rog..
                if (wsp == 0 && wspY == 1 && pl[wsp + 1][wspY - 1] == '*' && pl[wsp][wspY] == '*') {
                    gracz -= 1;
                }

                // prawy gorny rog..
                if (wsp == rozmiar - 1 && wspY == 1 && pl[wsp - 1][wspY - 1] == '*' && pl[wsp][wspY] == '*') {
                    gracz -= 1;
                }

                // lewy dolny rog..
                if (wsp == 0 && wspY == rozmiar && pl[wsp + 1][wspY - 1] == '*' && pl[wsp][wspY - 2] == '*') {
                    gracz -= 1;
                }

                // prawy dolny rog..
                if (wsp == rozmiar - 1 && wspY == rozmiar && pl[wsp - 1][wspY - 1] == '*' && pl[wsp][wspY - 2] == '*') {
                    gracz -= 1;
                }

                // sprawdzenie czy gracz Czarny jest otoczony przez gracza Bialego
                if (pl[wsp][wspY - 2] == '*') {
                    if (pl[wsp][wspY] == '*') {
                        if (pl[wsp - 1][wspY - 1] == '*') {
                            if (pl[wsp + 1][wspY - 1] == '*') {
                                gracz -= 1;
                            }
                            else {
                                planszaIni(x, y, attr, true);
                            }
                        }
                        else {
                            planszaIni(x, y, attr, true);
                        }
                    }
                    else {
                        planszaIni(x, y, attr, true);
                    }
                }
                else {
                    planszaIni(x, y, attr, true);
                }

            }

        }

        planszaIni(x, y, attr);

        gotoxy(x, y);
        textcolor(attr);
        textbackground(back);

        // jezeli gracz jest czarny
        if (gracz % 2 == 0) {
            textbackground(15);
            putch(' ');
        }
        // jezeli gracz jest bialy
        else if (gracz % 2 != 0) {
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
                if (y != granicaG) y = y - 1;
            }
            else if (zn == 0x50) {
                if (y != granicaD) y = y + 1;
            }
            else if (zn == 0x4b) {
                if (x != granicaL) x = x - 2;
            }
            else if (zn == 0x4d) {
                if (x != granicaP) x = x + 2;
            }
        }

    } while (zn != 'q');
    textcolor(WHITE);
    textbackground(BLACK);

}

// wczytuje co jest wpisane na klawiaturze i konwertuje to w liczby oraz przypisuje to do zmiennej 'rozmiar'
void podajRozmiar(int zn) {

    while (zn != 0x0D) {

        zn = getch();

        if (zn == 0x30) {
            char zero[] = "0";
            strcat(str, zero);
            rozmiar = atoi(str);
        }
        else if (zn == 0x31) {
            char jeden[] = "1";
            strcat(str, jeden);
            rozmiar = atoi(str);
        }
        else if (zn == 0x32) {
            char dwa[] = "2";
            strcat(str, dwa);
            rozmiar = atoi(str);
        }
        else if (zn == 0x33) {
            char trzy[] = "3";
            strcat(str, trzy);
            rozmiar = atoi(str);
        }
        else if (zn == 0x34) {
            char cztery[] = "4";
            strcat(str, cztery);
            rozmiar = atoi(str);
        }
        else if (zn == 0x35) {
            char piec[] = "5";
            strcat(str, piec);
            rozmiar = atoi(str);
        }
        else if (zn == 0x36) {
            char szesc[] = "6";
            strcat(str, szesc);
            rozmiar = atoi(str);
        }
        else if (zn == 0x37) {
            char siedem[] = "7";
            strcat(str, siedem);
            rozmiar = atoi(str);
        }
        else if (zn == 0x38) {
            char osiem[] = "8";
            strcat(str, osiem);
            rozmiar = atoi(str);
        }
        else if (zn == 0x39) {
            char dziewiec[] = "9";
            strcat(str, dziewiec);
            rozmiar = atoi(str);
        }
        else {}
    }
}

// robi nowa/czysta plansze
void stworzPlansze() {

    for (int h = 0; h <= (rozmiar - 1); h++) {
        for (int j = 1; j < (rozmiar - 1); j++) {
            pl[0][j] = '+';
            pl[h][0] = '+';
            pl[h][j] = '.';
            pl[rozmiar - 1][j] = '+';
            pl[h][rozmiar - 1] = '+';
        }
    }

}

// ustawia granice planszy za ktore nie mozna wyjsc kursorem
void przypiszOgraniczenia() {

    pl[rozmiar][rozmiar];

    granicaL = PLANSZA_X;
    granicaG = PLANSZA_Y + 1;
    granicaP = (rozmiar * 2) - 2 + PLANSZA_X;
    granicaD = PLANSZA_Y + rozmiar;

}


// deklaracja funkcji aby byla ona widoczna w funkcji sprawdzRozmiar()
void wyborRozmiaru(int x, int y, int zn, int attr, int back, int zero, char txt[32]);


void sprawdzRozmiar(int x, int y, int zn, int attr, int back, int zero, char txt[32]) {

    int dopuszczonyRozmiar = GRANICA_OKNA - PLANSZA_X;
    int dopuszczonyRozmiarY = GRANICA_OKNA_Y - PLANSZA_Y;

    for (int i = 0; i < 100; i++) {
        str[i] = 0;
    }

    if (((rozmiar * 2) - 1) > dopuszczonyRozmiar || rozmiar > dopuszczonyRozmiarY) {
        rozmiar = 0;

        for (int i = 0; i < 100; i++) {
            str[i] = 0;
        }

        wyborRozmiaru(x, y, zn, attr, back, zero, txt);
    }
    else {
        przypiszOgraniczenia();
        stworzPlansze();
        clrscr();
        program(x, y, zn, attr, back, zero, txt);
        clrscr();
        textcolor(WHITE);
        textbackground(BLACK);
        exit(0);
    }

}

void wyborRozmiaru(int x, int y, int zn, int attr, int back, int zero, char txt[32]) {

    int opcja;

    while (true) {

        clrscr();

        _setcursortype(_NOCURSOR);

        gotoxy(6, 12);
        cputs("Wybierz rozmiar planszy (nacisnij na odpowiednia literke na klawiaturze)");

        gotoxy(6, 14);
        cputs("a) 9x9");

        gotoxy(6, 16);
        cputs("b) 13x13");

        gotoxy(6, 18);
        cputs("c) 19x19");

        gotoxy(6, 20);
        cputs("d) wprowadz wlasny rozmiar");

        textcolor(RED);
        gotoxy(6, 22);
        cputs("q) WYJDZ Z GRY");
        textcolor(WHITE);

        opcja = getch();

        if (opcja == 'a') {

            rozmiar = 9;

            sprawdzRozmiar(x, y, zn, attr, back, zero, txt);

        }
        else if (opcja == 'b') {

            rozmiar = 13;

            sprawdzRozmiar(x, y, zn, attr, back, zero, txt);

        }
        else if (opcja == 'c') {

            rozmiar = 19;

            sprawdzRozmiar(x, y, zn, attr, back, zero, txt);

        }
        else if (opcja == 'd') {

            clrscr();

            gotoxy(6, 10);
            cputs("Wprowadz wlasny rozmiar..");

            podajRozmiar(zn);

            sprawdzRozmiar(x, y, zn, attr, back, zero, txt);

        }
        else if (opcja == 'q') {
            clrscr();
            exit(0);
        }
        else {}
    }

}

int main() {

    textcolor(WHITE);
    textbackground(BLACK);

    settitle("Go by Taras Shuliakevych, 196615");

    int zn = 0, x = PLANSZA_X, y = PLANSZA_Y + 1, attr = 0, back = 3, zero = 0;
    char txt[32];

    wyborRozmiaru(x, y, zn, attr, back, zero, txt);

    return 0;
}