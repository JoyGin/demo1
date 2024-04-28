#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t child;
    int status;
    long word;

    child = fork();
    if (child == 0) {
        // 子进程: 通过 PTRACE_TRACEME 告诉父进程开始跟踪
        ptrace(PT_TRACE_ME, 0, NULL, 0);
        execl("/bin/ls", "ls", NULL); // 替换为要跟踪的程序
    } else {
        // 父进程: 等待子进程停止并打印其退出状态
        wait(&status);
        if (WIFSTOPPED(status)) {
            printf("Child has stopped!\n");

            // 读取子进程的内存、寄存器等
            // word = ptrace(PTRACE_PEEKDATA, child, address, NULL);

            sleep(3);

            // 继续执行子进程
            ptrace(PT_CONTINUE, child, (caddr_t)1, 0);
        }

        // 等待子进程结束
        wait(NULL);
    }

    return 0;
}