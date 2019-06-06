// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <cstdio>
#include <string>

void pause_thread(int n) //n ==seconds
{
    auto start = std::chrono::high_resolution_clock::now();

    std::cout<<"\nthread: " + std::to_string(n) + " started";
    std::this_thread::sleep_for (std::chrono::seconds(n));

    std::cout << "\npause of " + std::to_string(n) + " seconds ended";

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "\nWaited " + std::to_string(elapsed.count());
}
 
int main() 
{
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nSpawning 3 threads...\n";
    std::thread t1 (pause_thread, 1);
    std::thread t2 (pause_thread, 2);
    std::thread t3 (pause_thread, 3);

    t1.join();
    t2.join();
    t3.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "\nWaited " + std::to_string(elapsed.count());

    std::cout<<"\nAll treads have finished!";

    std::getchar();
/*
    std::cout << "\nDone spawning threads. Now waiting for them to join:";
 
    t1.join();
    std::cout<<"\npassed join 1\n";
    t2.join();
    std::cout<<"\npassed join 2\n";
    t3.join();
    std::cout<<"\npassed join 3\n";

    std::cout << "\nAll threads joined!\n";
  

    std::getchar();*/
    return 0;
}