#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    switch (rand() % 3)
    {
    case 0:
        return new A;
        break;
    case 1:
        return new B;
    case 2:
        return new C;
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &)
        {
            std::cout << "C" << std::endl;
        }
    }
}

int main()
{
    srand(time(0));

    for (int i = 0; i < 3; ++i)
    {
        Base *p = generate();
        identify(p);
        identify(*p);

        delete p;
    }
    return 0;
}
