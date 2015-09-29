//Sean Clancy 
// CS235 Lab 2 

#include <iostream>
#include <vector>
#include <fstream> 
#include <map>
#include <set>
#include <list>
#include <sstream>
#include <ctype.h>
#include <locale>
using namespace std;


void get_dictionary(set<string>& dictionary, string filename)
{
	ifstream infile;
	infile.open(filename.c_str());
	if(infile.is_open())
	{
		string dicterms;
		string dicterm;
		locale loc;
		while(getline(infile,dicterms))
		{
			for(auto c : dicterms)
			{
				dicterm += std::tolower(c,loc);
			}
			dictionary.insert(dicterm);
			dicterm = "";
		}
	}
}
//reads in the whole text file as one string.

string get_document(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());
	if(infile.is_open())
	{
		string line1;
		string line;
		while(getline(infile,line1))
		{ 	
			line+= line1+"\n"; 
		}
		return line;
	}
	else
	{
		cout <<"The file you have chosen could not be opened." <<endl;
		string null = null;
		return null;
	}
}
string edit_text(string doc)
{
	std::locale loc;
	string line;
	int line_count=1;
	string edited_doc;
	stringstream docss;
	docss.str(doc); 
	while(getline(docss, line))
	{
		for(auto c : line)
	//for(char& c : doc)
		{
			if(isalpha(c))
			{
				edited_doc += std::tolower(c,loc); 
			}
			else
				edited_doc+= " "; 
		}
		edited_doc+="\n";
		line_count++;
	}
	return edited_doc;
}

void spellchecker(string edited_doc, map<string,list<int>>& MisspelledWordLines, set<string> dictionary)
{
	string line;
	int line_count1=1;
	stringstream document;
	document.str(edited_doc);
	while(getline(document, line)){
		stringstream FinDoc(line);
		string word;
		while(FinDoc >> word)	
		{
			if (!dictionary.count(word))
			{
				MisspelledWordLines[word].push_back(line_count1);
			}
		}											
		line_count1++;
	}
}

int main(int argc, char* argv[])
{
	set<string> dictionary;
	map<string,list<int>> MisspelledWordLines; 
	get_dictionary(dictionary,argv[1]);
	string doc = get_document(argv[2]);
	string edited_doc = edit_text(doc);
	spellchecker(edited_doc,MisspelledWordLines,dictionary);

	ofstream file;
	file.open(argv[3]);

	for(auto const &it1 : MisspelledWordLines) {
		file << it1.first << ":";
		for (std::list<int>::iterator it=MisspelledWordLines[it1.first].begin(); it != MisspelledWordLines[it1.first].end(); ++it){
			file << ' ' << *it;
		}
		file << endl;
	}
	return 0;
}


// for(auto c : line)
														// {
														// 	if(isalpha(c))
														// 	{
														// 		word+=c;
														// 	}	
														// 	else 
														// 	{
														// 		if(isspace(c)){

														// 		}
														//     	 if (dictionary.count(word))//==1
														//     	{

														//     	} 
														//     	else
														//     	{
														//     		if(word!="")
														//     		{
														//     			MisspelledWordLines[word].push_back(line_count1);
														//     		}
														//     	}
														//     	word = "";
														//     }