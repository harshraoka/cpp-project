#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<vector>
using namespace std;
class employee{
public:
	int id;
	int no_of_projects;
	int apraisal_score;
	string name;
	double salary;
	
	employee(){
		this->name=name;
		this->id=id;
		this->salary=salary;
		this->no_of_projects=no_of_projects;
		this->apraisal_score=apraisal_score;
		}

	virtual void input(){
		cout<<endl;
		system("cls");
		cout<<"\n\n\t\t\t\t Add a new employee";
		cout<<"\nNow getting the deatails "<<endl;
		cout<<"Enter the name :"<<endl;
		cin>>name;
		cout<<"Enter "<<name<<"'s  id :"<<endl;
		cin>>id;
		cout<<"Enter "<<name<<"'s salary :"<<endl;
		cin>>salary;
		cout<<"Enter the number of project "<<name<<" has finished: "<<endl;
		cin>>no_of_projects;
		cout<<"Enter the apraisal score of "<<name<<":"<<endl;
		cin>>apraisal_score;
		}

	virtual void display(){
		cout<<"\n"<<endl;
 		cout<<"The name of the employee is : "<<name<<endl;
 		cout<<"The ID of "<<name<<" is : "<<id<<endl;
 		cout<<"The salary of "<<name<<" is :"<<salary<<endl;
 		cout<<name<<" has completed "<<no_of_projects<<" projects."<<endl;
 		cout<<"The appraisal score of "<<name<<" is : "<<apraisal_score<<endl;
		}
	
};


class manager : public employee{
	public:
	
	virtual void input()
 	{
 		system("cls");
 		fstream file;
	 	int id,no_of_projects,apraisal_score,salary;
		string name,type;
 		cout<<"\n\n\t\t\t\t Add a new Manager";
 		cout<<"\n\n Enter the name of the Manager : ";
 		cin>>name;
 		cout<<"\n\n Enter the ID of "<<name<<" : ";
 		cin>>id;
 		cout<<"\n\n Enter the salary of "<<name<<" : ";
 		cin>>salary;
 		cout<<"\n\n Enter the number of projects the "<<name<<" has finished : ";
 		cin>>no_of_projects;
 		cout<<"\n\n Enter the apraisal score of "<<name<<"  : ";
 		cin>>apraisal_score;
 		file.open("D://manager.txt",ios::out|ios::app);
 		file<<" "<<name<<" "<<id<<" "<<salary<<" "<<no_of_projects<<" "<<apraisal_score<<"\n";
 		file.close();
 	}


 	void display()
 	{
 
 		fstream file;
 		int id,no_of_projects,apraisal_score,salary;
		string name,type;
 		cout<<"\n\nShow all Managers\n";
 		file.open("D://manager.txt",ios::in);
 		if(!file)
 		{
 			cout<<"\n\n No file present....";
 		}
 		else
 		{
 			file>>name>>id>>salary>>no_of_projects>>apraisal_score;
 			
 			while(!file.eof())
 			{	
 				cout<<"\n"<<endl;
 				cout<<"The name of the manger is : "<<name<<endl;
 				cout<<"The ID of "<<name<<" is : "<<id<<endl;
 				cout<<"The salary of "<<name<<" is :"<<salary<<endl;
 				cout<<name<<" has completed "<<no_of_projects<<" projects."<<endl;
 				cout<<"The appraisal score of "<<name<<" is : "<<apraisal_score<<endl;
 			file>>name>>id>>salary>>no_of_projects>>apraisal_score;
 			}
 			file.close();
 		}
 	}
 	

void appraise_employee()
{
 		fstream file;
 		int id,no_of_projects,apraisal_score,salary;
		string name,type,temp_name;

 		file.open("D://manager.txt",ios::in);
 		if(!file)
 		{
 			cout<<"\n\n No file present....";
 		}
 		else{
 				file>>name>>id>>salary>>no_of_projects>>apraisal_score;
 				while(!file.eof())
 				{
		 			try
		 			{
							if(no_of_projects ==0){
								throw runtime_error("projects completed");
							}
							else{
								salary = salary +(no_of_projects*10);
								cout<<"\nThe new salary of "<<name<<" is :"<<salary<<endl;
							}
						}
						catch(runtime_error &e)
						{
							cout<<"\nERROR: Since "<<name<<" has done zero projects we can not appraise salary. "<<endl;
				        }
				    	file>>name>>id>>salary>>no_of_projects>>apraisal_score;
			    	}
			    }
			    file.close();
}
};

class department{
	public:
	int id;
	string name;

	department(int id,string name){
		this->id=id;
		this->name=name;
		}

	virtual void display(){
		cout<<"the department id is: "<<id<<endl;
		cout<<"the department name is: "<<name<<endl;
		cout<<endl;
		}

	virtual void appraiseemployee(employee e[20],int y)=0;
	
	~department(){}
};

class hrdepartment : virtual public department{
public:

	hrdepartment(int id,string name):department(id,name){
		this->id=id;
		this->name=name;
		}

	void display(){
		cout<<"the hrd id is :"<<id<<endl;
		cout<<"the hrd name is :"<<name<<endl;
		cout<<endl;
		}
	void appraiseemployee(employee e[20],int y){
		for(int i=0;i<y;i++){
			try{
				if(e[i].no_of_projects ==0){
					throw runtime_error("projects completed");
				}
				else{
					e[i].salary = e[i].salary +(e[i].no_of_projects*10);
					cout<<"\n The new salary of "<<e[i].name<<" is "<<e[i].salary<<endl;
				}
			}
			catch(runtime_error &e){
				cout<<"EROR: Since employee has completed 0 projects,salary cannot be appraised."<<endl;
	        }
	    }
	}
	void find_best_performer(employee e[20],int y)
	{
		employee temp = e[0];
		for (int i = 0; i < y; ++i)
		{
			if (e[i].apraisal_score>temp.apraisal_score)
			{
				temp=e[i];
			}
		}
		cout<<temp.name<<endl;
	}
};

class supportstaff{
public:
	int ID;
	string name;
	int salary;

	supportstaff(){
		this->ID=ID;
		this->name=name;
		this->salary=salary;
	}
	void getinput(){
		cout<<endl;
		cout<<"Enter the name"<<endl;
		cin>>name;
		cout<<"Enter the ID of "<<name<<endl;
		cin>>ID;
		cout<<"Enter the salary of "<<name<<endl;
		cin>>salary;
	}

	void Display(){
		cout<<endl;
		cout<<"The name of the staff is "<<name<<endl;
		cout<<"The ID "<<name<<" is "<<ID<<endl;
		cout<<"The salary "<<name<<" is"<<salary<<" rupees"<<endl;
	}
};
main(){
	int e_num=0;
	int choice,choice1;
	string x,x1;
	hrdepartment *hrd = new hrdepartment(1080,"AIML");
	vector<supportstaff> s;

	employee* e = new employee[20];
	
	manager m;
	cout<<"\n\n\t\t\t\tThis is an Enterprise Resource Management Software\n";
	cout<<"\n\n\t\t\t\tCreated by:-\n";
	cout<<"\n\n\t\t\t\tHarsh Raoka (20BAI10180)\n";
	cout<<"\n\n\t\t\t\tTejas Joharapurkar (20BAI10148)\n";
	cout<<"\n\n\t\t\t\tAnanya Kaul (20BAI10077)\n";

	system("pause");

	p:

	system("cls");
 		cout<<"\n\n\t\t\t\tEmployee Management software";
 		cout<<"\n\n 1. Add New Employee";
 		cout<<"\n 2. Add New Manager";
 		cout<<"\n 3. Add New Support Staff";
 		cout<<"\n 4. Display All the Employee";
 		cout<<"\n 5. Appraise all emplyees";
 		cout<<"\n 6. Find best performer";
 		cout<<"\n 7. Exit";
 		cout<<"\n\n Your Choice : ";
 		cin>>choice;
 		switch(choice)
	{
		case 1:
			
			system("cls");
			
				do
				{
				system("cls");

				e[e_num].input();
				e_num++;
				cout<<"\n\n Do you want to add another Employee (y/n) : ";
				cin>>x;
				}
				while(x=="y");
			
			cout<<"\n\nPress ENTER to go back to the main menu "<<endl;
			break;

		case 2:
			
			system("cls");
			
				do
				{
				system("cls");

				m.input();
				cout<<"\n\n Do you want to add another Manager (y/n) : ";
				cin>>x1;
				}
				while(x1=="y");
			
			cout<<"\n\nPress ENTER to go back to the main menu "<<endl;
			break;

		case 3:
			
			system("cls");
			
				do
				{
				system("cls");

				s.push_back(supportstaff());
				s[s.size()-1].getinput();
				cout<<"\n\n Do you want to add another Support staff (y/n) : ";
				cin>>x1;
				}
				while(x1=="y");
			
			cout<<"\n\nPress ENTER to go back to the main menu "<<endl;
			break;

		
				
		case 4:
			system("cls");
			cout<<"\n\n\t\t\t\tDisplaying All Employees\n";
			cout<<"\nShowing all employees"<<endl;
			for (int i = 0; i < e_num; ++i)
			{
				e[i].display();
			}
			m.display();
			cout<<"\nShowing all Support staff"<<endl;
			for (int i = 0; i < s.size(); ++i)
			{
				s[i].Display();
			}

			cout<<"\nPress ENTER to go back to the main menu "<<endl;
			break;


		case 5:
			system("cls");
			cout<<"\nAppraising employees \n";
			hrd->appraiseemployee(e,e_num);
			m.appraise_employee();
			break;
	
		case 6:
			system("cls");
			cout<<"\nThe best performing employee is \n";
			hrd->find_best_performer(e,e_num);
			
			cout<<"\n\nPress ENTER to go back to the main menu "<<endl;

			break;

		case 7:
			exit(0);
		default:
			cout<<"\n\n Invalid choice...Please try again";
	}
	getch();
	goto p;
delete e,m,hrd;

}