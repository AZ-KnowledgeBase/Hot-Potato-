// Name: Abisheik Buwanekabahu| G number: G21328022
#include <iostream>
#include <vector>
using namespace std;

// Constants
const float smallSizeCost = 5.0;				// Costs for potato size
const float mediumSizeCost = 8.50;					
const float largeSizeCost = 10.25;					

const float cheeseCost = 1.00;					// Costs for toppings
const float butterCost = 0.40;					
const float garlicButterCost = 0.50;				
const float beansCost = 0.75;					
const float currySauceCost = 1.20;				
const float mushroomsCost = 0.80;				
const float onionCost = 0.40;					
const float extraCheeseCost = 1.50;				

const float saladCost = 1.50;					// Cost for extras 
const float hotDog = 4.00;					
const float fizzyDrinkCost = 0.50;				
const float waterCost = 0.80;					
const float teaCost = 1.00;					
const float coffeeCost = 1.20;					

const float valueRange = 100;					// Value range to discard in input stream
const float resetTotalCost = 0;					// Value that resets the totCost when order is reset or a new order is made

// Function prototypes
void menu(float &credits, float &totCost);			// Display and choose main menu options
void get_Credits(float &credits, float &totCost);		// Enter and Display total credits
void calculate_Bill(float &credits, float &totCost);		// Calculate and display bill	
void new_Order(float &credits, float &totCost);			// Asks if user wants to place a new order
void potatoSize_Display(float &credits, float &totCost);	// Display potato size menu
void choose_PotatoSize(float &credits, float &totCost);		// Take potato size choice
void toppin_Display(float &credits, float &totCost);		// Display toppings menu
void choose_Toppin(float &credits, float &totCost);		// Choose topping 
void another_Toppin(float &credits, float &totCost);		// Ask user if they want additional topping
void extra_Question(float &credits, float &totCost);		// Ask user if they want extra
void extra_Display(float &credits, float &totCost);		// Display extra menu
void choose_Extra(float &credits, float &totCost);		// Choose extra

int main()
{
	float credits = 0;					// Stores total credits user enters
	float totCost = 0;					// Tracks total cost of the order
	menu(credits,totCost);					
}

void menu(float &credits, float &totCost)
{
	int menuChoice = 0; 					// Stores menu option		
	cout<<"-------------------"<<endl;
	cout<<"Hot Potato"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"===========Main menu=========="<<endl;
	cout<<"1. Add Credits"<<"("<<credits<<")"<<endl;
	cout<<"2. New Order"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Choose your desired option: "<<endl;
	cin>>menuChoice;
	cout<<endl;
	
	if (cin.fail()) 					// Checks if the input is of invalid data type
	{
		cout<<"**Error: Please enter numbers only**\n"<<endl;
		cin.clear();					// Resets input stream's internal error flags
		cin.ignore(valueRange, '\n');			// Discards invalid inputs from range of 100 till a newline
		menu(credits,totCost);
	}
	else
	{
		switch(menuChoice)
		{
			case 1:
				get_Credits(credits,totCost);	
				break;
			case 2:
				potatoSize_Display(credits,totCost);	
				break;
			case 3:
				cout<<"Thank you for ordering at HotPotato!"<<endl;
				break;
			default:
				cout<<"**Please select one of the numbered options**\n"<<endl;
				menu(credits,totCost);		
		}
	}
}

void get_Credits(float &credits, float &totCost)
{
	float newCredits;
	cout<<"----------------------------------------------------\n";
	cout<<"Enter the desired number of credits for your order: \n";
	cin>>newCredits;
	
	if (cin.fail()) 					
	{
		cout<<"**Error: Please enter numbers only**"<<endl;
		cout<<"----------------------------------------------------\n";
		cin.clear();					
		cin.ignore(valueRange, '\n');			
		cout<<endl;					
		get_Credits(credits,totCost);			 
	}
	else if (newCredits > 0)
	{
		credits += newCredits;				
		cout<<"Your total number of credits : "<<credits<<endl;
		cout<<"----------------------------------------------------\n";
		cout<<endl;					
		menu(credits,totCost);				
			
	}
	else
	{
		cout<<"**Please enter a appropiate number**"<<endl;
		cout<<"----------------------------------------------------\n";
		cout<<endl; 					 
		get_Credits(credits,totCost); 			
	}
	
}

void calculate_Bill(float &credits, float &totCost)
{
	float addCredits = 0;
	if (totCost < credits)					
	{
	cout<<"===================\nTotal Credits     : \t"<<credits<<"\n==================="<<endl;
	cout<<"===================\nTotal Cost        : \t"<<totCost<<"\n==================="<<endl;
	credits -= totCost;
	cout<<"===================\nRemaining Balance : \t"<<credits<<"\n==================="<<endl;
	cout<<endl;
	new_Order(credits,totCost);				
	}
	else		
	{
	cout<<"-----------------------------------------\n";
	cout<<"Your Credits amount of "<<credits<<" is insufficient.";
	cout<<"\nPlease add more credits: "<<endl;
	cin>>addCredits;
	credits += addCredits;
	cout<<"\n-----------------------------------------\n"<<endl;
	cout<<endl;						 
	
	calculate_Bill(credits,totCost);			
	}
}	

void new_Order(float &credits, float &totCost)
{
	char orderAnswer; 							
	cout<<"Would you like to put in a new order? Please enter 'Y' if yes and 'N' for no"<<endl;
	cin>>orderAnswer;
	cout<<endl;
	
	if (orderAnswer == 'Y' || orderAnswer == 'y')
	{
		totCost = 0;					// Resets totCost for the new order	
		menu(credits,totCost);				
	}
	else if (orderAnswer == 'N' || orderAnswer == 'n')
	{
		cout<<"\nThank you for ordering at HotPotato!\n"<<endl;					
	}
	else
	{
		cout<<"**Please enter one of the 2 appropiate answers above**\n"<<endl;				 
		new_Order(credits,totCost);			
	}
}


void potatoSize_Display(float &credits, float &totCost)
{
	cout<<"------------------------------\n|Potatoe Size\n------------------------------"<<endl;
	cout<<"1. Small\t[5.00 credits]\n2. Medium\t[8.50 credits]\n3. Large\t[10.25 credits]\n";
	cout<<"4. Return to Main menu\n";
	choose_PotatoSize(credits,totCost);				
}

void choose_PotatoSize(float &credits, float &totCost)
{
	int orderChoice; 					// Stores the potato size option
	float potatoSizeCost = 0;
	cout<<"Choose your Selection: "<<endl;
	cin>>orderChoice;
	cout<<endl;						 
	
	if (cin.fail()) 					
	{
		cout<<"**Error: Please enter numbers only**\n"<<endl;					 
		cin.clear();					
		cin.ignore(valueRange, '\n');			
		potatoSize_Display(credits,totCost);			
	}
	else
	{
		switch(orderChoice)
		{
			case 1: 
				potatoSizeCost = smallSizeCost;
				totCost += potatoSizeCost;
				toppin_Display(credits,totCost);		
				break;
			case 2: 
				potatoSizeCost = mediumSizeCost;
				totCost += potatoSizeCost;
				toppin_Display(credits,totCost);		
				break;
			case 3: 
				potatoSizeCost = largeSizeCost;
				totCost += potatoSizeCost;
				toppin_Display(credits,totCost);		
				break;
			case 4:
				totCost = resetTotalCost;
				menu(credits, totCost);		
				break;
			default:
				cout<<"**Please select one of the numbered options**\n"<<endl;			 
				potatoSize_Display(credits,totCost);	
		}
	}
}

void toppin_Display(float &credits, float &totCost)
{
	cout<<"------------------------------\nToppings\n------------------------------\n";
	cout<<"1. Cheese\t[1.00 credits]\n2. Extra Cheese\t[0.40 credits]\n3. Butter\t[0.40 credits]\n";
	cout<<"4. Garlic Butter[0.50 credits]\n5. Curry Sauce\t[1.20 credits]\n6. Mushrooms\t[0.80 credits]\n";
	cout<<"7. Onions\t[0.40 credits]\n8. Beans\t[0.75 credits]\n9. Return to menu\n";
	choose_Toppin(credits,totCost);				
}

void choose_Toppin(float &credits, float &totCost)
{
	int toppinChoice; 					// User's topping choice 
	float toppinCost = 0;	
	cout<<"Choose your selection:"<<endl;
	cin>>toppinChoice;
	cout<<endl;						 
	
	if (cin.fail()) 					
	{
		cout<<"**Error: Please enter numbers only**\n"<<endl;
		cin.clear();					
		cin.ignore(valueRange, '\n');							 
		toppin_Display(credits,totCost);		
	}
	else
	{
		switch (toppinChoice)
		{
			case 1:
				toppinCost = cheeseCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 2:
				toppinCost = butterCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 3:
				toppinCost = garlicButterCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 4:
				toppinCost = beansCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 5:
				toppinCost = currySauceCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 6:
				toppinCost = mushroomsCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 7:
				toppinCost = onionCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 8:
				toppinCost = extraCheeseCost;
				totCost += toppinCost;
				another_Toppin(credits,totCost);		
				break;
			case 9:
				totCost = resetTotalCost;
				menu(credits,totCost);		
				break;
			default:
				cout<<"**Please select one of the numbered options**\n"<<endl;		 
				toppin_Display(credits,totCost);
		}
	}
}

void another_Toppin(float &credits, float &totCost)
{	
	char toppinAnswer; 					// User's answer if they want more toppings
	cout<<"---------------------------------\n";
	cout<<"Would you like a another Topping?\n";
	cout<<"Enter 'Y' for yes and 'N' for no\n";
	cout<<"---------------------------------\n";
	cin>>toppinAnswer;
	
	if (toppinAnswer == 'Y' || toppinAnswer == 'y')
	{
		toppin_Display(credits,totCost);		
	}
	else if (toppinAnswer == 'N' || toppinAnswer =='n')
	{
		cout<<endl;
		extra_Question(credits,totCost);		// Proceed to if user wants extras
	}
	else
	{
		cout<<"\n**Please enter one of the given values above**\n"<<endl;				 
		another_Toppin(credits,totCost);		// Re-enter answer if invalid input
	}
	
}

void extra_Question(float &credits, float &totCost)
{
	char extraAnswer; 					// User's answer if they want extras
	cout<<"-------------------------------------\n";
	cout<<"Would You like order any extra items?\n";
	cout<<"Enter 'Y' for yes and 'N' for no";
	cout<<"\n-------------------------------------\n";
	cin>>extraAnswer;
	
	if (extraAnswer == 'Y'||extraAnswer == 'y' )
	{
		extra_Display(credits,totCost);			// Proceed to extras menu
	}
	else if (extraAnswer == 'N'||extraAnswer == 'n')
	{
		cout<<"[Extra items will not be included in your order]\n";
		float noextraCost = 0;				// stores 0 if user doesn't want extras
		totCost += noextraCost;				
		cout<<endl;					 
		calculate_Bill(credits,totCost);		
	}
	else 
	{
		cout<<"\n**Please enter one of the given values above**\n"<<endl;					 
		extra_Question(credits,totCost);		
	}
}

void extra_Display(float &credits, float &totCost)
{
	cout<<"------------------------------\nExtra Additions\n------------------------------\n";
	cout<<"1. Salad Box\t[1.50 credits]\n2. Hot Dog\t[4.00 credits]\n3. Fizzy Drink\t[0.50 credits]\n";
	cout<<"4. Water Bottle [0.80 credits]\n5. tea\t\t[1.00 credits]\n6. Coffee\t[1.20 credits]\n";
	cout<<"7. Return to menu\n";
	choose_Extra(credits,totCost);				
}

void choose_Extra(float &credits, float &totCost)
{			
	float extraCost = 0;					
	int extraChoice = 0;					// User's extra choice
	cout<<"Choose your Selection: "<<endl;
	cin>>extraChoice;
	cout<<endl;
		
	if (cin.fail()) 					
	{
		cout<<"**Error: Please enter numbers only**\n"<<endl;
		cin.clear();					
		cin.ignore(valueRange, '\n');			
		extra_Display(credits,totCost);			
	}
	else
	{	
		switch (extraChoice)			
		{
			case 1:
				extraCost = saladCost;
				totCost += extraCost;
				calculate_Bill(credits,totCost);		
				break;
			case 2:
				extraCost = hotDog;
				totCost += extraCost;
				calculate_Bill(credits,totCost);		
				break;
			case 3:
				extraCost = fizzyDrinkCost;
				totCost += extraCost;
				calculate_Bill(credits,totCost);		
				break;
			case 4:
				extraCost = waterCost;
				totCost += extraCost;
				calculate_Bill(credits,totCost);		
				break;
			case 5:
				extraCost = teaCost;
				totCost += extraCost;
				calculate_Bill(credits,totCost);		
				break;
			case 6:
				extraCost = coffeeCost;
				totCost += extraCost;
				calculate_Bill(credits,totCost);		
				break;
			case 7:
				totCost = resetTotalCost;
				menu(credits,totCost);		
				break;
			default:
				cout<<"**Please select one of the numbered options**\n"<<endl;		 
				extra_Display(credits,totCost);	
		}
	}
}
