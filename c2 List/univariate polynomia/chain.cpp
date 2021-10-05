#include"chain.h"
using namespace std;
template<class T>
chain<T>::chain()
{
	firstNode = nullptr;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{
	if (theList->firstNode == nullptr) {
		firstNode = nullptr;
		listSize = 0;
	}
	firstNode = new chainNode(theList.firstNode->element);
	chainNode<T>* targetNode = theList.firstNode->next;
	chainNode<T>* sourceNode = firstNode;
	while (targetNode) {
		sourceNode->next = new chainNode<T>(targetNode->element);
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}
}

template<class T>
chain<T>::~chain()
{
	while (firstNode) {
		chainNode<T>* deleteNode = firstNode->next;
		delete firstNode;
		firstNode = deleteNode;
	}
}

template<class T>
T& chain<T>::get(int theIndex) const
{
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; ++i)
		currentNode = currentNode->next;
	return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement)
{
	chainNode<T>* currentNode = firstNode;
	int i;
	for (i = 0; i < listSize && currentNode->element != theElement; ++i);
	if (currentNode->element != theElement)return -1;
	return i;
}

template<class T>
void chain<T>::erase(int theIndex)
{
	if (theIndex == 0)
	{
		firstNode = firstNode->next;
		return;
	}
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex - 1; ++i)currentNode = currentNode->next;
	currentNode->next = currentNode->next ? currentNode->next->next : nullptr;
	--listSize;
}

template<class T>
void chain<T>::insert(int theIndex, const T& element)
{
	if (theIndex == 0) { firstNode = new chainNode<T>(element, firstNode); }
	else {
		chainNode<T>* currentNode = firstNode;
		for (int i = 0; i < theIndex - 1; ++i)currentNode = currentNode->next;
		currentNode->next = new chainNode<T>(element, currentNode->next);
	}
	++listSize;
}

template<class T>
void chain<T>::output(ostream& out)
{
	for (chainNode<T>* currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next)
		out << currentNode->element << " ";
}


template<class T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
	int i = toIndex - fromIndex + 1;
	while (i--)erase(fromIndex);
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostream s;
		s << "index=" << theIndex << " but the size of list is" << listSize;
		throw 
	}
}

template<class T>
ostream& operator<<(ostream& out, const chain<T>& x) {
	x.output(out); return out;
}