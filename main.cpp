#include <iomanip>
#include <iostream>

/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword

 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.


 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output


 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }

        // 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc()
        {
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl;
        }

        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;

        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;

        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}



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

    void mfcalcRecordStoragePerSecond()
    {
        std::cout << "A wav file at 16 bit/ 44.1 K consumes 88.2KB in storage per second. "
                  << "\nSo recording 10 files for 3 minutes will consume "
                  << std::setprecision(2) << this->calcRecordStoragePerSecond(10, 60.0)
                  << " MB in hard drive space.\n" << std::endl;
    }

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
    }
    float totalStorageInMB = totalStorageInKB * .0001f;
    return totalStorageInMB;
}

/*
 copied UDT 2:
 */

struct Dog
{
    std::string name;
    std::string hairColor;
    std::string breed;
    std::string temperament;
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

    void mfGainWeight()
    {
        std::cout << this->name << " is too skinny, and only weighs " << this->weight
                  << " lbs. I'm putting him on a weight gain diet so he can get up to "
                  << this->idealWeight << " lbs. \n" << std::endl;
    }
};

Dog::Dog() : name("Bob"),// inches
             hairColor  ("brown"),
             breed ( "doberman"),
             temperament ("aggressive"),
             weight (45.0f), // pounds
             hairLength (0.5f),
             idealWeight (60)
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
    int napIntervals = 4; // hours

    void meow(std::string breed, std::string temperament);
    void purr(std::string breed, std::string temperament);
    void scratch(std::string breed, std::string temperament);
    int sleep(int catNapIntervals);

    void mfSleep()
    {
        std::cout << "I can only study code when my cat is sleeping. She takes hour "
                  << "long naps every " << this->napIntervals << " hours. \nSo I can "
                  << "only only study " << this->sleep(this->napIntervals) << " hours per day. "
                  << "Otherwise she won't stay off the g!@#%$@ keyboard. \n" << std::endl;
    }
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
    Example::main();
    PetsAndSoftware catAndFlutter;
    SoftwareAndPets ptAndDog;

    Dog bob;
    bob.name = "Bob";
    bob.gainWeight(45.0f,60);

    std::cout << bob.name << " is too skinny, and only weighs " << bob.weight
              << " lbs. I'm putting him on a weight gain diet so he can get up to "
              << bob.idealWeight << " lbs. \n" << std::endl;

    Dog bob2;
    bob2.mfGainWeight();

    Cat whiskers;
    whiskers.napIntervals = 4;

    std::cout << "I can only study code when my cat is sleeping. She takes hour "
              << "long naps every " << whiskers.napIntervals << " hours. \nSo I can "
              << "only only study " << whiskers.sleep(4) << " hours per day. "
              << "Otherwise she won't stay off the g!@#%$@ keyboard. \n" << std::endl;

    Cat whiskers2;

    whiskers2.mfSleep();

    DAW reaper;

    std::cout << "A wav file at 16 bit/ 44.1 K consumes 88.2KB in storage per second. \nSo recording 10 files for 3 minutes will consume "
              << std::setprecision(2) << reaper.calcRecordStoragePerSecond(10, 60.0) << " MB in hard drive space.\n" << std::endl;

    DAW logic;

    logic.mfcalcRecordStoragePerSecond();

    std::cout << "good to go!" << std::endl;
}
