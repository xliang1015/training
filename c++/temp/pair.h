//Pair.h

template <class T>
class Pair 
{ 
	public: 
		Pair (T _x, T _y); 
		T Sum ();

	protected: 
		T x, y; 
};

template <class T> 
Pair<T>:air (T _x, T _y) : x (_x), y(_y) 
{ 
}

template <class T> 
T Pair<T>::Sum () 
{ 
	return x + y; 
}

// PairA.cpp 
#include "Pair.h"

int Add (int x, int y) 
{ 
	Pair <int> Two (x, y); 
	return Two.Sum (); 
}

// PairB.cpp 
#include "Pair.h"

int Double (int x) 
{ 
	Pair <int> Two (x, x); 
	return Two.Sum (); 
}
