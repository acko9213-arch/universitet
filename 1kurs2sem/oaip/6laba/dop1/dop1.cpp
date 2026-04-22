#include <iostream>
#include "Header.h"
int main() {
    int size = 7;

    
    int* my_array = create_array(size);

    if (my_array != nullptr) {
       
        init_array(my_array, size, 10);

       
        my_array[3] = 55;
        my_array[6] = 21;

       
        std::cout << "Contents: ";
        print_array(my_array, size);

    
        std::cout << "Max value: " << find_max(my_array, size) << std::endl;

    
        delete_array(my_array);
        std::cout << "Memory has been cleaned up." << std::endl;
    }

    return 0;
}