
// COS30008, List, Problem Set 3, 2022

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>

template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;	// the first element in the list
	size_t fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

	~List()                                                             // destructor - frees all nodes
    {
        while ( fRoot != nullptr )
        {
            if ( fRoot != &fRoot->getPrevious() )                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last
                
                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    void remove( const T& aElement )	                                // remove first match from list
    {
        Node* lNode = fRoot;                                            // start at first
        
        while ( lNode != nullptr )                                      // Are there still nodes available?
        {
            if ( **lNode == aElement )                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if ( lNode != &fRoot->getPrevious() )                       // not reached last
            {
                lNode = const_cast<Node*>(&lNode->getNext());           // go to next
            }
            else
            {
                lNode = nullptr;                                        // stop search
            }
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != nullptr )                                         // We have found the node.
        {
            if ( fCount != 1 )                                          // not the last element
            {
                if ( lNode == fRoot )
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }
            
            lNode->isolate();                                           // isolate node
            delete lNode;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

	//////////////////////////////////////////////////////////////////
    //// PS3
    //////////////////////////////////////////////////////////////////
    
	// P1

    List();                                     // default constructor

	bool empty() const;	                        // Is list empty?
	size_t size() const;                		// list size

	void push_front( const T& aElement );	    // adds aElement at front

    Iterator begin() const;                     // return a forward iterator
    Iterator end() const;                       // return a forward end iterator
    Iterator rbegin() const;                    // return a backwards iterator
    Iterator rend() const;                      // return a backwards end iterator

	// P2
	
	void push_back( const T& aElement );        // adds aElement at back

	// P3

    const T& operator[]( size_t aIndex ) const;	// list indexer

	// P4
	
    List( const List& aOtherList );             // copy constructor
    List& operator=( const List& aOtherList );	// assignment operator
    
	// P5

    List( List&& aOtherList );            		// move constructor
    List& operator=( List&& aOtherList );       // move assignment operator

    void push_front( T&& aElement );			// move push_front
    void push_back( T&& aElement );				// move push_back
};

// ────────────────────────────────  P1 implementation  ────────────────────────────────
template<typename T>
List<T>::List() :
    fRoot(nullptr),
    fCount(0)
{}

template<typename T>
bool List<T>::empty() const
{
    return fRoot == nullptr;        // list is empty when we have no root :contentReference[oaicite:0]{index=0}
}

template<typename T>
size_t List<T>::size() const
{
    return fCount;
}

template<typename T>
void List<T>::push_front(const T& aElement)
{
    Node* newNode = new Node(aElement);      // allocate new list node on the heap

    if (empty())                             // first element?
    {
        fRoot = newNode;                     // yes → becomes root (circular list of 1)
    }
    else
    {
        fRoot->push_front(*newNode);         // insert before current 12 o’clock position :contentReference[oaicite:1]{index=1}
        fRoot = newNode;                     // new node is the new root
    }
    ++fCount;
}

// ─── forward iterators ───────────────────────────────────────────────────────────────
template<typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return empty() ? Iterator(nullptr)       // empty list → past-end sentinel
                   : Iterator(fRoot);        // first payload node
}

template<typename T>
typename List<T>::Iterator List<T>::end() const
{
    return empty() ? Iterator(nullptr)
                   : Iterator(fRoot).end();  // built-in helper of the iterator
}

// ─── reverse iterators ───────────────────────────────────────────────────────────────
template<typename T>
typename List<T>::Iterator List<T>::rbegin() const
{
    return empty() ? Iterator(nullptr)
                   : Iterator(fRoot).rbegin();
}

template<typename T>
typename List<T>::Iterator List<T>::rend() const
{
    return empty() ? Iterator(nullptr)
                   : Iterator(fRoot).rend();
}
// ─────────────────────────────────────────────────────────────────────────────────────

// ────────────────────────────────  P2 implementation  ────────────────────────────────
template<typename T>
void List<T>::push_back( const T& aElement )
{
    Node* newNode = new Node( aElement );       // heap-allocate new list node

    if ( empty() )                              // list was empty → node becomes root
    {
        fRoot = newNode;
    }
    else
    {
        /*  Insert the new node just **before** the current root (12 o’clock position).
            DoublyLinkedList::push_front() places aNode in front of *this*, so calling it
            on the root makes the new node the new tail (6 o’clock) while the root stays
            unchanged.  The underlying algorithm is already provided in Tutorial 9.  :contentReference[oaicite:0]{index=0} */
        fRoot->push_front( *newNode );
    }
    ++fCount;
}
// ─────────────────────────────────────────────────────────────────────────────────────

// ─────────────────────────────  P3 implementation  ──────────────────────────────
template<typename T>
const T& List<T>::operator[]( size_t aIndex ) const
{
    // out-of-bounds check first
    if ( aIndex >= fCount )
    {
        throw std::out_of_range( "Index out of bounds." );
    }

    // walk forward aIndex steps from the root (root is index 0)
    const Node* lNode = fRoot;                         // may be nullptr only if fCount == 0

    for ( size_t i = 0; i < aIndex; ++i )
    {
        lNode = &lNode->getNext();                     // constant-time hop in the ring :contentReference[oaicite:1]{index=1}
    }

    return **lNode;                                    // Node dereference gives us the payload :contentReference[oaicite:2]{index=2}
}
// ────────────────────────────────────────────────────────────────────────────────

// ────────────────────────────────  P4 implementation  ────────────────────────────────
template<typename T>
List<T>::List( const List& aOtherList ) :
    fRoot( nullptr ),
    fCount( 0 )
{
    // delegate the real work to push_back so the relative order is preserved
    for ( const T& elem : aOtherList )
    {
        push_back( elem );
    }
}

template<typename T>
List<T>& List<T>::operator=( const List& aOtherList )
{
    // guard against accidental self-assignment
    if ( this != &aOtherList )
    {
        // 1. release current resources
        this->~List();          // invoke destructor body (but not delete this) :contentReference[oaicite:0]{index=0}
        fRoot  = nullptr;       // reset to empty state expected by push_back / empty()
        fCount = 0;

        // 2. copy nodes in original order
        for ( const T& elem : aOtherList )
        {
            push_back( elem );
        }
    }
    return *this;
}
// ─────────────────────────────────────────────────────────────────────────────────────

// ───────────────────────────────  P5 implementation  ───────────────────────────────
template<typename T>
List<T>::List( List&& aOtherList ) :
    fRoot( aOtherList.fRoot ),        // steal the ring-pointer
    fCount( aOtherList.fCount )       // …and the element count
{
    aOtherList.fRoot  = nullptr;      // leave source in a safe, empty state
    aOtherList.fCount = 0;
}

template<typename T>
List<T>& List<T>::operator=( List&& aOtherList )
{
    if ( this != &aOtherList )        // protect against self-move
    {
        this->~List();                // free current resources (destructor body)
        fRoot  = aOtherList.fRoot;    // transfer ownership
        fCount = aOtherList.fCount;

        aOtherList.fRoot  = nullptr;  // empty the source
        aOtherList.fCount = 0;
    }
    return *this;
}

// ---------- move push_front --------------------------------------------------------
template<typename T>
void List<T>::push_front( T&& aElement )
{
    Node* newNode = new Node( std::move( aElement ) );   // build payload in place

    if ( empty() )                                       // list was empty
    {
        fRoot = newNode;
    }
    else
    {
        fRoot->push_front( *newNode );   // splice before current root
        fRoot = newNode;                 // new node is the new head
    }
    ++fCount;
}

// ---------- move push_back ---------------------------------------------------------
template<typename T>
void List<T>::push_back( T&& aElement )
{
    Node* newNode = new Node( std::move( aElement ) );

    if ( empty() )                                       // first element?
    {
        fRoot = newNode;
    }
    else
    {
        /*  In the circular structure the node just *before* fRoot is the logical tail.
            Calling push_front on fRoot splices newNode right there, so it becomes
            the new tail while fRoot stays the head. */
        fRoot->push_front( *newNode );
    }
    ++fCount;
}
// ────────────────────────────────────────────────────────────────────────────────────
