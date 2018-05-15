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
        int coma = message.rfind(",",273);
        int dash = message.rfind("-",273);
        int split;
        if(space > ex && space > ques && space > period && space > semicolon && space > dash && space > coma)
        {
            split = space;
        }
        else if (coma > space && coma > ex && coma > ques && coma > period && coma > semicolon && coma > dash)
            split = coma;
        else if(ex > space && ex > ques && ex > period && ex > semicolon && ex > dash && ex > coma)
            split = ex;
        else if(ques > space && ques > ex && ques > period && ques > semicolon && ques > dash && ques > coma)
            split = ques;
        else if(period > space && period > ex && period > ques && period > semicolon && period > dash && period > coma)
            split = period;
        else if(semicolon > space && semicolon > ex && semicolon > ques && semicolon > period && semicolon > dash && semicolon > coma)
            split = semicolon;
        else if(dash > space && dash > ex && dash > ques && dash > period && dash > semicolon && dash > coma)
            split = dash;    
        else if(period == -1 && space == -1 && ques == -1 && ex == -1 && dash == -1 && semicolon == -1 && coma ==-1)
            split = 273;
        subMessages[size]=message.substr(0,split+1); //set username too
        message = message.substr(split+1);
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
    cout << "@"<<getUsername() << ": "<<subMessages[i] << " ("<< i+1 << "/" << size <<")"<<endl;
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