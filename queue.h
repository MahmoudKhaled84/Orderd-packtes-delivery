/*
 * queue.h
 *
 *  Created on: May 8, 2018
 *      Author: Kimo9
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
using namespace std;
#include <string>
#include <assert.h>

template<class QueueElemType>

class Queue
{
public:
    Queue();
    void enqueue(const QueueElemType );
    bool dequeue(QueueElemType &);
    bool front(QueueElemType &);
    bool QueueNum(QueueElemType &);
    bool tail(QueueElemType &);
    bool next(QueueElemType &);
    bool getDrop(int &);

private:
    struct Node;
    typedef Node *Link;
    struct Node
    {
        QueueElemType elem;
        int occurence;
        Link next;
    };

    Link head;
    Link current;
};


template<class QueueElemType>
Queue<QueueElemType>::Queue()
{
    head=NULL;
    current=NULL;
}

template<class QueueElemType>
void Queue<QueueElemType>::enqueue(const QueueElemType e)
{
    Link addednode;
    Link Pred;
    addednode = new Node;
    assert(addednode);

    addednode->elem = e;
    addednode->occurence=1;

    if(head==NULL || (head->elem)>e)
     {
        addednode->next = head;
        head = addednode;
     }

     else
     {
       if((head->elem)==e)
         (head->occurence)++;

      else
    	 {
            Pred = head;
            while((Pred->next)!= NULL && ((Pred->next->elem)<e))
                    Pred = Pred->next;

            if((Pred->next)!= NULL && ((Pred->next->elem)==e))
                    (Pred->next->occurence)++;

    		  else
    			{
    			   addednode->next=Pred->next;
    		       Pred->next=addednode;
    			}
    	 }
     }

}

template<class QueueElemType>
bool Queue<QueueElemType>::dequeue(QueueElemType&e)
{
    if(head==NULL)
    	return false;
    else
    {
    Link ptr = head;
    e = ptr->elem;
    head=head->next;
    delete ptr;

    return true;
    }
}

template<class QueueElemType>
bool Queue<QueueElemType>::front(QueueElemType &e)
{
    if(head==NULL)
    	return false;
    else
    {
    current = head;
    e = current->elem;

    return true;
    }
}

template<class QueueElemType>
bool Queue<QueueElemType>::QueueNum(QueueElemType &e)
{
	Link ptr1; e=1;
	if(head==NULL)
		return false;

	else
	{
		ptr1 = head;
		while((ptr1->next)!= NULL)
		{
			e++;
			ptr1  = ptr1 ->next;
		}

		return true;
	}

}

template<class QueueElemType>
bool Queue<QueueElemType>::tail(QueueElemType &e)
{
	Link ptr2; Link ptr3;
		if(head==NULL)
			return false;

		else
		{
			ptr2 = head;
			while((ptr2->next)!= NULL)
			{
				ptr3=ptr2->next;
				ptr2 = ptr2->next;
			}
            e= ptr3->elem;
			return true;
		}
}

template<class QueueElemType>
bool Queue<QueueElemType>::next(QueueElemType &e)
{
	if (current == NULL || current->next == NULL)
	        return false;

	    else
	    {
	       current = current->next;
	       e = current->elem;

           return true;
        }
}

template<class QueueElemType>
bool Queue<QueueElemType>::getDrop(int & e)
{
	Link ptr4 = head; e=0;
     if(head==NULL)
	    return false;

	  else
	  {
          if((ptr4->occurence)>1)
	            e++;

	  while( (ptr4->next) != NULL)
	  {
		  if((ptr4->next->occurence)>1)
			  e++;

		  ptr4 = ptr4->next;
	    }

	  return true;
	  }
}

#endif /* QUEUE_H_ */
