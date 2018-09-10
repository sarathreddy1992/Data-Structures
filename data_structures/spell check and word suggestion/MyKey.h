struct Data{
	int x;
	int y;
	int operator%(int size) const
	{
		return (x + y) % size;
	}
	bool operator==(const Data &d){
		if (x == d.x && y == d.y)
			return true;
		return false;
	
	}
	bool operator!=(const Data &d){
		if (x == d.x && y == d.y)
			return false;
		return true;

	}
};

class hash_generator
{
public:
	int operator()(const string key, int size) {
		int hash = 0;
		for (char c : key)
			hash += c;
		return hash%size;
	}
};