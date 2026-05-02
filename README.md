# Delhi-Dehradun Expressway Simulation System

This project is a C++ based simulation of the Delhi-Dehradun Expressway network, developed as part of the **External Training 2F** program. It utilizes advanced Data Structures and Algorithms to optimize travel, connectivity, and vehicle tracking.

## 🚀 Key Features

* **Shortest Path Calculation:** Implements **Dijkstra's Algorithm** to find the most efficient route between cities based on distance, time, or toll cost.
* **Minimum Spanning Tree (MST):** Uses **Kruskal's Algorithm** combined with **Disjoint Set Union (DSU)** to find the most cost-effective way to connect all cities in the network.
* **Vehicle Tracking:** Features a **Bloom Filter** for high-speed, memory-efficient checking of vehicle records.
* **Regional Statistics:** Employs a **Fenwick Tree (Binary Indexed Tree)** for rapid range queries to count cities within specific distance segments.

## 📁 Project Structure

* `include/`: Header files (.h) containing class declarations.
* `src/`: Implementation files (.cpp) containing the core logic and algorithms.
* `data/`: Configuration files, including `expressway.txt` for city and road data.

## 🛠️ How to Compile and Run

To compile the project, navigate to the root directory and run the following command in your terminal:

```bash
g++ src/*.cpp -Iinclude -o expressway

./expressway
```
# Members
+ Udayveer singh 
+ Vishnu Kumar 
+ Yanuj singh
+ Yash Parmar 
+ Yash Rajput
+ Yash Kumar Singh
+ Zeeshan Ahmed
+ Swayam Singh
+ Suraj tripathi
+ Ujjawal Singh
+ Vijay parmar
+ Varun parmar
+ Utkarsh singh
+ Tushar bharadwaj
+ Shubh Trivedi 


# License
This project is licensed under MIT license - Kindly refer the LICENSE file for details.
