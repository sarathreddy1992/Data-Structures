#include "Hash.h"
#include "MyKey.h"
#include <iostream>
#include <string>
using namespace std;


#ifdef DEBUG
int main()


{
	HashMap<int, string> hmap;
	hmap.put(1, "val1");
	hmap.put(2, "val2");
	hmap.put(3, "val3");
	hmap.put(4, "val4");
	string value;
	hmap.get(2, value);
	cout << value << endl;
	bool res = hmap.get(3, value);
	if (res)
		cout << value << endl;
	hmap.remove(3);
	res = hmap.get(3, value);
	if (res)
		cout << value << endl;
	struct MyKeyHash {
		unsigned long operator()(const Data& k, int size) const
		{
			return (k.x+k.y) % size;
		}
	};
	std::cout << "\ncustom data test\n\n";
	HashMap<Data, string> hmap2;
	Data d1;
	d1.x = 1;
	d1.y = 1;
	Data d2;
	d2.x = 2;
	d2.y = 2;
	Data d3;
	d3.x = 3;
	d3.y = 3;
	hmap2.put(d1, "v1");
	hmap2.put(d2, "v2");
	hmap2.put(d3, "v3");

	
	hmap2.get(d2, value);
	cout << value << endl;
	res = hmap2.get(d3, value);
	if (res)
		cout << value << endl;
	hmap2.remove(d3);
	res = hmap2.get(d3, value);
	if (res)
		cout << value << endl;
}
#endif