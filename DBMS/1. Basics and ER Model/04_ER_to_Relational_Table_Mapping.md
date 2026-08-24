# 4. ER to Relational Table Mapping Rules

To convert an ER Diagram into normalized relational database tables, follow these standard mapping rules:

---

## 1. Mapping Strong Entity Sets
- Create a table for the entity set.
- All simple attributes become columns.
- Primary key of entity set becomes the **Primary Key** of the table.

## 2. Mapping Weak Entity Sets
- Create a separate table.
- Include all simple attributes of the weak entity set.
- Include the **Primary Key of the Strong Identifying Entity** as a **Foreign Key**.
- **Composite Primary Key:** `(Strong_PK + Partial_Key / Discriminator)`.

## 3. Mapping 1:1 Relationships
- **Case A (Total participation on one side):** Combine the relationship table with the table having total participation (place foreign key on total side).
- **Case B (Partial participation on both sides):** Either create a third table or place the PK of one entity as a Foreign Key in the other.

## 4. Mapping 1:N Relationships (Most Common!)
- **Rule:** Place the **Primary Key of the "1" side** as a **Foreign Key on the "N" (Many) side table**.
- **No third table is required!** (Saves join overhead).
- *Example:* `Department(1)` $\leftrightarrow$ `Employee(N)`: Add `Dept_ID` (Foreign Key) to `Employee` table.

## 5. Mapping M:N (Many-to-Many) Relationships
- **Rule:** **A SEPARATE RELATIONSHIP (JUNCTION) TABLE IS MANDATORY.**
- The junction table contains:
  1. Primary Key of Entity $A$ (Foreign Key).
  2. Primary Key of Entity $B$ (Foreign Key).
  3. Any descriptive attributes of the relationship.
- **Primary Key of Junction Table:** Composite Key `(PK_A, PK_B)`.

## 6. Mapping Multi-Valued Attributes
- **Rule:** **A SEPARATE TABLE IS MANDATORY.**
- Table contains: `(Entity_Primary_Key, Multi_Valued_Attribute)`.
- *Example:* `Student_Phone(Roll_No, Phone_Number)`.
