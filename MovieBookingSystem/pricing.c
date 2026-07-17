
// calculating discounts based on groups
// student - 10%
// senior citizen - 20%
// Group discount (4 or more than 4 ) - 10%

//only one discount should be applicable except the group discount


float calculateTicketPrice(float basePrice, int totalTickets, int isStudent, int isSenior)
{
    float discountPercentage = 0.0;

    if(isSenior == 1)
    {
        discountPercentage+=0.20;
    }
    else if(isStudent == 1)
    {
        discountPercentage+=0.10;
    }

    if(totalTickets >= 4)
    {
        discountPercentage += 0.10;
    }

    float finalPrice = (basePrice*1.0)-(basePrice*discountPercentage);
    return finalPrice;
}
