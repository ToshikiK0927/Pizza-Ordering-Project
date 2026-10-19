#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;


/**
 * prompts the user to enter name and user has to input their name, after that a formated menu is printed
 * @return the customer's name
*/
string menu()
{
    cout << "Welcome to Toshiki and Ethan’s Pizzeria" << endl;
    cout << "Enter your first name: ";
    
    string customer_name;
    cin >> customer_name; // take input for customer name
    cout << endl;
    
    // the following uses setw() to format the menu neatly
    cout << "Pizza Size(inches)" << setw(10) << "Cost" << endl;
    cout << setw(10) << "10" << setw(19) << "$10.99" << endl;
    cout << setw(10) << "12" << setw(19) << "$12.99" << endl;
    cout << setw(10) << "14" << setw(19) << "$14.99" << endl;
    cout << setw(10) << "16" << setw(19) << "$16.99" << endl;
    cout << endl;
    
    return customer_name; // returns the customer name
}


/**
 * prompts the user each pizza size of 10, 12, 14, or 16 and user has to input the pizza size
 * the size and cost defaults to 12 and $12.99 respectively, when an invalid pizza size is inputted
 * @param the size of pizza
 * @return the cost of pizza
*/
double choose_size(int& size_of_pizza)
{
    cout << "What size pizza would you like?" << endl;
    cout << "10, 12, 14, or 16 (enter the number only): ";
    cin >> size_of_pizza; // take input for the pizza size
    
    // the pizza size is checked in each if statement to set the cost of the pizza based on size
    double cost; // initialize the cost of the pizza 
    if (size_of_pizza == 10) 
    {
        cost = 10.99; 
    }
    else if (size_of_pizza == 12) 
    {
        cost = 12.99; 
    }
    else if (size_of_pizza == 14) 
    {
        cost = 14.99;
    }
    else if (size_of_pizza == 16) 
    {
        cost = 16.99; 
    }
    else // if pizza size is anything other (most likely an input error) the following executes
    {
        cout << "Size unavailable, you will get a 12 inch." << endl;
        size_of_pizza = 12; 
        cost = 12.99; 
    }
    
    return cost; // return the cost
}


/**
 * prompts the user what type of pizza crust they want, then the user has to input (H)Hand-tossed, (T) Thin-crust, or (D) Deep-dish
 * the crust defaults to hand-tossed if when an invalid character is inputted
 * @return the name of crust type 
*/
string choose_crust()
{
    cout << "What type of crust do you want?" << endl;
    cout << "(H) Hand-tossed, (T) Thin-crust, or (D) Deep-dish (enter H, T, or D): ";
    char crust;
    cin >> crust; // take input for crust character
    
    // the crust character is checked to set the crust name
    string crust_type;
    switch(toupper(crust)) // toupper() is added to get rid of case sensitivity
    {
        case 'H': crust_type = "Hand-tossed"; break;
        case 'T': crust_type = "Thin"; break;
        case 'D': crust_type = "Deep-dish"; break;
        default:
        cout << "crust unavailable, you will get Hand-tossed." << endl; 
        crust_type = "Hand-tossed"; 
        break;
    }
    return crust_type; // return crust type
}
 
 
/**
 * prompts the topping options of pepperoni, sausage, onion, and mushroom, the user has to input either 'Y' or 'N'
 * @param toppings the string with all topping names
 * @return the number of toppings
*/
int choose_topping(string& toppings)
{
    // initialize all character variables for each topping
    char pepperoni;
    char sausage;
    char onion;
    char mushroom;
    
    cout << "All pizzas come with cheese." << endl;
    cout << "Additional toppings are $1.25 each, choose from: " << endl;
    cout << "Pepperoni, Sausage, Onion, Mushroom" << endl;

    cout << "Do you want Pepperoni? (Y/N): ";
    cin >> pepperoni;
    cout << "Do you want Sausage? (Y/N): "; 
    cin >> sausage;
    cout << "Do you want Onion? (Y/N): "; 
    cin >> onion;
    cout << "Do you want Mushroom? (Y/N): "; 
    cin >> mushroom;
    
    cout << endl;
    
    // each character variable for each topping is checked if 'Y' was inputted
    // if true, the topping is concatinated to the topping string, and increases the number of toppings
    // tolower() is a way to get rid of case sensitivity
    int numberofToppings = 1; // number of toppings is already 1 since cheese is already on the pizza
    if(tolower(pepperoni) == 'y')
    {
        toppings += " Pepperoni";
        numberofToppings++;
    }
    if(tolower(sausage) == 'y')
    {
        toppings += " Sausage";
        numberofToppings++;
    }
    if(tolower(onion) == 'y')
    {
        toppings += " Onion";
        numberofToppings++;
    }
    if(tolower(mushroom) == 'y')
    {
        toppings += " Mushroom";
        numberofToppings++;
    }
    
    return numberofToppings; // return the number of toppings
}

/**
 * compares the customer name with the owner names, "toshiki" and "ethan", then deducts $2 from the cost if true
 * @param customer_name name of customer_name
 * @param cost the cost of the current cost
*/
void is_owner(string customer_name, double& cost)
{
    bool owner = false; // initialize the flag if the customer name is the owners' name
    string toshiki = "toshiki";
    string ethan = "ethan";
    
    // if the length is not the same, there is no reason to compare
    if (customer_name.length() == toshiki.length() || customer_name.length() == ethan.length())
    {
        // go through each character in the string and compare each character to the name "toshiki"
        int i = 0;
        while(i < customer_name.length())
        {
            if (toshiki[i] == tolower(customer_name[i])) // tolower() is a way to get rid of case sensitivity
            {
                owner = true;
            }
            else
            {
                owner = false;
                break;
            }
            i++;
        }
        
        
        if(!owner) // if the customer name is already known to be "toshiki", there is no need to check for "ethan"
        {
            // go through each character in the string and compare each character to the name "ethan"
            i = 0;
            while(i < customer_name.length())
            {
                if(ethan[i] == tolower(customer_name[i]))
                {
                    owner = true;
                }
                else
                {
                    owner = false;
                    break;
                }
                i++;
            }
        }
        
        // utilize the flag to check if the customer name is the owners' names and the following will execute
        if(owner)
        {
            cout << "You will receive a $2 discount" << endl;
            cost -= 2.00;
        }
    }
}
    
int main()
{
    string customer_name = menu(); // run the menu() function while intializing the customer_name
    
    // run the choose_size() function while initializing the cost
    int size_of_pizza;
    double cost = choose_size(size_of_pizza);
    
    // run the choose_crust() function while initializing the crust_type
    string crust_type = choose_crust();
    
    // run the choose_topping() function while initializing the numberofToppings
    string toppings = "Cheese";
    int numberofToppings = choose_topping(toppings);
    
    
    cout << "Your order is as follows: " << endl;
    cout << size_of_pizza << "-inch pizza" << endl;
    
    cout << crust_type << " crust" << endl;
    cout << toppings << endl;
    
    // subtract 1 since cheese was added to the number of toppings (in which cheese does not add $1.25 to the cost)
    cost += (numberofToppings-1)*1.25;
    
    // run the isowner() function
    is_owner(customer_name, cost);
    
    // the following lines of codes uses precision value of 2 to get 2 decimal places
    cout << "The cost of your order is: $" << fixed << setprecision(2) << cost << endl;
    
    double tax = cost*0.0795; // tax is 7.95% of cost
    cout << "The tax is: $" << fixed << setprecision(2) << tax << endl;
    cout << "The total due is: $" << fixed << setprecision(2) << cost+tax << endl;
    cout << "Your order will be ready for pickup in 30 minutes.";
    
    return 0;
}