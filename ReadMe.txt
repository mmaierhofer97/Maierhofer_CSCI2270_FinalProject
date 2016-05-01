The point of this project is to create an implementation of an n-nary search tree that remains easily searchable. This was done by creating the tree, then creating a binary search tree every time the n-nary tree was altered. This data structure was created to best be able to manage a multi-tier system with each node having defined parents, and each parents having the possibility of children. This implementation was created in the context of creating a manipulatable hierarchy of a company so as to create a comprehensive employee databasse. Methods were implemented in order to best manage this databse while providing the user with the most possible information. The program is capable of adding employees, deleting employees, shifting employees, promoting employees, and analyzing the current hierarchy.
How to Run:
Command 1 adds employees. You enter their name and managers name. If they are the first employee, then the manager can remain blank. Command 2 can delete employees by name. Command 3 prints out the chain of command up to an employee, as well as their employees. This can be an effective tool to visualize the tree. 4 allows for the movement of the hierarchy of employees underneath a single manager. First you enter the name of the employee that you want to move. Then you enter the employee that you want them to be right of, or leave blank if you want them to be the leading child of a manager. Command 5 assigns tier levels, which become important in later commands. These may need to be updated after altering the hierarchy. Command 6 allows you to find the tier level of a specific employee by name. Command 7 performs a Breadth-First-Traversal that lists all employees and their levels. Command 8 counts the total number of employees in the organization. Command 9 allows for the promotion of an employee by name and reassigns their employees appropriately. Command 10 counts all of the employees at a certain tier level.
Dependencies:
None
System Requirements:
Runs on Codeblocks
Group Members:
None
Contributors:
None
Known Bugs:
The project is currently completely debugged to the best of the programmers knowledge