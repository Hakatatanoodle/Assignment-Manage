//Student Assignment manager
#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<fstream>

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
struct Index
{
  int subjectIndex;
  int assignmentIndex;

};
//function prototypes
void addSubject(std::vector<Subject>& subjects);
void addAssignment(std::vector<Subject>& subjects);
void viewAssignments(std::vector<Subject>& subjects);
void updateAssignment(std::vector<Subject>& subjects);
void deleteAssignment(std::vector<Subject>& subjects);
void deleteSubject(std::vector<Subject>& subjects);
void saveAndExit(std::vector<Subject>& subjects);

//file handling functions
void saveData(const std::vector<Subject>& subjects);
void loadData(std::vector<Subject>& subjects);
//inputValidation functions
int chooseSubject(std::vector<Subject>& subjects);
Index chooseAssignment(std::vector<Subject>& subjects);
int parseIndex(std::string);
void charInputValidation(std::string& str,char delimeter);

int main()
{

  int choice;
  std::cout<<"\n======Assignment Manager======\n";
  std::vector<Subject> subjects;
  loadData(subjects);
  do
  {
  std::cout<<"1.Add Subject\n";
  std::cout<<"2. Add Assignment\n";
  std::cout<<"3. View Assignments\n";
  std::cout<<"4. Update Assignment\n";
  std::cout<<"5. Delete Assignment\n";
  std::cout<<"6. Delete Subject\n";
  std::cout<<"7. Save and Exit\n";
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
    deleteAssignment(subjects);
    break;
    case 6: 
    deleteSubject(subjects);
    break;
    case 7:
    saveAndExit(subjects);
    break;
    default:
    std::cout<<"Invalid choice\n";
    break;
  }
}while(choice!=7);
  return 0;
}
//function definitions
int parseIndex(std::string s)
{
  int index;
  try
  {
    {
      // inputValidation converts 1-based input to 0-based index
      index = std::stoi(s) - 1;
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return -1 ;
  }
  return index; 
}
int chooseSubject(std::vector<Subject>& subjects)
{
    if (subjects.empty())
    {
        std::cout << "No subjects!"<< std::endl;
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
    subIndex = parseIndex(input);

    if (subIndex < 0 || subIndex >= subjects.size())
    {
        std::cout << "Out of range!";
        return -1;
    }

    return subIndex;
}
Index chooseAssignment(std::vector<Subject>& subjects)
{
  int subIndex = chooseSubject(subjects);
  if(subIndex == -1)
  {
    std::cout<<"Indexing error!"<<std::endl;
    return Index{-1,-1};
  }
  if(subjects[subIndex].assignments.size()<=0) 
  {
    std::cout<<" NO assignments for this subject!"<<std::endl; 
    return Index{-1,-1};
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
        assIndex = std::stoi(aInput)-1;
    }
    catch (...)
    {
        std::cout << "Invalid input!"<<std::endl;
        return Index{-1,-1};
    }

    if (assIndex < 0 || assIndex >= subjects[subIndex].assignments.size())
    {
        std::cout << "Out of range!"<<std::endl;
        return Index{-1,-1};
    }

    return Index{subIndex,assIndex};
}
//funcitno to input validation of certain delimeter 
void charInputValidation(std::string& str,char delimeter)
{
bool valid=false;
  while(!valid)
  {
    std::getline(std::cin,str);
    valid = true;
    for(char c: str)
    {
      if(c == delimeter)
      {
        std::cout<<"character" << delimeter << " is not allowed please re-enter"<<std::endl;
        valid = false;
        break;
      }
    }
  }
}

//function to save data to file
void saveData(const std::vector<Subject>& subjects)
{
  int subSize = subjects.size();
  std::ofstream oFile("assignment.txt");
  if(!oFile.is_open())
  {
    std::cout << "Error opening file!" << std::endl;
    return ;
  }
  oFile << subSize << std::endl;
  for(int i=0;i<subSize;i++)
  {
    oFile << subjects[i].name << std::endl;
    int assSize = subjects[i].assignments.size();
    oFile << assSize << std::endl;
    for(int j = 0; j < assSize; j++)
    {
      oFile << subjects[i].assignments[j].title << "|" ;
      oFile << subjects[i].assignments[j].description << "|";
      oFile << subjects[i].assignments[j].deadline << "|";
      oFile << subjects[i].assignments[j].status << std::endl;
    }
  }
  oFile.close();
}
//inputValidation

//function to load data from file
void loadData(std::vector<Subject>& subjects)
{
  std::ifstream iFile("assignment.txt");
  if(!iFile.is_open())
  {
    std::cout << "Error opening file!" << std::endl;
    return ;
  }
  std::cout << "Loading data......" << std::endl;
  int subCount;

  subjects.clear();

  iFile >> subCount;
  iFile.ignore();

  for(int i = 0; i < subCount ; i++)
  {
    Subject s;//construct a fresh subject
    std::getline(iFile,s.name);

    int assCount;
    iFile >> assCount;
    iFile.ignore();

    for(int j = 0; j < assCount ; j++)
    {
      Assignment a;
      std::getline(iFile,a.title,'|');
      std::getline(iFile,a.description,'|');
      std::getline(iFile,a.deadline,'|');

      int status;
      iFile >> status;
      iFile.ignore();
      a.status = status;
      s.assignments.push_back(a);
    }
    subjects.push_back(s);
  }
  iFile.close();
}

void addSubject(std::vector<Subject>& subjects)
{
  std::string Sname;
  std::cout<<"Enter subject name:\n"<<std::endl;
  
  charInputValidation(Sname,'|');
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
  charInputValidation(a.title,'|');
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
  Index assubIndex;
  assubIndex = chooseAssignment(subjects);
  if( assubIndex.subjectIndex == -1 || assubIndex.assignmentIndex == -1 )
  {
    std::cout<<"Indexing error!"<<std::endl;
    return ;
  }

  std::cout << "choose what do you want to update: " << std::endl;
  std::cout << "1.Assignment title" << std::endl;
  std::cout << "2.Assignment description" << std::endl;
  std::cout << "3.Assignment deadline" << std::endl;
  std::cout << "4.Assignment status" << std::endl;

  std::string aChoice;
  std::getline( std::cin, aChoice );
  int choice;
  choice = parseIndex(aChoice);
  if(choice == -1) 
  {
    std::cout<<"Invalid choice!"<<std::endl;
    return ;
  }
  // inputValidation converts 1-based input to 0-based index

  if(choice == 0)
  {
    std::cout << "Current title : " << subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].title << std::endl;
    std::cout << "Enter new title : ";
    std::getline(std::cin>>std::ws,subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].title);
  }
  else if(choice == 1)
  {
    std::cout << "Current description : " << subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].description << std::endl;
    std::cout << "Enter new description : ";
    std::getline(std::cin>>std::ws,subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].description);
  }
  else if(choice == 2)
  {
    std::cout << "Current deadline : " << subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].deadline << std::endl;
    std::cout << "Enter new deadline : " ;
    std::getline(std::cin>>std::ws,subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].deadline);
  }
  else if(choice == 3)
  {
    if(subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].status == false)
    {
      std::cout << "current status : Not Done"<< std::endl;
    }
    else if(subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].status == true)
    {
      std::cout << "current status : Done " << std::endl;
    }
    
    std::cout << "Toggle (Done/NotDone) : " << std::endl;
    std::string statusInput;
    std::getline(std::cin >> std::ws ,statusInput);
    if(statusInput == "Done" || statusInput == "done" || statusInput == "Yes" || statusInput == "yes")
    {
      subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].status = true;
    }
    else if(statusInput == "not done" || statusInput == "no")
    {
      subjects[assubIndex.subjectIndex].assignments[assubIndex.assignmentIndex].status = false;
    }
    else
    {
      std::cout << " invalid choice!"<<std::endl;
      return ;
    }
  }
    
  }

void deleteAssignment(std::vector<Subject>& subjects)
{
  std::cout << "Choose Assignment to delete: " <<std::endl;
  Index dChoose;
  dChoose = chooseAssignment(subjects);
  if(dChoose.subjectIndex == -1 || dChoose.assignmentIndex == -1)
  {
    std::cout << "Delete aborted!";
    return ; 
  }
  std::string ynchoice;
  std::getline(std::cin >> std::ws ,ynchoice);
  if(ynchoice == "Y" || ynchoice == "y" )
  {
    std::cout << "Assignment : " << subjects[dChoose.subjectIndex].assignments[dChoose.assignmentIndex].title << "deleted!" <<std::endl;
  subjects[dChoose.subjectIndex].assignments.erase(subjects[dChoose.subjectIndex].assignments.begin() + dChoose.assignmentIndex);
    return ;
  }
  else if(ynchoice == "N" || ynchoice == "n")
  {
    std::cout << "Deletion Aborted!" << std::endl;
    return ;
  }
  else
  {
    std::cout << "Invalid input!";
  }
  
}
void deleteSubject(std::vector<Subject>& subjects)
{
  std::cout<<"Choose Subject to delete: " << std::endl;
  int dChoose;
  dChoose = chooseSubject(subjects);
  if(dChoose == -1)
  {
    std::cout << "Deletion aborted!" << std::endl;
    return ;
  }
  std::cout << "Are you sure to delete (Y/N): " << subjects[dChoose].name <<std::endl;
  std::string ynchoice;
  std::getline(std::cin >> std::ws ,ynchoice);
  if(ynchoice == "Y" || ynchoice == "y" )
  {
    std::cout<<"Subject : "<< subjects[dChoose].name << " deleted!" << std::endl;
    subjects.erase(subjects.begin() + dChoose);
    return ;
  }
  else if(ynchoice == "N" || ynchoice == "n")
  {
    std::cout << "Deletion Aborted!" << std::endl;
    return ;
  }
  else
  {
    std::cout << "Invalid input!";
  }
}
void saveAndExit(std::vector<Subject>& subjects)
{
  saveData(subjects);
  std::cout<<"Saving and Exiting.\n"<<std::endl;
}

