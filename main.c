#include "main.h"

/**
 *Author: Steven Odhiambo & Anne Wangui
 *
 * free_data - frees data structure
 *
 * @datast: data structure
 * Return: no return
 */
void free_data(data_shell *datast)
{
	unsigned int i;

	for (i = 0; datast->_environ[i]; i++)
	{
		free(datast->_environ[i]);
	}

	free(datast->_environ);
	free(datast->pid);
}

/**
 * set_data - Initialize the data structure
 *
 * @datast: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datast, char **av)
{
	unsigned int i;

	datast->av = av;
	datast->input = NULL;
	datast->args = NULL;
	datast->status = 0;
	datast->counter = 1;

	for (i = 0; environ[i]; i++)
	{
	datast->_environ = malloc(sizeof(char *) * (i + 1));
	}

	for (i = 0; environ[i]; i++)
	{
		datast->_environ[i] = _strdup(environ[i]);
	}

	datast->_environ[i] = NULL;
	datast->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datast;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datast, av);
	shell_loop(&datast);
	free_data(&datast);
	if (datast.status < 0)
		return (255);
	return (datast.status);
}
