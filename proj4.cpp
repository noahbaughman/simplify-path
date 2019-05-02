
/**
 * @file proj4.cc
 * \mainpage
 *
 * CISC 2200, Data Structures<br>
 * Project 4: The Banking Simulation<p>
 *
 * This program simulates a bank line 
 *
 * @author Noah Baughman
 * @date   12/4
 *
 */

/*
 * includes ... you'll probably need more
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

/*
* This struct represents an Event, either arrival, or departure
* and holds the time, length of transaction, and Event Type.
*/
struct Event{
public:
   int time;
   int length;
   enum EventKind {Arrival, Departure};
   EventKind type;   
   Event(EventKind type, int time) : type(type), time(time) //constructor
   {
   }
   EventKind getType() { return type; }

};

/*
* This struct represents the camparison needed to fill the priority queue.
*/
struct Compare{
   /*
   * This function returns the event with the lowest time.
   *
   * @param, Two Events
   @ @return bool, whether e2 is less than e1
   */
   bool operator()(Event* e1, Event* e2){
      return e2->time < e1->time;
   }
};

/*
* This struct repreesents the list of events and constructs the data needed and functions used later on.
*/
struct EventList{
   priority_queue<Event*, vector<Event*>, Compare> eList;
   queue<Event*> bankQ;
   Event* customer;
   int count;
   int totalTime;
   int currentTime;
   bool tellerAvailable;
   void fill(istream& is);
   void simulate();
   void processArrival(Event* e);
   void processDeparture(Event* e);
};




/**
 * The usual main function
 */
int main(int argc, char** argv)
{
   EventList eventList;

   // command-line parameter munging   
   // also fills the event list with the input data
   char* progname = argv[0];            // simplify msgs a bit
   switch (argc) {
   case 1:
      eventList.fill(cin);
      break;
   case 2: {
      ifstream ifs(argv[1]);
      if (!ifs) {
         cerr << progname << ": couldn't open " << argv[1] << endl;
         return 1;
      }
      eventList.fill(ifs);
      break;
   }
   default:
      cerr << "Usage: " << progname << " [datafile]\n";
      return 2;
   }

  eventList.simulate();
}

/*
* This function creates Arrival events and fills the priority queue by reading in data from a file and
* constructing Arrival Events 
*
* @param is, series of data from datafile.
*/
void EventList::fill(istream& is){  
   int arrival = 0;
   int transaction;  
   while(is >> arrival >> transaction){
      count++;
      Event* e = new Event(Event::Arrival, arrival);
      e->length = transaction;
      eList.push(e);
   }
   cout << "EventList::fill was called\n";  
}


/*
* This function simulates the bank line by processing Arrival and Departure Events,
* and gives a summary of the simulation at the end.
*/
void EventList::simulate()
{
   tellerAvailable = true;
   currentTime = eList.top()->time;

   while(!eList.empty()){
      Event* curr = eList.top();
      Event::EventKind ty = curr->getType();
      if(ty == 0){
         cout << "Processing Arrival Event at: " << curr->time << endl;
         processArrival(curr);
      }
      else{
         cout << "Processing Departure Event at: " << curr->time << endl;
         processDeparture(curr);
      }
   }


   cout << "Final Statistics: " << endl;
   cout << "The number of people processed: " << count << endl;
   cout << "Average time spent waiting: " << (double)totalTime/count << endl;
}

/*
* This processes an arrival Event and proceeds if teller is available or puts customer in line
* if no teller available
*
* @param e, an Arrival Event
*/
void EventList::processArrival(Event* e){
   eList.pop();
   if(bankQ.empty() && tellerAvailable == true){
      currentTime = e->time + e->length;
      customer = new Event(Event::Departure, currentTime);
      customer->length = e->length;
      eList.push(customer);
      tellerAvailable = false;
   }
   else{
      bankQ.push(e);
   }
}

/*
* This processes a departure Event and starts processing next customer.
*
* @param e, a Departure Event
*/
void EventList::processDeparture(Event* e){
   eList.pop();
   if(!bankQ.empty()){
      customer = bankQ.front();
      totalTime += currentTime - customer->time;
      bankQ.pop();
      currentTime += customer->length;
      int leng = customer->length;
      customer = new Event(Event::Departure, currentTime);
      customer->length = leng;
      eList.push(customer);
   }
   else{
      tellerAvailable = true;
   }
}





