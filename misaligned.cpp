#include <iostream>
#include <assert.h>
#include <string>
#include <cstring>

std::string getColorPair(int majorColorId, int minorColorId){
    const char *majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char *minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int pairNumber = (((majorColorId * 5) + minorColorId) + 1) ;
    static char colurPair[100];
    sprintf(colurPair,"%d\t|\t%s\t|\t%s",pairNumber,majorColor[majorColorId],minorColor[minorColorId]);
    std::string retColorPair = colurPair;
    return retColorPair;
}

int printColorMap(){
    int majorColorIdx = 0, minorColorIdx = 0;
    for (majorColorIdx = 0; majorColorIdx < 5; majorColorIdx++){
        for (minorColorIdx = 0; minorColorIdx < 5; minorColorIdx++){
            std::cout << getColorPair(majorColorIdx,minorColorIdx) << std::endl;
        }
    }
    return majorColorIdx * minorColorIdx;
}

void testPrintColorMap(){
    assert(printColorMap() == 25);
    assert(getColorPair(0,0).compare("1	|	White	|	Blue") == 0);
    assert(getColorPair(1,4).compare("10	|	Red	|	Slate") == 0);
    assert(getColorPair(3,0).compare("16	|	Yellow	|	Blue") == 0);
    assert(getColorPair(4,0).compare("21	|	Violet	|	Blue") == 0);
    assert(getColorPair(4,4).compare("25	|	Violet	|	Slate") == 0);
}

int main(){
    testPrintColorMap();
    return 0;
}
