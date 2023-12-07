#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("Daryl", 50);
        cout << bureaucrat << endl;

        bureaucrat.incrementGrade();
        cout << bureaucrat << endl;

        bureaucrat.decrementGrade();
        cout << bureaucrat << endl;

        Bureaucrat invalidBureaucrat("Rick", 0);

        // Bureaucrat invBure("Beyza", 150);
        // cout << invBure << endl;

        // invBure.decrementGrade();
        // cout << invBure << endl;

        // invBure.decrementGrade();
        // cout << invBure << endl;

    } 
    catch (exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return (0);
}
