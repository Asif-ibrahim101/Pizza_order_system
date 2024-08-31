#include <iostream>
using namespace std;

void Main_Menu();

// dividers for the UI
void Dividers()
{
    string line = "-";

    for (int i = 0; i <= 50; i++)
    {
        cout << line;
    };

    cout << endl;
};

float Toppings(float& Credits) {
    int Numbering = 1;
    int Choose;
    
    string toppings[6] = {"Ham", "Mushroom", "Pepperoni", "Peppers", "Onion", "Extra Cheese"};  // Fixed typo
    float Topping_price[6] = {0.80, 0.50, 1.0, 0.80, 0.40, 1.50};
    
    // Display toppings menu
    for (int i = 0; i < 6; i++) {
        cout << Numbering++ << ". " << toppings[i] << " [" << Topping_price[i] << "]" << endl;
    }
    cout << "0. Return to Main Menu" << endl;
    
    // User input
    cout << "Please choose from the above toppings: ";
    cin >> Choose;
    
    // Validate input
    if (Choose >= 1 && Choose <= 6) {  // Check if options are between 1 and 6
       float Current_price = Credits + Topping_price[Choose - 1];
        cout << "You have addad " << toppings[Choose - 1] << "to your pizza. Your Current price is [" << Current_price << "]";  // Display selected topping
        
        Credits -= Topping_price[Choose - 1];  // Deduct price from credits
        
        cout << "Remaining Credits: " << Credits<< endl;  // Display remaining credits
    } else if (Choose == 0) {
        Main_Menu();  // Call Main_Menu function
    } else {
        cout << "Please select a valid option." << endl;  // Handle invalid input
    }
};

//Orderding the pizza
void OrderPizza(float &credit) {
    int options;
    
   const string pizzaSizes[3] = {"Small", "Medium", "Large"};  // Array for pizza sizes
    const float pizzaPrices[3] = {5.0, 8.50, 10.25};  // Array for pizza prices

    // Display menu
    cout << "Order Pizza - Select Size [Current Credits: " << credit << "]" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << pizzaSizes[i] << " [" << pizzaPrices[i] << " credit]" << endl;
    }
    cout << "4. Return to main menu" << endl;
    
    cout << "Pleas choose from the following options: " << endl;
    cin >> options;
    
      if (options >= 1 && options <= 3) {  // Check if options are 1, 2, or 3
        cout << "You have selected a " << pizzaSizes[options - 1] << " Pizza" << endl;  // Display selected size
        float remaining_credits = credit - pizzaPrices[options - 1];  // Calculate remaining credits
        Toppings(remaining_credits);  // Call Toppings function with remaining credits
    } else if (options == 4) {
        Main_Menu();  // Call Main_Menu function
    } else {
        cout << "Please select one of the following options." << endl;  // Handle invalid input
    }
};

// Main Menu
void Main_Menu()
{
    int Choose;
    cout << "Main Menu" << endl;
    cout << "1.Order Pizza [Current Balance: 0.0]" << endl;
    cout << "2.Exit" << endl;

    cout << "Please Choose a option: ";
    cin >> Choose;

    if (Choose == 1)
    {
         // adding credits
    float Current_balance;

    cout << "How much credits do you want to add: ";
    cin >> Current_balance;
        OrderPizza(Current_balance);
    }
    else if (Choose == 2)
    {
        exit;
    }
    else
    {
        cout << "Please choose one of the above options";
    };
}

int main()
{
    // intro
    Dividers();
    cout << "UClan PIZZA" << endl;
    Dividers();

    // Main Menu
    Main_Menu();
};