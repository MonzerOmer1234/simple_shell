#include "main.h"

/**
 * onCtrlC - Reacts to Ctrl + C.
 *
 * @signum: The signal code.
 */
void onCtrlC(int signum)
{
	UNUSED(signum);

	write(STDIN_FILENO, "\n", 1);
	write(STDIN_FILENO, prompt, prompt_size);
}

