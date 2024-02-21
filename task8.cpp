#include <iostream>

typedef enum
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
}Day;

typedef struct
{
    int day;
    int month;
    int year;
}Date;

const char* get(Day week_day) 
{
    switch (week_day) 
    {
        case Monday:
            return "Monday";
        case Tuesday:
            return "Tuesday";
        case Wednesday:
            return "Wednesday";
        case Thursday:
            return "Thursday";
        case Friday:
            return "Friday";
        case Saturday:
            return "Saturday";
	case Sunday:
	    return "Sunday";
	default:
            return "Invalid day";
    }
}

void print(Date current, Day week_day) 
{
    std::cout << "Day is: " << get(week_day) << std::endl;
    std::cout << "Date is: " << current.day << "." << current.month << "." << current.year << std::endl;
}

int main() 
{
    Date current = {22, 2, 2024};
    Day week_day = Wednesday;;
    print(current, week_day);
    return 0;
}
