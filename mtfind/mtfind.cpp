#include "Process.hpp"
#include <thread>

int main(int argc, char* argv[])
{   
    Process proc(argv[1]);
    
    std::thread _proc{ &Process::Find, proc, argv[2] };
    _proc.join();
    
    return 0;
}