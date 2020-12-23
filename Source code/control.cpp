/*

# Control Panel for Debian/Debian Based Linux. 
# Copyright (C) 2019-2020 M.Anish <aneesh25861@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class control
{
 
int update_status=0,upgrade_status=0;

void list();
void search(char *);
void remove(char *);
void sremove(char *);
void aremove();
void install(char *);
void about();
void update();
void updateapp(char *);
void upgrade();
void dist_upgrade();
void pause();

public:
void menu();

};

//Method to pause the program.
void control::pause()
{
char ch;
cout<<"\nPress q to continue...\n";
cin>>ch;
}

//Method to display list of all installed packages .
void control::list()
{
cout<<"\n==== Applications Installed ====\n";
system("dpkg-query -l");
}

//Method to update system. Equivalent to apt-get update.
void control::update()
{
int x=system("sudo apt-get update");
if (x==0)
update_status=1;
}

//Method to remove obsolete/ non essential packages.
void control::aremove()
{
system("sudo apt-get autoremove");
}

//Method to display Developer Information.
void control::about()
{
cout<<"\n\n==== About ====\n\n";
cout<<"Control Panel for Debian/Debian Based Linux.\nDeveloped By: M.ANISH < aneesh25861@gmail.com >";
}

//Method to upgrade all packages.
void control::upgrade()
{
if(update_status==1)
{
int x=system("sudo apt-get upgrade");
if(x==0)
upgrade_status=1;
}
else
{
update();
upgrade();
}
}

//Method to Fully upgrade the system.
void control::dist_upgrade()
{
if(upgrade_status==1)
system("sudo apt full-upgrade");
else
{
upgrade();
dist_upgrade();
}
}

//Method to install given package.
void control::install(char a[200])
{
char cmd[250];
strcpy(cmd,"sudo apt-get install ");
strcat(cmd,a); 
if(update_status==1)
system(cmd);
else
{
update();
system(cmd);
}
}

//Method to search given package in system.
void control::search(char a[200])
{
char cmd[250];
strcpy(cmd,"apt-cache search ");
strcat(cmd,a);
system(cmd);
}

//Method to remove given package.
void control::remove(char a[200])
{
char cmd[250];
strcpy(cmd,"sudo apt-get remove ");
strcat(cmd,a);
system(cmd);
}

//Method to remove given package and associated files like configuration, logs etc.
void control::sremove(char a[200])
{
char cmd[250];
strcpy(cmd,"sudo apt-get --purge remove ");
strcat(cmd,a);
system(cmd);
}

//Method to upgrade existing package.
void control::updateapp(char a[200])
{
char cmd[250];
strcpy(cmd,"sudo apt-get --only-upgrade install ");
strcat(cmd,a);
if(update_status==1)
system(cmd);
else
{
update();
system(cmd);
}
}

//Main Menu
void control::menu()
{
int lock=0;
char msg[50],ch;
strcpy(msg,"\nEnter Application Name:"); 
system("clear");
cout<<"\n\n==== Application Manager for Debian/Debian Based Linux ====\n\n"
    <<"Menu:-\n\n"
    <<"1)Check for Software Updates.\n"
    <<"2)View Installed Applications.\n"
    <<"3)Search for an Application.\n"
    <<"4)Install an Application.\n"
    <<"5)Remove Application.\n"
    <<"6)Remove Application with Configuration Files.\n"
    <<"7)Update an Application.\n"
    <<"8)Update all Applications.\n"
    <<"9)Remove Obsolete/Unwanted Packages.\n"
    <<"10)Upgrade Distribution\n"
    <<"11)About"
    <<"\n\nEnter choice:";
cin>>lock;

switch(lock)
{

case 1: {
          update();
          pause();
          menu();
          break;
         }

case 2: {
          list();
          pause();
          menu(); 
          break;
        }

case 3: { 
           char a[100];
           cout<<msg;
           cin.get(ch);
           cin.getline(a,100);
           search(a);
           pause();
           menu();
           break;
        }

case 4: {
           char a[100];
           cout<<msg;
           cin.get(ch);
           cin.getline(a,100);
           install(a);
           pause();
           menu();
           break;
         }

case 5: {
          char a[100];
          cout<<msg;
          cin.get(ch);
          cin.getline(a,100);
          remove(a);
          pause();
          menu();
          break;
        }

case 6:{
         char a[100];
         cout<<msg;
         cin.get(ch);
         cin.getline(a,100);
         sremove(a);
         pause();
         menu();
         break;
       }

case 7: {
         char a[100];
         cout<<msg;
         cin.get(ch);
         cin.getline(a,100);
         updateapp(a);
         pause();
         menu();
         break;
         }

case 8: {
          upgrade();
          pause();
          menu();
          break;
         }

case 9: {
          aremove();
          pause();
          menu();
          break;
        }

case 10: {
        dist_upgrade();
        pause();
        menu();
        break;
        }

case 11:{
          about();
          pause();
          menu();
          break;
         }

default:{
         cout<<"\nWrong Choice!";
         pause();
         menu();
        }
}
}
          
int main()
{
control o;
o.menu();
return 0;
}

