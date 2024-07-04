#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <ctime>

void gotoxy(int x, int y) {
    move(y, x);
    refresh();
}

void delay(unsigned int mseconds) {
    usleep(mseconds * 1000);  // usleep takes microseconds
}

void getup() {
    clear();
    gotoxy(10, 2);
    printw("Press X to Exit, Press Space to Jump");
    gotoxy(62, 2);
    printw("SCORE : ");
    gotoxy(1, 25);
    for (int x = 0; x < 79; x++)
        printw("ß");
    refresh();
}

int t = 0, speed = 40;

void ds(int jump = 0) {
    static int a = 1;

    if (jump == 0)
        t = 0;
    else if (jump == 2)
        t--;
    else 
        t++;

    gotoxy(2, 15 - t);
    printw("                 ");
    gotoxy(2, 16 - t);
    printw("         ÜÛßÛÛÛÛÜ");
    gotoxy(2, 17 - t);
    printw("         ÛÛÛÛÛÛÛÛ");
    gotoxy(2, 18 - t);
    printw("         ÛÛÛÛÛßßß");
    gotoxy(2, 19 - t);
    printw(" Û      ÜÛÛÛÛßßß ");
    gotoxy(2, 20 - t);
    printw(" ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ");
    gotoxy(2, 21 - t);
    printw(" ßÛÛÛÛÛÛÛÛÛÛÛ  ß ");
    gotoxy(2, 22 - t);
    printw("   ßÛÛÛÛÛÛÛß     ");
    gotoxy(2, 23 - t);
    if (jump == 1 || jump == 2) {
        printw("    ÛÛß ßÛ       ");
        gotoxy(2, 24 - t);
        printw("    ÛÜ   ÛÜ      ");
    } else if (a == 1) {
        printw("    ßÛÛß  ßßß    ");
        gotoxy(2, 24 - t);
        printw("      ÛÜ         ");
        a = 2;
    } else if (a == 2) {
        printw("     ßÛÜ ßÛ      ");
        gotoxy(2, 24 - t);
        printw("          ÛÜ     ");
        a = 1;
    }
    gotoxy(2, 25 - t);
    if (jump != 0) {
        printw("                ");
    } else {
        printw("ßßßßßßßßßßßßßßßßß");
    }
    refresh();
    delay(speed);
}

void obj() {
    static int x = 0, scr = 0;
    if (x == 56 && t < 4) {
        scr = 0;
        speed = 40;
        gotoxy(36, 8);
        printw("Game Over");
        getch();
        gotoxy(36, 8);
        printw("         ");
    }
    gotoxy(74 - x, 20);
    printw("Û    Û ");
    gotoxy(74 - x, 21);
    printw("Û    Û ");
    gotoxy(74 - x, 22);
    printw("ÛÜÜÜÜÛ ");
    gotoxy(74 - x, 23);
    printw("  Û    ");
    gotoxy(74 - x, 24);
    printw("  Û  ");
    x++;
    if (x == 73) {
        x = 0;
        scr++;
        gotoxy(70, 2);
        printw("     ");
        gotoxy(70, 2);
        printw("%d", scr);
        if (speed > 20)
            speed--;
    }
    refresh();
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int ch;
    getup();
    while (true) {
        while ((ch = getch()) == ERR) {
            ds();
            obj();
        }
        if (ch == ' ') {
            for (int i = 0; i < 10; i++) {
                ds(1);
                obj();
            }
            for (int i = 0; i < 10; i++) {
                ds(2);
                obj();
            }
        } else if (ch == 'x') {
            endwin();
            return 0;
        }
    }
}



use :
g++ -o game game.cpp -lncurses 
To Run
