# 4. Relational (RDBMS) vs. NoSQL Databases

## Comprehensive Comparison

| Feature | Relational Databases (RDBMS / SQL) | NoSQL Databases (Non-Relational) |
| :--- | :--- | :--- |
| **Data Model** | Tables with fixed schemas (Rows and Columns) | Flexible schemas (Document, Key-Value, Columnar, Graph) |
| **Query Language** | Structured Query Language (SQL) | Dynamic query APIs (JSON, BSON, GraphQL) |
| **Scaling Model** | **Vertical Scaling** (Scale-Up: Add more CPU / RAM to 1 server) | **Horizontal Scaling** (Scale-Out: Add more commodity servers to cluster) |
| **Consistency Model** | Strict **ACID** guarantees | Flexible **BASE** / Eventual Consistency |
| **Complex Joins** | Native, highly optimized multi-table joins | Denormalized data / Application-level joins |
| **Best For** | Financial systems, ERPs, structured transactional data | Massive write loads, real-time analytics, flexible schema apps |

---

## The 4 Main Types of NoSQL Databases

```
+-----------------------------------------------------------------------------------+
| NOSQL TYPE     | DATA FORMAT                   | BEST USE CASE    | EXAMPLES      |
+----------------+-------------------------------+------------------+---------------+
| Document Store | JSON / BSON documents         | E-Commerce, CMS  | MongoDB,      |
|                |                               | user profiles    | CouchDB       |
+----------------+-------------------------------+------------------+---------------+
| Key-Value      | Hash Table (Key -> Value)     | Caching, Session | Redis,        |
|                |                               | storage          | Memcached     |
+----------------+-------------------------------+------------------+---------------+
| Wide-Column    | Tables with dynamic columns   | Time-series, IoT | Apache        |
|                | grouped in Column Families    | sensor data      | Cassandra     |
+----------------+-------------------------------+------------------+---------------+
| Graph Database | Nodes (Entities) and          | Social networks, | Neo4j,        |
|                | Edges (Relationships)         | fraud detection  | Amazon Neptune|
+-----------------------------------------------------------------------------------+
```
