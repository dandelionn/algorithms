#include "Wallet.h"

#include <thread>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int noThreads = 100;
	Wallet wallet;
	std::vector<std::thread> threads;

   	auto start = std::chrono::high_resolution_clock::now();


	//se pornesc 100 de treaduri cu valoarea 25 
	//wallet este un function object deoarece este apelat ca o functie
	//este supradefinit operatul ()
	for (int index = 0; index < noThreads; index++)
	{
		threads.emplace_back(std::ref(wallet), 25);
	}

	//se asteapta terminarea executiei tututor treadurilor
	for (std::thread& thread : threads)
	{
		thread.join();
	}

 	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;

    std::cout << "\nWaited " + std::to_string(elapsed.count());

	std::cout << wallet.getMoney() << std::endl;
	system("pause");
}