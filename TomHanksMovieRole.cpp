//Tom Hanks .cpp


#include"TomHanksMovieRole.h"


//constructor 
TomHanksMovieRole::TomHanksMovieRole()
{
	string movieTitle;
	int releaseYear = 0;
	string movieRole;
}

TomHanksMovieRole::~TomHanksMovieRole()
{
	//Deconstructor doesn't need population
}


string TomHanksMovieRole::getMovieTitle() const
{
	return movieTitle;
}


int TomHanksMovieRole::getReleaseYear() const
{
	return releaseYear;
}

string TomHanksMovieRole::getMovieRole() const
{
	return movieRole;
}


// mutators

void TomHanksMovieRole::setMovieTitle(string newMovieTitle)
{
	movieTitle = newMovieTitle;
}

void TomHanksMovieRole::setReleaseYear(int newReleaseYear)
{
	releaseYear = newReleaseYear;
}

void TomHanksMovieRole::setMovieRole(string newMovieRole)
{
	movieRole = newMovieRole;
}

// Operator overloads

istream& operator >>(istream& inStream, TomHanksMovieRole &tomHanksRole)
{
	// Code provided by Cliff Snyder
	string inputLine;
	const char tab(9);

	getline(inStream, inputLine, tab); // Reads title
	if (!inStream.eof()) // If file read is successful
	{
		tomHanksRole.setMovieTitle(inputLine); // Stores title
		getline(inStream, inputLine, tab); // Read release year
		tomHanksRole.setReleaseYear(stoi(inputLine)); // Converts string to int
		getline(inStream, inputLine);
		tomHanksRole.setMovieRole(inputLine);
	}

	return inStream;

}

ostream& operator << (ostream& outStream, TomHanksMovieRole &tomHanksRole)
{
	outStream << tomHanksRole.getMovieTitle();
	outStream << tomHanksRole.getMovieRole();
	outStream << tomHanksRole.getReleaseYear() << endl;

	return outStream;
}
