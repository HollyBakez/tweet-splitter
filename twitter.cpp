#include "twitter.hpp"

// Insert code here to implement MultiTweet functions
// splitTweets and display
void MultiTweet::splitTweets()
{
     string arrString[100];
    const int charLimit= 274; // constant limit on the amount of chars allowed
    int beginIndex = 0; //initializes the first index to 0
    bool specialChar;
    int index = 0; // index intialized to 0
    int splits;
     splits= (message.length()/280);
    
    for (int i = 0; i <= splits; i++) //counts through the splits
    {
        index = charLimit + index; //updates the index through each iteration of the split loop, i.e each split another char amt is added on top of 280
            if (index > message.length())
            {
                index = message.length(); //saves the last index of the message in the index
            }
        if(message[index] != ' ' || message[index] != '?' || message[index] != '.' || message[index] != '!') //Special character cases, if the last index is neither of these
        {
            for (int k = index; k > 0; k--) //Count back from the special character case until it finds a space
                if (message[k] ==' ' || message[k] == '?' || message[k] == '.' || message[k] == '!') //Special characters, when the index lands on these in the array
                {
                    index = k+1; // The index is = to the k index from the message string
                    specialChar = false;
                    break;
                }
            
        }
        if (specialChar == true) //If there is no spaces or punctuations in 274th char than split 
        {
            index = 273;
        }
        
        arrString[i] = message.substr(beginIndex, index-beginIndex); //.substr allows to store from the string with the domain within () to arr
        // This arr stores the split mssgs and updates it to the int main to be passed to displaySplitTweet
        subMessages[i].setMessage(arrString[i]);
        subMessages[i].setUsername(username);
        beginIndex = index; // Updates the beginning index for the loop again
        size++;
        
    }
    
   if(size>1)
   {
    for(int i = 0 ; i < size; i++)
    {
       string counter = " (" + to_string(i+1)+"/"+to_string(size) + ")"; //saves the "(/)" to the end of the array
       subMessages[i].setMessage(subMessages[i].getMessage()+ counter);
    } 
   }

};

virtual void MultiTweet::display()
{
    cout<< "@" << username << ": " << message;
    cout<< endl;
}
// Insert code here to implement TweetStream functions
// addMessage and display
void TweetStream::addMessage(string message)
{
    if(message.length()<280)
    {
        tweets[size] = message;
        
    }
    else 
    {
        tweets[size] = message;
    }
    size++
}

void TweetStream::display()
{
    for(int i = 0; i < size; i++)
    {
        tweets[i]->display();
    }
}