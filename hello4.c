#include <stdio.h>
#include <curses.h>
#include <time.h>


int main() {
	int i;
	initscr();
	clear();
	for (i = 0; i < LINES; i++) {
		move (i, i + i);
		// if (i % 2 == 1) {
		// 	standout();
		// }
		addstr("hello world");
		// if (i % 2 == 1) {
		// 	standend();
		// }
		refresh();
		// sleep(1);
		usleep(40000);
		move(i, i + i);
		addstr("           ");
	}
	getch();
	endwin();
}
