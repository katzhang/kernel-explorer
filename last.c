#include <stdio.h>
#include <utmpx.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void show_time(long seconds) {
	char *readable_time;
	readable_time = ctime(&seconds);
	printf("%12.12s", readable_time+4);
}

void show_info(struct utmpx *record) {
	printf(record->ut_user);
	printf(" ");
	printf(record->ut_line);
	printf(" ");
	show_time(record->ut_tv.tv_sec);
	printf("\n");
};

int main() {
	struct utmpx* current_record;

	utmpname(WTMP_FILE);

	setutxent();

	while (current_record = getutxent()) {
		if (current_record->ut_type == USER_PROCESS) {
			show_info(current_record);
		}
	}

	endutxent();
	return 0;
}