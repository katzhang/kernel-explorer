#include <stdio.h>
#include <curses.h>


int main() {
	int i;
	initscr();
	clear();
	for (i = 0; i < LINES; i++) {
		move (i, i + i);
		if (i % 2 == 1) {
			standout();
		}
		addstr("hello world");
		if (i % 2 == 1) {
			standend();
		}
		sleep(1);
		refresh();
	}
	getch();
	endwin();
}
