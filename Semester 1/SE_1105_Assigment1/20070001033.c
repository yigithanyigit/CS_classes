#include <stdio.h>

//P.S : User will only enter the valid inputs

void welcome()
{
    //Print a welcome message to the user
    printf("Welcome To Yigitbucks");
}

int hot_or_cold()
{
    //Ask user to select hot or cold
    int type;
    printf("For Hot drink menu please Type (1), For Cold drink please type (2) \n ***Additional Note: Cold is expensive 2 TL from Hot. \n");
    scanf_s(" %d", &type);
    return type;
}

int coffee_type(int type)
{
    //Ask user to select a coffee type
    printf("What do you want to drink today?\n");
    int coffe;
    if (type == 1)
    {

        printf("Hot Filtered Cofffe (1)(2 TL) \n Mocha (2)(6 TL) \n Latte (3)(8 TL) \n ");
        scanf_s(" %d", &coffe);
        return coffe;
    }
    else
    {
        printf("Cool Lime (1)(12 TL) \n Ice White Mocha (2)(8 TL) \n Iced Filtered Coffe (3)(10 TL) \n ");
        scanf_s(" %d", &coffe);
        return coffe;
    }
}

int coffee_size(int type)
{
    //Ask user to select a coffee size
    int size;
    if (type == 2)
    {
        printf("We have only 1 size at COLDS \n");
        return 0;
    }
    else
    {
        printf("Select Size \n Tall(1),Grande(2) and Vetti(3)");
        scanf_s(" %d", &size);
        return size;
    }
}

int extra_essance()
{
    int essence;
    printf("Do you want extra essence with extra 1 TL cost?\n Yes(1), No(2) \n");
    scanf_s(" %d", &essence);
    return essence;
}

int coffee_sugar(int type)
{
    //Ask if user would like to add sugar
    int sugar;
    if (type == 2)
    {
        sugar = extra_essance();
    }
    else
    {
        printf("Do you want sugar with extra 1 TL cost?\n Yes(1), No(2) \n");
        scanf_s(" %d", &sugar);
    }
    return sugar;
}

int cost(int coffeeType, int coffeeSize, int sugar, int type)
{
    //Print the price of the coffee acording to user's choices.
    int price = 0;
    if (type == 2)
    {
        price += 2;
        if (coffeeType == 1)
        {
            price += 12;
        }
        else if (coffeeType == 2)
        {
            price += 8;
        }
        else if (coffeeType == 3)
        {
            price += 10;
        }
    }
    else
    {

        if (coffeeType == 1)
        {
            price += 2;
        }
        else if (coffeeType == 2)
        {
            price += 6;
        }
        else if (coffeeType == 3)
        {
            price += 8;
        }
        price *= coffeeSize;
    }
    if (sugar == 1)
    {
        price += 1;
    }
    return price;
}

void summary(int coffeeType, int coffeeSize, int sugar, int type, int cost)
// Prints Summary of Order
{
    printf("You selected ");
    if (type == 1)
    {
        switch (coffeeType)
        {
        case 1:
            printf("Hot Filtered Coffee ");
            break;
        case 2:
            printf("Mocha ");
            break;

        case 3:
            printf("Latte ");
            break;
        }
    }
    else
    {
        switch (coffeeType)
        {
        case 1:
            printf("Cool Lime ");
            break;
        case 2:
            printf("Ice White Mocha ");
            break;

        case 3:
            printf("Iced Filtered Coffee ");
            break;
        }
    }
    if (sugar == 1)
    {
        printf("with Extra Sugar/Essence ");
    }
    else
    {
        printf("without Extra Sugar/Essence ");
    }
    printf("Cost: %d ", cost);
}

void goodbye()
{
    //Print a goodbye message for the user
    printf("\nGoodbye ! ");
}

void main()
{
    //Welcome the user, take their order, calculate the price and say goodbye
    int coffee;
    int size;
    int sugar;
    int type;
    int coffeCost;

    welcome();
    type = hot_or_cold();
    coffee = coffee_type(type);
    size = coffee_size(type);
    sugar = coffee_sugar(type);
    coffeCost = cost(coffee, size, sugar, type);
    summary(coffee, size, sugar, type, coffeCost);
    goodbye();
}
