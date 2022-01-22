#include <iostream>
#include <assert.h>
#include <string>

int printColorMapForSingleDigit(){
    const char *majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char *minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 5; j++){
            std::cout << i * 5 + j << "  | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}
int printColorMapForDoubleDigit(){
    const char *majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char *minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for (i = 2; i < 5; i++){
        for (j = 0; j < 5; j++){
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}
std::string getColorPairForPairNumber(int pairNumber){
    const char *majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char *minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (pairNumber == (i * 5 + j)){
                std::string returnMajorColor = majorColor[i];
                std::string returnMinorColor = minorColor[i];
                return (returnMajorColor.append(" | ").append(returnMinorColor));
            }
        }
    }
    return "";
}

int main(){
    assert(printColorMapForSingleDigit() == 10);
    assert(printColorMapForDoubleDigit() == 25);
    assert(getColorPairForPairNumber(0) == "");
    assert(getColorPairForPairNumber(25) == "Violet | Slate");
    return 0;
}
