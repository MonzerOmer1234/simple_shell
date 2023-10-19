#include "main.h"

/**
 * change_directory - Change the current directory
 * @newpwd: The path pf the new Directory
 *
 * Return: Nothing
 */
void change_directory(const char *newpwd)
{
	int retunstate, home_offset, oldpwd_offset, pwd_offset;
	char buffer[1024];
	char *cwd;
	char *home = _getenv("HOME", &home_offset);
	char *pwd = _getenv("PWD", &pwd_offset);
	char *oldpwd = _getenv("OLDPWD", &oldpwd_offset);

	if (newpwd == NULL || _strcmp(newpwd, "") == 0)
		newpwd = home;
	else if (_strcmp(newpwd, "-") == 0)
	{
		newpwd = oldpwd;
		write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
		write(STDOUT_FILENO, "\n", 1);
	}

	retunstate = chdir(newpwd);
	if (retunstate != 0)
	{
		perror("Error");
		return;
	}

	cwd = getcwd(buffer, sizeof(buffer));
	if (cwd == NULL)
	{
		perror("Error");
		return;
	}

	_setenv("OLDPWD", pwd, 1);
	_setenv("PWD", cwd, oldpwd_offset);
}
