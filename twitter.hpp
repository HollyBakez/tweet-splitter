#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <iostream>
#include <string>
using namespace std;

// Insert code here for the Tweet class from Project 2
class Tweet 
 {
 private:
 string username;
 string message;
 int charLength; 
 public:
 
 Tweet() //Default Constructor
 {
     username.empty();
     message.empty();
     charLength = 0;
 }
 
 Tweet(string u, string m)
 {
     username = u;
     message = m;
     charLength = message.length();
 }
 
 void setUsername(string u)
 {
     username = u;
 }
 void setMessage(string m)
 {
     message = m;
     charLength=message.length();
 }
 
 string getUsername()
 {
     return username;
 }
 string getMessage()
 {
     return message;
 }
 int getCharLength()
 {
     return charLength;
 }
 
 virtual void display()
 {
     cout<< "@" << username << ": " << message;
     cout<< endl;
     
 }
 };
// Insert code here for the MultiTweet class that inherits from Tweet
class MultiTweet: public Tweet
{
private:
string* subMessages;
int size;
public:
    
    MultiTweet(string u, string m): Tweet(u,m)
    {
        subMessages = new string[100];
        size=0;
        splitTweets();
    }
    void splitTweets();
    
    int getSize()
    {
        return size;
    }
    virtual void display();
};
// Insert code here for the TweetStream class
 class TweetStream
 {
private:
string userName;
Tweet* tweets[100];
int size;
public:
     TweetStream(string un)
     {
         userName = un;
         size = 0;
     }
     void setUsername(string un)
     {
         userName = un;
     }
     string getUsername()
     {
         return userName;
     }
     void setSize(int s)
     {
         size = s;
     }
     
     int getSize()
     {
         return size;
     }
     
     void addMessage(string message);
     
     void display();
     
 };
#endif
