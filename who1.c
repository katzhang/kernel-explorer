#include <stdio.h>
#include <utmpx.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void show_info(struct utmpx *record);

int main() {
	struct utmpx* current_record;

	setutxent();

	while (current_record = getutxent()) {
		if (current_record->ut_type == USER_PROCESS) {
			printf(current_record->ut_user);
			printf(" ");
			printf(current_record->ut_line);
			printf(" ");
			printf("%10ld", current_record->ut_tv.tv_sec);
			printf("\n");
		}
	}

	endutxent();
	return 0;
}