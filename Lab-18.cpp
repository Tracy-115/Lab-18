// COMSC-210 | Lab 18 | Kyawt Thinzar Min
// IDE used: Visual Studio Code
   #include <iostream>
   #include <string>
    using namespace std;

    struct Movie{
      float rating;
      string comment;
      Movie *next;
    };
      void Head(Movie *&head, float rating, string &comment);
      void tail(Movie *&head, float rating, string &comment);
      void output(Movie *head);
      void deleteReview(Movie *&head);
    int main(){
      Movie *head=nullptr;

      int choice;
      cout << "Which linked list method should we use?\n";
      cout << "    [1] New nodes are added at the head of the linked list\n"<< "    [2] New nodes are added at the tail of the linked list\n";
      cout << "    Choice: ";
      cin >> choice;
      cin.ignore();

      char decision = 'Y';
      while (toupper(decision) == 'Y') {
          float rating;
          string comment;

          cout << "Enter review rating 0-5: ";
          cin >> rating;
          cin.ignore();
          cout << "Enter review comments: ";
          getline(cin, comment);
          if (choice == 1){
            Head (head, rating, comment);
          }
          else{
            tail (head, rating, comment);
          }
          cout << "Enter another review? Y/N: ";
          cin >> decision;
          cin.ignore();
      }
        output(head);
        return 0;
    }
    void Head(Movie *&head, float rating, string &comment){
      Movie *newNode = new Movie;
      newNode->rating=rating;
      newNode->comment=comment;
      newNode->next = head;
      head = newNode;
    }

    void tail(Movie *&head, float rating, string &comment){
      Movie *newNode = new Movie;
      newNode->rating=rating;
      newNode->comment=comment;
      newNode->next = nullptr; //this is to see if it is the last node or not

      if (!head) {
        head = newNode;      
        return;                      
      }

      //these are to point to the last node and transverse until the new review reaches the end
      Movie *temp = head; 
      while (temp->next){
        temp = temp->next;
      }
      temp->next = newNode;
    }
    void output( Movie *head){
      int count = 0;
        float total = 0;
        Movie *temp = head;

        while (temp) {
            cout << "    > Review #" << ++count << ": " << temp->rating << ": " << temp->comment << endl;
            total += temp->rating;
            temp = temp->next;
        }
        if (count > 0){
            cout << "    > Average: " << total / count << endl;
        }
    }

    void deleteReview(Movie *&head){
      while (head){
        Movie *temp=head;
        head = head->next;
        delete temp;
      }
      head = nullptr;
    }








