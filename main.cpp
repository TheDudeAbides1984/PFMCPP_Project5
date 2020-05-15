/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4:

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main

 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.

 4) write the name of your class where it says "OwnerClass"

 5) write wrapper classes for each type similar to how it was shown in the video

 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
    This means if you had something like the following in your main() previously:
*/
#if false
Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
#endif
/*
   you would update that to use your wrappers:
*/

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.

 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

/*
 copied UDT 1:
 */
#include <iomanip>
#include <iostream>
#include "LeakedObjectDetector.h"

struct DAW
{
    DAW ();

    ~DAW ()
    {
        std::cout << ("DAW struct destructor called\n") << std::endl;
    }

    std::string company;
    int price;
    int compatiblePlatforms; // Windows and Mac
    int channelCount; // no limit
    int maxPluginsPerChannel; //no limit
    float versionNumber;

    void record (int channelCount);

    void edit (int channelCount);

    void mix (int channelCount, int maxPluginsPerChannel);

    float calcRecordStoragePerSecond (int numOfFiles, float maxRecordTime);

    void mfcalcRecordStoragePerSecond ()
    {
        std::cout << "A wav file at 16 bit/ 44.1 K consumes 88.2KB in storage per second. "
                  << "\nSo recording 10 files for 3 minutes will consume "
                  << std::setprecision (2) << this->calcRecordStoragePerSecond (10, 60.0)
                  << " MB in hard drive space.\n" << std::endl;
    }

    struct Software
    {
        Software ();

        std::string name = "Reaper";
        float versionNumber = 6.08f;

        float updateVersion (float versionNumber = 6.08f);
    };

    JUCE_LEAK_DETECTOR(DAW)
};

struct DAWWrapper
{
    DAWWrapper (DAW* ptr) : pointerToDAW (ptr)
    {}

    ~DAWWrapper ()
    {
        delete pointerToDAW;
    }

    DAW* pointerToDAW = nullptr;
};

DAW::DAW () : company ("Cockos"),
              price (60),
              compatiblePlatforms (2),
              channelCount (0),
              maxPluginsPerChannel (0),
              versionNumber (6.08f)
{

}

DAW::Software::Software ()
{}

float DAW::calcRecordStoragePerSecond (int numOfFiles, float maxRecordTime)
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

    Dog ();

    ~Dog ()
    {
        std::cout << ("Dog struct destructor called\n") << std::endl;
    }

    float run (float weight, std::string breed); // to determine a general speed
    void bark (std::string breed, std::string temperament);

    void whine (std::string breed, std::string temperament);

    float gainWeight (float currentWeight, int idealDogWeight);

    void mfGainWeight ()
    {
        std::cout << this->name << " is too skinny, and only weighs " << this->weight
                  << " lbs. I'm putting him on a weight gain diet so he can get up to "
                  << this->idealWeight << " lbs. \n" << std::endl;
    }

    JUCE_LEAK_DETECTOR(Dog)
};

struct DogWrapper
{
    DogWrapper (Dog* ptr) : pointerToDog (ptr)
    {}

    ~DogWrapper ()
    {
        delete pointerToDog;
    }

    Dog* pointerToDog = nullptr;
};

Dog::Dog () : name ("Bob"),// inches
              hairColor ("brown"),
              breed ("doberman"),
              temperament ("aggressive"),
              weight (45.0f), // pounds
              hairLength (0.5f),
              idealWeight (60)
{

}

float Dog::gainWeight (float currentWeight, int idealDogWeight)
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
    Cat ();

    ~Cat ()
    {
        std::cout << ("Cat struct destructor called\n") << std::endl;
    }

    std::string hairColor = "black";
    std::string breed = "domestic short hair";
    std::string temperament = "friendly";
    float hairLength = 0.75f;
    int napIntervals = 4; // hours

    void meow (std::string breed, std::string temperament);

    void purr (std::string breed, std::string temperament);

    void scratch (std::string breed, std::string temperament);

    int sleep (int catNapIntervals);

    void mfSleep ()
    {
        std::cout << "I can only study code when my cat is sleeping. She takes hour "
                  << "long naps every " << this->napIntervals << " hours. \nSo I can "
                  << "only only study " << this->sleep (this->napIntervals) << " hours per day. "
                  << "Otherwise she won't stay off the g!@#%$@ keyboard. \n" << std::endl;
    }

    JUCE_LEAK_DETECTOR(Cat)
};

struct CatWrapper
{
    CatWrapper (Cat* ptr) : pointerToCat (ptr)
    {}

    ~CatWrapper ()
    {
        delete pointerToCat;
    }

    Cat* pointerToCat = nullptr;
};

Cat::Cat () = default;

int Cat::sleep (int catNapIntervals)
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
    PetsAndSoftware ();

    Cat dosia;
    Dog fido;
    DAW studioOne;

    ~PetsAndSoftware ()
    {
        std::cout << "PetsAndSoftware destructor called.\n" << std::endl;
        std::cout << "Cat is finally going to sleep, now I can work.\n" << std::endl;
    }

    JUCE_LEAK_DETECTOR(PetsAndSoftware)
};

struct PetsAndSoftwareWrapper
{
    PetsAndSoftwareWrapper (PetsAndSoftware* ptr) : pointerToPetsAndSoftware (ptr)
    {}

    ~PetsAndSoftwareWrapper ()
    {
        delete pointerToPetsAndSoftware;
    }

    PetsAndSoftware* pointerToPetsAndSoftware = nullptr;
};

PetsAndSoftware::PetsAndSoftware () = default;

/*
 new UDT 5:
 */

struct SoftwareAndPets
{
    SoftwareAndPets ();

    Cat max;
    Dog fred;
    DAW logic;

    ~SoftwareAndPets ()
    {
        std::cout << "Software and pets destructor called. \n" << std::endl;
        fred.name = "Fred";
        std::cout << fred.name << " has finally put on weight. He's"
                  << " now up to " << fred.gainWeight (30, 50)
                  << " lbs.\n" << std::endl;
    }

    JUCE_LEAK_DETECTOR(SoftwareAndPets)
};

struct SoftwareAndPetsWrapper
{
    SoftwareAndPetsWrapper (SoftwareAndPets* ptr) : pointerToSoftwareAndPets (ptr)
    {}

    ~SoftwareAndPetsWrapper ()
    {
        delete pointerToSoftwareAndPets;
    }

    SoftwareAndPets* pointerToSoftwareAndPets = nullptr;
};

SoftwareAndPets::SoftwareAndPets () = default;  //oooo you fancy with the 'default' lol!

#include <iostream>

int main ()
{
    DogWrapper bob(new Dog());
    bob.pointerToDog->name = "Bob";
    bob.pointerToDog->gainWeight (45.0f, 60);

    std::cout << bob.pointerToDog->name << " is too skinny, and only weighs " 
              << bob.pointerToDog->weight << " lbs. I'm putting him on a weight gain "
              << "diet so he can get up to "
              << bob.pointerToDog->idealWeight << " lbs. \n" << std::endl;

    DogWrapper bob2(new Dog());
    bob2.pointerToDog->mfGainWeight ();

    CatWrapper whiskers(new Cat());//Cat whiskers;  <<<< Do this
    whiskers.pointerToCat->napIntervals = 4;

    std::cout << "I can only study code when my cat is sleeping. She takes hour "
              << "long naps every " << whiskers.pointerToCat->napIntervals 
              << " hours. \nSo I can only only study " << whiskers.pointerToCat->sleep(4)
              << " hours per day.Otherwise she won't stay off the g!@#%$@ keyboard. \n" 
              << std::endl;

    CatWrapper whiskers2(new Cat()); 
    whiskers2.pointerToCat->mfSleep();

    DAWWrapper reaper(new DAW());

    std::cout
            << "A wav file at 16 bit/ 44.1 K consumes 88.2KB in storage per second. \n"
            << "So recording 10 files for 3 minutes will consume "
            << std::setprecision (2) << reaper.pointerToDAW->calcRecordStoragePerSecond (10, 60.0)
            << " MB in hard drive space.\n" << std::endl;

    DAWWrapper logic(new DAW());

    logic.pointerToDAW->mfcalcRecordStoragePerSecond ();

    PetsAndSoftwareWrapper catAndFlutter(new PetsAndSoftware());

    SoftwareAndPetsWrapper ptAndDog(new SoftwareAndPets());

    std::cout << "good to go!" << std::endl;
}
