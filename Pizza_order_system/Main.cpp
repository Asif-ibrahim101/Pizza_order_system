#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Function declarations
void mainMenu();
void drawDivider();
void orderPizzas(float& currentCredits);
void chooseTopping(float& currentCredits, vector<string>& pizzaToppings, float& pizzaPrice);

// Function to draw a line divider for the UI
void drawDivider() {
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
}

// Function to display the toppings menu and handle a single topping choice
void chooseTopping(float& currentCredits, vector<string>& pizzaToppings, float& pizzaPrice) {
    const string toppings[6] = { "Ham", "Mushroom", "Pepperoni", "Peppers", "Onion", "Extra Cheese" };
    const float toppingPrices[6] = { 0.80f, 0.50f, 1.0f, 0.80f, 0.40f, 1.50f };
    int choice;

    // Display toppings menu
    cout << "Choose Toppings [Current Balance: $" << fixed << setprecision(2) << currentCredits << "]\n";
    for (int i = 0; i < 6; i++) {
        cout << (i + 1) << ". " << toppings[i] << " [$" << toppingPrices[i] << "]" << endl;
    }
    cout << "0. Finish toppings selection\n";
    cout << "Please choose a topping (1-6) or 0 to finish: ";
    cin >> choice;

    // Handle user choice
    if (choice == 0) {
        // Finish topping selection
        return;
    }
    else if (choice >= 1 && choice <= 6) {
        float price = toppingPrices[choice - 1];
        if (currentCredits >= price) {
            currentCredits -= price;
            pizzaPrice += price;
            pizzaToppings.push_back(toppings[choice - 1]);
            cout << "Added " << toppings[choice - 1] << " to your pizza. Remaining balance: $" << currentCredits << endl;
        }
        else {
            cout << "Not enough credits! Please add more credits.\n";
            float addedCredits;
            cout << "Enter additional credits: ";
            cin >> addedCredits;
            currentCredits += addedCredits;
            cout << "Updated balance: $" << currentCredits << endl;
        }
    }
    else {
        cout << "Invalid option. Please choose a valid topping option.\n";
    }
}

// Function to display the pizza size menu and handle user choice
void orderPizzas(float& currentCredits) {
    const string pizzaSizes[3] = { "Small", "Medium", "Large" };
    const float pizzaPrices[3] = { 5.0f, 8.50f, 10.25f };
    int choice;
    vector<string> pizzaToppings;
    float pizzaPrice = 0.0f;

    while (true) {
        drawDivider();
        cout << "Order Pizza - Select Size [Current Balance: $" << fixed << setprecision(2) << currentCredits << "]\n";
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". " << pizzaSizes[i] << " [$" << pizzaPrices[i] << "]" << endl;
        }
        cout << "4. Finish ordering pizzas\n";
        cout << "Please choose a pizza size (1-3) or 4 to finish: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            float price = pizzaPrices[choice - 1];
            if (currentCredits >= price) {
                currentCredits -= price;
                pizzaPrice = price;  // Set pizza price based on selection

                cout << "You have selected a " << pizzaSizes[choice - 1] << " Pizza.\n";

                // Allow adding multiple toppings
                bool Loop_break = true;
                while (Loop_break) {
                    chooseTopping(currentCredits, pizzaToppings, pizzaPrice); // Single topping choice
                    cout << "Current toppings on your pizza: ";
                    for (const auto& topping : pizzaToppings) {
                        cout << topping << " ";
                    }
                    cout << "\nDo you want to add more toppings? (1 for yes, 0 for no): ";
                    int moreToppings;
                    cin >> moreToppings;
                    if (moreToppings == 0) {
                        Loop_break = false;
                    }
                }

                // Print receipt
                drawDivider();
                cout << "Receipt:\n";
                cout << "Pizza Price: $" << fixed << setprecision(2) << pizzaPrice << endl;
                cout << "Toppings Price: $" << fixed << setprecision(2) << (pizzaPrice - price) << endl;
                cout << "Total Price: $" << fixed << setprecision(2) << pizzaPrice << endl;
                cout << "Remaining Balance: $" << fixed << setprecision(2) << currentCredits << endl;
                cout << "Toppings: ";
                for (const auto& topping : pizzaToppings) {
                    cout << topping << " ";
                }
                cout << "\n";
                exit(0);
            }
            else {
                cout << "Not enough credits! Please add more credits.\n";
                float addedCredits;
                cout << "Enter additional credits: ";
                cin >> addedCredits;
                currentCredits += addedCredits;
                cout << "Updated balance: $" << currentCredits << endl;
            }
        }
        else if (choice == 4) {
            break;  // Finish ordering pizzas
        }
        else {
            cout << "Invalid option. Please choose a valid pizza size option.\n";
        }
    }
}

// Main menu function to handle user choices
void mainMenu() {
    float currentCredits = 0.0f;
    int choice;

    while (true) {
        drawDivider();
        cout << "Main Menu\n";
        cout << "1. Order Pizza [Current Balance: $" << fixed << setprecision(2) << currentCredits << "]\n";
        cout << "2. Exit\n";
        cout << "Please choose an option (1-2): ";
        cin >> choice;

        if (choice == 1) {
            cout << "How much credits do you want to add: ";
            cin >> currentCredits;
            orderPizzas(currentCredits);
        }
        else if (choice == 2) {
            exit(0);  // Exit the program
        }
        else {
            cout << "Invalid option. Please choose a valid menu option.\n";
        }
    }
}

int main() {
    // Intro
    drawDivider();
    cout << "UClan PIZZA\n";
    drawDivider();

    // Start the main menu
    mainMenu();

    return 0;
}
