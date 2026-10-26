#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
	printf("Parent: pid=%d, ppid=%d\n", getpid(), getppid());
	fflush(NULL);

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return 1;
	}

	if (pid == 0) {
		printf("Child: pid=%d, ppid=%d\n", getpid(), getppid());
		fflush(NULL);
		execlp("dont-exist", "dont-exist", "test", (char *)NULL);
		perror("execlp");
		_exit(127);
	}

	int status;
	if (waitpid(pid, &status, 0) == -1) {
		perror("waitpid");
		return 1;
	}

	if (WIFEXITED(status)) {
		printf("Parent: child finished with coed %d\n", WEXITSTATUS(status));
	} else if (WIFSIGNALED(status)) {
		printf("Parent: child finished from signal %d\n", WTERMSIG(status));
	}
	return 0;
}

