#include <iostream>
#include <random>

using namespace std;

void shuffleFisherYates(char*);
void fillArray(char*);
void createDecryptArray(char*, char*);

int main()
{
  char map [94];
  char map1 [94];

  fillArray(map);
  //  fillArray(map1);
  shuffleFisherYates(map);
  createDecryptArray(map, map1);
  for (int i = 0; i < 94; i++)
    {
      cout << map[i];
    }
  cout << endl << endl;
  string usrMsg;
  string encryptMsg;
  while(usrMsg != "~")
    {
      getline(cin, usrMsg);
  if(usrMsg != "")
    {
  for(int i = 0; i < usrMsg.length(); i++)
    {
      int num = int(usrMsg[i]);
      if(num == 126)
	{
	  usrMsg = "~";
	  break;
	}
      encryptMsg += map[num - 32];
    }
     }
  cout << encryptMsg << endl << endl;
  string msg = "";
  for(int i = 0; i < encryptMsg.length(); i++)
    {
      int num = int(encryptMsg[i]);
      msg += map1[num - 32];
    }
  cout << msg << endl << endl; 
  encryptMsg = "";


    }




  return 0;
}

void fillArray(char*  A)
{
  for (int i = 0; i < 94; i++)
    {
      A[i] = char(i + 32);
      cout << A[i];
}
  cout << endl << endl;;
}

// a Random object has been created with name random
void shuffleFisherYates(char* A) {
  int size = 94;
  default_random_engine generator;
  generator.seed(3);
  uniform_int_distribution<int> distribution(0,94);

  for(int i=0; i<size; i++) {
    int randomIndex = (i + distribution(generator)) %94;
    uniform_int_distribution<int> distribution(0, size - i);
    char randomLetter = A[randomIndex];
    A[randomIndex] = A[i];
    A[i] = randomLetter;
  }
}

void createDecryptArray(char* A, char* A1)
{
  default_random_engine generator;
  generator.seed(3);
  uniform_int_distribution<int> distribution(0,94);
  for(int i = 0; i < 94; i++)
    {
      //      int randomIndex = (i + distribution(generator)) % 94;
      // uniform_int_distribution<int> distribution(0, 94 - i);
      // cout << char(randomIndex + 32) << " ";      
      //char letter = A[i];
      //  A[i] = char(randomIndex + 32);
      //      A[randomIndex] = letter;

      int index = A[i];
      cout << char(index);
      A1[index-32] = i + 32; 
          
    }
  cout << endl << endl;
  for(int i = 0; i < 94; i++)
    {
      cout << char(A[i]);
    }
  cout << endl << endl;
  for(int i = 0; i < 94; i++)
    {
      cout << char(A1[i]);
    }
  cout << endl << endl;

}
