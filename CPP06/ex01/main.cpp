#include "Data.hpp"

int main() {
    t_data* originalData = new t_data{"btekinli", 24, 7.14};

    uintptr_t serializedPtr = serialize(originalData);

    t_data* deserializedData = deserialize(serializedPtr);

    std::cout << "test: " << deserializedData << "\n";

    if (originalData == deserializedData) {
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Username: " << deserializedData->username << "\nAge: " << deserializedData->age
                  << "\nLevel: " << deserializedData->level << std::endl;
        std::cout << "ptr address: " << deserializedData << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }

    delete originalData;

    return 0;
}
