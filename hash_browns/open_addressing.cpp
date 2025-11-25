
#include <iostream>

class HashMapOA
{
public:
	HashMapOA()
	{
		realloc(10);
	}

	size_t getCap() {
		return m_cap;
	}

	void print()
	{
		for (int i = 0; i < m_cap; i++)
		{
			if (m_data[i] > 0)
			{
				std::cout << m_data[i] << ", ";
			}
		}
	}

	void insert(int key) {

		size_t idx = hashFn(key);
		// using size is always at least 1 less than cap & linear probing
		while (true)
		{
			// if the key already exists
			if (m_data[idx] == key) {
				std::cout << "collision - key already exists" << std::endl;
				return;
			}
			// we'll use non positive numbers to signify emptiness
			if (m_data[idx] <= 0)
			{
				std::cout << "inserted at index: " << idx << std::endl;
				m_data[idx] = key;
				m_size++;
				if (m_size + 1 >= m_load * m_cap)
				{
					realloc(m_cap * m_scale);
				}
				break;
			}

			std::cout << "collision at index: " << idx << " - probing backwards" << std::endl;
			
			if (idx == 0) 
			{
				idx = m_cap - 1;
			}
			else {
				idx--;
			}
		}

		
	}

private:
	size_t hashFn(int key)
	{
		return key % m_cap;
	}

	void realloc(size_t new_cap) {
		std::cout << "reallocating from " << m_cap << " to " << new_cap << std::endl;

		size_t oldCap = m_cap;
		m_cap = new_cap;
		int* oldArr = m_data;
		// make new array,
		m_data = new int[new_cap];
		// copy existing into new

		if (m_size > 0)
		{
			for (int i = 0; i < oldCap; i++)
			{
				if (oldArr[i] > 0)
				{
					insert(oldArr[i]);
				}
			}
		}
		delete[] oldArr;
	}

	size_t m_size = 0;
	size_t m_cap = 0;
	double m_load = 0.75;
	double m_scale = 1.5;
	int* m_data = nullptr;
};

int main()
{
	HashMapOA m;
	m.print();
	std::cout << m.getCap() << std::endl;

	m.insert(5);
	m.insert(7);
	m.insert(7);
	m.insert(8);
	m.insert(9);
	m.insert(1);
	m.insert(17);
	m.insert(23);
	m.insert(28);
	m.insert(64);
	m.insert(13);
	m.insert(43);
	m.insert(41);
	m.insert(55);
	m.insert(77);
	m.insert(78);
	m.insert(89);
	m.insert(97);
	m.insert(101);
	m.print();
}