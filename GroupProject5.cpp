#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const int bookDetails = 4;
const int numOfBooks = 10; //wanted to be able to change this seems impossible without vectors or any other things we have not been taught AB
struct books {
	string BookName;
	string BookType;
	double BookPrice;
	int NumberSold;
};
char selection;

void ShowUsage()
{
	cout << "To show program usage 'S'" << endl;
	cout << "To input a file to be processed press 'G'" << endl;
	cout << "To calculate number of books sold and total for each book press 'A'" << endl;
	cout << "To display number of books sold and total for each press 'P'" << endl;
	cout << "To quit the program press 'Q'" << endl;
}
//fwd declare
bool input(string file_name, books books_sold[numOfBooks]);

void calculate(books books_sold[numOfBooks]);

void print();




int main(int argc, char* argv[])
{
	//allowing for input of filename AB
	string file_name;
	//instanc of struct to use in calls AB
	books booksData[numOfBooks];
	//bool to check if file opens
	bool tof;
	//calling the instructions to use the program then letting the user input the part they want to do. Then loops until the user quits. Alex Rettell
	ShowUsage();

	do {

		cout << "Please enter selection: ";
		cin >> selection;

		if (selection == 's' || selection == 'S')
		{
			system("cls");
			ShowUsage();
		}
		else if (selection == 'g' || selection == 'G')
			//entering name of file to go through AB
			cout << "Enter the name of your text file. (must have 10 books)";
		cin >> file_name;
		cout << endl;
		//with file name can call input AB
		tof = input(file_name, booksData);
		//if file doesnt open end program
		if (tof == false) {
			return -1;
		}
		else if (selection == 'a' || selection == 'A')
			calculate();
		else if (selection == 'p' || selection == 'P')
			print();
		else if (selection == 'q' || selection == 'Q')
		{
			cout << "Thank You";

			break;
		}


	} while (1);


}
//AlexBennett
bool input(string file_name, books books_sold[numOfBooks])
{
	//variable to use commands with
	ifstream openFile;
	//openfile
	openFile.open(file_name);
	//checking to see if file opens
	if (!openFile)
	{
		cout << "Sorry could not open your file. Please try again later." << endl;
		return false;
	}
	else
	{
		cout << "File opened sucessfully." << endl;
	}
	//collecting data
	while (openFile)
	{
		//two loops to go through all details
		for (int row = 0; row < numOfBooks; row++) {
			for (int col = 0; col < bookDetails; col++) {
				//collecting all data here
				openFile >> books_sold[numOfBooks].BookName;
				openFile >> books_sold[numOfBooks].BookType;
				openFile >> books_sold[numOfBooks].BookPrice;
				openFile >> books_sold[numOfBooks].NumberSold;
			}
		}
	}
	void calculate(books books_sold[numOfBooks]){
		for (int row = 0; row < numOfBooks; row++) {

			for (int col = 0; col < bookDetails; col++) {

				float BookPrice = books_sold[numOfBooks].BookPrice;
				float NumberSold = books_sold[numOfBooks].NumberSold;
				float TotalSales= BookPrice* NumberSold;
			}
		}
	}

	openFile.close();
	return true;
