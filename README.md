# Library Management System

This is a simple console-based library management system written in C++. The system allows for adding, displaying, sorting, searching, and deleting library members. It also includes functionality to check and sort members by name or ID.

## Features

- **Add Member**: Add a new library member with their name and automatically generated ID.
- **Display Members**: Display all library members.
- **Sort Members by Name**: Sort and display library members by their names.
- **Sort Members by ID**: Sort and display library members by their IDs.
- **Search Member by ID**: Search for a library member by their ID.
- **Delete Member**: Delete a library member by their ID.
- **Load Members**: Load members from the file.
- **Rewrite Members**: Rewrite the members file after deletion.

## Getting Started

### Prerequisites

- C++ compiler
- Text editor or IDE for C++ development

## Code Overview

The program consists of several functions within the `library` class, each responsible for a specific task. Below is an overview of each function:

### `library::library`

- Constructor for the `library` class.

### `library::~library`

- Destructor for the `library` class.

### `library::addMember`

- Prompts the user to enter the member's name.
- Generates a unique member ID.
- Writes the member's name and ID to the `members.txt` file.

### `library::generateID`

- Generates a unique member ID in the format `M####`.

### `library::checkID`

- Checks if a generated member ID already exists in the `members.txt` file.

### `library::displayMember`

- Reads and displays all members from the `members.txt` file.

### `library::loadMember`

- Loads members from the `members.txt` file into vectors for further processing.

### `library::checkMember`

- Checks if a member exists in the `members.txt` file by name.

### `library::sortMember`

- Sorts and displays members by their names.

### `library::sortMemberId`

- Sorts and displays members by their IDs.

### `library::sequentialSearch`

- Searches for a member by their ID in the `members.txt` file.

### `library::deleteMember`

- Deletes a member from the `members.txt` file by their ID.

### `library::rewriteMember`

- Rewrites the `members.txt` file after a member has been deleted.

## Usage

1. Run the program.
2. Select an option from the menu to add, display, sort, search, or delete members.

## Example

Here is an example of how the program works:

1. **Add Member**
   ```
   Enter member's name: John Doe
   Member ID: M1234
   Member added successfully
   ```

2. **Display Members**
   ```
   Name:                Member ID :
   John Doe             M1234
   ```

3. **Sort Members by Name**
   ```
   Name:                Member ID :
   John Doe             M1234
   ```

4. **Sort Members by ID**
   ```
   Member ID:           Name:
   M1234                John Doe
   ```

5. **Search Member by ID**
   ```
   Search member ID (M####): M1234
   Data found in the file.
   Member name: John Doe
   ```

6. **Delete Member**
   ```
   Enter the Member ID to be delete: M1234
   MemberID successfully deleted.
   ```
