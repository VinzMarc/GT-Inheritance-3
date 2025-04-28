#include <iostream>
#include <string>
using namespace std;

// Base class: Beverage
class Beverage {
private:
    string name;
    int volume; // in milliliters
    bool isChilled;

public:
    Beverage(const string& name, int volume, bool isChilled)
        : name(name), volume(volume), isChilled(isChilled) {}

    string getName() const { return name; }
    int getVolume() const { return volume; }
    bool getIsChilled() const { return isChilled; }

    bool isEmpty() const { return volume == 0; }

    string toString() const {
        return name + " (" + to_string(volume) + "mL) " +
               (isChilled ? "is still chilled" : "is not chilled anymore");
    }
};

// Subclass: Water (extends Beverage)
class Water : public Beverage {
private:
    string type; // "Purified", "Regular", or "Distilled"

public:
    Water(int volume, bool isChilled, const string& type)
        : Beverage("Water", volume, isChilled), type(type) {}

    Water(int volume, bool isChilled)
        : Beverage("Water", volume, isChilled), type("Regular") {}

    string getType() const { return type; }

    string toString() const {
        return Beverage::toString() + " [" + type + "]";
    }
};

// Subclass: Beer (extends Beverage)
class Beer : public Beverage {
private:
    double alcoholicContent; // percentage (0.01 to 1.00)

public:
    Beer(int volume, bool isChilled, double alcoholicContent)
        : Beverage("Beer", volume, isChilled), alcoholicContent(alcoholicContent) {}

    double getAlcoholicContent() const { return alcoholicContent; }

    string getType() const {
        if (alcoholicContent < 0.03)
            return "Flavored";
        else if (alcoholicContent < 0.06)
            return "Regular";
        else
            return "Strong";
    }

    string toString() const {
        return Beverage::toString() + " (" + to_string(alcoholicContent * 100) + "% alcoholic content) [" + getType() + "]";
    }
};

int main() {
    // Input for Water
    int waterVolume;
    string waterChilledInput, specifyTypeInput, waterType;
    bool waterChilled;

    cout << "Enter water volume (mL): ";
    cin >> waterVolume;
    cout << "Is the water chilled? (yes/no): ";
    cin >> waterChilledInput;
    waterChilled = (waterChilledInput == "yes");

    cout << "Do you want to specify water type? (yes/no): ";
    cin >> specifyTypeInput;

    if (specifyTypeInput == "yes") {
        cout << "Enter water type (Purified, Regular, Distilled): ";
        cin >> waterType;
    } else {
        waterType = "Regular";
    }

    Water water(waterVolume, waterChilled, waterType);
    cout << "\nWater Details:\n" << water.toString() << endl;

    // Input for Beer
    int beerVolume;
    string beerChilledInput;
    bool beerChilled;
    double alcoholContent;

    cout << "\nEnter beer volume (mL): ";
    cin >> beerVolume;
    cout << "Is the beer chilled? (yes/no): ";
    cin >> beerChilledInput;
    beerChilled = (beerChilledInput == "yes");

    cout << "Enter alcohol content (e.g., 0.045 for 4.5%): ";
    cin >> alcoholContent;

    Beer beer(beerVolume, beerChilled, alcoholContent);
    cout << "\nBeer Details:\n" << beer.toString() << endl;

    return 0;
}