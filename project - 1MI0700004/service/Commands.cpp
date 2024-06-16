#include "Commands.h"

void Commands::commands()
{
	std::cout << "Choose a command:" << std::endl;
	std::cout << std::endl;
	std::cout << "1.Open file:" << std::endl;
	std::cout << "2.Save file:" << std::endl;
	std::cout << "3.Save file as:" << std::endl;
	std::cout << "4.Undo:" << std::endl;
	std::cout << "5.Remove column by name:" << std::endl;
	std::cout << "6.Remove column by number:" << std::endl;
	std::cout << "7.Rearange column:" << std::endl;
	std::cout << "8.Sort column by number:" << std::endl;
	std::cout << "9.Sort column by name:" << std::endl;
	std::cout << "10.Filter column by number:" << std::endl;
	std::cout << "11.Filter column by name:" << std::endl;
	std::cout << "12.Copy row:" << std::endl;
	std::cout << "13.Add minimal row:" << std::endl;
	std::cout << "14.Add maximal row:" << std::endl;
	std::cout << "15.Add median row:" << std::endl;
	std::cout << "16.Print table:" << std::endl;
	std::cout << "17.Close current file:" << std::endl;
	std::cout << "18.Exit:" << std::endl;

}

void Commands::run()
{
	bool exit = false;
	commands();
	int number;
	int command;
	
	while (!exit)
	{
		std::vector<int> helper;
		
		std::string input;
		try
		{
			std::cout << std::endl;
			std::cout << "Enter a command: " << std::endl;
			std::cin >> command;

			switch (command)
			{
			case 1: 
				std::cout << "Enter file name: " << std::endl;
				std::cin >> input;
				object.openFile(input);
				break;
			case 2: 
				object.saveFile();
				break;
			case 3: 
				std::cout << "Enter file name: " << std::endl;
				std::cin >> input;
				object.saveFileAs(input);
				std::cout << "Filed saved successfuly!" << std::endl;
				break;
			case 4: 
				object.undo();
				break;
			case 5: 
				std::cout << "Enter name: " << std::endl;
				std::cin >> input;
				object.removeColumnByName(input);
				std::cout << "Column removed successfuly!" << std::endl;
				break;
			case 6:
				std::cout << "Enter number: " << std::endl;
				std::cin >> number;
				object.removeColumnByNumber(number);
				std::cout << "Column removed successfuly!" << std::endl;

				break;
			case 7:
				std::cout << "Enter how many numbers you want to enter " << std::endl;
				
				std::cin >> number;
				for (size_t i = 0; i < number; i++)
				{
					std::cout << "Enter number: " << std::endl;
					int helpN;
					std::cin >> helpN;
					helper.push_back(helpN);
				}
				object.columnRearrange(helper);
				std::cout << "Columns rearranged successfuly!" << std::endl;

				break;
			case 8:
				std::cout << "Enter number: " << std::endl;
				std::cin >> number;
				object.sortByColumnNumber(number);
				break;
			case 9:
				std::cout << "Enter name: " << std::endl;
				std::cin >> input;
				object.sortByColumnName(input);
				break;

			case 10:
				std::cout << "Enter number: " << std::endl;
				std::cin >> number;
				object.filterByColumnNumber(number);
				break;
			case 11:
				std::cout << "Enter name: " << std::endl;
				std::cin >> input;
				object.filterByColumnName(input);
				break;
			case 12:
				std::cout << "Enter number: " << std::endl;
				std::cin >> number;
				object.copyRow(number);
				std::cout << "Successfuly copied row!" << std::endl;
				break;
			case 13:
				object.addMinimalRow();
				std::cout << "Minimal row added successfuly!" << std::endl;
				break;
			case 14:
				object.addMaximumRow();
				std::cout << "Maximum row added successfuly!" << std::endl;
				break;
			case 15:
				object.addMedianRow();
				std::cout << "Median row added successfuly!" << std::endl;
				break;
			case 16: 
				object.printTable();
				break;
			case 17: 
				object.closeFile();
				std::cout << "File is closed. You can open new one!" << std::endl;
				break;
			case 18:
				std::cout << "Do you want to save the changes? " << std::endl;
				std::cout << "1 - Yes, 2 - No. Please enter: " << std::endl;
				std::cin >> number;
				if (number == 1)
				{
					object.saveFile();
				}
				exit = true;
				break;
			default:
				throw ("Inalid command! Program closes! ");
				exit = true;
				break;
				
			}
		}
		catch (const char* msg)
		{
			std::cout << msg << std::endl;
			exit = true;
		}
		
	}

}

