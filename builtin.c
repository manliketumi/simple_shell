#include "shell.h"
/**
 * _mycd - return the current working directory
 * @data: pointer of the address
 * Return: cd
 */
int _mycd(info_t *data)
{
char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!s)
{
_puts("TODO: >>getcwd failure emsg here<<\n");
return (1);
}

if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
{
chdir_ret = chdir("/");
}
else
{
chdir_ret = chdir(dir);
}
}
else if (_strcmp(info->argv[1], "-") == 0)
{
dir = _getenv(info, "OLDPWD=");

if (!dir)
{
_puts(s);
_putchar('\n');
return (1);
}
chdir_ret = chdir(dir);
}
else
{
chdir_ret = chdir(info->argv[1]);
}

if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
return (1);
}

if (_setenv(info, "OLDPWD", _getenv(info, "PWD=")) != 0)
{
_puts("Error setting OLDPWD environment variable\n");
return (1);
}

if (_setenv(info, "PWD", getcwd(buffer, 1024)) != 0)
{
_puts("Error setting PWD environment variable\n");
return (1);
}

return (0);
}
