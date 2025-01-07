# Simple Bank System

The Simple Bank System is a straightforward C++ application designed to simulate basic banking operations. It provides features such as user authentication, account management, transactions, and currency exchange. This project focuses on simplicity and ease of use while incorporating basic security measures, like encrypted password storage.

## 🚀 Project Purpose

This is a personal project to demonstrate basic banking operations implemented in C++. It covers account management, transactions, and basic security features like password encryption. This project is aimed at showcasing an understanding of C++ fundamentals, object-oriented programming, and simple user authentication systems.

## Features

### 🛡️ Login Screen

The system includes a secure login screen where users can authenticate with a username and password. Each login session displays:

*   Current Date and Day
*   Active User Information

For added security, users are given three attempts to log in successfully. If the maximum number of attempts is reached, access will be temporarily restricted to prevent unauthorized access.

### 📋 Main Menu

Once logged in, users are presented with a comprehensive main menu offering the following options:

*   Show Client List: View all registered clients.
*   Add New Client: Easily create a new client account.
*   Delete Client: Remove a client from the database securely.
*   Update Client Info: Modify existing client details.
*   Find Client: Search for a specific client by name or ID.
*   Transactions: Access transaction-related operations (details below).
*   Manage Users: Administer user accounts with advanced management options.
*   Login Register: Review login history and manage user access.
*   Currency Exchange: Perform currency-related operations (details below).
*   Logout: Exit the system safely.

### 💵 Transactions Menu

The transactions menu allows users to manage their finances effectively:

*   Deposit: Add funds to an account.
*   Withdraw: Withdraw money securely.
*   Total Balances: View the cumulative balance of all accounts.
*   Transfer: Move money between accounts.
*   Transfer Log: Review a history of all transfers for transparency.

### 🔑 Manage Users

The system supports advanced user account management, including:

*   List Users: Display all user accounts in the system.
*   Add New User: Create new user accounts with specific privileges.
*   Delete User: Safely remove a user account.
*   Update User: Edit existing user details.
*   Find User: Search for a user by username or other criteria.

### 🌍 Currency Exchange Menu

The currency exchange feature allows users to handle foreign currency transactions efficiently:

*   List Currencies: View all supported currencies and their rates.
*   Find Currency: Search for specific currencies by name or code.
*   Update Rate: Update exchange rates dynamically.
*   Currency Calculator: Calculate conversions between different currencies easily.

### 🔒 Encrypted Password Storage

Passwords are securely encrypted using an algorithm that is integrated within the project files. The encryption algorithm is implemented as part of the classes in the project to ensure that user passwords remain protected. Even if the database is compromised, the passwords are not stored in plain text, increasing the system's security.

## 🚀 Future Features

- Integration with a real database for persistent data storage.
- Enhancing the user interface for a more polished experience.
- Implementing user session timeout for additional security after inactivity.

## ⚠️ Known Limitations

- The system currently supports only basic banking operations and is not connected to a real-world bank or database. It's for demo purposes.
- While input validation is applied, there may still be room for more extensive edge-case handling.
- Some user interface aspects are minimal and may not be fully optimized for large-scale use.

## 📁 Project Structure

The project is organized into the following directories:

*   `Core/`: Implements core functionalities and logic.
*   `Lib/`: Auxiliary libraries and helper functions.
*   `Main/`: Application's entry point.
*   `Screens/`: Handles user interface components.
*   `Text Files/`: Persistent storage for account and transaction data.

## 📄 License and Contribution

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please fork this repository and submit a pull request with your improvements or fixes.
