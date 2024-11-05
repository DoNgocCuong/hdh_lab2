

// #include "user.h"
// #include "syscall.h"  // Đảm bảo bao gồm tệp này

// typedef unsigned int uint; // Định nghĩa kiểu uint

// // Hàm main
// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         printf("Usage: trace <mask> <command> [args...]\n");
//         exit(1);
//     }

//     int mask = atoi(argv[1]);  // Chuyển đổi tham số đầu tiên thành số nguyên

//     // Gọi system call trace để theo dõi các syscall theo mask
//     trace(mask);

//     // In ra các tham số của lệnh sẽ thực thi
//     // printf("Executing: %s", argv[2]);
//     for (int i = 3; i < argc; i++) {
//         printf(" %s", argv[i]);
//     }
//     printf("\n");

//     // Thực thi lệnh với các tham số còn lại
//     if (exec(argv[2], argv + 2) < 0) {
//         printf("Error executing %s. Exec returned: -1\n", argv[2]);
//         exit(1);
//     }

//     exit(0);  // Kết thúc chương trình
// }

// Function to set the trace mask

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"



int
main(int argc, char *argv[])
{
    if(argc < 3){
       printf("Usage: trace mask program [args...]\n");

        exit(1);
    }
    
    int mask = atoi(argv[1]);

    if(fork() == 0){
        trace(mask);  // Kích hoạt theo dõi
        exec(argv[2], &argv[2]);  // Chạy chương trình với các tham số truyền vào
        printf("exec %s failed\n", argv[2]);

    } else {
        wait(0);
    }

    exit(1);  // hoặc exit(0) tùy theo ngữ cảnh

}

