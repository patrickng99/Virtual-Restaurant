/*This program is a user interface of an experimental restaurant,
 where the customers don't get a food menu but instead state their
 food preference and food will be prepared for them, based on their
 preference. The program also calculates how much the customers have
 to pay for the food. */

//Author: Patrick Karangwa   September 18, 2019

/*The user input in this program will be to enter the scale (1 to 100) to which
 they prefer a particular type of food item and the amount of money they have for food.
 Once the user has entered all the inputs, the program will calculate the results and
 prepare a "virtual meal". At the end of the program, the output will be the
 total amount of money due, including tax.*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    //Initialization of variables
    int meatScale = 0;
    int veggieScale = 0;
    int pastaScale = 0;
    int potatoScale = 0;
    int chocolateScale = 0;
    int fruitScale = 0;
    float budget = 0.0;
    const float TAX = 0.07;
    const float MAIN_COURSE_PRICE = 10.0;
    const float APPETIZER_PRICE = 5.0;
    const float DESSERT_PRICE = 5.0;
    float totalTax = 0.0;
    float totalPrice = 0.0;
    string appetizer = " ";
    string mainCourse = " ";
    string dessert = " ";
    //The boolean variables will enable the calculation of the price
    bool isGettingAppt = false;
    bool isGettingMnCrs = false;
    bool isGettingDessert = false;
    //Introduction
    cout<<"\n\t  Hello there! Weclome to VIRTU-RANT Restaurant!\n";
    cout<<"\tAt this restaurant, our customers get a surprise meal\n";
    cout<<"\tbased on what they prefer and we prepare it for them.\n";
    cout<<"\t\t\tLet's get started!!\n\n";
    
    //Asking for user input
    //The if-else statements in between insure that the user's input is withing the range
    cout<<"How much do you like meat on scale of 1 to 100? \n";
    cin>>meatScale;
    if(meatScale > 100)
        meatScale = 100;
    else if(meatScale < 1)
        meatScale = 1;
    cout<<meatScale<<endl;
    cout<<"How much do you like vegetables on scale of 1 to 100? \n";
    cin>>veggieScale;
    if(veggieScale > 100)
        veggieScale = 100;
    else if(veggieScale < 1)
        veggieScale = 1;
    cout<<veggieScale<<endl;
    cout<<"How much do you like pasta on scale of 1 to 100? \n";
    cin>>pastaScale;
    if(pastaScale > 100)
        pastaScale = 100;
    else if(pastaScale < 1)
        pastaScale = 1;
    cout<<pastaScale<<endl;
    cout<<"How much do you like potatoes on scale of 1 to 100? \n";
    cin>>potatoScale;
    if(potatoScale > 100)
        potatoScale = 100;
    else if(potatoScale < 1)
        potatoScale = 1;
    cout<<potatoScale<<endl;
    cout<<"How much do you like chocolate on scale of 1 to 100? \n";
    cin>>chocolateScale;
    if(chocolateScale > 100)
        chocolateScale = 100;
    else if(chocolateScale < 1)
        chocolateScale = 1;
    cout<<chocolateScale<<endl;
    cout<<"How much do you like fruit on scale of 1 to 100? \n";
    cin>>fruitScale;
    if(fruitScale > 100)
        fruitScale = 100;
    else if(fruitScale < 1)
        fruitScale = 1;
    cout<<fruitScale<<endl;
    cout<<"What is your budget (before tax) for this meal? \n";
    cin>>budget;
    cout<<budget<<endl;
    cout<<"\n";
    
    //Choosing the Apetizers
    if(budget >= 15)
    {
        //If there is a tie between the meat and vegetable preference, meat is assigned by default
        if(meatScale >= 10 && meatScale > veggieScale)
        {
            appetizer = "Chicken Wings";
            cout<<"Appetizer: "<<appetizer<<endl;
        }
        else if(veggieScale >= 10 && veggieScale > meatScale)
        {
            appetizer = "Garden Salad";
            cout<<"Appetizer: "<<appetizer<<endl;
        }
        else if(meatScale >= 10 && veggieScale >= 10 && meatScale == veggieScale)
        {
            appetizer = "Chicken Wings";
            cout<<"Appetizer: "<<appetizer<<endl;
        }
        else
        {
            appetizer = "Garlic Bread";
            cout<<"Appetizer: "<<appetizer<<endl;
        }
        isGettingAppt = true; //This means the customer will be getting an appetizer
    }
    /*else
    {
        cout<<"The appetizers will be off for this order. Let's see what we can get for your budget. \n";
    }*/
    cout<<"\n";
    
    //Choosing the Main Course
    if(budget >= 10)
    {
        //Here we are comparing two items at the same time.
        //In case there is a tie between the vegetable and meat preference, meat is assigned by default
        if(meatScale >= 10 && potatoScale >= 10 && meatScale >= veggieScale && potatoScale > pastaScale) 
        { 
            mainCourse = "Steak and baked potato";
            cout<<"Main Course: "<<mainCourse<<endl;
        }
        //In case there is a tie between the pasta and potato preference, pasta is assigned by default
        else if(meatScale >= 10 && pastaScale >= 10 && meatScale >= veggieScale && pastaScale >= potatoScale)
        {
            mainCourse = "Spaghetti and meat sauce";
            cout<<"Main Course: "<<mainCourse<<endl;
        }
        else if(veggieScale >= 10 && veggieScale > meatScale)
        {
            mainCourse = "Pasta primavera";
            cout<<"Main Course: "<<mainCourse<<endl;
        }
        else
        {
            mainCourse = "Cheese Omelet";
            cout<<"Main Course: "<<mainCourse<<endl;
        }
        isGettingMnCrs = true;
    }
    else
    {
        cout<<"Sorry, we can't prepare anything for $"<<budget<<".\n";
    }
    cout<<"\n";
    
    //Choosing the Dessert
    if(budget >= 20)
    {
        //If there is a tie between the chocolate and fruit scale, fruit is assigned by default
        if(chocolateScale >= 10 && chocolateScale > fruitScale)
        {
            dessert = "Chocolate cake";
            cout<<"Dessert: "<<dessert<<endl;
        }
        else if(fruitScale >= 10 && fruitScale >= chocolateScale)
        {
            dessert = "Apple pie";
            cout<<"Dessert: "<<dessert<<endl;
        }
        else
        {
            dessert = "Vanilla ice cream";
            cout<<"Dessert: "<<dessert<<endl;
        }
        isGettingDessert = true;
    }
    cout<<endl;
    
    //Calculating the price due and generating ouput
    //First case: they are getting the whole combo
    if(isGettingAppt == true && isGettingMnCrs == true && isGettingDessert == true)
    {
        totalTax = (MAIN_COURSE_PRICE + APPETIZER_PRICE + DESSERT_PRICE) * TAX ;
        totalPrice = totalTax + (MAIN_COURSE_PRICE + APPETIZER_PRICE + DESSERT_PRICE);
        cout<<"Here is your order summary: \n";
        cout<<"\t\t"<<appetizer<<": $"<<APPETIZER_PRICE<<endl;
        cout<<"\t\t"<<mainCourse<<": $"<<MAIN_COURSE_PRICE<<endl;
        cout<<"\t\t"<<dessert<<": $"<<DESSERT_PRICE<<endl;
        cout<<"\t\tSales Tax: $"<<totalTax<<endl;
        cout<<"\t\tTotal: $"<<totalPrice<<endl;
        cout<<"\nThank you for eating at VIRTU-RANT We hope to see you again soon!!\n";
    }
    //Second case: they are getting an appetizer and main course only
    else if(isGettingAppt == true && isGettingMnCrs == true && isGettingDessert == false)
    {
        totalTax = (MAIN_COURSE_PRICE + APPETIZER_PRICE) * TAX;
        totalPrice = totalTax + (MAIN_COURSE_PRICE + APPETIZER_PRICE);
        cout<<"Here is your order summary: \n";
        cout<<"\t\t"<<appetizer<<": $"<<APPETIZER_PRICE<<endl;
        cout<<"\t\t"<<mainCourse<<": $"<<MAIN_COURSE_PRICE<<endl;
        cout<<"\t\tSales Tax: "<<totalTax<<endl;
        cout<<"\t\tTotal: $"<<totalPrice<<endl;
        cout<<"\nThank you for eating at VIRTU-RANT We hope to see you again soon!!\n";
    }
    //Third case: they are getting the main course only
    else if(isGettingAppt == false && isGettingMnCrs == true && isGettingDessert == false)
    {
        totalTax = MAIN_COURSE_PRICE * TAX;
        totalPrice = totalTax + MAIN_COURSE_PRICE;
        cout<<"Here is your order summary: \n";
        cout<<"\t\t"<<mainCourse<<": $"<<MAIN_COURSE_PRICE<<endl;
        cout<<"\t\tSales Tax: $"<<totalTax<<endl;
        cout<<"\t\tTotal: $"<<totalPrice<<endl;
        cout<<"\nThank you for eating at VIRTU-RANT We hope to see you again soon!!\n";
    }
    return 0;
}
