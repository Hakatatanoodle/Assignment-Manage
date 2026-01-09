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
void updateAssignment(std::vector<Subject>& subjects);
void deleteAssignment();
void saveAndExit();
int chooseSubject(std::vector<Subject>& subjects);
int chooseAssignment(std::vector<Subject>& subjects);

int main()
{
  int choice;
  std::cout<<"\n======Assignment Manager======\n";
  std::vector<Subject> subjects;
  do
  {
  std::cout<<"1.Add Subject\n";
  std::cout<<"2. Add Assignment\n";
  std::cout<<"3. View Assignments\n";
  std::cout<<"4. Update Assignment\n";
  std::cout<<"5. Delete Assignment\n";
  std::cout<<"6. Save and Exit\n";
  std::cout<<"choose: ";
  std::cin>>choice;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    updateAssignment(subjects);
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
    if (subjects.empty())
    {
        std::cout << "No subjects!";
        return -1;
    }

    std::cout << "\nChoose a subject:\n";
    for (size_t i = 0; i < subjects.size(); i++)
    {
        std::cout << i + 1 << ". " << subjects[i].name << '\n';
    }

    std::string input;
    std::getline(std::cin >> std::ws, input);

    int subIndex;
    try
    {
        subIndex = std::stoi(input) - 1;
    }
    catch (...)
    {
        std::cout << "Invalid input!";
        return -1;
    }

    if (subIndex < 0 || subIndex >= subjects.size())
    {
        std::cout << "Out of range!";
        return -1;
    }

    return subIndex;
}
int chooseAssignment(std::vector<Subject>& subjects)
{
  int subIndex = chooseSubject(subjects);
  if(subIndex == -1)
  {
    std::cout<<"Indexing error!";
    return -1;
  }
  if(subjects[subIndex].assignments.size()<=0) 
  {
    std::cout<<" NO assignments for this subject!"; 
    return -1;
  }
  std::cout << "Choose the assignment: " << std::endl;
  for(size_t i=0; i<subjects[subIndex].assignments.size();i++)
  {
    std::cout<<i+1<<"."<<subjects[subIndex].assignments[i].title<<std::endl;
  }
  std::string aInput;
  getline(std::cin,aInput);
  int assIndex;
    try
    {
        assIndex = std::stoi(aInput) - 1;
    }
    catch (...)
    {
        std::cout << "Invalid input!";
        return -1;
    }

    if (assIndex < 0 || assIndex >= subjects.size())
    {
        std::cout << "Out of range!";
        return -1;
    }

    return assIndex;
}

void addSubject(std::vector<Subject>& subjects)
{
  std::string Sname;
  std::cout<<"Enter subject name:\n"<<std::endl;
  std::getline(std::cin,Sname);
  Subject Sub;
  Sub.name = Sname;
  subjects.push_back(Sub);
}
void addAssignment(std::vector<Subject>& subjects)
{
  Assignment a;
  int subjectIndex;
  subjectIndex = chooseSubject(subjects);
  if(subjectIndex == -1) 
  {
    std::cout<<"Indexing error";
    return;
  }
  std::cout << "Enter assignment title:" << std::endl;
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
void updateAssignment(std::vector<Subject>& subjects)
{
  int assignmentIndex;
  assignmentIndex = chooseAssignment(subjects);
  if( assignmentIndex == -1 )
  {
    std::cout<<"Indexing error!";
    return ;
  }

  std::cout << "choose what do you want to update: " << std::endl;
  std::cout << "1.Assignment title" << std::endl;
  std::cout << "2.Assignment description" << std::endl;
  std::cout << "3.Assignment deadline" << std::endl;
  std::cout << "4.Assignment status" << std::endl;

  std::string aChoice;
  getline( std::cin, aChoice );




}
void deleteAssignment()
{
  std::cout<<"Delete Assignment\n"<<std::endl;
}
void saveAndExit()
{
  std::cout<<"Saving and Exiting\n"<<std::endl;
}

