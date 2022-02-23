// B-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template< typename T>
class Node
{
private:
	T* keys;
	int order;
	bool leafnode;
	Node** ptr;//child
	int numOfkeys;

public:
	Node() {}
	Node(int o, bool x)
	{
	    if(o%2=0){ //if the order is even// assume  o=4 then order =2
        order = o/2 ;
        keys = new T[2 * order -1];//maximum number of keys //max key =3
        *ptr = new Node[2 * order]; //maximum number of childerns //max child =4
	    }else{
	    order = (o+1)/2; //if the order is odd  //assume o=5 then order =3
	    keys = new T[2 * order -2 ];//max key =4
	    *ptr = new Node[2 * order- 1];//max child=5
	    }

		leafnode = x;
		numOfkeys = 0;


	}
	~Node() {}

    template< typename T>
    friend class Btree;

};


template< typename T>
class Btree
{
private:
	 Node<T> * root ;
	int order;

public:
	Btree() {}
	Btree(int n)
	{
		root = NULL;
		order = n;
	}
	~Btree() {}
////////////////////////////////////////////////////////////////////////////
	void Split(int ind,Node *y) {
  Node*z = new Node(y->order, y->leafnode);
  z->numOfkeys = order - 1;
  //////////////////////////////////

  for (int i = 0; i < order - 1; i++){
    z->keys[i] = y->keys[i + order];
  }
  //////////////////////////////////
  if (y->leafnode == false) {
    for (int i = 0; i < order; i++){
      z->ptr[i] = y->ptr[i + order];
    }
  }
  //////////////////////////////////
  y->numOfkeys = order - 1;
  for (int i = numOfkeys; i >= ind + 1; i--){
    ptr[i + 1] = ptr[i];
  }
  ptr[ind + 1] = z;
  //////////////////////////////////
  for (int i = numOfkeys- 1; i >= ind; i--){
    keys[i+ 1] = keys[i];
  }
  //////////////////////////////////
  keys[ind] = y->keys[order - 1];
  numOfkeys = numOfkeys + 1;
}

};

int main()
{

	Btree <int> b(3);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
