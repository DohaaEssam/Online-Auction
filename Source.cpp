#include<iostream>
#include<string>
using namespace std;


struct sign_in
{
	int ID;
	string Email;
	string Name;
	int Password;
	int Phone_num;
	string Address;
	int points = 0;
	string list[3];
};
struct Date
{
	int Day;
	int Month;
	int Year;
};
struct Items
{
	int Member_id;
	int Item_num;
	string Category;
	int H_price;
	int L_price;
	Date S_data;
	Date E_data;
	bool status = true;
};
sign_in input();
void Feedback(sign_in);
void Market_place(Items item[]);
void Agreement(Items item[]);
void Search(Items item[]);
void Monthly_report(Items item[]);

int main()
{
	const int IT_SIZE = 3;
	int choice, b, num;
	int n = 0;
	int w = 0;
	int k = 0;
	char x, y, a, l, z, yes;
	Items item[IT_SIZE];
	sign_in Member;
	while (n <= 5)
	{
		cout << endl;
		cout << "\t\t\t WELCOME IN ONLINE AUCTION MANAGMENT SYSTEM \n";
		cout << endl;
		cout << endl;
		cout << "\t1\t SIGN UP \n";
		cout << endl;
		cout << "\t2\t MARKET PLACE \n";
		cout << endl;
		cout << "\t3\t SEARCH \n";
		cout << endl;
		cout << "\t4\t MONTHLY REPORT \n";
		cout << endl;

		cout << " Press Any Number From Above \n ";

		cin >> choice;
		switch (choice)
		{
		case 1:
			
				cout << "Do You Want To Sell Any Thing ? \n";
				cin >> x;
				if (x == 'y' || x == 'Y')
				{
					cout << "Please Full Of This Form \n";
					Member = input();
					cout << "Please Mention Three Items You Want to Sell \n";
					for (int e = 0; e < IT_SIZE; e++)
					{
						cin>>Member.list[e];
					}
					cout << "Please Identify Three Items \n";
					for (int i = 0; i < IT_SIZE; i++)
					{
						cout << "Enter Your ID \n";
						cin >> item[i].Member_id;
						cout << "Enter Item Number \n";
						cin >> item[i].Item_num;
						cout << "Enter Item Category \n";
						cin >> item[i].Category;
						cout << "Enter The Highest Price Do you Want In This Item \n";
						cin >> item[i].H_price;
						cout << "Enter The Lowest Price You Can Accept For Your Item \n";
						cin >> item[i].L_price;
						cout << "The Starting Date To Show This Item by Day, Month And Year \n ";
						cin >> item[i].S_data.Day;
						cin >> item[i].S_data.Month;
						cin >> item[i].S_data.Year;
						cout << "The Last Date To Show This Item In Store By Day, Month And Year \n ";
						cin >> item[i].E_data.Day;
						cin >> item[i].E_data.Month;
						cin >> item[i].E_data.Year;
					}
					cout << " Do You Want To Leave Feedback \n ";
					cin >> y;
					cout << endl;
					if (y == 'y' || y == 'Y')
					{
						Feedback(Member);
					}
					else
						cout << " Thank You For Using Our System \n";
				}
				else if (x == 'n' || x == 'N')
				{
					cout << "Do You Want To Buy Any Thing \n";
					cin >> a;
				
						if (a == 'y' || a == 'Y')
						{
							cout << "Please Full Of This Form \n";
							Member = input();
							cout << "1\t To Show Market Place \n";
							cout << endl;
							cout << "2\t To Make Search \n";
							cin >> b;
							if (b == 1)
							{
								Market_place(item);
								cout << "Choose The Item Number You Want To Buy \n";
								cin >> num;
								
									
										cout << "Do You Want To Buy This Item With This Price \n ";
										cin >> l;
										if (l == 'y' || l == 'Y')
										{
											cout << "The Transaction Process Is Complete \n ";
											cout << endl;
											cout << "Congratulations ! \n";
											for (int j = 0; j < IT_SIZE; j++)
											{
												if (num == item[j].Item_num)
													item[j].status = false;
											}
											cout << " Do You Want To Leave Feedback \n ";
											cin >> z;
											if (z == 'y' || z == 'Y')
											{
												Feedback(Member);
											}
											else
												cout << " Thank You For Using Our System \n";
										}
										else
										{
											Agreement(item);
											cout << " Do You Want To Leave Feedback \n ";
											cin >> z;
											if (z == 'y' || z == 'Y')
											{
												Feedback(Member);
											}
											else
												cout << " Thank You For Using Our System \n";

										}
									
								
									
							}
							else if (b == 2)
							{
								Search(item);
								cout << "Do You Want To Buy This Item ? \n";
								cin >> yes;
									if (yes == 'y' || yes == 'Y')
									{
										cout << "Do You Want To Buy This Item With This Price \n ";
										cin >> l;
										if (l == 'y' || l == 'Y')
										{
											cout << "The Transaction Process Is Complete \n ";
											cout << endl;
											cout << "Congratulations ! \n";
											for (int j = 0; j < IT_SIZE; j++)
											{
												if (num == item[j].Item_num)
													item[j].status = false;
											}
											
										}
										else
					
											Agreement(item);
									}
								
									cout << " Do You Want To Leave Feedback \n ";
									cin >> z;
									cout << endl;
									if (z == 'y' || z == 'Y')
									{
										Feedback(Member);
									}
									else
										cout << " Thank You For Using Our System \n";
							}
							else
							{
								cout << "Your Choice Does Not Exist \n";
								cout << endl;
								cout << "Please ReEnter Your Choice \n ";
							}
						}
						else
							cout << " Please ReEnter Your Answer\n";
				}
				else
					cout << "Please ReEnter Your Answer ! \n";
				
				break;

        case 2:
			Market_place(item);
			cout << "You Can Not Buy Any Thing Unless You Have an Email \n";
			break;
		case 3:
			Search(item);
			cout << endl;
			cout << "You Can Not Buy Any Thing Unless You Have an Email \n";
			break;
		case 4:
			Monthly_report(item);
			cout << endl;
			break;
		default:
			cout << "Incorrect Choice ! \n";
			cout << endl;
			break;
			
		}
		n++;
	}
}

sign_in input()
{
	sign_in Members;
	cout << "Enter Your ID \n";
	cin >> Members.ID;
	cout << "Enter Your Email \n";
	cin >> Members.Email;
	cout << "Enter Your Name \n";
	cin >> Members.Name;
	cout << "Enter Your Password \n";
	cin >> Members.Password;
	cout << "Enter Your Phone Number \n";
	cin >> Members.Phone_num;
	cout << "Enter Your Dilavery Address \n";
	cin >> Members.Address;
	return Members;
}
void Feedback(sign_in Member)
{
	int Id;
	string Comment;
	int Rate;
	cout << " Enter The ID Of The Other Member \n";
	cin >> Id;
	cout << " Please Enter Your Rate About This Member \n";
	cin >> Rate;
	for (int i = 0; i < 5; i++)
	{
		if (Id == Member.ID)
		{
			if (Rate >= 3 && Rate<=5)
				Member.points++;
		}
	}
	cout << " Please Leave Comment About The Other Member \n";
	cin >> Comment;

}
void Market_place(Items item[])
{
	const int SIZE = 3;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Member ID:" << item[i].Member_id << endl;
		cout << "Item Number:" << item[i].Item_num << endl;
		cout << "Item Category:" << item[i].Category << endl;
		cout << "Item Price:" << item[i].H_price << endl;
		if (item[i].status == true)
			cout << "Avalable " << item[i].status;
		else
			cout << "Sold" << item[i].status;
		cout << endl;
		cout << "********************************";
		cout << endl;
	}
}
void Agreement(Items item[])
{
	const int SIZE = 3;
	int Num, Suggest;
	cout << "Enter The Item Number And Your Suggested Price \n";
	cin >> Num;
	cin >> Suggest;
	for (int i = 0; i < SIZE; i++)
	   if (Suggest >= item[i].L_price&& Suggest <= item[i].H_price)
		    item[i].status = false;
		    cout << "The Transaction Process Is Complete \n ";
	     	cout << "Congratulations ! \n";
}
void Search(Items item[])
{
	const int SIZE = 3;
	string Cat; 
	int P, x =0;
	int choice;
	
	cout << "1\t If You Want To Search by The Category Name \n ";
	cout << "2\t If You Want To Search By The Price And The Category Name \n ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "What Category Did You Search For ? \n";
		cin >> Cat;
		for (int i = 0; i < SIZE; i++)
		{
			if (Cat == item[i].Category)
			{
				cout << "Member ID:" << item[i].Member_id << endl;
				cout << "Item Number:" << item[i].Item_num << endl;
				cout << "Item Category:" << item[i].Category << endl;
				cout << "Item Price:" << item[i].H_price << endl;
				if (item[i].status == true)
					cout << "Avalable " << item[i].status;
				else
					cout << "Sold" << item[i].status;
				cout << endl;
				cout << "********************************";
				cout << endl;
			}
		}

		break;
	case 2:
		cout << "What Is The Price And Category Did You Search For ?\n";
		cin >> P;
		cin >> Cat;
		for (int x = 0; x < SIZE; x++)
		{
			if (Cat == item[x].Category&& P == item[x].H_price)
			{
				cout << "Member ID:" << item[x].Member_id << endl;
				cout << "Item Number:" << item[x].Item_num << endl;
				cout << "Item Category:" << item[x].Category << endl;
				cout << "Item Price:" << item[x].H_price << endl;
				if (item[x].status == true)
					cout << "Avalable " << item[x].status;
				else
					cout << "Sold" << item[x].status;
				cout << endl;
				cout << "********************************";
				cout << endl;
			}
		}
		break;
	default:
		cout << "Please ReEnter Your Choice \n ";
		break;
	}
}
void Monthly_report(Items item[])
{
	const int SIZE = 3;
	int x, y, z, a, b;
	int Top_day1 = 0;
	int Top_day2 = 0;
	cout << "Which Month Would You Like To Know Its Top Category ?\n";
	cin >> z;
	for (int i = 0; i < SIZE; i++)
	{
		a = item[i].S_data.Day;
		b = item[i].S_data.Month;
		x = item[i].E_data.Day;
		y = item[i].E_data.Month;
		if (Top_day1 < x && y == z && Top_day2 <a && b==z )
		{
			Top_day1 = x;
			Top_day2 = a;
		}
	}
	for (int j = 0; j < SIZE; j++)
	{
		if (Top_day1 == item[j].E_data.Day && z == item[j].E_data.Month && Top_day2 == item[j].S_data.Day)
			cout << "The Top Category This Month is " << item[j].Category;
		cout << endl;
	}
}