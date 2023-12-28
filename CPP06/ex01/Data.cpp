#include "Data.hpp"

uintptr_t serialize(t_data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

t_data* deserialize(uintptr_t raw) {
    return reinterpret_cast<t_data*>(raw);
}
