//
// Created by Pavan Sai Ram Korumilli on 10/10/2021
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>

// constructor with default name
Library::Library(const string &Name) 
{
string number = Name;

}

// destructor
// nothing on heap
Library::~Library() 
{
  // destructor
}

// isInLibrary is the function takes reference string BookName that const that doesn't change, The function
// checks to see the numberofbooks where it is zero then it would return false which it doesn't have any books
//Go's through thte array which is bookofarray and checks to see each one where the book name matchs.
bool Library::isInLibrary(const string &BookName) const 
{

  if(numberOfBooks == 0)

  {

    return false;

  }

  else 

  {

    for( int i =0; i < numberOfBooks; i++)

    {

      if(booksOfArray[i] == BookName)

      {

        cout <<" The book is in Library already";

         return true;

      }
      
    }

    return false;

  }

}
// The function findBook has name as string with it being const which doesn't require to change.
// checks to see if the numberOfBooks are zero then it would return false which means their is nothing
// else it go through booksofarray until the name of matchs with the array.
// then it would return the index of the array where the name match
// if the name doesn't match the bookofarray that it would return -1, which the name doesn't match. 
  int Library::findBook(const string& name) const

  {

    if(numberOfBooks == 0)
    {
      
      return -1;

    }

    else

    {

    for( int i = 0; i < numberOfBooks; i++)

    {

      if(booksOfArray[i] == name)

      {

        return i;

      }

    }

    return -1;

    }

  }

//function addBook has string BookName as parameter beacause the the array is string and parameter should be string
//It checks to see if the numberofbook are full or equal to 100, then the array is full
//else the isInLibray function of bookname is used to see if the bookname is already is in use or not.
// if the book name is not used again then
// add a new book to the array which is booksofarray.
// return true if successful,
// then the numberofbooks increase.
bool Library::addBook(const string &BookName) 
{
 
  if( numberOfBooks == MAX)

  {

    return false;

  }

  else 

    if(!isInLibrary(BookName))

    {

      booksOfArray[numberOfBooks] = BookName;

      numberOfBooks++; 

      return true;

    }
  
  return false;

}

//function remove has string BookName as parameter beacause the the array is string and parameter should be string
//creating a new variable removeinbook is to find the index of the book that you want to remove the book
// checks to see the removeInBook to see whether it is -1
// it would return false
// removes to book from the bookofarrays and replaces it with the last book of the bookofarrays or array.
// number of books would decrease.
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName)
{
   
  int removeInBook = findBook(BookName);

  if(removeInBook == -1)

  {

     return false;

  }

  booksOfArray[removeInBook] = booksOfArray[numberOfBooks -1];

  numberOfBooks--;

  return true;

}

// function listAllBook is a void types which doesn't  return any type.
//go through the array and prints them all.
void Library::listAllBooks() const

{

  for(int i = 0; i < numberOfBooks; i++)

  {

    cout << booksOfArray[i]<< " ";

  }

}

// This function outputs the stream
// go's through the array ans outputs them.
ostream &operator<<(ostream &Out, const Library &Lib) 

{
  for(int i = 0; i < Lib.numberOfBooks; i++)

  {

    Out <<Lib.booksOfArray[i] << " ";

  }

  return Out;

}