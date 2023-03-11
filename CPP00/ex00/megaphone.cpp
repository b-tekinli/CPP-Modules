/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <btekinli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:31:04 by btekinli          #+#    #+#             */
/*   Updated: 2023/03/11 14:31:12 by btekinli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::cout;


int main(int ac, char **av)
{
    int j = 1;
    int i = 0;

    if (ac > 1)
    {
        while (av[j]) {
            i = 0;
            while (av[j][i])
            {
                cout << (char)toupper(av[j][i]);
                i++;
            }
            j++;
        }
        cout << "\n";
    }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
    return (0);
}
