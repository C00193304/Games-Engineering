#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

static int counter;
const int n = 5;
int buf, p = 0, c = 0;
 static std::mutex m_lock;


void Producer()
{
	int a[n] = { 10, 20, 30, 40, 50 };
	bool run = true;
	while (run == true)
	{
		m_lock.lock();
		while (p < n)
		{
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			while (!(p == c)) // await
			{
			//	std::cout << "spinning:" << std::endl;
			}
			buf = a[p];
			std::cout << a[p] << "deposited in buffer" << std::endl;
			p = p + 1;
		}
		std::cout << "production finished" << std::endl;
		run = false;
		m_lock.unlock();
	}
}

void Consumer()
{
	std::cout << m_lock.try_lock() << std::endl;
	int b[n];
	bool run = true;
	while (run == true)
	{
		m_lock.lock();
		while (c < n)
		{
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			while ((p <= c))//await
			{
				//std::cout << "spinning: " << std::endl;
			}
			b[c] = buf;
			std::cout << buf << " deposited in b[]" << std::endl;
			c = c + 1;
		}
		std::cout << "consumption finished" << std::endl;
		run = false;
		m_lock.unlock();
	}
}

void fun()
{
	while (true)
	{
		std::cout << std::this_thread::get_id() << std::endl;

		m_lock.lock();
		counter = counter + 1;
		std::cout << "counter: " << counter << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		m_lock.unlock();
	}
}

int main(void)
{

	std::thread t1(fun);
	std::thread t2(fun);
	t1.join();
	t2.join();
	std::cin.get();
}