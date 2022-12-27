#include <iostream>
using namespace std;

int main()
{
    const float KG_PER_LB = .453592, M_PER_INCH = .0254;    // Conversion values as constants
    float weightInPounds, heightInInches;                   // before conversion
    float weightInKg, heightInM;                            // after conversion
    float bodyMassIndex;                                    // BMI

    cout << "Please enter weight (in pounds):" << endl;
    cin >> weightInPounds;
    cout << "Please enter height (in inches):" << endl;
    cin >> heightInInches;

    weightInKg = weightInPounds * KG_PER_LB;                // Converting weight 
    heightInM = heightInInches * M_PER_INCH;                // Converting height 
    bodyMassIndex = weightInKg / (heightInM * heightInM);   // BMI

    if (bodyMassIndex < 18.5)
        cout << "The weight status is: Underweight" << endl;
    else if (bodyMassIndex >= 18.5 && bodyMassIndex < 25)
        cout << "The weight status is: Normal" << endl;      
    else if (bodyMassIndex >= 25 && bodyMassIndex < 30)
        cout << "The weight status is: Overweight" << endl;  
    else
        cout << "The weight status is: Obese" << endl;

    return 0;
}