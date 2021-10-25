#include <iostream>
#include <string>

//Function to take the user input for the browser they want to use
//Only 3 browsers for now
//Enter integer to open the browser of choice
//Option to exit out of the application if needed
void inputBrowser(int& browserChoice)
{
	std::cout << "What browser do you want to open?" << std::endl;
	std::cout << "Enter 1 for Chrome\nEnter 2 for Firefox\nEnter 3 for Edge\nEnter 4 to Exit" << std::endl;
	std::cout << "Enter your browser of choice : ";
	std::cin >> browserChoice;
	std::cout << std::endl;
}

//Function to return the browser string
//Runs inputBrowser within and validates input
//Then returns a string based on the user choice
std::string returnBrowser()
{
	int browserChoice;
	bool first = true;
	do
	{
		if (!first)
		{
			std::cout << "You have entered invalid input. Please try again." << std::endl;
		}
		inputBrowser(browserChoice);

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "You have entered invalid input. Please try again." << std::endl;

			inputBrowser(browserChoice);
		}
		first = false;
	} while (browserChoice != 1 && browserChoice != 2 && browserChoice != 3 && browserChoice != 4);

	switch (browserChoice)
	{
	case 1:
		return "chrome ";
		break;
	case 2:
		return "firefox ";
		break;
	case 3:
		return "msedge ";
		break;
	case 4:
		return "exit";
		break;
	default:
		return "";
		break;
	}
}

//Function to return the private browser append string
//Validates the user input
//Returns a string based on the user's browser choice
std::string privateBrowsing(std::string browser)
{
	char privateInput;
	bool first = true;
	do
	{
		if (!first)
		{
			std::cout << "You have entered invalid input. Please try again." << std::endl;
		}

		std::cout << "Would you like to use private browsing?" << std::endl;
		std::cout << "Enter 'Y' or 'N' : ";
		std::cin >> privateInput;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << std::endl;

		first = false;
	} while (privateInput != 'Y' && privateInput != 'y' && privateInput != 'N' && privateInput != 'n');

	if (privateInput == 'Y' || privateInput == 'y')
	{
		if (browser == "chrome ")
		{
			return "-incognito ";
		}
		else if (browser == "firefox ")
		{
			return "-private ";
		}
		else if (browser == "msedge ")
		{
			return "-inprivate ";
		}
	}
	return "";
}

//Function to return search query the application needs to search for
//Asks the user if they want to search up an URL or not
//Replaces spaces with '%20' if there are any within the search query
std::string searchQuery()
{
	char input;
	bool first = true;
	do
	{
		if (!first)
		{
			std::cout << "You have entered invalid input. Please try again." << std::endl;
		}

		std::cout << "Would you like to search up an URL?" << std::endl;
		std::cout << "Enter 'Y' or 'N' : ";
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << std::endl;

		first = false;
	} while (input != 'Y' && input != 'y' && input != 'N' && input != 'n');

	std::string query;
	if (input == 'Y' || input == 'y')
	{
		std::cout << "Enter the URL you want to search up : ";
		std::getline(std::cin, query);
		std::cout << std::endl;
	}
	else
	{
		query += "https://www.google.com/search?q=";
		
		std::string tempString;
		std::cout << "What would you like to search for?\nKeep blank if you want to open browser only" << std::endl;
		std::cout << "Enter your search query : ";
		std::getline(std::cin, tempString);
		std::cout << std::endl;

		if (tempString == "")
		{
			return tempString;
		}

		for (int i = 0; i < tempString.size(); i++)
		{
			if (tempString[i] == ' ')
			{
				tempString.replace(i, 1, "%20");
			}
		}

		query += tempString;
	}

	return query;
}

//Main function
//Runs an infinite while loop that is broken only when user enters 4 during browser input
//Runs returnBrowser, privateBrowsing and searchQuery and then opens the browser with the given search query
int main()
{
	while (true)
	{
		std::string operation = "start ";

		std::string browser = returnBrowser();
		if (browser == "exit")
		{
			std::cout << "Closing program" << std::endl;
			break;
		}
		operation += browser;

		std::string privateAppendString = privateBrowsing(browser);
		operation += privateAppendString;

		std::string query = searchQuery();
		operation += query;

		system(operation.c_str());
	}

	return 1;
}