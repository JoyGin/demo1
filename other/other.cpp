#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <sys/file.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dlfcn.h>
#include <cstring>

//
// Created by 王泽鑫 on 2024/4/10.
//

typedef struct _IVFile {
    char IVhandler[8];
    char IV_value[16];
} IVFile;

void read_file() {
    int fd_IVfile = open("./o0oooOO0ooOo.dat", O_RDONLY);
    struct stat sb;
    fstat(fd_IVfile, &sb);

    void *IVmemPtr = calloc(1, sb.st_size);

    read(fd_IVfile, IVmemPtr, sb.st_size);

    int ivfilesize = sb.st_size / sizeof(IVFile);

    IVFile *ivfilemap = static_cast<IVFile *>(IVmemPtr);

    const char *limit_time;
    for (int count = 0; count < ivfilesize; ++count) {
        if (strncmp(ivfilemap[count].IVhandler, "XT3E4", strlen("XT3E4")) == 0) {
            limit_time = ivfilemap[count].IV_value;
        } else if (strncmp(ivfilemap[count].IVhandler, "C14TC", strlen("C14TC")) == 0) {
            std::cout << "ptrace_num=" << *(int *) ivfilemap[count].IV_value << std::endl;
        }
    }

    unsigned int limit = *(unsigned int *) limit_time ^ 0xabcdcbab;
    time_t t;
    struct tm *tm;
    time(&t);
    tm = localtime(&t);
    unsigned int now = (tm->tm_year + 1900) * 10000 + (tm->tm_mon + 1) * 100 + tm->tm_mday;

    std::cout << "limit=" << limit << ", now=" << now << std::endl;

    close(fd_IVfile);
}

void read_so() {
    void *soinfo = dlopen("./libdvm.so", RTLD_NOW);
    void *fn = dlsym(soinfo, "dvm_dalvik_system_DexFile");
}

void test_strtok_r() {
    char line[512] = "729c2dc000-729c600000 ---p 00000000 00:00 0 ";
    char *plast = nullptr;
    char *begin_addr = strtok_r(line, "- ", &plast);
    std::cout << "begin_addr=" << begin_addr << std::endl;
    std::cout << "plast=" << (plast - line) << std::endl;

    char *end_addr = strtok_r(nullptr, "- ", &plast);
    std::cout << "end_addr=" << end_addr << std::endl;
    std::cout << "plast=" << (plast - line) << std::endl;
}

int main() {
//    read_file();
    test_strtok_r();
}