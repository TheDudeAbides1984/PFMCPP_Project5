#include <iomanip>
#include <iostream>

/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor.

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have:
        member functions,
        member variables,
        constructors that initialize the members.
        for() or while() loops that modify member variables

 Define your implementations of all functions OUTSIDE of the class.
 Then do instruction 2)

 If you DID do Project 3, do instruction 1)

 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission.

 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative

 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.

 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.

 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 copied UDT 1:
 */

struct DAW
{
    DAW();
    ~DAW()
    {
        std::cout << ("DAW struct destructor called\n") << std::endl;
    }
    std::string company;
    int price;
    int compatiblePlatforms; // Windows and Mac
    int channelCount; // no limit
    int maxPluginsPerChannel; //no limit
    float versionNumber;

    void record(int channelCount);
    void edit(int channelCount);
    void mix(int channelCount, int maxPluginsPerChannel);
    float calcRecordStoragePerSecond(int numOfFiles, float maxRecordTime);

    struct Software
    {
        Software();
        std::string name = "Reaper";
        float versionNumber = 6.08f;

        float updateVersion(float versionNumber = 6.08f);
    };
};

DAW::DAW() : company("Cockos"),
             price(60),
             compatiblePlatforms(2),
             channelCount(0),
             maxPluginsPerChannel(0),
             versionNumber(6.08f)
{

}

DAW::Software::Software() {}

float DAW::calcRecordStoragePerSecond(int numOfFiles, float maxRecordTime)
{
    float totalStorageInKB = 0;
    float numOfSeconds = 0;

    while (numOfSeconds < maxRecordTime)
    {
        ++numOfSeconds;
        totalStorageInKB = numOfFiles * numOfSeconds * 88.2f;

        // std::cout <<totalStorageInKB << std::endl;
    }
    float totalStorageInMB = totalStorageInKB * .0001f;
    return totalStorageInMB;
}

/*
 copied UDT 2:
 */

struct Dog
{
    std::string hairColor;
    std::string breed;
    std::string temperament;
    std::string name;
    float weight;
    float hairLength;
    int idealWeight;

    Dog();
    ~Dog()
    {
        std::cout << ("Dog struct destructor called\n") << std::endl;
    }

    float run (float weight, std::string breed); // to determine a general speed
    void bark(std::string breed, std::string temperament);
    void whine(std::string breed, std::string temperament);
    float gainWeight(float currentWeight, int idealDogWeight);

};

Dog::Dog() : hairColor  ("brown"),
             breed ( "doberman"),
             temperament ("aggressive"),
             weight (75.7f), // pounds
             hairLength (0.5f),
             idealWeight (0)// inches
{

}

float Dog::gainWeight(float currentWeight, int idealDogWeight)
{
    idealWeight = idealDogWeight;
    weight = currentWeight;
    for (int i = 0; currentWeight < idealDogWeight; ++i)
    {
        ++currentWeight;
    }
    return currentWeight;
}

/*
 copied UDT 3:
 */

struct Cat
{
    Cat();
    ~Cat()
    {
        std::cout << ("Cat struct destructor called\n") << std::endl;
    }
    std::string hairColor = "black";
    std::string breed = "domestic short hair";
    std::string temperament = "friendly";
    float hairLength = 0.75f;
    int napIntervals{}; // hours

    void meow(std::string breed, std::string temperament);
    void purr(std::string breed, std::string temperament);
    void scratch(std::string breed, std::string temperament);
    int sleep(int catNapIntervals);
};

Cat::Cat() = default;

int Cat::sleep(int catNapIntervals)
{
    napIntervals = catNapIntervals;
    int hoursICanStudy = 0;
    for (int i = 0; i < 24; ++i)
    {
        if (i % napIntervals == 0)
        {
            ++hoursICanStudy;
        }
    }
    return hoursICanStudy;
}

/*
 new UDT 4:
 */

struct PetsAndSoftware
{
    PetsAndSoftware();
    Cat dosia;
    Dog fido;
    DAW studioOne;

    ~PetsAndSoftware()
    {
        std::cout << "PetsAndSoftware destructor called.\n" << std::endl;
        std::cout << "Cat is finally going to sleep, now I can work.\n" << std::endl;
    }
};

PetsAndSoftware::PetsAndSoftware() = default;

/*
 new UDT 5:
 */

struct SoftwareAndPets
{
    SoftwareAndPets();
    Cat max;
    Dog fred;
    DAW logic;

    ~SoftwareAndPets()
    {
        std::cout << "Software and pets destructor called. \n" << std::endl;
        fred.name = "Fred";
        std::cout << fred.name << " has finally put on weight. He's"
                  << " now up to " << fred.gainWeight(30,50)
                  << " lbs.\n" << std::endl;
    }
};

SoftwareAndPets::SoftwareAndPets() = default;

#include <iostream>
int main()
{
    PetsAndSoftware catAndFlutter;
    SoftwareAndPets ptAndDog;

    Dog bob;
    bob.name = "Bob";
    bob.gainWeight(45.0f,60);

    std::cout << bob.name << " is too skinny, and only weighs " << bob.weight
              << " lbs. I'm putting him on a weight gain diet so he can get up to "
              << bob.idealWeight << " lbs. \n" << std::endl;

    Cat whiskers;
    whiskers.napIntervals = 4;

    std::cout << "I can only study code when my cat is sleeping. She takes hour "
              << "long naps every " << whiskers.napIntervals << " hours. \nSo I can "
              << "only only study " << whiskers.sleep(4) << " hours per day."
              << "Otherwise she won't stay off the g!@#%$@ keyboard. \n" << std::endl;

    DAW reaper;

    std::cout << "A wav file at 16 bit/ 44.1 K consumes 88.2KB in storage per second. \nSo recording 10 files for 3 minutes will consume "
              << std::setprecision(2) << reaper.calcRecordStoragePerSecond(10, 60.0) << " MB in hard drive space.\n" << std::endl;

    std::cout << "good to go!" << std::endl;
}
