# Arbitrary_Precision_Calculator
/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

### 📄 **Project Documentation: arbitrary precision calculator Using Doubly Linked List**


#### 📌 **1. Project Overview**

This project implements a **Big Integer Arithmetic System** using **Doubly Linked Lists (DLL)** in C.
Since built-in integer types have size limits, this program allows performing arithmetic on extremely large numbers (thousands of digits long).

Operations supported:

| Operator | Operation      |
| -------- | -------------- |
| `+`      | Addition       |
| `-`      | Subtraction    |
| `x`      | Multiplication |
| `/`      | Division       |

All numbers are stored digit-by-digit in a doubly linked list, allowing precise manipulation regardless of size.

---

#### 📌 **2. Key Features**

* Supports integers larger than `long long`, `__int128`, etc.
* Handles **positive and negative numbers**.
* Removes **leading zeros** automatically.
* Uses **DLL traversal** for arithmetic from least significant to most significant digit.

---

#### 📌 **3. Input Format**

The program expects:

```
./a.out <operand1> <operator> <operand2>
```

📌 Example:

```
./a.out 12345678901234567890 x 987654321
```

If the format is incorrect, the program prints an error message.

---

#### 📌 **4. Data Structure Used**

```c
typedef struct node
{
    struct node *prev;
    int data;     // stores a single digit (-9 to 9 if first node is signed)
    struct node *next;
} Dlist;
```

Each number is stored as:

```
1234 → [1] <-> [2] <-> [3] <-> [4]
```

If negative:

```
-987 → [-9] <-> [8] <-> [7]
```

---

#### 📌 **5. Program Workflow**

```
Start
│
├─ Validate Arguments and Inputs
│
├─ Convert operand1 and operand2 into DLLs
│
├─ Remove extra leading zeros
│
├─ Perform selected arithmetic:
│       ├─ addition()
│       ├─ substraction()
│       ├─ multiplication()
│       └─ division()
│
├─ Store result in result DLL
│
└─ Print final output
```

---

#### 📌 **6. Function Descriptions**

| Function                 | Purpose                                               |
| ------------------------ | ----------------------------------------------------- |
| `validate_operand()`     | Ensures input contains valid digits and optional sign |
| `validate_operator()`    | Ensures operator is valid (`+ - x /`)                 |
| `convert_ascii_to_dll()` | Converts operand string to doubly linked list         |
| `dll_insert_at_first()`  | Inserts digit at the beginning of result list         |
| `remove_zero()`          | Removes unnecessary leading zeros                     |
| `compare_list()`         | Compares magnitudes of two numbers                    |
| `addition()`             | Performs digit-wise addition                          |
| `substraction()`         | Handles positive and negative subtraction logic       |
| `multiplication()`       | Performs repeated addition based multiplication       |
| `division()`             | Performs long-division style computation              |
| `print_list()`           | Displays the number stored in DLL format              |

---

#### 📌 **7. Example Output**

**Input:**

```
./a.out 99999 + 1
```

**Output:**

```
99999
1
Result = 100000
```

---

**Input:**

```
./a.out -500 x 12
```

**Output:**

```
-500
12
Result = -6000
```

---

#### 📌 **8. Error Handling**

| Condition                      | Message                                                              |
| ------------------------------ | -------------------------------------------------------------------- |
| Invalid operator               | `Invalid Operator choose ( +, -, x, / )`                             |
| Non-digit character in operand | `Please enter only digits.`                                          |
| Wrong argument format          | `Invalid Arguments. Please pass: ./a.out operand1 operator operand2` |
| Divide by zero                 | `Error: Cannot divide by zero`                                       |

---

#### 📌 **9. Limitations**

* Division logic may not support fractions (only integer results).
* No modulo operation implemented.
* Performance decreases with extremely large numbers (100,000+ digits).


