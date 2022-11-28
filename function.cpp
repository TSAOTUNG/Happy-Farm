#include <iostream>
#include <string>
#include "function.h"

//constructor
template <class T>
Node<T>::Node(T x, T y, T fence)
{
   this->next = NULL;
   this->x = x;
   this->y = y;
   this->fence = fence;
}

//compare the order of nodes
template <class T>
T Node<T>::compare(T x, T y)
{
   if (this->y > y)
   {
      return 1;
   }
   else if (this->y < y)
   {
      return -1;
   }
   else if (this->y == y && this->x > x)
   {
      return 1;
   }
   else if (this->y == y && this->x < x)
   {
      return -1;
   }
   else
   {
      return 0;
   }
}

//constructor
template <class T>
LinkedList<T>::LinkedList()
{
   first = NULL;
   length = 0;
}


template <class T>
void LinkedList<T>::insert(T x, T y, T fence)
{
   Node<T>* current_ptr = first;
   //build a new node to insert
   Node<T>* newNode = new Node<T>(x, y, fence);
   if (newNode->fence==0 || newNode->fence==1)
   {
       if (first == NULL) //there is no node in the list
       {
           //insert the node at the beginning
           first = newNode;
       }
       else
       {
           if (current_ptr->compare(newNode->x, newNode->y) == 1)
           {
               //insert the node at the beginning when list is not empty
               newNode->next = first;
               first = newNode;
               return;
           }
           if (current_ptr->compare(newNode->x, newNode->y) == 0)
           {
               if (newNode->fence == 1 && current_ptr->fence == 0)
               {
                   current_ptr->fence = 1;
                   //delete newNode;
                   //cout << current_ptr->fence;
                   return;
               }
               else
               {
                   return;
               }
           }
           // compare current->next with newNode
           while (current_ptr != NULL) // Traversal
           {
               if (current_ptr->next == NULL)
               {
                   current_ptr->next = newNode;
                   //cout << "wow1";
                   return;
               }
               if (current_ptr->next->compare(newNode->x, newNode->y) == 1)
               {
                   // insert part
                   newNode->next = current_ptr->next;
                   current_ptr->next = newNode;
                   //cout << "wow2";
                   return;
               }
               if (current_ptr->next->compare(newNode->x, newNode->y) == 0)
               {
                   if (newNode->fence == 1 && current_ptr->next->fence == 0)
                   {
                       current_ptr->next->fence = 1;
                       //delete newNode;
                       //cout << current_ptr->fence;
                       return;
                   }
                   else
                   {
                       return;
                   }
               }
               current_ptr = current_ptr->next;
           }
        }
   }
}
template <class T>
void LinkedList<T>::deletion(T x, T y)
{
   Node<T>* temp = first;
   if (temp == NULL)
   {
      //cout << "There is no node to delete in the list." << endl;
      return;
   }
   Node<T>* follow = NULL;
   while (temp != NULL) // Traversal
   {
      if((temp->x == x && temp->y == y))
      {
         if (temp->fence == 0)
         {
            if (temp == first)
            {
               //delete at the front
               first = temp->next; //first point to next node
               delete temp;
               temp = NULL;
            }
            else
            {
               //delete in elsewhere
               follow->next = temp->next;  //jump the link to link another node
               delete temp;
               temp = NULL;
            }
            return;
         }
      }

      follow = temp;
      temp = temp->next;
   }
}

template <class T>
void LinkedList<T>::show()
{
   cout << "Display" << endl;
   if (first == NULL)
   {
      //cout << "There is no node in the list.\n";
      return;
   }
   Node<T>* cur = first;
   while (cur != NULL)
   {
      if (cur->fence == 1 || cur->fence == 0)
      {
         cout << "(" << cur->x << "," << cur->y << ")" << endl;
         //cout << cur->fence << endl;
      }
      cur = cur->next;
   }
}

LinkedList<long long> fen;
//  solving function
void plant(long long x, long long y, int withFence)
{
   fen.insert(x, y, withFence);
}

void thief(long long x, long long y)
{
   fen.deletion(x, y);
   fen.deletion(x + 1, y);
   fen.deletion(x - 1, y);
   fen.deletion(x, y + 1);
   fen.deletion(x, y - 1);
}

void superThief(long long x, long long y)
{
   fen.deletion(x, y);
   fen.deletion(x + 1, y);
   fen.deletion(x - 1, y);
   fen.deletion(x, y + 1);
   fen.deletion(x - 1, y + 1);
   fen.deletion(x + 1, y + 1);
   fen.deletion(x, y - 1);
   fen.deletion(x - 1, y - 1);
   fen.deletion(x + 1, y - 1);
}

void display()
{
   fen.show();
}




