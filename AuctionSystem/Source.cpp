#include <iostream>
#include <string>
using namespace std;

struct User
{
	int User_ID;
	string
		User_number,
		User_1st_name,
		User_last_name,
		User_email,
		User_password,
		User_delivery_addres;

};

struct item
{
	int  item_ID;
	string
		discrebtion,
		category,
		item_price,
		stat,
		start_date,
		end_date;


};

int buyed_item_counter = 0, Verification_loop_counter = 1, User_ID = 0, Item_selected = 0;

bool Status = true;

bool Available = true;

User Users_arr[100];
int user_counter = 1;

item Items_arr[100];
int item_counter = 4;

//this function takes the feedback from the user
void feedback();

//The function used when the user wants to register.
void user_register();

//The function checks if the user email correct.
void emailValidation_check();

//The function check if the user password less than six digits.
void passwordValidation_check();

//The function checks if the user phone number valid.
void phonenumberValidation_check();

//display the sell menu
void sell_menu();

//display the buy menu
void buy_menu();

//the function used when the user wants to add a new item for sale.
void adding_item();

//the function used when the user wants to see the available items. 
void show_items();

//the function used when the user wants to search via category.
void catigory_search();

//the function used when the user wants to know the most selling categories
void bestSelling_category();


int main()
{
	string Verification_Password;

	int	Verification_ID,

		First_menu_choice = 0,

		Second_menu_choice = 0;

	cout << "AUCTION SYSTEM\n_______________________\n";
	do//system loop
	{
		//First menu.
		cout << "press (1) to login\n_______________________\nPress (2) to register\n_______________________\nPress (0) to exit\n_______________________\n->";
		cin >> First_menu_choice;

		system("cls");

		switch (First_menu_choice)
		{

			//case (1) when the user chose login.
		case 1:
		{
			cout << "ID : ";
			cin >> Verification_ID;

			cout << "PASSWORD : ";
			cin >> Verification_Password;

			system("cls");

			do//this loop check if the password and the id is correct or not to allow the user to login.
			{

				if (Verification_ID == Users_arr[Verification_loop_counter].User_ID && Verification_Password == Users_arr[Verification_loop_counter].User_password)
				{

					for (int i = 1; i > 0; i++)//this loop to make the user logged in until the user choose to log out
					{
						cout << "Welcome : " << Users_arr[Verification_loop_counter].User_1st_name << " " << Users_arr[Verification_loop_counter].User_last_name;


						//second menu
						cout << "\n_______________________\npress (1) to sell\n_______________________\nPress (2) to buying\n_______________________\nPress (0) to logout\n";
						cin >> Second_menu_choice;

						system("cls");


						if (Second_menu_choice == 1)
						{
							sell_menu();
						}


						else if (Second_menu_choice == 2)
						{
							buy_menu();
						}

						else if (Second_menu_choice == 0)
						{
							cout << "logout..." << endl;

							Verification_loop_counter *= 0;
							i *= -1;
						}

						else
							cout << "NOT AN OPTION\n";

					}
				}

				else if (Verification_loop_counter > user_counter)
				{
					cout << "-> ID or password is not found\n";

					Verification_loop_counter *= 0;
				}

				else
				{
					Verification_loop_counter++;
				}

			} while (Verification_loop_counter != 0);//end of the do-while loop


			break;
		}

		//case (2) when the user chose register.
		case 2:
		{
			user_register();
			user_counter++;
			break;
		}
		//case (2) when the user choce to exit.
		case 0:
		{
			First_menu_choice = 0;
			break;
		}

		default:
		{
			cout << "not an option \n";
			break;
		}

		}//End of the switch

		Verification_loop_counter == 1;
		cout << endl;

	} while (First_menu_choice > 0);//end of the do while loop

	return 0;
}

void feedback()
{
	string feedBack;
	int rating = 0;
	for (int z = 1; z > 0; z++)
	{
		cout << "rate the item : ";
		cin >> rating;
		if (rating >= 1 && rating <= 5)
		{
			cout << "enter your feedback\n";
			cin >> feedBack;
			z *= -1;
		}
		else
		{
			cout << "the rating must be from 1 to 5\n";
		}
	}
}

void passwordValidation_check()
{
	bool x = false;
	int chk = 6;

	do
	{
		cin >> Users_arr[user_counter].User_password;
		if (Users_arr[user_counter].User_password.size() > chk)
		{
			x = true;
		}
		else
		{
			cout << "password must be more than six characters or digits\nPassword : ";
			x = false;
		}
	} while (x == false);
}

void emailValidation_check()
{
	bool i = false;
	string e = "@yahoo.com", x = "@gmail.com";

	do {

		cin >> Users_arr[user_counter].User_email;

		if (Users_arr[user_counter].User_email.size() > e.size() || Users_arr[user_counter].User_email.size() > x.size())
		{
			i = true;
		}
		else
		{
			cout << "invalid email\nthe email adrdress should be like (name@ex.com)\nEmail : ";
			i = false;
		}
	} while (i == false);
}

void phonenumberValidation_check()
{
	string phone_num;
	bool x = false;

	do
	{
		cin >> Users_arr[user_counter].User_number;
		Users_arr[user_counter].User_number;

		int correct = 11;

		if (correct == Users_arr[user_counter].User_number.size())
		{
			x = true;
		}

		else
		{
			cout << "the phone number is invalid\nphone number : ";
			x = false;
		}

	} while (x == false);
}

void user_register()
{
	cout << "Pleas enter your data to register\n";

	cout << "___________________\nFirst Name : ";
	cin >> Users_arr[user_counter].User_1st_name;

	cout << "___________________\nLast Name : ";
	cin >> Users_arr[user_counter].User_last_name;

	cout << "___________________\nEmail : ";
	emailValidation_check();

	cout << "___________________\nPhone number : ";
	phonenumberValidation_check();

	cout << "___________________\nDelivery addres : ";
	cin >> Users_arr[user_counter].User_delivery_addres;

	cout << "___________________\nPassword : ";
	passwordValidation_check();

	Users_arr[user_counter].User_ID = (user_counter + 100);
	cout << "___________________\nYour ID is : " << Users_arr[user_counter].User_ID << endl;

}

void adding_item()
{
	int k = 0;

	cout << "Chose the category\n1.Smart phone\n2.Laptop\n3.Cars\n4.Other\n";

	cin >> k;

	switch (k)

	{

	case 1:

	{
		Items_arr[item_counter].category = "Smart phone";
		break;
	}

	case 2:

	{
		Items_arr[item_counter].category = "Laptop";
		break;
	}

	case 3:
	{
		Items_arr[item_counter].category = "Cars";
		break;
	}

	case 4:
	{
		Items_arr[item_counter].category = "Other";
		break;
	}

	default:
		break;
	}

	cout << "_______________________\nenter the item discrebtion :";
	cin >> Items_arr[item_counter].discrebtion;

	cout << "_______________________\nenter item price : ";
	cin >> Items_arr[item_counter].item_price;

	cout << "_______________________\nenter the auction start date : ";
	cin >> Items_arr[item_counter].start_date;

	cout << "_______________________\nenter the auction end date : ";
	cin >> Items_arr[item_counter].end_date;

	cout << "_______________________\nEnter item ID : ";
	cin >> Items_arr[item_counter].item_ID;

	cout << "_______________________\nThe item is successfully added \n ";

}

void show_items()
{
	Items_arr[0].category = "Smart phone";
	Items_arr[0].start_date = "15/8/2020";
	Items_arr[0].end_date = "15/10/2020";
	Items_arr[0].discrebtion = "Iphone X 128GB Black";
	Items_arr[0].item_price = "10,000 EGP";
	Items_arr[0].item_ID = 622;

	Items_arr[1].category = "Cars";
	Items_arr[1].start_date = "1/8/2020";
	Items_arr[1].end_date = "6/8/2020";
	Items_arr[1].discrebtion = "BMW X8 red";
	Items_arr[1].item_price = "1,200,000 EGP";
	Items_arr[1].item_ID = 752;

	Items_arr[2].category = "Laptop";
	Items_arr[2].start_date = "30/7/2020";
	Items_arr[2].end_date = "9/11/2020";
	Items_arr[2].discrebtion = "Lenovo laptop /16GB RAM / i7 / GTX 1650 4GB VRAM";
	Items_arr[2].item_price = "17,500 EGB";
	Items_arr[2].item_ID = 540;

	Items_arr[3].category = "Other";
	Items_arr[3].start_date = "3/8/2020";
	Items_arr[3].end_date = "15/12/2020";
	Items_arr[3].discrebtion = "Rolex golden watch";
	Items_arr[3].item_price = "6,000 EGP";
	Items_arr[3].item_ID = 925;

	for (int f = 0; f < item_counter; f++)
	{


		cout << "category : " << Items_arr[f].category << endl

			<< "discrebtion : " << Items_arr[f].discrebtion << endl

			<< "price : " << Items_arr[f].item_price << endl

			<< "starting date : " << Items_arr[f].start_date << endl

			<< "ending date : " << Items_arr[f].end_date << endl

			<< "Item ID : " << Items_arr[f].item_ID << endl;

		if (Status == true)
			cout << "item is availble\n";

		else
			cout << "item is not availble\n";

		cout << "__________________________\n";
	}
}

void catigory_search()
{
	int b;string search_by_category;

	cout << "Chose the category to search\n1.Smart phone\n2.Laptop\n3.Cars\n4.Other\n";

	cin >> b;

	switch (b)
	{

	case 1:
	{
		search_by_category = "Smart phone";
		break;
	}

	case 2:
	{
		search_by_category = "Laptop";
		break;
	}

	case 3:
	{
		search_by_category = "Cars";
		break;
	}

	case 4:
	{
		search_by_category = "Other";
		break;
	}

	default:
		break;
	}

	for (int q = 0; q < item_counter; q++)
	{
		if (search_by_category == Items_arr[q].category)
		{
			cout << "discrebtion : " << Items_arr[q].discrebtion << endl

				<< "category : " << Items_arr[q].category << endl

				<< "starting price : " << Items_arr[q].item_price << endl

				<< "starting date : " << Items_arr[q].start_date << endl

				<< "ending date : " << Items_arr[q].end_date << endl

				<< "Item ID : " << Items_arr[q].item_ID << endl;

			break;
		}

		else
			cout << "Category not found\n";break;
	}
}

void bestSelling_category()
{
	for (int X = 0; X < buyed_item_counter;X++)
	{
		if (Items_arr[X].category == Items_arr[X + 1].category)
		{
			cout << "The best selling category is : " << Items_arr[X].category;
			X *= 100;
		}
		else
		{
			cout << "there is no best selling category yet\n";
			X *= 100;
		}
	}
}

void sell_menu()
{
	int x = 0, accept_or_refuse = 0;
	cout << "~SALE_!\n";

	cout << "press (1) to add a new item\nPress (2) to show the sold items\nPress (0) for the first menu\n";
	cin >> x;

	system("cls");

	if (x == 1)
	{
		adding_item();

		item_counter++;

		Verification_loop_counter *= 0;

		system("cls");
	}
	else if (x == 2)
	{
		cout << "showing the the sold items\n";
		for (int z = 0; z < item_counter; z++)
		{
			if (Item_selected == Items_arr[z].item_ID)
			{
				cout << Item_selected << "This item has been sold to : " << User_ID << endl;
				Available = false;
				Status = false;
			}
			else
				cout << "No sold items yet \n";
			Verification_loop_counter *= 0;
		}


	}


	else if (x == 0)
	{

		system("cls");
	}
}

void buy_menu()
{
	int User_Choice = 0;
	cout << "~BUY_!";
	cout << "\npress (1) to show items\nPress (2) to serch via category\npress (3) to show buyed items\npress (4) to show the best selling category\nPress (0) for the first menu\n";
	cin >> User_Choice;

	system("cls");

	if (User_Choice == 1)
	{
		show_items();

		cout << "press (1) to buy\npress (0) to exit\n";
		cin >> Item_selected;

		if (Item_selected == 1)
		{
			cout << "enter the item ID to buy the item\n";

			cout << "Item ID : ";
			cin >> Item_selected;

			cout << "Enter your ID : ";
			cin >> User_ID;

			feedback();

			cout << "successfully buyed\n";
			buyed_item_counter++;
			Available == false;
		}
		else
			system("cls");
	}

	else if (User_Choice == 2)
	{

		catigory_search();

	}

	else if (User_Choice == 3)
	{
		if (Available == false)
		{
			cout << Item_selected << " item has been buyed\n";
		}
		else
		{
			cout << "Nothing yet\n";
		}
	}

	else if (User_Choice == 4)
	{
		bestSelling_category();
	}

	else if (User_Choice == 0)
	{
		system("cls");
	}

}
