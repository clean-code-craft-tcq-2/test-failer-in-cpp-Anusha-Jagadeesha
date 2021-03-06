#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms > 0 && cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms >= 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize(){
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(38) == 'S');
    assert(size(42) == 'L'); 
    //negative scenario  
    assert(size(-38) == '\0');
    assert(size(0) == '\0');
    std::cout << "All is well (maybe!)\n";
}

int main() {
    testTshirtSize();
    return 0;
}
