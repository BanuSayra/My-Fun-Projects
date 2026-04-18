
# Driver.cpp - Program Overview

This is the **main driver file** for a calculator application that performs various mathematical operations. It's a menu-driven C++ program that handles expression evaluation, linear equation solving, and trigonometric/logarithmic calculations, with a file-based history tracking system.

## Key Components

### Global Data Structures
- **`qOutput`**: Queue storing results of operations
- **`qInput`**: Queue storing input expressions
- Both queues maintain a history of the last 5 operations

### Main Functions

| Function | Purpose |
|----------|---------|
| **`DisplayMenu()`** | Shows menu options (1-7) to the user |
| **`inputExpression()`** | Parses and evaluates infix, postfix, or prefix expressions |
| **`InsertInQ()`** | Adds expression and result to queues; maintains max 5 records |
| **`writeFile()`** | Writes input expressions and outputs to `RecordInput.txt` and `RecordOutput.txt` |
| **`readFile()`** | Reads historical records from files into queues on startup |
| **`printRecords()`** | Displays the last 5 operations with inputs and outputs |
| **`TrigonometricFunctions()`** | Calculates sin, cos, tan for a given angle in degrees |
| **`logarithm()`** | Computes natural log and log base 10 |

### Menu Options
1. **Evaluate expressions** - Infix, postfix, or prefix notation
2. **Solve linear equations**
3. **Convert infix to postfix**
4. **Trigonometric functions** (sin, cos, tan)
5. **Logarithmic functions** (ln, log₁₀)
6. **View last 5 operations**
7. **Exit**

### Expression Evaluation Logic
The `inputExpression()` function determines the expression type by checking:
- **Prefix**: Operator at the start → calls `EvaluatePrefix()`
- **Postfix**: Operator at the end → calls `EvaluatePostfix()`
- **Infix**: Digit at the start → calls `EvaluateInfix()`

### File Persistence
- On startup, `readFile()` loads previous 5 operations from disk
- After each operation, `writeFile()` saves records to text files
- This allows history to persist between program runs

---

**Note**: The program includes helper files (`Postfix.cpp`, `Infix.cpp`, `Prefix.cpp`, `Conversion.cpp`, `SolvingEquation.cpp`) that contain the actual implementation of expression evaluation and equation solving logic.
