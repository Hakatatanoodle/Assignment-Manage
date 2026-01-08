//Student Assignment manager
#include<iostream>
#include<vector>
#include<string>
#include<limits>
struct Assignment
{
  std::string title;
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
void viewAssignments(std::vector<Subject>& subjects);
void updateAssignment();
void deleteAssignment();
void saveAndExit();
int chooseSubject(std::vector<Subject>& subjects);

int main()
{
  int choice;
  std::vector<Subject> subjects;

  do
  {
  std::cout<<"\n======Assignment Manager======\n";
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
    viewAssignments(subjects);
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
}while(choice!=6);
  return 0;
}
//function definitions
int chooseSubject(std::vector<Subject>& subjects)
{
 std::string input;
 if(subjects.size()<=0) {std::cout<<"No subjects!"; return -1;}
 std::cout<<"\nChoose a subject\n:"; 
 for(size_t i=0;i<subjects.size();i++)
 {
  std::cout<<i+1<<"."<<subjects[i].name<<std::endl;
 }
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
 getline(std::cin,input);
 return std::stoi(input)-1;
}
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
  Assignment a;
  int subjectIndex;
  subjectIndex = chooseSubject(subjects);
  if(subjectIndex == -1) return;
  std::cout<<"Enter assignment title:"<<std::endl;
  std::getline(std::cin,a.title);
  std::cout<<"Enter the description of the assignment: "<<std::endl;
  std::getline(std::cin,a.description);
  std::cout<<"Enter the deadline of the assignment: "<<std::endl;
  std::getline(std::cin,a.deadline);
  a.status = false;//default status
  subjects[subjectIndex].assignments.push_back(a);
}

void viewAssignments(std::vector<Subject>& subjects)
{
  //choose subject
  int subjectIndex;
  subjectIndex = chooseSubject(subjects);
  if(subjectIndex == -1) return;
  if(subjects[subjectIndex].assignments.size()<=0) std::cout<<"No assignments!";
  else
  {
    //print assignments
    std::cout<<"Title\t"<<"Description\t"<<"Deadline\t"<<"Status\n";
    std::cout<<"--------------------------------------------------"<<std::endl;
    for(std::size_t i=0;i<subjects[subjectIndex].assignments.size();i++)
    {
      std::cout<<subjects[subjectIndex].assignments[i].title<<"\t";
      std::cout<<subjects[subjectIndex].assignments[i].description<<"\t\t";
      std::cout<<subjects[subjectIndex].assignments[i].deadline<<"\t";
      if(subjects[subjectIndex].assignments[i].status) std::cout<<"Done\t"<<std::endl;
      else std::cout<<"Not Done\t"<<std::endl;
    }
  }
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

