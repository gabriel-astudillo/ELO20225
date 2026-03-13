#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t miPID = getpid();
    std::cout << "Hola. PID=" << miPID << "\n";
      
    fork();
    fork();
    fork();

    std::cout << "Al final. PID=" << miPID << "\n";

    exit(EXIT_SUCCESS);
}

