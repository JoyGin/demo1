//
// Created by 王泽鑫 on 2024/4/18.
//

#include <unistd.h>
#include <cstdio>

int main() {
    int ret = 100;
    int id = fork();
    if (id == 0) {
        ret = 20;
    }
    sleep(1);
    printf("ret 的值为: %d\n", ret);
    return 0;

//    printf("hello pro: %d, ret: %d\n", getpid(), id);
}