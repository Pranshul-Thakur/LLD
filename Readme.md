## ** Library Management System**

### 🧩 Features:
* Add, remove, search books
* Borrow/return books
* Basic user roles (admin, member)

## 🔍 OOP Principles Covered:

| Concept | How It's Used |
|---------|---------------|
| **Classes & Objects** | `Book`, `User`, `Library` as main classes |
| **Interfaces** | Abstract class `ILibraryService` for defining service behavior |
| **Inheritance** | `Admin` and `Member` inherit from `User` |
| **Polymorphism** | Virtual methods overridden by `Admin` / `Member` |
| **Abstraction** | Hide book operations inside `Library` class |
| **Encapsulation** | Use private members & getters/setters |
| **Aggregation** | `Library` has a list of `Book` objects (books can exist without Library) |
| **Composition** | `User` composed of credentials (username, password) |
| **Association** | `User` borrows books (relationship, not ownership) |

## 🔐 SOLID + Other Principles:

| Principle | Implementation Example |
|-----------|------------------------|
| **SRP** | Each class has one responsibility (`Book`, `User`, `Library`) |
| **OCP** | Add new user roles without changing existing logic |
| **LSP** | `Admin` and `Member` can be used in place of base `User` |
| **ISP** | Separate interfaces for `BookService`, `UserService` |
| **DIP** | Use interface (`ILibraryService`) instead of concrete classes |
| **DRY** | Common functionality reused via base classes or helpers |
| **KISS** | Simple class structure and functions |
| **YAGNI** | Only implement necessary features |
| **LoD** | Methods call only immediate dependencies |

## ✅ You Only Need:
* `Book` class
* `User` (base), `Admin` & `Member` (inherit)
* `Library` class (handles everything)
* `ILibraryService` interface
* Basic CLI with `main()` to call functions