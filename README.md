# Push_swap

Push_swap is a 42 project where I created a program that sorts integers using a limited set of stack operations.  
The goal is to sort data efficiently while minimizing the number of operations, which strengthened my skills in algorithms, data structures, and problem-solving in C.  
For this project, I implemented **Turk Sort** to optimize sorting sequences.

---

## 🛠️ Features

- Sorts integers using **stack operations**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`  
- Efficient sorting with **Turk Sort** algorithm  
- Handles small and large datasets  
- **Bonus:** Checker program verifies if a sequence of operations correctly sorts the stack  
- Prints the sequence of operations to sort the numbers  

---

## ⚡ Usage

Clone the repository and compile:

```bash
git clone https://github.com/mhmdam14/push_swap.git
cd push_swap
make         # Compiles push_swap
make bonus   # Compiles the bonus checker
./push_swap 3 2 5 1 4
./checker 3 2 5 1 4
