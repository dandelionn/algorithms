#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void myFunction()
	{
		for (auto index = 0; index < 10; ++index)
		{
			std::cout << "From my thread " << index << "\n";
		}
	}

void FunctionPointer()
{
	// create a thread and init
	std::thread myThread(myFunction);
	// Action from the main thread
	for (unsigned i = 0; i < 10; i++) {
		std::cout << "Main thread executing" << std::endl;
	}

	/// Join the thread
	// The main thread wants to wait for a thread to finish successfully. So, we used join(). 
	// If the initial main thread didn't wait for the new thread to finish, it would continue to the end of main() 
	// and end the program, possibly before the new thread have had a chance to run.
	myThread.join();
}

void Lambda()
{
	// create a thread and init using a lambda
	std::thread myThread([]()
	{
		for (auto index = 0; index < 10; ++index)
		{
			std::cout << "From my thread" << index << "\n";
		}
	});

	// Action from the main thread
	for (unsigned i = 0; i < 10; i++)
	{
		std::cout << "Main thread executing" << std::endl;
	}

	/// Join the thread
	myThread.join();
}

void CreateThread()
{
	//FunctionPointer();

	//Lambda();
}


void TheJoin()
{
	/// Tip
	//  Never call join() or detach() on std::thread object with no associated executing thread
	std::vector<std::thread> myVectorOfThreads;

	// create a vector of threads
	for (int index = 0; index < 10; ++index)
	{
		myVectorOfThreads.push_back(std::thread([]()
		{
			std::cout << std::this_thread::get_id() << '\n';
		}));
	}
	// int the vector and output the thread id in each one

	// join all threads (maybe using mem_fn)
	std::for_each(std::begin(myVectorOfThreads), 
		std::end(myVectorOfThreads), std::mem_fn(&std::thread::join));
}

void TheDetach()
{
	/// Tip - este copiat joinul!!!
	//  Never call join() or detach() on std::thread object with no associated executing thread
	std::vector<std::thread> myVectorOfThreads;

	// create a vector of threads
	for (int index = 0; index < 10; ++index)
	{
		myVectorOfThreads.push_back(std::thread([]()
		{
			std::cout << std::this_thread::get_id() << '\n';
		}));
	}
	// int the vector and output the thread id in each one

	// join all threads (maybe using mem_fn)
	std::for_each(std::begin(myVectorOfThreads),
		std::end(myVectorOfThreads), std::mem_fn(&std::thread::detach));
	
	
	/// Tip - aici este detach-ul!!!
	// Never forget to call either join or detach on a std::thread object with associated executing thread 

	// create a vector of threads

	// int the vector and output the thread id in each one

	// detach all threads (maybe using mem_fn)
}

void JoinAndDetach()
{
	//TheJoin();

	TheDetach();
}


void threadOne(int x, char s)
{
	std::cout << x << s << std::endl;
}

void SimpleArguments()
{
	// Init a thread variable with threadOne method
	// Check if joinable and join
	std::thread myThread(threadOne, 5, 'M');

	if (myThread.joinable())
	{
		myThread.join();
	}
}

void HowNotTo()
{
	// This is an example of how not to pass a pointer to a thread

	// 1. Create a thread
	// 2. Inside that thread create a pointer
	// 3. Inside that thread create a new thread and pass the pointer to the new created thread
	// 4. Simulate some heavy computation (with sleep) in the second thread
	// 5. Modify the value of the pointer in the second thread
	// 6. In the first thread also modify the value of the pointer
	// 7. delete the pointer
	// 8. Join the second thread in the first thread
	// 9. Join the first thread
	// 10. What is going on ?
}

void HowNotTo2()
{
	// How not to pass references to thread
	//

	//
	// Even if threadCallback accepts arguments as reference but still changes done it are not visible outside the thread.
	// Its because x in the thread function threadCallback is reference to the temporary value copied at the new thread’s stack.

	// 1. Create a new thread and pass a const referece to it
	// 2. Modify the const reference variale inside that thread
	// 3. Join the thread
	// 4. Do some logging inside and outside the thread, what values are you expected to get?
}

void HowToPassRefArg()
{
	// 1. Create a new thread and pass a const referece to it
	// 2. Modify the const reference variale inside that thread
	// 3. Join the thread
	// 4. Do some logging inside and outside the thread, what values are you expected to get?
}

void ThreadArguments()
{
	SimpleArguments();

	HowNotTo();

	HowNotTo2();

	HowToPassRefArg();
}

int main()
{
	CreateThread();

	//JoinAndDetach();

	ThreadArguments();

	std::cin.get();

	return 0;
}