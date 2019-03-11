// main for TomHanks


#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "BSTree.h"
#include"TomHanksMovieRole.h"
using namespace std;




int main()
{

	const string MYFILE = "TomHanksMovieRoles.txt"; // Constant file name 
	ifstream infile;
	TomHanksMovieRole tomHanksRole;
	BSTree<string, TomHanksMovieRole> tree;

	infile.open(MYFILE);

	assert(infile.is_open);
	while (!infile.eof())
	{
		infile >> tomHanksRole;
		tree.insert(tomHanksRole.getMovieTitle(), tomHanksRole);
	
	}

	//output the tree
	cout << tree;
	
	system("PAUSE");
	return 0;
}
