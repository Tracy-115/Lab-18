#include <iostream>
#include <string>
using namespace std;

struct Movie{
  float rating;
  string comment;
  Movie *next;
}

int main{
  Movie *head=nullptr;
  
  char decision;
  while (toupper(again) == 'Y') {
      float rating;
      string decision;

      cout << "Enter review rating 0-5: ";
      cin >> rating;
      cout << "Enter review comments: ";
      getline(cin, desision);

