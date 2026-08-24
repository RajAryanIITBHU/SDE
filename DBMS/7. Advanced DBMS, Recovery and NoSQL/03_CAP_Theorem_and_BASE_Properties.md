# 3. CAP Theorem & BASE Properties in Distributed Databases

## 1. The CAP Theorem (Brewer's Theorem)

In any distributed data store, you can guarantee **at most TWO out of three properties simultaneously**:

```
                              [ CONSISTENCY (C) ]
                                    /     \
                                   /       \
                                  /  CA     \  CP
                                 / (RDBMS)   \ (MongoDB, Redis)
                                /             \
            [ AVAILABILITY (A) ] ------------- [ PARTITION TOLERANCE (P) ]
                                      AP
                              (Cassandra, DynamoDB)
```

### The Three Properties:
1. **Consistency (C):** Every read receives the most recent write or an error. All nodes see the exact same data simultaneously.
2. **Availability (A):** Every non-failing node returns a successful response for every request (no errors/timeouts).
3. **Partition Tolerance (P):** The system continues to operate despite arbitrary network dropped messages or node communication network partitions.

### The Real-World Reality:
- In real distributed networks, **network partitions ($P$) are unavoidable**.
- Therefore, distributed databases must choose between:
  - **CP (Consistency + Partition Tolerance):** Block or reject requests if data cannot be synchronized (e.g., MongoDB, HBase, Redis Cluster).
  - **AP (Availability + Partition Tolerance):** Return slightly stale data rather than failing the request (e.g., Apache Cassandra, Amazon DynamoDB, CouchDB).

---

## 2. BASE Properties (NoSQL Philosophy)

While relational systems follow strict **ACID**, distributed NoSQL databases follow **BASE**:

- **B - Basically Available:** System guarantees availability according to CAP (returns responses even during node failures).
- **S - Soft State:** The state of the system may change over time, even without new inputs, due to background data replication.
- **E - Eventual Consistency:** Given enough time without new updates, all replicas will eventually converge and become consistent.
