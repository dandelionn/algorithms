#include "Wallet.h"

#include <thread>
#include <mutex>

void Wallet::addMoney(int amount)
{
	/*
	The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

	mutex offers exclusive, non-recursive ownership semantics:

	A calling thread owns a mutex from the time that it successfully calls either lock or try_lock until it calls unlock.
	When a thread owns a mutex, all other threads will block (for calls to lock) or receive a false return value (for try_lock) if they attempt to claim ownership of the mutex.
	A calling thread must not own the mutex prior to calling lock or try_lock.
	The behavior of a program is undefined if a mutex is destroyed while still owned by any threads, or a thread terminates while owning a mutex. The mutex class satisfies all requirements of Mutex and StandardLayoutType.

	std::mutex is neither copyable nor movable.*/

	/*
	The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.

	When a lock_guard object is created, it attempts to take ownership of the mutex it is given. When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is released.
	*/
	static std::mutex mtx;
	for (int index = 0; index < amount; index++)
	{
		std::lock_guard<std::mutex> lockGuard(mtx);
		m_money++;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		//~lockGuard()
		//{
			//std::mutex::unlock;_
		//}
	}
}

void Wallet::operator()(int amont)
{
	addMoney(amont);
}

int Wallet::getMoney()
{
	return m_money;
}

Wallet::Wallet(int money):m_money(money)
{
	//Empty
}


Wallet::~Wallet()
{
}
