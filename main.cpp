#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Initial probabiliy of each bag
float Pbags[] = {0.1, 0.2, 0.4, 0.2, 0.1};
// Given bags have inifnite candies these are static probability
float PCherry[] = {1.0, 0.75, 0.5, 0.25, 0.0};
float PLime[] = {0.0, 0.25, 0.5, 0.75, 1};

// Calculates the probabiliy of a Lime candy being selected given the current world state
float probabilityLime()
{
    float sum = 0.0;
    // Iterate over each bag
    for (int i = 0; i < 5; i++)
    {
        sum += Pbags[i] * PLime[i];
    }
    return sum;
}

// Calculates the probability of a Cherry candy being selected given the current world state
float probabilityCherry()
{
    float sum = 0.0;
    // Iterate over each bag
    for (int i = 0; i < 5; i++)
    {
        sum += Pbags[i] * PCherry[i];
    }
    return sum;
}

// Calculate the probability of Cherry being picked from bag i
float probabilityCherryBag(int i)
{

    return (Pbags[i] * PCherry[i]);
}

// Calculate the probability of Lime being picked from bag i
float probabilityLimeBag(int i)
{
    return (Pbags[i] * PLime[i]);
}

// Debugging tool for printing current bag state
void printBags()
{
    for (int i = 0; i < 5; i++)
    {
        cout << Pbags[i] << ", ";
    }
    cout << endl;
}

// Save the output to result.txt (reset each run)
void writeResult(string input)
{
    ofstream result("result.txt");
    result << "Observation sequence Q: " << input << endl;
    result << "Length of Q: " << input.length() << endl;
    result << endl;
    result << "P(h1 | Q) = " << fixed << setprecision(5) << Pbags[0] << endl;
    result << "P(h2 | Q) = " << Pbags[1] << endl;
    result << "P(h3 | Q) = " << Pbags[2] << endl;
    result << "P(h4 | Q) = " << Pbags[3] << endl;
    result << "P(h5 | Q) = " << Pbags[4] << endl;

    result << endl;
    result << "Probability that the next candy we pick will be C, given Q: " << probabilityCherry() << endl;
    result << "Probability that the next candy we pick will be L, given Q: " << probabilityLime() << endl;
    result.close();
}

int main(int argc, char *argv[])
{
    // Default user input to nothing
    string userInput = "";
    float probLime = probabilityLime();
    float probCherry = probabilityCherry();

    // Check if arguments passed in
    if (argc == 2)
    {
        userInput = argv[1];
    }
    else
    {
        writeResult(userInput);
    }

    // Iterate over every user input character 
    for (int input = 0; input < userInput.length(); input++)
    {
        char currentInput = userInput[input];
        // Recalculate the probability given the current world status before each new candy
        probLime = probabilityLime();
        probCherry = probabilityCherry();

        // Only two possible inputs
        switch (currentInput)
        {
        case 'C':
        {
            for (int i = 0; i < 5; i++)
            {
                Pbags[i] = probabilityCherryBag(i) / probCherry;
            }
        }

        break;
        case 'L':
        {
            for (int i = 0; i < 5; i++)
            {
                Pbags[i] = probabilityLimeBag(i) / probLime;
            }
        }
        break;

        // Notify the user of invalid input
        default:
            cout << "Invalid character " << currentInput << " plese provide only C or L" << endl;
            break;
        }
    }

    // printBags(); // Debugging tool
    // Log results
    writeResult(userInput);
}