#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;
const int max_tries = 7;
int letterFill (char, string, string&);
int main()
{
    string name;
    char letter;
    int num_of_wrong_guesses = 0;
    string word;
    string words[10] = {"germany","france","turkey","italy","russia","spain","austria","greece","switzerland","japan"};
    
    srand(time(NULL));
    int n=rand()%10;
    word=words[n];
    
    string unknown(word.length(),'_');
    
    cout<<"\nWelcome to Hangman Game."<<endl;
    cout<<"\nThe category in this program is 'Countries'.";
    cout<<"\nEach letter is represented by an underscore.";
    cout<<"\nType only one letter at a time.";
    cout<<" You have "<<max_tries<<" tries in total.\n";

    
    while (num_of_wrong_guesses<max_tries){
        
        cout<<unknown;
        cout<<"\n\nGuess a letter: ";
        cin>>letter;
        
        
        if (letterFill(letter, word, unknown)==0){
            cout<<"\nThis letter is not in the word.\n";
            num_of_wrong_guesses++;
            
        if(num_of_wrong_guesses==1){
                
                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
                    }
        else if(num_of_wrong_guesses==2){
                
                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    O" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
                    }
        else if(num_of_wrong_guesses==3){
        
                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    O" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
                    
                    }
        else if(num_of_wrong_guesses==4){

                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    O" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |     \\" <<endl;
                            cout << "  |      \\" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
                       
                    }
        else if(num_of_wrong_guesses==5){
                
                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    O" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |   / \\" <<endl;
                            cout << "  |  /   \\" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
                        
                    }
        else if(num_of_wrong_guesses==6){
                
                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    O" <<endl;
                            cout << "  |   /|" <<endl;
                            cout << "  |  / |" <<endl;
                            cout << "  |   / \\" <<endl;
                            cout << "  |  /   \\" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
                    }
        else if(num_of_wrong_guesses==7){
                
                            cout << "  +----+" <<endl;
                            cout << "  |    |" <<endl;
                            cout << "  |    O" <<endl;
                            cout << "  |   /|\\" <<endl;
                            cout << "  |  / | \\" <<endl;
                            cout << "  |   / \\" <<endl;
                            cout << "  |  /   \\" <<endl;
                            cout << "  |" <<endl;
                            cout << "  +=========" <<endl;
       
                    }
        else{
                
            }
        }
        else{
            cout<<"You found a letter.\n\n";
        }
        
        
        cout<<"You have "<<max_tries-num_of_wrong_guesses<<" guesses left.";
        
        if(word==unknown){
            cout<<word<<endl;
            cout<<"Congratulations! You found the word.";
            break; 
            
        }
    }
    
    if(num_of_wrong_guesses==max_tries){
        cout<<"\nSorry! You've lost."<<endl;
        cout<<"The word was: "<<word<<endl;
    }
    
    
    cin.get(); cin.get();
    return 0;
}

int letterFill(char guess, string secretword, string &guessword)
{

    int i;
    int matches = 0;
    int len=secretword.length();
    for(i=0; i<len; i++){
        if(guess==guessword[i])
            return 0;
        if(guess==secretword[i]){ 
            guessword[i]=guess;
            matches++;
        }
    }
    
    return matches;
}
