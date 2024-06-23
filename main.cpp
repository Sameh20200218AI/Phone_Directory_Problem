#include <iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
struct node
{
    string first_name,last_name,phone_number;
};
class PhoneDirectory
{
private:
    vector <node>Directory;

public:
    PhoneDirectory(){}

    string filter_string(string s)
    {
       for(int i=0;i<s.size();i++)
       {
           s[i] = tolower(s[i]);
       }
       string new_str ="";
       for(int i=0;i<s.size();i++)
       {
          if(s[i]==' ')
            continue;
          else
            new_str += s[i];
       }
       return new_str;
    }
    void add()
    {
        string f_name, l_name, ph_number;
        cout <<"Please , Enter first name and last name , phone number for an entry : "<<endl;
        cin >>f_name>>l_name>>ph_number;
        node newNode;

        newNode.first_name =filter_string( f_name);
        newNode.last_name = filter_string(l_name);
        newNode.phone_number =filter_string( ph_number);
        Directory .push_back(newNode);

    }
    void print_()
    {
        for(int i=0;i <Directory.size();i++)
        {
            cout <<"For "<<i+1<<" st entry in directory , First Name is : "<<Directory[i].first_name <<" And Last Name is : "<<Directory[i].last_name<< " And Phone Number is : " <<Directory[i].phone_number<<endl;
        }
    }
    void search_by_firstName()
    {
        string f_name;
        cout <<"Enter first name : "<<endl;
        cin >> f_name;
        f_name = filter_string(f_name);
        bool flag= false;
        for(int i=0;i<Directory.size();i++)
        {

            if(Directory[i].first_name==f_name)
            {
                flag = true;
                cout <<"This entry is exist in directory ."<<endl;
                cout <<"The informations about this entry are : "<<endl;
                cout <<" An entry in directory , First Name is : "<<Directory[i].first_name <<" And Last Name is : "<<Directory[i].last_name<< " And Phone Number is : " <<Directory[i].phone_number<<endl;
            }
        }
        if(flag == false)
        {
            cout <<"This entry does not exist in directory ."<<endl;
        }
    }
    void search_by_phoneNumber()
    {
        string Ph_number;
        cout <<"Enter phone number : "<<endl;
        cin >> Ph_number;
        Ph_number = filter_string(Ph_number);
        bool flag =false;
        for(int i=0;i<Directory.size();i++)
        {

            if(Directory[i].phone_number==Ph_number)
            {
                flag = true;
                cout <<"This entry is exist in directory ."<<endl;
                cout <<"The informations about this entry are : "<<endl;
                cout <<" An entry in directory , First Name is : "<<Directory[i].first_name <<" And Last Name is : "<<Directory[i].last_name<< " And Phone Number is : " <<Directory[i].phone_number<<endl;
            }
        }
        if(flag == false)
        {
            cout <<"This entry does not exist in directory ."<<endl;
        }
    }
    void sort_by_firstName()
    {
         string f_name, l_name, ph_number;
         for(int i=0;i<Directory.size();i++)
         {
             for(int j=0;j<Directory.size();j++)
             {
                 if(Directory[j].first_name >Directory[i].first_name)
                 {
                     f_name = Directory[j].first_name;
                     l_name = Directory[j].last_name;
                     ph_number = Directory[j].phone_number;

                     Directory[j].first_name = Directory[i].first_name;
                     Directory[j].last_name = Directory[i].last_name;
                     Directory[j].phone_number = Directory[i].phone_number;

                     Directory[i].first_name = f_name;
                     Directory[i].last_name = l_name;
                     Directory[i].phone_number = ph_number;
                 }
             }
         }
         cout <<"The list after sorting is : "<<endl;
         print_();
    }
    void delete_by_firstName()
    {
        vector<node> Directory_after_deletion;
        string f_name;
        cout <<"Please , Enter first name : "<<endl;
        cin >> f_name;
        f_name = filter_string(f_name);
        for(int i=0;i<Directory.size();i++)
        {
            if(Directory[i].first_name==f_name)
            {
                continue;
            }
            else
            {
                Directory_after_deletion.push_back(Directory[i]);
            }
        }
        Directory = Directory_after_deletion;
    }
    void delete_by_PhoneNumber()
    {
        vector<node> Directory_after_deletion;
        string ph_num;
        cout <<"Please , Enter Phone number : "<<endl;
        cin >> ph_num;
        ph_num = filter_string(ph_num);
        for(int i=0;i<Directory.size();i++)
        {
            if(Directory[i].phone_number==ph_num)
            {
                continue;

            }
            else
            {
                Directory_after_deletion.push_back(Directory[i]);
            }
        }
        Directory = Directory_after_deletion;
    }


};
int main()
{
    PhoneDirectory obj;
    while(true)
    {
        int choice;
        cout <<endl;
        cout <<"1. Add an entry to the directory ."<<endl;
        cout <<"2. Search by first name ."<<endl;
        cout <<"3. Search by phone number ."<<endl;
        cout <<"4. Delete an entry from the directory by first name ."<<endl;
        cout <<"5. Delete an entry from the directory by phone number ."<<endl;
        cout <<"6. List All entries in phone directory ."<<endl;
        cout <<"7. Sort by first name in the directory ."<<endl;
        cout <<"8. Exit form this program ."<<endl;
         cout <<endl<<"Please , enter your choice : "<<endl;
         cin >>choice;
         while(choice <1 || choice >8)
         {
             cout<<"Please , enter your choice again : "<<endl;
             cin >>choice;
         }
         if(choice ==1)
            obj.add();
         else if(choice ==2)
            obj.search_by_firstName();
         else if(choice == 3)
            obj.search_by_phoneNumber();
         else if(choice ==4)
            obj.delete_by_firstName();
         else if(choice ==5)
            obj.delete_by_PhoneNumber();
         else if(choice ==6)
            obj.print_();
         else if(choice ==7)
            obj.sort_by_firstName();
        else if(choice ==8)
            return 0;
    }
    return 0;
}
