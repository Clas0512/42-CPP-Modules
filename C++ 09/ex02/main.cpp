#include <iostream>
#include <deque>

int main(){


	std::deque<int> q;
	std::deque<int>::iterator it;
	it = q.begin();

	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	q.push_back(5);
	q.push_back(2);


	if (q.front() == q.back())
	{
		std::cout << "zort\n";
		exit(31);
	}
	
	std::cout << q.front() << std::endl;
	it = q.begin();
	std::cout << *it << std::endl;
	q.pop_front();

	
	std::cout << q.front() << std::endl;
	it = q.begin();
	std::cout << *it << std::endl;
	q.pop_front();
	
	
	std::cout << q.front() << std::endl;
	it = q.begin();
	std::cout << *it << std::endl;
	q.pop_front();
	
	
	std::cout << q.front() << std::endl;
	it = q.begin();
	std::cout << *it << std::endl;
	q.pop_front();
	
	it = q.begin();
	std::cout << *it << std::endl;
	std::cout << q.front() << std::endl;

	return (0);
}