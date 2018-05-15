#include "twitter.hpp"

// Insert code here to implement MultiTweet functions
// splitTweets and display
void MultiTweet::splitTweets()
{
     string message = getMessage();
    while (message.length()>274)
    {
        int space = message.rfind(" ", 273);
        int ex = message.rfind ("!", 273);
        int ques = message.rfind("?",273);
        int period = message.rfind(".",273);
        int semicolon = message.rfind(";",273);
        int dash = message.rfind("-",273);
        int split;
        if(space > ex && space > ques && space > period && space > semicolon && space > dash)
        {
            split = space;
        }
        else if(ex > space && ex > ques && ex > period && ex > semicolon && ex > dash)
            split = ex;
        else if(ques > space && ques > ex && ques > period && ques > semicolon && ques > dash)
            split = ques;
        else if(period > space && period > ex && period > ques && period > semicolon && period > dash)
            split = period;
        else if(semicolon > space && semicolon > ex && semicolon > ques && semicolon > period && semicolon > dash)
            split = semicolon;
        else if(dash > space && dash > ex && dash > ques && dash > period && dash > semicolon)
            split = dash;    
        else if(period == -1 && space == -1 && ques == -1 && ex == -1 && dash == -1 && semicolon == -1)
            split = 273;
        subMessages[size]=getMessage().substr(0,split+1); //set username too
        setMessage(getMessage().substr(split+1));
        size++;
    }
    if (message.length() > 0)
    {
        subMessages[size]= message;
        size++;
    }
   
};

void MultiTweet::display()
{
    for ( int i = 0; i<size ; i++)
    {
    cout <<subMessages[i]<< " ("<< i+1 << "/" << size <<") "<<endl;
    }
}
// Insert code here to implement TweetStream functions
// addMessage and display
void TweetStream::addMessage(string message)
{
    if(message.length()<=280)
    {
        
        tweets[size] = new Tweet(userName, message);
        
    }
    else 
    {
        
        tweets[size] = new MultiTweet(userName, message);
    }
    size++;
}

void TweetStream::display()
{
    for(int i = 0; i < size; i++)
    {
        tweets[i]->display();
    }
}