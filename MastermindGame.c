//include libarys
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Global variables/arrays to be used across all functions.
int MenuChoice, Attempt, Secret[4], Guess[4], Match[4]={0,0,0,0}, code=0, g=0, b=0, w=0, W=0, Win=0, Max=0, r=0;


//Global Functions declared to be used across all functions.  
int Menu();

void EasyMode(), OptionsMenuFunc(), MediumMode(), HardMode(), RandomGenEasy(), RandomGenMedium(), RandomGenHard();


main()////Start of the Main Function////
{
	//Start of a do/while loop where the user chooses from a list of options
	do
	{	//Start of a switch statement//Printing out the menu function
		//the user chooses modes or if they want help or to quit.
		//each cace calls the approiate function
		switch (MenuChoice = Menu())
		{
			case 1:
					{
						EasyMode();
						break;
					}
			case 2:
					{
						MediumMode();
						break;
					}
			case 3:
					{	
						HardMode();
						break;
					}
			case 4:
					{	
						OptionsMenuFunc();
						break;
					}
			case 5:
			default:
					{
						printf("\n\tGoodbye\a");
						fflush(stdin);
						break;
					}
		}
	}
	while(MenuChoice !=5);
}//End of Main function


void RandomGenMedium()//Start of the medium mode random gen function 
{
	//This Random Generator for Medium
	//the for loop makes code in it populate the secret array with 4 numbers out of 7 numbers(1-7)
	srand(time(NULL));
	
	for(code=0; code<4; code++)
	{
		Secret[code] = 1 + rand() %7;
		printf("\nAnswer %d \n", Secret[code]);
	}
}

void RandomGenHard()//Start of the random func for the hard mode
{
	//This random generator for hard
	//the for loop makes code in it populate the secret array with 4 numbers out of 8 numbers(0-7)
	//0 is for blank spaces
	srand(time(NULL));
	
	for(code=0; code<4; code++)
	{
		Secret[code] = rand() %7;
		printf("\nAnswer %d \n", Secret[code]);
	}
}

int Menu()//Start of the Menu Func
{
	// do/while loop that prints out the list of choices until a user picks one
	do
	{
		printf("\n\tWelcome to Mastermind.\n");
		printf("\n");
		printf("\nPress 1 to Challenge in easy mode.");
		printf("\nPress 2 to Challenge in medium mode.");
		printf("\nPress 3 to Challenge in hard mode.");
		printf("\nPress 4 to for help.");
		printf("\nPress 5 to exit");
		printf("\n");
		printf("\nWhat say you: ");
		fflush(stdin);
		
		scanf_s("%d", &MenuChoice);
	}
	while((MenuChoice<1)||(MenuChoice >5));
	
	return(MenuChoice);
}//End of Menu Function

void EasyMode()//Easy mode function
{
		//the system prints out a line asking the user how many goes they want
		//user puts in how many
		printf("\n\nEnter the amount of attempts you would like to have (Max 15): ");
		fflush(stdin);
		
		scanf("%d", &Max);
			
		//checks if the user entered a bad input
		if((Max<=0) || (Max>=16))
		{
			// do/while then repeats the process until its satisfied
			do
			{
				printf("\n\nEnter the amount of attempts you would like to have (Max 15): ");
				fflush(stdin);
				
				scanf("%d", &Max);
			}
			while((Max<=0) || (Max>=16));
		}
		
		else
		{//RandomGenEasy();

		//random generator code
		srand(time(NULL));
		
		for(code=0; code<4; code++)
		{
			Secret[code] = 1 + rand() %7;
			printf("\nAnswer %d \n", Secret[code]);	
		}

			//For loop for the number of attemps allowed
			for(Attempt=1; Attempt<=Max; Attempt++)
			{   
				printf("\nColours: 1 (Red) 2 (Orange) 3 (Yellow) 4 (Green) 5 (Blue) 6 (Indigo) 7 (Violet) ");
				printf("\n");
				printf("\nPlease enter one number at a time");
				printf("\n");
				printf("\nAttempt %d : \n",Attempt);
				
				for(g=0; g<4; g++)
				{	
					scanf("\n %d", &Guess[g]);
				}
			
				for(b=0; b<4; b++)
				{	
					//checks if the number in guess[] is the same as the number in the same location of the secret[]
					//and if it is it prints a black peg
					//it also sets the value to 1(true) in the Match array for each number that is right.
					if(Guess[b] == Secret[b])
					{
						printf("*");
						Match[b]=1;
					}
					
					else
					{
						for(W=0; W<4; W++)
						{
							
							if((Guess[b] == Secret[W]) && (b!=W))
							{ 
								//checks if the number in guess[] is the same as the number in the same location of the secret[]
								//and if it isnt it prints a white peg
								//it checks if the number in the Match[] is the same number as the one in the same location in the Secret[]
								//if it is it prints a white peg.

								if(Match[W]==0)
								{
			 						printf("o");
									
								}
							}	
						}	
					}
				}
				
				//checks to see if all the numbers of the secret code are the same as the ones the user put in if so you win
				if(Secret[0]==Guess[0] && Secret[1]==Guess[1] && Secret[2]==Guess[2] && Secret[3]==Guess[3])
				{
					printf("\n");
					printf("\nCongratulations you won the code was: %d,%d,%d,%d ", Secret[0], Secret[1], Secret[2], Secret[3]);
					printf("\n");
					system("pause");
					break;
				}	
				
				//checks to see if the user has met the limit of tries if so you lose
				if(Attempt==Max)
				{
					printf("\n");
					printf("\n Unfortunately you did not guess the code: %d,%d,%d,%d ", Secret[0], Secret[1], Secret[2], Secret[3]);
					printf("\n");
					system("pause");
					break;
				}
			}//End Attempt for loop
		}
}

void MediumMode()//Medium mode function
{
		printf("\n\nEnter the amount of attempts you would like to have (Max 15): ");
		scanf("%d", &Max);
		
		if((Max<=0) || (Max>=16))
		{
			do
			{
				printf("\n\nEnter the amount of attempts you would like to have (Max 15): ");
				scanf("%d", &Max);
			}
			while((Max<=0) || (Max>=16));
		}
		
		//calls the Random gen function for medium
		RandomGenMedium();

		//For loop for the number of attemps allowed
		for(Attempt=1; Attempt<=Max; Attempt++)
		{   
			printf("\nColours: 1 (Red) 2 (Orange) 3 (Yellow) 4 (Green) 5 (Blue) 6 (Indigo) 7 (Violet) ");
			printf("\n");
			printf("\nPlease enter one number at a time");
			printf("\n");
			printf("\nAttempt %d : \n",Attempt);
			
			//for loop for user guesses
			for(g=0; g<4; g++)
			{
				scanf("\n %d", &Guess[g]);
			}
			
			for(b=0; b<4; b++)
			{	
				//checks if the number in guess[] is the same as the number in the same location of the secret[]
				//and if it is it prints a black peg
				//it also sets the value to 1(true) in the Match array for each number that is right.
				if(Guess[b] == Secret[b])
				{
					printf("*");
					Match[b]=1;
				}
				
				else
				{
					for(W=0; W<4; W++)
					{
						if((Guess[b] == Secret[W]) && (b!=W))
						{ 
							//checks if the number in guess[] is the same as the number in the same location of the secret[]
							//and if it isnt it prints a white peg
							//it checks if the number in the Match[] is the same number as the one in the same location in the Secret[]
							//if it is it prints a white peg.
							if(Match[W]==0)
							{
			 					printf("o");
							}
						}	
					}	
				}
			}
			// checks if user has won
			if(Secret[0]==Guess[0] && Secret[1]==Guess[1] && Secret[2]==Guess[2] && Secret[3]==Guess[3])
			{
				printf("\n");
				printf("\nCongratulations you won the code was: %d,%d,%d,%d ", Secret[0], Secret[1], Secret[2], Secret[3]);
				printf("\n");
				system("pause");
				break;
			}	
			//checks if user has lost
			if(Attempt>=Max)
			{
				printf("\n");
				printf("\n Unfortunately you did not guess the code: %d,%d,%d,%d ", Secret[0], Secret[1], Secret[2], Secret[3]);
				printf("\n");
				system("pause");
				break;
			}
		}//End Attempt for loop					
}

void HardMode()//Hard mode func
{
		printf("\n\nEnter the amount of attempts you would like to have (Max 15): ");
		scanf("%d", &Max);
		
		if((Max<=0) || (Max>=16))
		{
			do
			{
				printf("\n\nEnter the amount of attempts you would like to have (Max 15): ");
				scanf("%d", &Max);
			}
			while((Max<=0) || (Max>=16));
		}

		RandomGenHard();//calls hard mode rand function

		//For loop for the number of attemps allowed
		for(Attempt=1; Attempt<=Max; Attempt++)
		{   
			printf("\nColours: 1 (Red) 2 (Orange) 3 (Yellow) 4 (Green) 5 (Blue) 6 (Indigo) 7 (Violet) ");
			printf("\nBlanks: 0 (Blank) ");
			printf("\n");
			printf("\nPlease enter one number at a time");
			printf("\n");
			printf("\nAttempt %d : \n",Attempt);
			fflush(stdin);

			for(g=0; g<4; g++)
			{
				scanf("\n %d", &Guess[g]);
			}
			
			for(b=0; b<4; b++)
			{	
				//checks if the number in guess[] is the same as the number in the same location of the secret[]
				//and if it is it prints a black peg
				//it also sets the value to 1(true) in the Match array for each number that is right.
				if(Guess[b] == Secret[b])
				{
					printf("*");
					Match[b]=1;
				}
				
				else
				{
					for(W=0; W<4; W++)
					{
						if((Guess[b] == Secret[W]) && (b!=W))
						{ 
							//checks if the number in guess[] is the same as the number in the same location of the secret[]
							//and if it isnt it prints a white peg
							//it checks if the number in the Match[] is the same number as the one in the same location in the Secret[]
							//if it is it prints a white peg.
							//and it resets the match array back to 0.
							if(Match[W]==0)
							{
			 					printf("o");
							}
						}	
					}	
				}
			}
			
			if(Secret[0]==Guess[0] && Secret[1]==Guess[1] && Secret[2]==Guess[2] && Secret[3]==Guess[3])
			{
				printf("\n");
				printf("\nCongratulations you won the code was: %d,%d,%d,%d ", Secret[0], Secret[1], Secret[2], Secret[3]);
				printf("\n");
				system("pause");
				break;
			}	
				
			if(Attempt>=Max)
			{
				printf("\n");
				printf("\n Unfortunately you did not guess the code: %d,%d,%d,%d ", Secret[0], Secret[1], Secret[2], Secret[3]);
				printf("\n");
				system("pause");
				break;
			}
		}//End Attempt for loop					
}

//This is the options Menu which is used to explain how the game works
void OptionsMenuFunc()
{    
      printf("\n");
	  printf("The goal of Mastermind is to guess the secret code picked by the Mastermind.\n");
	  printf("\n");
      printf("The seceret code is made up of 4 random colours(numbers),\n");
	  printf("from the 7 colours of the rainbow.\n");
      printf("You are allowed up to 15 attempts at guessing the code.\n");      
      printf("Every '*' you see means you have choosen,\n");
	  printf("one colour correctly and its the right place.\n");
      printf("Every 'o' you see means that you have,\n");
	  printf("one colour correct but in the wrong place.\n");
      printf("\n");
	  printf("\t\nCan you beat the Mastermind!!!\n");
	  printf("\n");
	  fflush(stdin);
	  system("pause");
}
