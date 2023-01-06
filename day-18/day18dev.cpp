#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "Enter a string: ";
    std::string s;
    std::getline(std::cin, s);

    // Convert the string to lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Create a map to store the frequency of each letter
    std::map<char, int> frequency;

    // Iterate through the string and count the frequency of each letter
    for (std::string::iterator it = s.begin(); it != s.end(); it++)
    {
        char c = *it;
        if (isalpha(c))
        {
            frequency[c]++;
        }
    }

    // Sort the letters in descending order of frequency
    std::vector<std::pair<char, int>> sortedLetters;
    for (std::map<char, int>::iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        sortedLetters.push_back(*it);
    }
    std::sort(sortedLetters.begin(), sortedLetters.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b)
    {
        return a.second > b.second;
    });

    // Print the top 5 most occurring letters and their frequency as a percentage
    int totalCount = 0;
    for (std::string::iterator it = s.begin(); it != s.end(); it++)
    {
        if (isalpha(*it))
        {
            totalCount++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        std::pair<char, int> p = sortedLetters[i];
        std::cout << p.first << ": " << (p.second / (double)totalCount) * 100 << "%" << std::endl;
    }

    return 0;
}
