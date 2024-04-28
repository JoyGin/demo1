//
// Created by 王泽鑫 on 2024/4/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/ptrace.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // 子进程
        printf("Child process: PID = %d\n", getpid());
        printf("Child process is stopping itself with SIGSTOP\n");
        kill(getpid(), SIGSTOP); // 发送 SIGSTOP 信号给自己
        printf("Child process continues after being stopped.\n");
        _exit(EXIT_SUCCESS);
    } else {
        // 父进程
        int status;
        pid_t wpid;

        // 使用 WUNTRACED 选项等待子进程状态变化
        wpid = waitpid(pid, &status, WUNTRACED);
        if (wpid == -1) {
            perror("waitpid");
            return EXIT_FAILURE;
        }

        if (WIFSIGNALED(status)) {
            printf("Parent process: Child with PID %d exit by signal %d\n",
                   wpid, WSTOPSIG(status));
        }

        if (WIFSTOPPED(status)) {
            printf("Parent process: Child with PID %d stopped by signal %d\n",
                   wpid, WSTOPSIG(status));
        }

        // 父进程可以在这里决定是否发送 SIGCONT 给子进程
         kill(pid, SIGCONT);

        // 等待子进程终止
        wpid = waitpid(pid, &status, 0);
        if (wpid == -1) {
            perror("waitpid");
            return EXIT_FAILURE;
        }

        if (WIFEXITED(status)) {
            printf("Parent process: Child with PID %d exited with status %d\n",
                   wpid, WEXITSTATUS(status));
        }
    }

    return EXIT_SUCCESS;
}