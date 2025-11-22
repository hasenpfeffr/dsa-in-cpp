
#include <iostream>

class HashMapOA
{
public:
	HashMapOA()
	: m_data(new int[m_cap]) 
	{}
private:
	size_t m_size = 0;
	size_t m_cap = 10;
	int* m_data = nullptr;
};

int main() 
{
	HashMapOA m;
}