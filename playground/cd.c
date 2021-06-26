#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

/* Use this variable to remember original terminal attributes. */

struct termios org_term;
struct termios new_term;
struct termios cd_term;

void set_input_mode(void)
{
	tcgetattr(STDIN_FILENO, &org_term);
	new_term = org_term;
	new_term.c_lflag &= ~(ICANON);
	new_term.c_cc[VMIN] = 1;
	new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}


void set_input_mode2(void)
{
  cd_term = org_term;
	cd_term.c_lflag &= ~(ECHO | ICANON);
	cd_term.c_cc[VMIN] = 0;
	cd_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &cd_term);
}


int main(void)
{
	char c;

	set_input_mode();
	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		if (c == '\004') /* C-d */
      {
        set_input_mode2();
        char dummy;
        while(read(0, &dummy, 1) == 1);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
      }
		else
			putchar(c);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &org_term);
	return EXIT_SUCCESS;
}
