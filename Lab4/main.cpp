#include "linkedlist.h"

int main(int argc, char* argv[])
{
	ifstream infile;
	infile.open(argv[1]);
	string t;
	int index;
	string item;
	ofstream out;
	out.open(argv[2]);
	LinkedList<string> list;
	while(infile >> t)
	{
		if(t=="clear")
		{
			out << "clear"<<endl;
			list.clear();
		}
		else if(t=="insert")
		{
			infile >> index;
			infile >> item;
			out << "insert " << index << " " << item<< endl;
			list.insert(index,item);
		}
		else if(t=="print")
		{
			out << "print" <<endl;
			out << list.print();
		}
		else if(t=="find")
		{
			infile >> item;
			out << "find " << item << " " << list.find_item(item)<<endl; 
		}
		else if(t=="remove")
		{
			infile >> index;
			out << "remove " << index << " " <<  list.remove(index)<< endl;
		}

	}
}
	