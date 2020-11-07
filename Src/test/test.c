#include "apilib.h"

void HariMain(void)
{
	char *buf;
	int win;
	api_initmalloc();
	buf = api_malloc(150 * 100);
	win = api_openBorderlessWin(buf, 150, 100, -1, "test");
	api_point(win, 75, 59, 3);
	api_putstr1("BORDERLESS WINDOW", 17);
	for (;;) {
		if (api_getkey(1) == 0x0a) {
			break;
		}
	}
	api_end();
}
