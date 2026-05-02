#include <iostream>
#include <string>
#include "../include/Expressway.h"

using namespace std;

void runCLI(Expressway& e) {
    int ch;
    while(true) {
        cout << "\n--- Delhi-Dehradun Expressway System ---" << endl;
        cout << "1. Shortest Path (Dijkstra)\n2. MST (Kruskal)\n3. Fuel Arbitrage Check\n4. Exit\nSelection: ";
        if (!(cin >> ch)) break;
        
        if (ch == 1) {
            string start, end;
            cout << "Enter Start City: "; cin >> start;
            cout << "Enter Destination: "; cin >> end;
            auto result = e.shortestPath(start, end, 'd');
            if (get<0>(result) == -1) {
                cout << "Path not found!" << endl;
            } else {
                cout << "Shortest Distance: " << get<0>(result) << " km" << endl;
                cout << "Path: ";
                for (const auto& city : get<4>(result)) cout << city << " -> ";
                cout << "END" << endl;
            }
        } 
        else if (ch == 2) {
            e.getMST(); // This calls the Kruskal logic we added
        } 
        else if (ch == 3) {
            cout << "Checking for Fuel Arbitrage cycles..." << endl;
            vector<double> rates = {0.8, 1.2, 0.9}; // Example rates
            if(e.hasFuelArbitrage(rates)) cout << "Arbitrage Opportunity Found!" << endl;
            else cout << "No Arbitrage detected." << endl;
        } 
        else if (ch == 4) {
            break;
        }
    }
}

int main() {
    Expressway e;
    if(!e.loadFromFile("data/expressway.txt")) {
        cout << "Error: data/expressway.txt not found!" << endl;
        return 1;
    }
    runCLI(e);
    return 0;
}