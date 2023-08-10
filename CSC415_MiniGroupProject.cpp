/*
Course Code: CSC415
Company Name: Arau Airline
Author: Muhammad Ammar, Muhammad Muaz, Nur Azmatun
Group: RCS2401A
Objective: Mini Group Project
*/

#include <iostream>
#include <string.h>
using namespace std;

// function prototype
void displayMenu ();
void displayMenu2 ();
void displayMealsSet();
void calculatePrice (int, int, int, float&);
void calculateTax (float, float&);
void calculateBag (int, float&, float);
void calcMealsSet(int, float&);

// main function
int main () {
	
	displayMenu ();
	displayMenu2 ();
	displayMealsSet();
	
	// declaration and initialisation
	float price, totalPayment=0, bag, priceMeals, priceBag=0, priceTax, totalAll;
	bool proceed;
	char ic[13], name[50], contactNumber[12];
	int destination, way, type, meals;
	
	do {
		
		//reset priceBag to 0
		priceBag = 0;
		
		// input
		cout << "Please enter your name: ";
		cin.get (name, 50);
		cin.ignore(50, '\n');
		
		cout << "Please enter your IC number (Without '-'): ";
		cin.get (ic, 13);
		cin.ignore(13, '\n');
		
		cout << "Please enter your contact number (Without '-'): ";
		cin.get (contactNumber, 12);
		cin.ignore(12, '\n');
		
		cout << "Please enter destination (1 - 7): ";
		cin >> destination;	
		
		cout << "One Way or Two Way? (1 - One Way / 2 - Two Way): ";
		cin >> way;
		
		cout << "Economy Class or Business Class? (1 - Economy / 2 - Business ): ";
		cin >> type;
		
		cout << "Total baggage capacity (in KG): ";
		cin >> bag;	
		
		cout << "Please choose meals set (1 - 4): ";
		cin >> meals;						

		cout << endl;

		// function call for calculation
		calculatePrice (destination, way, type, price);
		calculateBag (type, priceBag, bag);
		calcMealsSet (meals,priceMeals);
		calculateTax (price,priceTax);
		
		// calculation total for 1 person
		totalPayment = price + priceBag + priceMeals + priceTax;
		
		// receipt - display back all input for 1 person
	    cout << "-------------------------------------------------------------------" << endl;
	    cout << "                           ARAU AIRLINE                            " << endl;
	    cout << "                             RECEIPT                               " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "  NAME             | " << name                                       << endl;
        cout << "  IC NO.           | " << ic                                         << endl;
        cout << "  CONTACT NO.      | " << contactNumber                              << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "  TICKET TYPE      | " << type                                       << endl;
        cout << "  WAY              | " << way                                        << endl;
        cout << "  TICKET  PRICE    | RM" << price                                    << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "  MEAL SET         | SET " << meals                                  << endl;
        cout << "  MEAL PRICE       | RM" << priceMeals                               << endl;
        cout << "  BAGGAGE CAPACITY | " << bag << " KG "                              << endl;
        cout << "  BAGGAGE FEE      | RM" << priceBag                                 << endl;
        cout << "  TAX              | RM" << priceTax                                 << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "  TOTAL PAYMENT    | RM" << totalPayment                             << endl;
        cout << "-------------------------------------------------------------------" << endl;
		
		// calculation total for all person / customer / passenger 
		totalAll = totalAll + totalPayment;
		
		// prompt to continue or not
		cout << "\nDo you want to continue? (1 - yes / 0 - no): ";
		cin >> proceed;
		
		cin.ignore(13, '\n');
		
		cout << endl;
		
	} while (proceed == true);
	
	// display total payment for all person / customer / passenger 
    cout << "-------------------------------------------------------------------" << endl;
    cout << "                           ARAU AIRLINE                            " << endl;
    cout << "                           FINAL RECEIPT                           " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "  TOTAL PAYMENT  | RM" << totalAll                                   << endl;
    cout << "-------------------------------------------------------------------" << endl;
	
	return 0;
}

// function definition - calculate meals
void calcMealsSet (int meals, float& priceMeals) {
	if (meals == 1) {
		priceMeals = 20;
	}
	else if (meals == 2) {
		priceMeals = 20;
	}
	else if (meals == 3) {
		priceMeals = 30;
	}
	else if (meals == 4) {
		priceMeals = 10;
	}
	else {
		priceMeals = 0;
	}
}

//function definition - calculate tax and charges
void calculateTax (float price, float& priceTax) {
	
	//add passenger service charge RM11 + add service tax 6%
	priceTax = (price*0.06) + 11;
}

//function definition - calculate baggage charge
void calculateBag (int type, float& priceBag, float bag) {
	float extra;
	
	//for economy class limited to 7KG
	if ((type == 1) && (bag > 7)) {
		extra = bag - 7;
		priceBag = extra * 10;
	}
	
	//for business class limited to 14KG
	else if ((type == 2) && (bag > 14)) {
		extra = bag - 14;
		priceBag = extra * 10;
	} 
}

// function definition - calculate price 
void calculatePrice (int destination, int way, int type, float& price){
	
	if (destination == 1) { // Alor Setar
		
		if (way == 1){ // One way
	        
			if (type == 1){ //Economy
				price = 34; 
			}
	        
			else if (type == 2) { //Business 
				price = 48;
			}
		    
			else { //Wrong input for flight class
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else if (way == 2){ //Two Way
	        
			if (type == 1){ //Economy
				price = 61; 
			}
	         
			else if (type == 2) { //Business
				price = 86;
			}
		    
			else { //Wrong input for flight class
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
			
		else { //Wrong input for one way or two way trip
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
	else if (destination == 2){ //Penang
        if (way == 1){
	        
			if (type == 1){ 
				price = 54; 
			}
	        
			else if (type == 2) {
				price = 76;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else if (way == 2){ 
		    
			if (type == 1){
				price = 98; 
			}
	        
			else if (type == 2) { 
				price = 138;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
			
		else {
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
	else if (destination == 3) { //Terengganu
	
        if (way == 1){
	        
			if (type == 1){ 
				price = 74; 
			}
	        
			else if (type == 2) {
				price = 104;
			}
			
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else if (way == 2){ 
	        
			if (type == 1){
				price = 133; 
			}
	         
			else if (type == 2) { 
				price = 186;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}

		else {
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
    else if (destination == 4) { //Kota Bharu
    
        if (way == 1){
	        
			if (type == 1){ 
				price = 64; 
			}
	         
			else if (type == 2) {
				price = 90;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else if (way == 2){ 
	        
			if (type == 1){
				price = 115; 
			}
	        
			else if (type == 2) { 
				price = 161;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else {
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
	else if (destination == 5) { // Langkawi
        
        if (way == 1){
	       
			if (type == 1){ 
				price = 84; 
			}
	       
			else if (type == 2) {
				price = 118;
			}
		
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else if (way == 2){ 
	        
			if (type == 1){
				price = 136; 
			}
	        
			else if (type == 2) { 
				price = 151;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
			
		else {
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
	
	else if (destination == 6) { // Sandakan
    	
        if (way == 1) {
	        
			if (type == 1){ 
				price = 134; 
			}
	        
			else if (type == 2) {
				price = 188;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
		
		else if (way == 2){ 
	        
			if (type == 1){
				price = 241; 
			}
	         
			else if (type == 2) { 
				price = 337;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
			
		else {
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
	
	else if (destination == 7) { //Kuching
		
	   if (way == 1){
	        
			if (type == 1){ 
				price = 164; 
			}
	         
			else if (type == 2) {
				price = 230;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
	
		else if (way == 2){ 
		        
			if (type == 1){
				price = 414; 
			}
	         
			else if (type == 2) { 
				price = 580;
			}
		    
			else {
			cout << "Error. Please enter correct type of flight class." << endl;
			}
		}
	
		else {
		cout << "Error. Please enter correct trip type." << endl;
		}
	}
	
	//wrong input for destination
	else {
		cout << "Error. Please enter correct destination." << endl;
	}

}

// function definition - display menu (destination and ticket price)
void displayMenu (){
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|                           ARAU AIRLINE                            |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|    DESTINATION   |        ONE WAY         |        TWO WAY        |" << endl;
	cout << "|       FROM       -------------------------------------------------|" << endl;
	cout << "|       KLIA       |  ECONOMY  |  BUSINESS  |  ECONOMY |  BUSINESS  |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "| 1 - ALOR SETAR   |    34.00  |   48.00    |   61.00  |   86.00    |" << endl;
	cout << "| 2 - PENANG       |    54.00  |   76.00    |   98.00  |  138.00    |" << endl;
	cout << "| 3 - TERENGGANU   |    74.00  |  104.00    |  133.00  |  186.00    |" << endl;
	cout << "| 4 - KOTA BHARU   |    64.00  |   90.00    |  115.00  |  161.00    |" << endl;
	cout << "| 5 - LANGKAWI     |    84.00  |  118.00    |  136.00  |  151.00    |" << endl; 
	cout << "| 6 - SANDAKAN     |   134.00  |  188.00    |  241.00  |  337.00    |" << endl;
	cout << "| 7 - KUCHING      |   164.00  |  230.00    |  414.00  |  580.00    |" << endl;	
	cout << "|-------------------------------------------------------------------|" << endl << endl;
}

// function definition - display menu (Additional Infomation)
void displayMenu2 (){
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "| Standard (Economy) Baggage Capacity = 7 KG                        |" << endl;
	cout << "| Premium (Business) Baggage Capacity = 14 KG                       |" << endl;
	cout << "| Additional Baggage Capacity         = RM 10.00 / KG               |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "| Airport Tax                         = RM 11.00                    |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "| Service Tax & Insurance (Flight     = 6% of the net ticket price  |" << endl,
	cout << "| Delay, Trip Cancellation, Lost,                                   |" << endl;
	cout << "| Damaged or Stolen Luggage)                                        |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl << endl;

}

// function definition - display meals set
void displayMealsSet () {
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|                             MEALS SET                             |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|   SET 1  | NASI LEMAK WITH BOILED EGG AND MINERAL WATER  |  RM20  |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|   SET 2  | TUNA SANDWICH AND TEH TARIK                   |  RM20  |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|   SET 3  | CHICKEN RENDANG WITH WHITE RICE AND TEH O     |  RM30  |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|   SET 4  | CHICKEN MUSHROOM SOUP AND 100 PLUS            |  RM10  |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << "|       Input '0' if you're not interested in any set of meals.     |" << endl;
	cout << "|-------------------------------------------------------------------|" << endl;
	cout << endl;
}
