
//#include<vector>
//#include<string>
#include"dependency.h"
#include"graph.h"
#include<fstream>
#include"Header.h"
using namespace std;

//#include"../filesystem/FileSystem.h"
//#include<unordered_map>



vector<string> Dependency :: fileRead(string file)
{
	DIR* dir;
	dirent* pdir;
	vector<string> files;
	dir = opendir(file.c_str());
	while(pdir=readdir(dir))
		{
		files.push_back(pdir->d_name);

	}
	return files;
}


int a;
int main()
{
	Dependency dep;
	std::cout << "test files in .\\ TestFiles";
	std::vector<std::string> temp;
	 /*FileSystem::Directory::getFiles(".", "*.h");
	FileSystem::Directory::getFiles(".", "*.cpp");
	std::string direc = FileSystem::Directory::getCurrentDirectory();*/
	////FileSystem::Directory::setCurrentDirectory(".\\inputFiles");
	//for (size_t i = 0; i < temp.size(); ++i)
	//{
	//	std::cout << "\n    " << FileSystem::Path::getFullFileSpec(temp[i]).c_str();
	//}

	size_t i;
	vector<string> files11 = dep.fileRead("../TestFiles/");
	unordered_map<string, vector<string>> values;
	//int j = 0;
	//for (auto i = 0; i < 10; i++) {
	//	j = i + 1;

	//}
	vector<string> getDependency;
	dep.setfileset(files11);
	getDependency = dep.finddependecy();
	values = dep.map();
	//dep.finddependecy();
	dep.displaydependency();
	//dep.disp();	
	//Graph graph(a);
	//graph.graph_();
	//graph.getTranspose();
	//graph.vectorlist();
	return 0;

}