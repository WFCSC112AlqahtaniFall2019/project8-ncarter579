//Nathan Carter


#include <iostream>
#include "Data.h"
#include <stack>
#include <queue>


#include <fstream>

int main() {
    stack <Data> stac;               //creating containers
    queue <Data> que;
    priority_queue <Data> p_que;

    ifstream inputs;       //creating input and output variables
    ofstream stacked;
    ofstream queued;
    ofstream sorted;

    inputs.open ("all_seasons.csv");     //opening files
    stacked.open ("stacked.txt");
    queued.open ("queued.txt");
    sorted.open ("sorted.txt");

    if (!inputs.is_open()){                     //checking to see if all files were opened correctly
        cout << "inputs isn't open" << endl;
        return -1;
    }
    if (!stacked.is_open()){
        cout << "stacked isn't open" << endl;
        return -1;
    }
    if (!queued.is_open()){
        cout << "queued isn't open" << endl;
        return -1;
    }
    if (!sorted.is_open()){
        cout << "sorted isn't open" << endl;
        return -1;
    }

    string points;       //creating strings for all of my inputs
    string rebounds;
    string assists;
    string rating;

    cout << "Reading ../dataset.csv…" << endl;

    for(int i = 0; i < 10101; i++){             //for the length of the data set
        //while(!inputs.eof()){
        getline(inputs, points, ',');           //getting the inputs from the data set and storing them in the strings
        getline(inputs, rebounds, ',');
        getline(inputs, assists, ',');
        getline(inputs, rating);

        Data object (stod(points), stod(rebounds), stod(assists), stod(rating));   //creating a Data object by converting strings to double and storing them in the object
        stac.push(object);        //putting the Data objects into the containers
        que.push(object);
        p_que.push(object);


    }

    cout << "Writing data in stack inserted at head into stacked.txt." << endl;      //printing the data to the proper output file
    while(!stac.empty()){
        stacked << stac.top();    //printing out
        stac.pop();          //deleting from the container
    }
    cout << "Writing data in queue inserted at tail into queued.txt." << endl;
    while(!que.empty()){
        queued << que.front();     //printing out
        que.pop();          //deleting from the container
    }
    cout << "Writing data in sorted linked list sorted by attribute into sorted.txt." << endl;
    while(!p_que.empty()){
        sorted << p_que.top();        //printing out
        p_que.pop();                  //deleting from the container
    }


    inputs.close ();         //closing all of the opened files
    stacked.close ();
    queued.close ();
    sorted.close ();
    return 0;
}