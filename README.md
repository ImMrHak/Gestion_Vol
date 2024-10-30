# Gestion_Vol_BDD

## Overview
```Gestion_Vol_BDD``` is a C++ project for managing flight information within a MySQL database. It provides functionality for storing, retrieving, and updating flight details, enabling efficient management of flight schedules, passenger information, and other essential data.

> **Note:** This project has known vulnerabilities, specifically **SQL Injection** risks. Inputs are not sanitized, which may expose the database to malicious queries.

## Features
- **Add Flight:** Add new flight details to the database.
- **Update Flight:** Update existing flight information.
- **Delete Flight:** Remove flight records from the database.
- **Retrieve Flights:** Fetch and display flight information based on various filters.

## Prerequisites
- **C++ Compiler:** Ensure a C++17 compatible compiler is installed.
- **MySQL Database System:** Install MySQL and adjust the database configuration in the code as required.

## Installation

1. Clone the repository:
   ```git clone https://github.com/ImMrHak/Gestion_Vol_BDD.git```

2. Navigate to the project directory:
   ```cd Gestion_Vol_BDD```

3. Open the solution file ```Gestion_Vol_BDD.sln``` in your preferred IDE (Visual Studio).

4. Configure the MySQL database connection in ```Connect.h```.

## Usage
To run the project:
1. Compile the project by building the solution in your IDE.
2. Execute the compiled program to access the flight management functionalities.

## Contributing
1. Fork the repository.
2. Create a new branch (```git checkout -b feature-branch```).
3. Commit your changes (```git commit -am 'Add new feature'```).
4. Push to the branch (```git push origin feature-branch```).
5. Create a pull request.
