//Student Assignment manager
#include<iostream>
#include<vector>
#include<string>
struct Assignment
{
  std::string description;
  std::string deadline;
  bool status;
};
struct Subject
{
  std::string name;
  std::vector<Assignment> assignments;
};
//function prototypes
void addSubject(std::vector<Subject>& subjects);
void addAssignment(std::vector<Subject>& subjects);
void viewAssignments();
void updateAssignment();
void deleteAssignment();
void saveAndExit();
int main()
{
  int choice;
  std::vector<Subject> subjects;

  while(choice!=6)
  {
  std::cout<<"======Assignment Manager======\n";
  std::cout<<"1.Add Subject\n";
  std::cout<<"2. Add Assignment\n";
  std::cout<<"3. View Assignments\n";
  std::cout<<"4. Update Assignment\n";
  std::cout<<"5. Delete Assignment\n";
  std::cout<<"6. Save and Exit\n";
  std::cout<<"choose: ";
  std::cin>>choice;
  switch(choice)
  {
    case 1: 
    addSubject(subjects);
    break;
    case 2:
    addAssignment(subjects);
    break;
    case 3:
    viewAssignments();
    break;
    case 4:
    updateAssignment();
    break;
    case 5:
    deleteAssignment();
    break;
    case 6:
    saveAndExit();
    break;
    default:
    std::cout<<"Invalid choice\n";
    break;
  }
}
  return 0;
}
//function definitions
void addSubject(std::vector<Subject>& subjects)
{
  std::cout<<"Enter subject name:\n"<<std::endl;
  std::string Sname;
  std::cin>>Sname;
  Subject Sub;
  Sub.name = Sname;
  subjects.push_back(Sub);
}
void addAssignment(std::vector<Subject>& subjects)
{
  std::string input;
  int subIndex;
  if(subjects.size()<=0) std::cout<<"No subjects!";
  for(int i=0;i<subjects.size();i++)
  {
    std::cout<<i+1<<"."<<subjects[i].name<<std::endl;
  }
  std::cout<<"Choose subject: ";
  getline(std::cin,input);
  subIndex = std::stoi(input) - 1;
}

void viewAssignments()
{
  std::cout<<"Assignments\n"<<std::endl;
}
void updateAssignment()
{
  std::cout<<"Update Assignment\n"<<std::endl;
}
void deleteAssignment()
{
  std::cout<<"Delete Assignment\n"<<std::endl;
}
void saveAndExit()
{
  std::cout<<"Saving and Exiting\n"<<std::endl;
}

