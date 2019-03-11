//Binary Tree Class


#pragma once

#include <ostream>
#include "BinKeyedNode.h"
#include "Queue.h"
using namespace std;


template <class K,class P>
class BSTree
{

private:

	// Attributes
	BinKeyedNode<K,P> *head;
	

	// Inorder output method
	void inOrderOutputHelper(ostream& outStream, BinKeyedNode<K,P> *current) const
	{

		if (current != nullptr)
		{
			inOrderOutputHelper(outStream, current->getLeft());
			outStream << current->getPayload();
			inOrderOutputHelper(outStream, current->getRight());
		}
	}

	//// copy helper method
	//BinKeyedNode<K,P>* copyHelper(BinKeyedNode<K,P>* current)
	//{
	//	BinKeyedNode<K,P> *temp = nullptr;
	//	if (current != nullptr)
	//	{
	//		temp = new BinKeyedNode<K, P>(current->getPayload()); /*copyHelper(current->getLeft())*//*copyHelper(current->getRight()*/
	//		
	//	}
	//		
	//	return temp;
	//}

	BinKeyedNode<K,P>* insertNode(BinKeyedNode<K, P>* nodePtr, const K &newKey, const P &newPayload)
	{
		if (nodePtr == nullptr) // Empty Node
		{
			nodePtr = new BinKeyedNode<K, P>(newKey, newPayload);
		}

		else if (newKey < nodePtr->getSearchKey()) // Less than
		{
			nodePtr->setLeft(insertNode(nodePtr->getLeft(), newKey, newPayload));
			
		}
			
		else // Greater than or equal
		{
			nodePtr->setRight(insertNode(nodePtr->getRight(), newKey, newPayload));
		}

		return nodePtr;
	}
	
	bool findNode(BinKeyedNode<K, P> *nodePtr, const K &searchKey, P &returnPayload)
	{
		bool returnValue = false;

		if (nodePtr != nullptr) // check for empty tree
		{
			if (searchKey == nodePtr->getSearchKey()) // found
			{
				returnValue = true;
				returnPayload = nodePtr->getPayload();
			}
		}

		else if (searchKey < nodePtr->getSearchKey()) // Less than
		{
			returnValue = findNode(nodePtr->getLeft(), searchKey, returnPayload);
		}

		else // Greater than or equal
		{
			returnValue = findNode(nodePtr->getRight(), searchKey, returnPayload);
		}
		
		return returnValue;
	}


public:


	//Default constructor
	BSTree()
	{
		head = nullptr;
		
	}

	//// copy constructor
	//BSTree(const BSTree &fromTree)
	//{
	//	/*this->head = fromTree.getRoot();*/
	//	this->head = copyHelper(fromTree.head);
	//}

	 //Deconstructor
	~BSTree()
	{
		clearTree(this->head);
	}


	//// Accessor 
	//BinKeyedNode<P>* getRoot() const
	//{
	//	return head;
	//}

	
	//// Mutators
	//void setHead(BinKeyedNode<P> *node)
	//{
	//	head = node;
	//}

	void insert(const K &newKey, const P &newPayload)
	{
		head = insertNode(head, newKey, newPayload);
	}

	bool find(const K &searchKey, P &returnPayload)
	{
		return(findNode(head, searchKey, returnPayload));
	}

	// clear Tree Method
	void clearTree(BinKeyedNode<K,P> * current)
	{
		if (current != nullptr)
		{
			clearTree(current->getLeft());
			clearTree(current->getRight());
			delete current;
		}
	}



	// << overload
	friend ostream& operator <<(ostream& outStream, BSTree tree)
	{
		
		tree.inOrderOutputHelper(outStream, tree.head);
		return outStream;
	}


	// = overload
	 BSTree& operator =(const BSTree& fromTree)
	{
		
		 if (this != &fromTree)
		 {
			 
			 clearTree(this->head);
			 this->head = copyHelper(fromTree.getRoot());
		 }


		return *this;
	}
};
