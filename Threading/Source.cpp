#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

static int counter;
const int n = 5;
int buf, p = 0, c = 0;
static std::mutex m_lock;
int empty = n;
int full = 0;
int front = 0;
int rear = 0;

void P(int &s)
{
	while (s <= 0)
	{

	}
	s--;
}

void V(int &s)
{
	s++;
}

void Producer()
{
	int a[n] = { 10, 20, 30, 40, 50 };

	bool run = true;
	while (run == true)
	{
		
		while (p < n)
		{
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;
			
			while (!(p == c)) // await
			{
			//	std::cout << "spinning:" << std::endl;


			}
			m_lock.lock();
			P(empty);
			buf[&rear] = a[p];
			rear = (rear + 1) % n;
			V(full);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			m_lock.unlock();

			std::cout << a[p] << "deposited in buffer" << std::endl;
			
			p = p + 1;
		}
		std::cout << "production finished" << std::endl;
		run = false;
	}
}

void Consumer()
{
	int b[n];
	bool run = true;
	while (run == true)
	{
		//m_lock.lock();
		while (c < n)
		{
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;
			
			while ((p <= c))//await
			{
				//std::cout << "spinning: " << std::endl;
			}
			m_lock.lock();
			P(full);
			b[c] = buf[&front];
			front = (front + 1) % n;
			V(empty);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			m_lock.unlock();

			std::cout << buf << " deposited in b[]" << std::endl;
			c = c + 1;
		}
		std::cout << "consumption finished" << std::endl;
		run = false;

	}
}

int main(void)
{

	std::thread t1(Producer);
	std::thread t2(Consumer);
	t1.join();
	t2.join();
	std::cin.get();
}