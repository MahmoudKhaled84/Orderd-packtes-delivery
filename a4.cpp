#include "queue.h"
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    if(argc>5)
    {
      int i; int Expect,Drop=0; int front,item,item1; bool flag,flag1,flag2;
      Queue<int> qu,wqu;

      int seqNumBits=atoi(argv[1]);
      int windowSize=pow(2,atoi(argv[2]));
      int initSeq=atoi(argv[3]);
      int maxnum = pow(2,seqNumBits);
      Expect=initSeq;

      if(initSeq>(maxnum-1))
      {
          cout<<"Invalid Configuration";
          return 0;
      }

      if( (!isdigit(*argv[1])) || (!isdigit(*argv[2])) || (!isdigit(*argv[3])) || (*argv[4]!=':') )
      {
    	  cout<<"Invalid Configuration";
    	  return 0;
      }


       if(windowSize>maxnum-1)
       {
         cout<<"Invalid Configuration";
         return 0;
        }

        for(i=5; i<argc; i++)
        {

          if(atoi(argv[i])> (maxnum-1) )
    	     {
    	        cout<<"Invalid Packet";
    	        return 0;
    	     }

    	  if(!isdigit(*argv[i]))
    	  {
    		  cout<<"Invalid Packet";
    		  return 0;
    	  }

        }

      cout<<"R"<<' ';

      for(i=5; i<argc; i++)
      {

          if(atoi(argv[i])> (maxnum-1) )
    	     {
    	        cout<<"Invalid Packet";
    	        return 0;
    	     }

    	  if(!isdigit(*argv[i]))
    	  {
    		  cout<<"Invalid Packet";
    		  return 0;
    	  }


          flag=qu.front(front);

          if(atoi(argv[i])==Expect)
            {
                if(flag && (front==atoi(argv[i])))
                {
                    qu.dequeue(front);
                    Drop++;
                }

                cout<<Expect<<' ';
                if(atoi(argv[i])==(maxnum-1))
                    Expect=0;

                else Expect++;
            }

         else
         {
            if ( flag && (front==Expect) )
         {
             flag=qu.dequeue(front);
             if(flag)
             {
                 cout<<front<<' ';
                 if(front==(maxnum-1))
                    Expect=0;

                 else Expect++;
             }
         }

             if( ( atoi(argv[i]) < Expect ) || ( atoi(argv[i]) >= (Expect+windowSize) ) )
             {
                 if( ((Expect+windowSize)>maxnum) && (atoi(argv[i])<(Expect+windowSize-maxnum)) )
                    qu.enqueue(atoi(argv[i]));

                 else Drop++;
             }


            else
            {
                if(flag && (front==atoi(argv[i])))
                    Drop++;

                else  qu.enqueue(atoi(argv[i]));
            }
         }
      }


      i=0;
      flag=qu.QueueNum(item);
      flag1=qu.front(front);

      while( (i<item) && flag1)
      {
          if(front==Expect)
          {
             cout<<front<<' ';
             if(front==(maxnum-1))
                Expect=0;

             else Expect++;
             wqu.enqueue(front);
          }

          flag1=qu.next(front);
      }

      cout<<"E"<<' '<<Expect<<' ';
      cout<<"W"<<' ';

      i=0;
      flag=qu.QueueNum(item);
      flag1=wqu.front(front);
      flag2=qu.front(item1);

      if(!flag1)
      {
          while(flag2)
          {
              if(item1>Expect)
                cout<<item1<<' ';

              flag2=qu.next(item1);
          }

          flag2=qu.front(item1);
          while(flag2)
          {
              if(item1<Expect)
              {
                   cout<<item1<<' ';
                   flag2=qu.dequeue(item1);
              }
              flag2=qu.next(item1);
          }

           while(flag2)
           {
               qu.dequeue(item1);
               flag2=qu.next(item1);
           }

      }

      else
      {
        while(flag2 && (i<item))
        {
        if(front==item1)
        {
            qu.dequeue(item1);
            wqu.dequeue(front);
        }

        else
        {
            cout<<item1<<' ';
            qu.dequeue(item1);
        }

        flag1=wqu.front(front);
        flag2=qu.front(item1);
        }

      }

      flag2=qu.front(item1);
      /*while(flag2)
      {
          cout<<item1<<' ';
          qu.dequeue(item1);
          flag2=qu.next(item1);
      }*/

      cout<<"D#"<<' '<<Drop;

    }



    else cout

      <<"Invalid Configuration";


}
