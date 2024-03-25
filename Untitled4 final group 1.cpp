#include<iostream>
#include<conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 
#include <cstdlib>  
#include <ctime>  

int x=0;
using namespace std;

#ifndef nullptr
#define nullptr NULL
#endif

class Homepage {
public:
    static void display() {
        cout << "\tWelcome to QUIZGAME\n"<<endl;
        cout << "\t CLICK 1 TO CONTINUE...."<<endl;
    }
};

class User {
private:
    string username;
    string password;

public:
    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}

    const string& getUsername() const {
        return username;
    }

    const string& getPassword() const {
        return password;
    }

    bool checkCredentials(const string& uname, const string& pwd) const {
        return (username == uname && password == pwd);
    }

    bool isValidUsername() const {
        int count_digits = 0;
        for (size_t i = 0; i < username.length(); ++i) {
            if (isdigit(username[i])) {
                count_digits++;
            }
        }
        return (count_digits >= 2);
    }

    bool isValidPassword() const {
        if (password.length() >= 8) {
            bool hasSpecialChar = false;
            for (size_t i = 0; i < password.length(); ++i) {
                if (!isalnum(password[i])) {
                    hasSpecialChar = true;
                    break;
                }
            }
            return hasSpecialChar;
        }
        return false;
    }
};

class UserDatabase {
private:
    vector<User> users;

public:
    void addUser(const string& uname, const string& pwd) {
        User newUser(uname, pwd);
        users.push_back(newUser);
        cout << "User '" << uname << "' registered successfully!\n";
    }

    User* findUser(const string& uname) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].getUsername() == uname) {
                return &users[i];
            }
        }
        return nullptr;
    }

    void saveToFile() {
        ofstream file("users.txt", ios::out | ios::app); 
        if (file.is_open()) {
            for (size_t i = 0; i < users.size(); ++i) {
                file << users[i].getUsername() << "," << users[i].getPassword() << "\n";
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void loadFromFile() {
        ifstream file("users.txt");
        if (file.is_open()) {
            string uname, pwd;
            while (getline(file, uname, ',') && getline(file, pwd)) {
                addUser(uname, pwd);
            }
            file.close();
        }
    }
};

class RegistrationSystem {
private:
    UserDatabase database;

public:
    RegistrationSystem() {
        database.loadFromFile(); 
    }

    ~RegistrationSystem() {
        database.saveToFile(); 
    }

    void registerUser() {
        bool validRegistration = false;
        while (!validRegistration) {
            string username, password;
            cout << "Enter username: "<<endl;
            cin >> username;
            cout << "Enter password: "<<endl;
            cin >> password;

            if (isValidRegistration(username, password)) {
                database.addUser(username, password);
                validRegistration = true;
            } else {
                cout << "Invalid username or password format! Please try again.\n";
            }
        }
    }

    bool isValidRegistration(const string& username, const string& password) const {
        User tempUser(username, password);
        return (tempUser.isValidUsername() && tempUser.isValidPassword());
    }
};
class QuizGame
{
	public:
	void header()
{
	
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
	cout<<"\t\t\t\t\t QUIZ GAME  "<<endl;
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
	cout<<"\t\t\t\t\t LEVEL 1 "<<endl;
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
}
void footer()
{
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
	cout<<"\t\t\t\t\t FINAL RESULT "<<endl;
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
}
void user()
{
	char ch1[100];
	cout<<"\t Guest Enter Your Name : "<<endl;
	cin>>ch1;
	cout<<" \t Welcome "<<ch1<<endl;
}
void results(){
        int totalQuestions = 25; 
        int totalMarks = totalQuestions * 10; 
        cout << "\n\tYour Final Score: " << x << " out of " << totalMarks << "\n";

        if (x >= totalMarks / 2) {
            cout << "\n\tCongratulations! You have successfully completed all levels.\n";
        } else {
            cout << "\n\tSorry! You did not score enough to pass all levels.\n";
        }
        ofstream resultFile("results.txt", ios::out | ios::app);
        if (resultFile.is_open()) {
        resultFile << "Final Score: " << x << " out of " << totalMarks << "\n";
        resultFile << (x >= totalMarks / 2 ? "Congratulations! You have successfully completed all levels." : "Sorry! You did not score enough to pass all levels.") << "\n";
        resultFile.close();
            cout << "\n\tResults saved to 'results.txt'.\n";
        } else {
            cout << "\n\tUnable to open results file!\n";
        }
    }
	
};

int main()
{	
	RegistrationSystem regSystem;
    regSystem.registerUser();
    
    char choice;
    do{
        Homepage::display();
        cin >> choice;

        switch (choice) {
            case '1':
            	cout<<"!!!!!!!!!!!!!!!!!! WELCOME TO GAME !!!!!!!!!!!!!!!!!!!"<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
        while(choice != '1');
    
		getch();
    
	char ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11;
	QuizGame obj1,obj2,obj3,obj4;
	obj1.user();
	obj2.header();
	cout<<"\t Q1. Which of the following is ' THE HOLY  LAND'? \n\t a.Jerusalem \n\t b.Mathura \n\t c.Mecca  "<<endl;
	cin>>ch2;
	if(ch2=='c')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x<<endl;
		cout<<" \t Press Enter! ";
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q2. Which of the following is called as ' THE ROOF OF THE WORLD'? \n\t a.Nepal \n\t b.Rome \n\t c.Tibet "<<endl;
	cin>>ch2;
	if(ch2=='c')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;

	}
else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q3. Which of the following is called as ' THE LAND OF RISING SUN'? \n\t a.Chicago \n\t b.Japan \n\t c.Tibet"<<endl;
	cin>>ch2;
	if(ch2=='b')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q4. Which of the following is called as ' THE GIFT OF NILE'? \n\t a.Chicago \n\t b.Egypt \n\t c.Africa "<<endl;
	cin>>ch2;
	if(ch2=='b')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q5. Which of the following is called as ' THE LAND OF MIDNIGHT SUN'? \n\t a.Norway \n\t b.Japan \n\t c.Australia"<<endl;
	cin>>ch2;
	if(ch2=='a')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q6. Which of the following is called as ' THE LAND OF THUNDERBOLT'? \n\t a.Bhutan \n\t b.Canada \n\t c.Arab"<<endl;
	cin>>ch2;
	if(ch2=='a')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<" \t Q7. Which of the following is called as ' THE WINDY CITY? \n\t a.Jerusalem \n\t b.Japan \n\t c.Chicago"<<endl;
	cin>>ch2;
	if(ch2=='c')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q8. Which of the following is called as ' THE LAND OF WHITE ELEPHANTS'? \n\t a.Bangladesh \n\t b.Thailand \n\t c.India"<<endl;
	cin>>ch2;
	if(ch2=='b')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q9. Which of the following is called as ' THE CITY OF SEVEN HILLS'? \n\t a.Rome \n\t b.Nilgiri Hills \n\t c.Tibet "<<endl;
	cin>>ch2;
	if(ch2=='a')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	obj2.header();

	cout<<"\t Q10. Which of the following is called as 'THE DARK CONTIENENT'? \n\t a.Asia \n\t b.Australia \n\t c.Africa"<<endl;
	cin>>ch2;
	if(ch2=='c')
	{
		x=x+10;
		cout<<" \t Great! Your Game score is: "<<x;
		cout<<"\n \t CONGRATULATIONS!!! YOU ARE UPTO LEVEL 2.";
	}
	else
	{
	cout<<" \t Sorry wrong answer "<<endl;
	cout<<" \t Press Enter! ";
	}
	getch();
	system ("CLS");
	
	cout<<"\n \t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*";
    cout<<"\n \t\t\t\t\t Level 2";
    cout<<"\n \t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
    
    cout << "\t Q1. In the box, how many ports are open?\n\t a.6 \n\t b.2 \n\t c.none"<<endl;
    char answer1;
    cin >> answer1;
    if (answer1 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q2. What version of the squid proxy is running on the machine?\n\t a.2.3.1 \n\t b.3.5.12 \n\t c.4.23.7"<<endl;
    char answer2;
    cin>>answer2;
    if (answer2 == 'b') {
        x += 10;
        cout << " \t Great! Your Game score is:"<<x<<endl;
    } else {
        cout << " \t Sorry wrong answer "<<endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q3. How many ports will Nmap scan if the flag -p-400 was used?\n\t a.200 \n\t b.50 \n\t c.400"<<endl;
    char answer3;
    cin >> answer3;
    if (answer3 == 'c') {
        x += 10;
        cout << " \t Great! Your Game score is: "<<x<<endl;
    } else {
        cout << " \t Sorry wrong answer "<<endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q4. What is the most likely operating system this machine is running?\n\t a.Ubuntu \n\t b.macOS \n\t c.Linux"<<endl;
    char answer4;
    cin>>answer4;
    if (answer4 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is:"<<x<<endl;
    } else {
        cout << " \t Sorry wrong answer"<<endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q5. What port is the web server running on?\n\t a.3333 \n\t b.2323 \n\t c.11111"<<endl;
    char answer5;
    cin >> answer5;
    if (answer5 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is:"<<x<<endl;
    } else {
        cout << " \t Sorry wrong answer"<<endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
    
    cout<<"\n \t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*";
    cout << "\n \t\t\t\t\t Level 3";
    cout<<"\n \t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;
    
	cout << "\t Q1. What does the acronym 'SQL' stand for in the context of databases?\n\t a.Structured Query Language \n\t b.Sequence Quiz Language \n\t c.Statue Qut Language"<<endl;
    char answer6;
    cin>>answer6;
    if (answer6 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q2. In cybersecurity, what does the term 'MITM' stand for?\n\t a.Man-in-the-Mat \n\t b.Man-in-the-Middle \n\t c.Man-in-the-Meusuem"<<endl;
    char answer7;
    cin>>answer7;
    if (answer7 == 'b') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q3. What is the primary purpose of a 'honeypot' in cybersecurity?\n\t a.Triception \n\t b.Inception \n\t c.Deception"<<endl;
    char answer8;
    cin>>answer8;
    if (answer8 == 'c') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
	
    cout << "\t Q4. Which of the following is a common cryptographic hash function?\n\t a.MD5 \n\t b.MD10 \n\t c.MD2"<<endl;
    char answer9;
    cin>>answer9;
    if (answer9 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
	
    cout << "\t Q5. In the context of cybersecurity, what is a 'firewall' used for?\n\t a.Damaged \n\t b.Destroyed \n\t c.Protection"<<endl;
    char answer10;
    cin>>answer10;
    if (answer10 == 'c') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
    
    cout<<"\n \t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*";
    cout<<"\n \t\t\t\t\t Level 4";
    cout<<"\n \t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*"<<endl;

    cout << "\t Q11. What is the 'Heartbleed' vulnerability?\n\t a.Bleeding \n\t b.Attack \n\t c.Operation"<<endl;
    char answer11;
    cin>>answer11;
    if (answer11 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
    
    cout << "\t Q12. What is 'Wireshark' commonly used for in cybersecurity?\n\t a.Entry \n\t b.Analysis \n\t c.Analyst"<<endl;
    char answer12;
    cin>>answer12;
    if (answer12 == 'b') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");

    cout << "\t Q13. What does the term 'phishing' refer to in cybersecurity?\n\t a.Programming \n\t b.Engineering \n\t c.Deception"<<endl;
    char answer13;
    cin>>answer13;
    if (answer13 == 'c') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
    
    cout << "\t Q14. Which of the following is an ethical hacking technique used to find vulnerabilities in a system?\n\t a.Injection \n\t b.Penetration \n\t c.DDOS attacks"<<endl;
    char answer14;
    cin>>answer14;
    if (answer14 == 'b') {
        x += 10;
    cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    getch();
	system ("CLS");
    
    cout << "\t Q15. Which encryption algorithm is commonly used for securing web traffic (HTTPS)?\n\t a.TLS/SSL \n\t b.MDS \n\t c.TTL"<<endl;
    char answer15;
    cin>>answer15;
    if (answer15 == 'a') {
        x += 10;
        cout << " \t Great! Your Game score is: " << x << endl;
    } else {
        cout << " \t Sorry wrong answer " << endl;
        cout<<" \t Press Enter! ";
    }
    
    getch();
	system ("CLS");
	obj3.footer();
	obj4.results();
	getch();
 	return 0;
}
