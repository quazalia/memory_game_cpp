#include <iostream>
#include <cmath>
#include <cstdlib>  
#include <ctime>
#include <algorithm>
#include <random>
#include <functional>
using namespace std;

void tapEnter() {
  cout << "Press Enter to continue...";
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  
  cin.get();  
  system("clear");
}

int main() {
  srand(time(0));
  int arrLength, attempts=0;
  bool isWon = false;
  cout << "Welcome to the memory game!\n Enter the size of an array (6-20): ";
  cin >> arrLength;
  int arr[arrLength];
  string questionArr[arrLength];

  if (arrLength % 2 == 0 && (arrLength >= 6 && arrLength <= 20))
  {
    for (int i = 0; i < arrLength; i+=2)
    {
      int k= rand()%10+1;
      arr[i] = k;
      arr[i + 1] = k;
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(arr, arr + arrLength, g);
    for (int i = 0; i < arrLength; i++)
    {
      questionArr[i] = "?";
    }
    
    while (isWon == false)
    {
      int firstNum, secondNum, check = 0;
      cout << "Here is the array: ";
      for (int i = 0; i < arrLength; i++)
      {
        cout << questionArr[i] << " ";
      }
      cout << "\nEnter the index to show: ";
      cin >> firstNum;
      cout << "The card at index " << firstNum << " is: " << arr[firstNum];

      cout << "\nEnter the second index to show: ";
      cin >> secondNum;
      cout << "The card at the index " << secondNum << " is: " << arr[secondNum] << endl;

      attempts++;

      for (int i = 0; i < arrLength; i++) {
        if (i == firstNum || i == secondNum) {
          cout << arr[i] << " ";
        }
        else {
          cout << questionArr[i] << " ";
        }
      }

      if (arr[firstNum] == arr[secondNum]) {
        cout << "\nGreat the cards are matched. Continue...\n" << endl;
        questionArr[firstNum] = to_string(arr[firstNum]);
        questionArr[secondNum] = to_string(arr[secondNum]);
      }
      else {
        cout << "\nThe cards do not match! Try again!\n" << endl;
      }

      for (int i = 0; i < arrLength; i++) {
        if (questionArr[i] != "?") {
          check ++;
        }
      }
      if (check == arrLength) {
        cout << "Congratulations! You won! here's the amount of your attempts: " << attempts << "\n";
        isWon = true;
      }
      else {
        tapEnter();
        cout << "\n\n";
      }
    }
    
  }
  else cout << "Please, enter an even number from 6 to 20 range";
  
  return 0;
}