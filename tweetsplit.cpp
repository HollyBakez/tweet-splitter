#include <iostream>
#include <string>
#include "twitter.hpp"

using namespace std;

int main()
{
  // Insert code here to get user input for username and message (feel free to reuse code from Project 2)
  string username;
  string message;
  cout << "Please enter your username: ";
  cin >> username;
  cin.ignore();
  cout << "Please input your message: ";
  getline(cin, message);
  
  // Insert code here to create a TweetStream object that receives as parameters the data from the user
 TweetStream obj(username);
 
    obj.addMessage(message);
  // Insert code here to add the user's message to the TweetStream
  // Insert code here to display tweets in the TweetStream object
    obj.display();
  return 0;
}
