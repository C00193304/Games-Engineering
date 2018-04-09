#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

static int counter;
const int n = 5;
int buf, p = 0, c = 0;
int buf2[5];
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
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			while (!(p == c)) // await
			{
			//	std::cout << "spinning:" << std::endl;
			}
			//semaphore signalling 
			//m_lock.lock();
			buf = a[1];
			std::cout << a[p] << "deposited in buffer" << std::endl;

			P(empty);
			buf2[rear] = buf;
			rear = (rear + 1) % n;
			V(full);

			//m_lock.unlock();

			

			p = p + 1;
		std::cout << "production finished" << std::endl;
	}
}

void Consumer()
{
	int b[n];
	bool run = true;
	while (run == true)
	{
		//m_lock.lock();
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));

			while ((p <= c))//await
			{
				//std::cout << "spinning: " << std::endl;
			}
			std::cout << buf << " deposited in b[]" << std::endl;
			//semaphore
			//m_lock.lock();
			P(full);
			b[c] = buf2[front];
			front = (front + 1) % n;
			V(empty);
			
			//m_lock.unlock();

			
			c = c + 1;
		std::cout << "consumption finished" << std::endl;

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