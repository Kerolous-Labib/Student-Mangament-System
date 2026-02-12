<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Student Management System</title>
</head>

<body>

<h1>🎓 Student Management System (Linked List in C)</h1>

<p>
A simple <b>Student Management System</b> implemented in <b>C language</b> using a
<b>Singly Linked List</b> data structure.
</p>

<p>
This project demonstrates dynamic memory allocation, linked list operations,
and basic data validation in C.
</p>

<hr>

<h2>📌 Features</h2>
<ul>
<li>➕ Add a new student</li>
<li>📋 Display all students</li>
<li>🔎 Search for a student by ID</li>
<li>✏️ Update student information</li>
<li>📊 Calculate average GPA</li>
<li>🏆 Find the highest GPA</li>
<li>❌ Delete a student by ID</li>
<li>🚪 Exit safely (free all allocated memory)</li>
</ul>

<hr>

<h2>🏗️ Project Structure</h2>

<h3>1️⃣ struct student</h3>
<p>Stores student information:</p>
<ul>
<li><b>id</b> → Unique student ID</li>
<li><b>name</b> → Student name</li>
<li><b>age</b> → Student age</li>
<li><b>gpa</b> → Student GPA (0.00 – 4.00)</li>
</ul>

<h3>2️⃣ struct node</h3>
<p>Represents a linked list node:</p>
<ul>
<li><b>data</b> → Student structure</li>
<li><b>next</b> → Pointer to next node</li>
</ul>

<p>A global pointer <b>head</b> points to the first student in the list.</p>

<hr>

<h2>🧠 Concepts Used</h2>
<ul>
<li>Dynamic Memory Allocation (malloc, free)</li>
<li>Singly Linked List operations</li>
<li>Pointer manipulation</li>
<li>Input validation using do...while</li>
<li>Searching and traversal algorithms</li>
</ul>

<hr>

<h2>🔐 Data Validation</h2>
<ul>
<li>Student ID must be <b>unique</b></li>
<li>GPA must be between <b>0.00 and 4.00</b></li>
<li>Memory allocation is checked before use</li>
</ul>

<hr>

<h2>⚙️ How It Works</h2>
<ul>
<li>Memory is dynamically allocated when adding students.</li>
<li>If the list is empty, the new student becomes the head.</li>
<li>The system checks for duplicate IDs before inserting.</li>
<li>All operations traverse the linked list node by node.</li>
<li>All memory is freed before exiting to avoid memory leaks.</li>
</ul>

<hr>

<h2>🚀 How to Compile and Run</h2>

<pre>
gcc main.c Student_function.c -o student_system
./student_system
</pre>

<p><i>Adjust filenames depending on your project structure.</i></p>

<hr>

<h2>📷 Example Operations</h2>
<ul>
<li>Add multiple students</li>
<li>Search using ID</li>
<li>Update GPA</li>
<li>Display class average</li>
<li>Delete a student</li>
<li>Exit safely</li>
</ul>

<hr>

<h2>🎯 Learning Purpose</h2>
<ul>
<li>Beginners learning Data Structures in C</li>
<li>Students practicing Linked Lists</li>
<li>Understanding dynamic memory management</li>
<li>Practicing modular programming</li>
</ul>

<hr>

<h2>🛠️ Possible Future Improvements</h2>
<ul>
<li>File handling (Save/Load students)</li>
<li>Sorting students by GPA</li>
<li>Handling invalid input types</li>
<li>Converting to Doubly Linked List</li>
<li>Adding a graphical or menu interface</li>
</ul>

<hr>

<h2>👨‍💻 Author</h2>
<p>
<b>Kerolous Labib</b><br>
Automotive Engineering Student<br>
C Programming & Embedded Systems Enthusiast
</p>

</body>
</html>
