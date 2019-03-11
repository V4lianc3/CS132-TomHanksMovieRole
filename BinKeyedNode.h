// Binary Node class with search Key
#pragma once

// includes
#include <ostream>
using namespace std;

// Code provided by Cliff Snyder
template <class K, class P>
class BinKeyedNode
{
private:

	K searchKey;
	P payload;
	BinKeyedNode *left;
	BinKeyedNode *right;
	

public:

	//constructor
	BinKeyedNode(K newSearchKey, P newPayload)
	{
		// Constructor
		searchKey = newSearchKey;
		payload = newPayload;
		left = nullptr;
		right = nullptr;
	}

	//constructor with parameters
	/*BinKeyedNode(P newPayload, BinKeyedNode<P>* newLeft, BinKeyedNode<P>* newRight)
	{
		payload = newPayload;
		left = newLeft;
		right = newRight;
	}*/

	// accessors 
	P getPayload() const
	{
		return payload;

	}

	BinKeyedNode* getLeft() const
	{
			// get left pointer
			return left;
	
	}

	BinKeyedNode* getRight() const
	{
			//get the right pointer
			return right;
	
	}

	K getSearchKey() const
	{
		return searchKey;
	}

		// mutators
		void setPayload(P newPayload)
		{
			// set the payload
			payload = newPayload;
	
		}
	
		void setLeft(BinKeyedNode *newLeft)
		{
			// set the new pointer
	
			left = newLeft;
	
		}
	
		void setRight(BinKeyedNode *newRight)
		{
			// set the new right pointer
			right = newRight;
		}

		void setSearchKey(K newKey)
		{
			searchKey = newKey;
		}
	
		// Operator Overload
		friend ostream& operator <<(ostream& outStream, const BinKeyedNode& node)
		{
			outStream << node.getPayload();
			return outStream;
		}
	
		// Destructor
		~BinKeyedNode()
		{
	
		}
	};


