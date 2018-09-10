#include"dependency.h"

unordered_map<string, vector<string>> Dependency::map()
{
	return values;
}

void Dependency::setfileset(vector<string> file1)
{
	files = file1;
	packages = file1;
}
void Dependency::disp()
{
	cout << "The dependent files are" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	for (int i = 0; i < files.size(); i++)
	{
		files[i];
		cout << endl;

	}

	for (int j = 0; j < packages.size(); j++)
	{
		packages[j];
		cout << endl;
	}
 }

void Dependency::dependency(string PackageName, vector<string> list)
{
	unordered_map < string, vector<string>>::const_iterator iter = values.find(PackageName);
	if (iter == values.end())
	{
		values[PackageName] = list;
	}
}

//void Dependency::finddependecy()
vector<string> Dependency::finddependecy()
{
	vector<string> vect;
	for (size_t i = 3; i < files.size(); i++)
	{
		string packagename = getpackagename(files[i]);
//		string path = "TestFiles" + files[i];
		//ifstream depanal(path);
		//	if (depanal)
		//	{
		//		cout << endl<<"able to read the file" << endl;
		//	}
		ifstream depanal(files[i]);
			if (depanal)
			{
				cout << endl<<"able to read the file" << endl;
			}
			else
			{
				cout <<endl<< "could not read the file" << endl;
			}
			string s;
			string ss;
			while (getline(depanal, ss))
			{
				size_t found = ss.find("#");
				if (found != string::npos)
				{
					s += ss;
					s.push_back('/n');

				}
			}
			for (size_t i = 0; i < packages.size(); ++i)
			{
				size_t found = s.find(packages[i]);
				if (found != string::npos)
				{
					vector<string>::iterator iter;
					iter = find(vect.begin(), vect.end(), packages[i]);
					if (iter == vect.end())
					{
						string child = getpackagename(packages[i]);
						if (child != packagename)
							vect.push_back(child);
					}
				}
			}
	}
	return vect;
}

string Dependency::getpackagename(string filename)
{
	size_t foundh = filename.find(".h");
	size_t foundcpp = filename.find(".cpp");
	if (foundh != string::npos)
	{
		replacestring(".h", "", filename);
	}
	if (foundcpp != string::npos)
	{
		replacestring(".cpp", "", filename);

	}
	return filename;
}

void Dependency::displaydependency()
{
	cout << endl << "The identified dependencies along files are" << endl;
	cout << "===============================================================" << endl;
	for (unordered_map<string, vector<string>>::const_iterator it = values.begin(); it != values.end(); it++)
	{
		cout << it->first;
		cout << endl;

		for (vector<string>::size_type a = 0; a < it->second.size(); a++)
		{
			cout <<endl<< (it->second)[a] << endl;
			cout << endl;

		}
	}
}

void Dependency::replacestring(string old, string rep, string & file_contents)
{
	for (int pos = 0;
	(pos = file_contents.find(old, pos)) != std::string::npos;
	pos += rep.length())
	{
		file_contents.replace(pos, old.length(), rep);
	}
}
