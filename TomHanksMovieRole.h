// Tom Hanks Movie Role class

#pragma once


// #includes
#include <iostream>
#include <string>
using namespace std;

class TomHanksMovieRole
{

private:

	// attributes
	string movieTitle;
	int releaseYear;
	string movieRole;


public:
	// Constructor
	TomHanksMovieRole();

	// Deconstructor
	~TomHanksMovieRole();


	// Accessors

	string getMovieTitle() const;
	int getReleaseYear() const;
	string getMovieRole() const;

	// Mutators

	void setMovieTitle(string newMovieTitle);
	void setReleaseYear(int newReleaseYear);
	void setMovieRole(string newMovieRole);


	friend istream& operator >>(istream& inStream, TomHanksMovieRole &tomHanksRole);
	friend ostream& operator <<(ostream& outStream, TomHanksMovieRole &tomHanksRole);



};

